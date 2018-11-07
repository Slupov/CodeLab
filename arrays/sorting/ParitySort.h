#ifndef ARRAYS_SORTING_PARITYSORT_H
#define ARRAYS_SORTING_PARITYSORT_H

/**
 *  @brief
 *  @url https://leetcode.com/problems/sort-array-by-parity/description/
 *  @date 06.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "ArraySorter.h"

class ParitySort : public ArraySorter
{
public:
    virtual void sort(int32_t * array, const uint64_t arraySize) override;
};


#endif //DUMMY_TEST_PARITYSORT_H
