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
#define MANTISSA_BITS 7

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

        /** normally would not use bit fields since they are out of the C++
            standard, generally an array of 6 uint8_t's would be a great way to
            represent a 6 B number but this representation is deprived of
            flexibility to change the custom size of the structure easily **/

        uint8_t _sign      : SIGN_BITS;     // 1  bit
        uint8_t _exponent  : EXPONENT_BITS; // 7  bits

        uint64_t _mantissa : MANTISSA_BITS; // 40 bits
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_LARGEFLOAT_H
