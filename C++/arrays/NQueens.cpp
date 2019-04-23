/**
 *  @brief
 *  @date 20.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "NQueens.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#define EMPTY_SPACE 0
#define QUEEN 1

void NQueens::initData()
{
    std::cout << "Enter n (number of row_cells/cols/queens): ";
    std::cin >> _n;

    _board.resize(_n);

    for(std::vector<uint8_t> & row: _board)
    {
        row.resize(_n, EMPTY_SPACE);
    }

    _attackedColumn.resize(_n, EMPTY_SPACE);
    _attackedDiagonalLeft.resize(_n * 2 - 1, EMPTY_SPACE);
    _attackedDiagonalRight.resize(_n * 2 - 1, EMPTY_SPACE);
}

void NQueens::solve()
{
    initData();

    placeQueen(0);
}

void NQueens::placeQueen(const int32_t row)
{
    if(row == _n)
    {
        printSolution();
        printf("\n");
        return;
    }

    for(int32_t col = 0; col < _n; ++col)
    {
        if(!isSafe(row, col))
            continue;

        _board[row][col] = QUEEN;
        setAttackedColumnsDiagonals(row, col, QUEEN);

        placeQueen(row + 1);

        _board[row][col] = EMPTY_SPACE;
        setAttackedColumnsDiagonals(row, col, EMPTY_SPACE);
    }
}

bool NQueens::isSafe(const int32_t row, const int32_t col)
{
    return !(_attackedColumn[col] ||
             _attackedDiagonalLeft[row + col] ||
             _attackedDiagonalRight[col - row + _n - 1]);
}

void NQueens::printSolution()
{
    for(int32_t row = 0; row < _n; ++row)
    {
        printf("|");
        for(int32_t col = 0; col < _n; ++col)
        {
            printf("%d|", _board[row][col]);
        }

        printf("\n");
    }
}

void NQueens::setAttackedColumnsDiagonals(const int32_t row,
                                          const int32_t col,
                                          const uint8_t value)
{
    _attackedColumn[col] = _attackedDiagonalLeft[row + col] =
    _attackedDiagonalRight[col - row + _n - 1] = value;
}
