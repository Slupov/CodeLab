/**
 *  @brief
 *  @date 03.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "TransposeMatrix.h"

void TransposeMatrix::solve()
{
    TwoDimensionArrayProblem::solve();

    const int32_t COLS = _dataSizes[0];

    int32_t ** transposedMatrix = new int32_t * [COLS];

    for(int32_t tRow = 0; tRow < COLS; ++tRow)
    {
        transposedMatrix[tRow] = new int32_t[_rows];
    }

    for(int32_t row = 0; row < _rows; ++row)
    {
        for(int32_t col = 0; col < COLS; ++col)
        {
            transposedMatrix[col][row] = _data[row][col];
        }
    }

    printSolution(transposedMatrix);

    //free up memory
    for(int32_t i = 0; i < COLS; ++i)
    {
        delete [] transposedMatrix[i];
        transposedMatrix[i] = nullptr;
    }

    delete[] transposedMatrix;
    transposedMatrix = nullptr;
}

void TransposeMatrix::printSolution(int32_t ** transposedMatrix)
{
    printArray();

    printf("\n");
    printf("| Transposed matrix |\n");
    printf("v                   v\n");
    printf("\n");

    for(int32_t rowT = 0; rowT < _dataSizes[rowT]; ++rowT)
    {
        for(int32_t colT = 0; colT < _rows; ++colT)
        {
            printf("%d ", transposedMatrix[rowT][colT]);
        }

        printf("\n");
    }
}
