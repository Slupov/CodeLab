#ifndef ARRAYS_NQUEENS_H
#define ARRAYS_NQUEENS_H

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

#include "ArrayProblem.h"

class NQueens : public ArrayProblem
{
    public:
        NQueens();

        virtual ~NQueens();

        virtual void initData() override;

        virtual void solve() override;

    private:
        std::vector<std::vector<uint8_t>> _board;

        uint32_t _n;
};


#endif //ARRAYS_NQUEENS_H
