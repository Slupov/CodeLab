/**
 *  @brief
 *  @date 13.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <bitset>
#include <iostream>

//Other libraries headers

//Own components headers

#include "LargeFloat.h"

/**
 * NOTE!: Exponent is 7 bits so the exponent bias (needed for negative
 * exponents must be 0111 1111 / 2 -> 127/2 -> 64
 * So the exponent range is [-63; 63]
 * **/
#define EXP_BIAS 64
#define DOUBLE_EXP_BIAS 1023

#define DOUBLE_SIGN_BITS 1
#define DOUBLE_EXPONENT_BITS 11
#define DOUBLE_MANTISSA_BITS 52

#define BITS_IN_BYTE 8

#define DEBUG_LOGS 1

/** Test results at http://www.binaryconvert.com/convert_double.html **/

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

    /** we need the bits in the input double to be reversed for a simpler
      * modification **/
    uint64_t * bits = (uint64_t *)&initValue;
    uint64_t reversed = reverseBits(*bits);

#if DEBUG_LOGS
    printf("Default constructor value: \n");
    printBits(bytePtr, bytesCnt * BITS_IN_BYTE);

    std::cout << "\n";

    printf("REVERSED constructor value: \n");
    printBits((uint8_t*)&reversed, bytesCnt * BITS_IN_BYTE);
    printDoubleBitsLegend(0, bytesCnt * BITS_IN_BYTE);
#endif//DEBUG_LOGS

    //double 1 bit sign
    _sign = extractSign(reversed);

    //double 11 bits exponent > my exponent bits 7
    _exponent = extractExp(reversed);

    //double 52 bits mantissa > my mantissa bits 40
    _mantissa = extractMantissa(reversed);
}

LargeFloat LargeFloat::operator+(const LargeFloat & b)
{
    /** use the smaller exponent **/
    _exponent = _exponent < b._exponent ? _exponent : b._exponent;

    /** add both mantissas **/
    uint64_t mantissa = _mantissa + b._mantissa;

    //unset 52 - 40 = 12 bits
    uint64_t mask = (1ul << 63); //0000 0000 ... ... ... ... ... ... 0000 0001

    const uint32_t LOOP_END = static_cast<uint32_t>(
            (sizeof(uint64_t) * BITS_IN_BYTE) - MANTISSA_BITS);

    //unset obsolete bits in the beggining
    for(uint32_t i = 0; i < LOOP_END; ++i)
    {
        mantissa = (mantissa & ~mask);
        mask >>= 1;
    }

    _mantissa = mantissa;

    /** determine sign **/
    //TODO Implement later (how to determine sign?)

    return *this;
}

std::ostream & operator<<(std::ostream & ostream, const LargeFloat & value)
{
    //TODO Left to implement later. Print binary representantion for now
    if (1 == value._sign)
    {
        ostream << "-";
    }

    printf("1.");
    uint64_t mantissa = value._mantissa;
    value.printBits((uint8_t*)&mantissa, MANTISSA_BITS);

    ostream << "x 2^" << std::to_string(value._exponent - EXP_BIAS);

    return ostream;
}

uint8_t LargeFloat::extractSign(const uint64_t reversed)
{
    //return 1 if negative, 0 if positive
    uint8_t *bytePtr  = (uint8_t *)&reversed;
    uint32_t bytesCnt = sizeof(reversed);

    //first bit is for the sign
    uint8_t result = bytePtr[0];
    result &= 1;

    return result;
}

uint8_t LargeFloat::extractExp(const uint64_t reversed)
{
    // we dont need the sign bit
    uint64_t bits = reversed >> 1;

    uint16_t* shortPtr = (uint16_t*)&bits;
    uint16_t exponent = *shortPtr;

    //get next 11 bits
    uint16_t mask = (1 << 15); //0000 0000 0000 0001

    const uint32_t LOOP_END = static_cast<uint32_t>(
            (sizeof(uint16_t) * BITS_IN_BYTE) - DOUBLE_EXPONENT_BITS);

    //unset obsolete bits in the beggining
    for(uint32_t i = 0; i < LOOP_END; ++i)
    {
        exponent = (exponent & ~mask);
        mask >>= 1;
    }

    return static_cast<uint8_t>(exponent);
}

uint64_t LargeFloat::extractMantissa(const uint64_t reversed)
{
    //double mantissa is 52 bits
    //we dont need the first 12 bits (1 sign + 11 exponent)
    uint64_t bits = reversed >> 12;

    //unset 52 - 40 = 12 bits
    uint64_t mask = (1ul << 63); //0000 0000 ... ... ... ... ... ... 0000 0001

    const uint32_t LOOP_END = static_cast<uint32_t>(
            (sizeof(uint64_t) * BITS_IN_BYTE) - MANTISSA_BITS);

    //unset obsolete bits in the beggining
    for(uint32_t i = 0; i < LOOP_END; ++i)
    {
        bits = (bits & ~mask);
        mask >>= 1;
    }

    return bits;
}

void LargeFloat::printBits(uint8_t *bytePtr, const uint32_t bitsCount) const
{
    uint32_t bytes = bitsCount / BITS_IN_BYTE;
    
    if (bitsCount % BITS_IN_BYTE != 0)
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

    std::string MSG = "SEEEEEEEEEEEMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
                      "MMMMMMMMMMMM";

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

uint64_t LargeFloat::reverseBits(const uint64_t input) // input bits to be reversed
{
    const int32_t bits = sizeof(uint64_t) * BITS_IN_BYTE;
    std::bitset<bits> inputBits = input;
    std::bitset<bits> reversedBits = 0;

    for(int32_t i = bits - 1; i >= 0; --i)
    {
        reversedBits[bits - i - 1] = inputBits[i];
    }

    return reversedBits.to_ullong();
}
