/**
 *  @brief
 *  @date 18.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "SumOfSubarrayMinimums.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers

void SumOfSubarrayMinimums::initData()
{
    //clear working array
    _workingArray.clear();
    uint64_t newSize = 0;

    std::cout << "Enter working array size: ";
    std::cin >> newSize;

    _workingArray.resize(newSize);
    std::cout << "Enter working array with elements separated by a space: ";

    uint64_t x;
    for(uint32_t i = 0; i < newSize; ++i)
    {
        std::cin >> x;
        _workingArray[i] = x;
    }
}

void SumOfSubarrayMinimums::solve()
{
    initData();

    std::vector<uint64_t> & A = _workingArray;
    const uint64_t A_SIZE = A.size();

    std::vector<int32_t> smallerIndexes{-1};

    //sums[i] stores sums of minimums of the subarrays A[0..i, i]
    std::vector<int32_t> sums(A_SIZE, 0);

    int32_t numberOfSubarraysWhereSmallest;

    //for each index i we count minimums of all the subarrays A[0..i, i] and
    //calculate their sum.
    for(uint32_t i = 0; i < A_SIZE; i++)
    {
        //if element on the last of the smaller indexes is bigger than the
        //current element remove its index
        while(smallerIndexes.size() > 1 && A[smallerIndexes.back()] > A[i])
        {
            //remove last element
            smallerIndexes.pop_back();
        }

        //the number of subarrays where the current element is the smallest
        numberOfSubarraysWhereSmallest = i - smallerIndexes.back();
        sums[i] = static_cast<int32_t>(A[i] * numberOfSubarraysWhereSmallest);

        //if there's still smaller indexes, add their sum to the current sum
        if(smallerIndexes.size() > 1)
        {
            sums[i] += sums[smallerIndexes.back()];
        }

        smallerIndexes.push_back(i);
    }

    //calculate end result
    int32_t result = 0;

    for(const int32_t n: sums)
    {
        result = (result + n) % (1000000000 + 7);
    }

//    return result;
    printf("%d", result);
}
