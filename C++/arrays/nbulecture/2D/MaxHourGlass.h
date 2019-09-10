#ifndef ARRAYS_NBULECTURE_2D_MAXHOURGLASS_H
#define ARRAYS_NBULECTURE_2D_MAXHOURGLASS_H

/**
 *  @brief Find the biggest hour glass sum in the matrix
 *  @url https://www.geeksforgeeks.org/maximum-sum-hour-glass-matrix
 *
 *  A B C
 *    D        ---->  hour-glass
 *  E F G
 *
 *  @date 07.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "arrays/TwoDimensionArrayProblem.h"

class MaxHourGlass : public TwoDimensionArrayProblem
{
public:
    virtual void solve() override;

private:
    void printSolution(const int32_t ansR, const int32_t ansC,
            const int32_t ansSum);

};


#endif //ARRAYS_NBULECTURE_2D_MAXHOURGLASS_H
