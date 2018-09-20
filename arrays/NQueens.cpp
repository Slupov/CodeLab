/**
 *  @brief
 *  @date 19.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "NQueens.h"

#define EMPTY_SPACE 0
#define QUEEN 1

NQueens::NQueens() : _n(0)
{

}

void NQueens::initData()
{
    std::cout << "Enter n (number of rows/cols/queens): ";
    std::cin >> _n;

    _board.resize(_n);

    for(std::vector<uint8_t> & row: _board)
    {
        row.resize(_n, EMPTY_SPACE);
    }
}

void NQueens::solve()
{
    initData();
}

NQueens::~NQueens()
{

}

