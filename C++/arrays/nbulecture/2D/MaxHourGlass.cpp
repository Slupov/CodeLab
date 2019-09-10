/**
 *  @brief
 *  @date 07.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "MaxHourGlass.h"

void MaxHourGlass::solve()
{
    TwoDimensionArrayProblem::solve();

    printArray();
    printf("\n");

    if(_rows < 3 || _dataSizes[0] < 3)
    {
        printf("Matrix[%d, %d] cannot contain hour-glasses...",
               _rows, _dataSizes[0]);
        return;
    }

    int32_t ansR   = 0;
    int32_t ansC   = 0;
    int32_t maxSum = INT32_MIN;

    for(int32_t row = 0; row < _rows - 2; row++)
    {
        for(int32_t col = 0; col < _dataSizes[row] - 2; col++)
        {
            // Considering mat[row][col] as top left cell of
            // hour glass.
            int32_t sum = (_data[row][col] + _data[row][col + 1] +
                           _data[row][col + 2]) +
                          (_data[row + 1][col + 1]) +
                          (_data[row + 2][col] + _data[row + 2][col + 1] +
                           _data[row + 2][col + 2]);

            // update new max sum
            if(maxSum < sum)
            {
                ansR   = row;
                ansC   = col;
                maxSum = sum;
            }
        }
    }

    printSolution(ansR, ansC, maxSum);
}

void MaxHourGlass::printSolution(const int32_t ansR, const int32_t ansC,
                                 const int32_t ansSum)
{

    printf("%5d%5d%5d\n", _data[ansR][ansC], _data[ansR][ansC + 1],
           _data[ansR][ansC + 2]);

    printf("%5s%5d%5s         -----sum-----> %d\n",
           "", _data[ansR + 1][ansC + 1], "", ansSum);

    printf("%5d%5d%5d", _data[ansR + 2][ansC], _data[ansR + 2][ansC + 1],
           _data[ansR + 2][ansC + 2]);
}