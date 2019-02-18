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

    printf("Default constructor value: \n");
    printBits(bytePtr, bytesCnt * BITS_IN_BYTE);
    printDoubleBitsLegend(0);

    //double 1 bit sign
    _sign = extractSign(initValue);

    //double 11 bits exponent > my exponent bits 7
    _exponent = extractExp(initValue);

    //double 52 bits mantissa > my mantissa bits 40
    _mantissa = extractMantissa(initValue);
}

LargeFloat LargeFloat::operator+(const LargeFloat & b)
{
    _mantissa += b._mantissa;
    return *this;
}

std::ostream & operator<<(std::ostream & ostream, const LargeFloat & value)
{
    if (1 == value._sign)
    {
        ostream << "-";
    }

    //in range {-63; 63}
    int8_t expInt = 0;

    if (value._exponent < EXP_BIAS)
    {
        expInt = static_cast<int8_t>(value._exponent - EXP_BIAS);
    }
    else
    {
        expInt = static_cast<int8_t>(value._exponent + EXP_BIAS);
    }

    ostream << "x 2^" << std::to_string(expInt);

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
    printf("\n...EXTRACTING EXPONENT... \n");

    //double's exponent is the 11 bits before the least significant bit (sign)
    //decode the IEE754 double exponent

    int16_t *shortPtr  = (int16_t *)&number;
    int16_t decodedExponent = shortPtr[3];

    //remove the sign bit
    decodedExponent <<= 1;

    //unset obsolete 4 bits in the beggining
    for(uint32_t i = 0; i < 4; ++i)
    {
        decodedExponent &= ~(1 << (sizeof(int16_t) - 1 - i));
    }

    decodedExponent >>= 4;

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
    printf("\n...EXTRACTING MANTISSA... \n");

    //double 52 bits mantissa > my mantissa bits 40
    uint64_t *longPtr  = (uint64_t *)&number;

    uint64_t result = *longPtr;

    const int8_t SHIFT_VALUE = (DOUBLE_SIGN_BITS + DOUBLE_EXPONENT_BITS);
    result <<= SHIFT_VALUE;

    printBits((uint8_t*)&result, sizeof(double) * BITS_IN_BYTE);
    printDoubleBitsLegend(SHIFT_VALUE);

    return result;
}

void LargeFloat::printBits(uint8_t *bytePtr, const uint32_t bitsCount)
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


void LargeFloat::reverseBits(uint8_t * startByte, const uint32_t bytes,
                             uint8_t * outBytes)
{
    for(uint32_t i = 0; i < bytes; ++i)
    {
        outBytes[bytes - 1] = reverseByte(startByte[i]);
    }
}

void LargeFloat::printDoubleBitsLegend(const int8_t shiftedOffset)
{
    uint32_t loopEnd = 0;
    uint8_t packByte = 0;

    std::string MSG = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
                      "MMMMMMMMMMMMEEEEEEEEEEES";

    printf("\n");

    //bits shifted left
    if (shiftedOffset > 0)
    {
        loopEnd = static_cast<uint32_t>(64 - shiftedOffset);

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

        for(uint32_t j = 0; j < 64; ++j)
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

        for(uint32_t j = posShiftedOffset; j < 64; ++j)
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
        for(uint32_t i = 0; i < 64; ++i)
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
