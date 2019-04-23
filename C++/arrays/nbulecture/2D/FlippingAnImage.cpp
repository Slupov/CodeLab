/**
 *  @brief
 *  @date 06.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "FlippingAnImage.h"

void FlippingAnImage::solve()
{
    TwoDimensionArrayProblem::solve();

    int32_t temp = 0;
    int32_t cols = 0;

    for(int32_t row = 0; row < _rows; ++row)
    {
        cols = _dataSizes[row];

        for(int32_t i = 0; i < (cols + 1) / 2; ++i)
        {
            //reversing && inversing at the same time
            temp = _data[row][i] ^ 1;
            _data[row][i] =  _data[row][cols - 1 - i] ^ 1;
            _data[row][cols - 1 - i] = temp;
        }
    }
}
