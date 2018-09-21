#ifndef CODELAB_NQUEENS_H
#define CODELAB_NQUEENS_H



/**
 *  @brief
 *  @date 20.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "ArrayProblem.h"

class NQueens : public ArrayProblem
{
    public:
        virtual void solve() override;

    private:
        virtual void initData() override;

        void printSolution();

        void placeQueen(const int32_t row);

        //checks whether a position is safe for a queen to be put
        bool isSafe(const int32_t row, const int32_t col);


        void setAttackedColumnsDiagonals(const int32_t row, const int32_t col,
                                         const uint8_t value);

        std::vector<std::vector<uint8_t>> _board;

        std::vector<uint8_t> _attackedColumn;
        std::vector<uint8_t> _attackedDiagonalLeft;
        std::vector<uint8_t> _attackedDiagonalRight;

        int32_t _n;
};


#endif //CODELAB_NQUEENS_H
