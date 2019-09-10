#ifndef CODELAB_ARRAYS_NBULECTURE_1D_CONTAINERWITHMOSTWATER_H
#define CODELAB_ARRAYS_NBULECTURE_1D_CONTAINERWITHMOSTWATER_H

/**
 *  @brief
 *  @url https://leetcode.com/problems/container-with-most-water/description/
 *  @date 30-Oct-18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "arrays/OneDimensionArrayProblem.h"

class ContainerWithMostWater : public OneDimensionArrayProblem
{
public:
    virtual ~ContainerWithMostWater() = default;

    virtual void solve() override;

private:

    /**
    * @brief consider the area for every possible pair of the lines and find
    * out the maximum area out of those.
    * @comlexity O(n^2)
    * **/
    uint32_t solveBruteForce();

    /**
   * @brief
   * @comlexity O(n)
   * **/
    uint32_t solveTwoPointers();
};

#endif //CODELAB_ARRAYS_NBULECTURE_1D_CONTAINERWITHMOSTWATER_H
