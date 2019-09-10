#ifndef ARRAYS_NBULECTURE_1D_ARRAYSHIFT_H
#define ARRAYS_NBULECTURE_1D_ARRAYSHIFT_H

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
#include "arrays/OneDimensionArrayProblem.h"

class ArrayShift : public OneDimensionArrayProblem
{
public:
    virtual void solve() override;

private:
    /**
    * @brief solved over the working array only
    * @comlexity O(n)
    * **/
    void solveCyclicReplacements(const int32_t shifts);

    /**
    * @brief solved by making a temporary copy of the working array
    * @comlexity O(n)
    * **/
    void solveAdditionalArray(const int32_t shifts);
};


#endif //ARRAYS_NBULECTURE_1D_ARRAYSHIFT_H
