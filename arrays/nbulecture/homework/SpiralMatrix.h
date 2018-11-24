#ifndef ARRAYS_NBULECTURE_HOMEWORK_SPIRALMATRIX_H
#define ARRAYS_NBULECTURE_HOMEWORK_SPIRALMATRIX_H

/**
 *  @brief
 *  @url none
 *  @date 04.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "arrays/TwoDimensionArrayProblem.h"

class SpiralMatrix : public TwoDimensionArrayProblem
{
public:
    SpiralMatrix() = default;

    virtual ~SpiralMatrix() = default;

    virtual void solve() override;

    virtual void initData() override;

    virtual void initDataSimple() override;

    virtual void initRandomData() override;

    virtual void printArray() override;

private:

    //values vary in range [-1, 1]
    int32_t _xSpeed;
    int32_t _ySpeed;
};

#endif //ARRAYS_NBULECTURE_HOMEWORK_SPIRALMATRIX_H
