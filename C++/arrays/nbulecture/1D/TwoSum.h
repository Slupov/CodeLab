#ifndef ARRAYS_NBULECTURE_1D_TWOSUM_H
#define ARRAYS_NBULECTURE_1D_TWOSUM_H

/**
 *  @brief
 *  @url https://leetcode.com/problems/two-sum/description/
 *  @date 01-Nov-18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "arrays/OneDimensionArrayProblem.h"

class TwoSum : public OneDimensionArrayProblem
{
public:
    virtual ~TwoSum() = default;

    virtual void solve() override;

    /**
    * @brief consider every possible pair
    * @comlexity O(n^2)
    * **/
    void solveBruteForce(const int32_t target);

    void solveHashTable(const int32_t target);
};


#endif //ARRAYS_NBULECTURE_1D_TWOSUM_H
