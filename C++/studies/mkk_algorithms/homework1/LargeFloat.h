#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_LARGEFLOAT_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_LARGEFLOAT_H

/**
 *  @brief
 *  @date 13.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <ostream>

//Other libraries headers

//Own components headers

//Forward declarations
class LargeFloat;

#define SIGN_BITS 1
#define EXPONENT_BITS 7
#define MANTISSA_BITS 40

#pragma pack(2)
class LargeFloat
{
    public:
        LargeFloat();
        LargeFloat(const double initValue);

        ~LargeFloat() = default;

        LargeFloat operator+(const LargeFloat &b);

        friend std::ostream& operator<<(std::ostream& ostream,
                                        const LargeFloat &value);

    private:

        uint8_t  extractSign(const uint64_t reversed);
        uint8_t  extractExp(const uint64_t reversed);
        uint64_t extractMantissa(const uint64_t reversed);

        /** Prints all bits in a given space of bytes. Starts every byte with
         *  printing its most significant bit first.
         *  Used for debug purposes only.
         *  **/
        void printBits(uint8_t *bytePtr, const uint32_t bytes) const;

        /** reverses bits in byte. First the left four bits are swapped with the
         * right four bits. Then all adjacent pairs are swapped and then all
         * adjacent single bits. This results in a reversed order.**/
        inline uint8_t reverseByte(uint8_t b)
        {
            b = static_cast<uint8_t>((b & 0xF0) >> 4 | (b & 0x0F) << 4);
            b = static_cast<uint8_t>((b & 0xCC) >> 2 | (b & 0x33) << 2);
            b = static_cast<uint8_t>((b & 0xAA) >> 1 | (b & 0x55) << 1);

            return b;
        }

        uint64_t reverseBits(const uint64_t bits);

        inline void printDoubleBitsLegend(const int8_t shiftedOffset,
                                          const uint32_t bitsCount);

        /** normally would not use bit fields since they are out of the C++
            standard, generally an array of 6 uint8_t's would be a great way to
            represent a 6 B number but this representation is deprived of
            flexibility to change the custom size of the structure easily **/

        uint8_t _sign      : SIGN_BITS;     // 1  bit
        uint8_t _exponent  : EXPONENT_BITS; // 7  bits

        uint64_t _mantissa : MANTISSA_BITS; // 40 bits
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_LARGEFLOAT_H
