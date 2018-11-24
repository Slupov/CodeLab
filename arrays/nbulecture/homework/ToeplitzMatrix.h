#ifndef DATAGENERATOR_SPIRALMATRIX_H
#define DATAGENERATOR_SPIRALMATRIX_H

/**
 *  @brief https://leetcode.com/problems/toeplitz-matrix/description/
 *  @date 04.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "arrays/TwoDimensionArrayProblem.h"

class ToeplitzMatrix : public TwoDimensionArrayProblem
{
public:
    ToeplitzMatrix() = default;

    virtual ~ToeplitzMatrix() = default;

    virtual void solve() override;
};

#endif //DATAGENERATOR_SPIRALMATRIX_H
