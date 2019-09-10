#ifndef ARRAYS_NBULECTURE_2D_TRANSPOSEMATRIX_H
#define ARRAYS_NBULECTURE_2D_TRANSPOSEMATRIX_H



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
#include "arrays/TwoDimensionArrayProblem.h"

class TransposeMatrix : public TwoDimensionArrayProblem
{

public:
    virtual void solve() override;

private:
    void printSolution(int32_t ** transposedMatrix);
};


#endif //ARRAYS_NBULECTURE_2D_TRANSPOSEMATRIX_H
