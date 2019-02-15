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
 * **/
#define EXP_BIAS 63

LargeFloat::LargeFloat()
{
    _mantissa = 0;
    _exponent = 0;
    _sign     = 0;
}

LargeFloat::LargeFloat(const double initValue)
{
    //double 1 bit sign
    //double 11 bits exponent > my exponent bits ?
    //double 52 bits mantissa > my mantissa bits ?
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
