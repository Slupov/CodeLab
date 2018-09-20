#ifndef CODELAB_ARRAYPROBLEMS_H
#define CODELAB_ARRAYPROBLEMS_H

/**
 *  @brief
 *  @date 18.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>

//Other libraries headers

//Own components headers
#include "arrays/ArrayProblem.h"

class SumOfSubarrayMinimums : public ArrayProblem
{
    public:
        void initData();

        /**
         * @brief Given an array of integers A, find the sum of min(B), where B
         * ranges over every (contiguous) subarray of A. Since the answer may be
         * large, return the answer modulo 10^9 + 7.
         *
         * @url https://leetcode.com/problems/sum-of-subarray-minimums/description
         * **/
        virtual void solve() override;

    private:
        std::vector<uint64_t> _workingArray;
};


#endif //CODELAB_ARRAYPROBLEMS_H
