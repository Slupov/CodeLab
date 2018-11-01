#ifndef ARRAYS_ARRAYPROBLEM_H
#define ARRAYS_ARRAYPROBLEM_H

/**
 *  @brief
 *  @date 19.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <vector>

//Other libraries headers

//Own components headers
#include "Problem.h"

class ArrayProblem : public Problem
{
    public:
        virtual ~ArrayProblem() = default;

        virtual void initData() = 0;

        virtual void solve() = 0;
};


#endif //ARRAYS_ARRAYPROBLEM_H
