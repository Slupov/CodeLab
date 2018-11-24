/**
 *  @brief
 *  @date 04.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "ToeplitzMatrix.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

void ToeplitzMatrix::solve()
{
    TwoDimensionArrayProblem::solve();

    printArray();

    for(int32_t row = 0; row < _rows; ++row)
    {
        for(int32_t col = 0; col < _dataSizes[row]; ++col)
        {
            //both row and col are not first
            if(row > 0 && col > 0)
            {
                //upper prev row and prev col cell is not equal to current cell
                if (_data[row - 1][col - 1] != _data[row][col])
                {
                    printf("false");
                    return;
                }
            }
        }
    }

    printf("true");
}