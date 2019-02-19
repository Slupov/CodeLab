///**
// *  @brief
// *  @date 13.02.19
// *  @author Stoyan Lupov
// */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "LargeFloat.h"

/**
 * NOTE!: Exponent is 7 bits so the exponent bias (needed for negative
 * exponents must be 0111 1111 / 2 -> 127/2 -> 63
 * So the exponent range is [-64; 63]
 * **/
#define EXP_BIAS 63
#define DOUBLE_EXP_BIAS 1023

#define DOUBLE_SIGN_BITS 1
#define DOUBLE_EXPONENT_BITS 11

#define BITS_IN_BYTE 8

#define DEBUG_LOGS 0

LargeFloat::LargeFloat()
{
    _mantissa = 0;
    _exponent = 0;
    _sign     = 0;
}

LargeFloat::LargeFloat(const double initValue)
{
    uint8_t *bytePtr  = (uint8_t *)&initValue;
    uint32_t bytesCnt = sizeof(double);

#if DEBUG_LOGS
    printf("Default constructor value: \n");
    printBits(bytePtr, bytesCnt * BITS_IN_BYTE);
    printDoubleBitsLegend(0, bytesCnt * BITS_IN_BYTE);
#endif//DEBUG_LOGS

    //double 1 bit sign
    _sign = extractSign(initValue);

    //double 11 bits exponent > my exponent bits 7
    _exponent = extractExp(initValue);

    //double 52 bits mantissa > my mantissa bits 40
    _mantissa = extractMantissa(initValue);
}

LargeFloat LargeFloat::operator+(const LargeFloat & b)
{
    //TODO Left to implement later.
    return *this;
}

std::ostream & operator<<(std::ostream & ostream, const LargeFloat & value)
{
    //TODO Left to implement later.
    if (1 == value._sign)
    {
        ostream << "-";
    }

    printf("1.");
    uint64_t mantissa = value._mantissa;
    value.printBits((uint8_t*)&mantissa, MANTISSA_BITS);

    //in range {-63; 64}
//    int8_t expInt = 0;
//
//    if (value._exponent < EXP_BIAS)
//    {
//        expInt = static_cast<int8_t>(value._exponent - EXP_BIAS);
//    }
//    else
//    {
//        expInt = static_cast<int8_t>(value._exponent + EXP_BIAS);
//    }

    ostream << "x 2^" << std::to_string(value._exponent);

    return ostream;
}

uint8_t LargeFloat::extractSign(const double number)
{
    //return 1 if negative, 0 if positive
    uint8_t *bytePtr  = (uint8_t *)&number;
    uint32_t bytesCnt = sizeof(double);

    //last bit is for the sign
    uint8_t result = bytePtr[bytesCnt - 1];
    result >>= BITS_IN_BYTE - 1;
    result = static_cast<uint8_t>(result & 1);

    return result;
}

uint8_t LargeFloat::extractExp(const double number)
{
    //TODO Stoyan Lupov Not sure if that's how to "cut" the exponent from the
    //bigger double exponent. Need to take a second look at this later.
    //Spoiler: That's probably not the way it should be done :)

#if DEBUG_LOGS
    printf("\n...EXTRACTING EXPONENT... \n");
#endif//DEBUG_LOGS

    //double's exponent is the 11 bits before the least significant bit (sign)
    //decode the IEE754 double exponent

    //double 11 bits exponent > my exponent bits 7

    int16_t *shortPtr  = (int16_t *)&number;
    int16_t decodedExponent = shortPtr[3];

#if DEBUG_LOGS
    printBits((uint8_t*)&decodedExponent, sizeof(int16_t) * BITS_IN_BYTE);
    printDoubleBitsLegend(0, sizeof(int16_t) * BITS_IN_BYTE);
#endif//DEBUG_LOGS

    //remove the sign bit
    decodedExponent <<= 1;

#if DEBUG_LOGS
    printBits((uint8_t*)&decodedExponent, sizeof(int16_t) * BITS_IN_BYTE);
    printDoubleBitsLegend(1, sizeof(int16_t) * BITS_IN_BYTE);
#endif//DEBUG_LOGS

    //unset obsolete 4 bits in the beggining
    int16_t unsetter = 0;
    for(uint32_t i = 0; i < 5; ++i)
    {
        unsetter = static_cast<int16_t>(~(1 << (sizeof(int16_t) - 2 + i)));
        decodedExponent &= unsetter;
    }

#if DEBUG_LOGS
    printBits((uint8_t*)&decodedExponent, sizeof(int16_t) * BITS_IN_BYTE);
    printDoubleBitsLegend(1, sizeof(int16_t) * BITS_IN_BYTE);
#endif//DEBUG_LOGS

    uint8_t result = 0;

    if (decodedExponent <= EXP_BIAS)
    {
        result = static_cast<uint8_t>(decodedExponent);
    }
    else
    {
        //set to max value of our exponent
        result = 2 * EXP_BIAS;
    }

    return result;
}

uint64_t LargeFloat::extractMantissa(const double number)
{
#if DEBUG_LOGS
    printf("\n...EXTRACTING MANTISSA... \n");
#endif//DEBUG_LOGS

    const uint32_t DOUBLE_BITS = sizeof(double) * BITS_IN_BYTE;
    //double 52 bits mantissa > my mantissa bits 40
    uint64_t *longPtr  = (uint64_t *)&number;
    uint64_t result = *longPtr;

    //unset obsolete 12 bits after the mantissa
    uint64_t unsetter = 0;
    uint64_t unsetterValue = 1;

    uint32_t loopEnd = DOUBLE_SIGN_BITS + DOUBLE_EXPONENT_BITS;

    for(uint32_t i = 0; i < loopEnd; ++i)
    {
        unsetter = static_cast<uint64_t>(
                ~(unsetterValue << (DOUBLE_BITS - 1 - i)));

        result &= unsetter;
    }

#if DEBUG_LOGS
    printBits((uint8_t*)&result, DOUBLE_BITS);
    printDoubleBitsLegend(0, DOUBLE_BITS);
#endif//DEBUG_LOGS

    return result;
}

void LargeFloat::printBits(uint8_t *bytePtr, const uint32_t bitsCount) const
{
    uint32_t bytes = bitsCount / 8;
    
    if (bitsCount % 8 != 0)
    {
        ++bytes;
    }

    uint8_t byte = 0;
    uint8_t packByte = 0;
    uint8_t currentBit = 0;

    for(uint32_t i = 0; i < bytes; ++i)
    {
        byte = bytePtr[i];

        for(uint32_t j = 0; j < BITS_IN_BYTE; ++j)
        {
            ++packByte;

            if (currentBit == bitsCount)
            {
                return;
            }

            //xxxx xxxx & 0000 0001
            printf("%d", byte & 1);
            byte >>= 1;

            if (packByte == 8)
            {
                printf(" ");
                packByte = 0;
            }
        }
    }
}

void LargeFloat::printDoubleBitsLegend(const int8_t shiftedOffset,
                                       const uint32_t bitsCount)
{
    uint32_t loopEnd = 0;
    uint8_t packByte = 0;

    std::string MSG = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
                      "MMMMMMMMMMMMEEEEEEEEEEES";

    MSG = MSG.substr(MSG.size() - bitsCount, bitsCount);

    printf("\n");

    //bits shifted left
    if (shiftedOffset > 0)
    {
        loopEnd = static_cast<uint32_t>(bitsCount - shiftedOffset);

        for(uint32_t i = 0; i < shiftedOffset; ++i)
        {
            ++packByte;

            printf(" ");

            if (packByte == 8)
            {
                printf(" ");
                packByte = 0;
            }
        }

        for(uint32_t j = 0; j < bitsCount; ++j)
        {
            ++packByte;

            printf("%c", MSG[j]);

            if (packByte == 8)
            {
                printf(" ");
                packByte = 0;
            }
        }
    }
    else if (shiftedOffset < 0)
    {
        uint32_t posShiftedOffset =
                static_cast<uint32_t>(-shiftedOffset);

        for(uint32_t i = 0; i > posShiftedOffset; ++i)
        {
            ++packByte;
            printf("%c", ' ');

            if (packByte == 8)
            {
                printf(" ");
                packByte = 0;
            }
        }

        for(uint32_t j = posShiftedOffset; j < bitsCount; ++j)
        {
            ++packByte;
            printf("%c", MSG[j]);

            if (packByte == 8)
            {
                printf(" ");
                packByte = 0;
            }
        }
    }
    else
    {
        for(uint32_t i = 0; i < bitsCount; ++i)
        {
            ++packByte;
            printf("%c", MSG[i]);

            if (packByte == 8)
            {
                printf(" ");
                packByte = 0;
            }
        }
    }

    printf("\n");
}
