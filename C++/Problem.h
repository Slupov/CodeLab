#ifndef PROBLEM_H
#define PROBLEM_H

/**
 *  @brief
 *  @date 19.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <iostream>
#include <cstdint>

//Other libraries headers

//Own components headers

class Problem
{
    public:
        virtual void solve() = 0;

    protected:
        virtual void initData() = 0;
};

#endif //PROBLEM_H
