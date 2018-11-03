#ifndef ARRAYS_SORTING_BUBBLESORT_H
#define ARRAYS_SORTING_BUBBLESORT_H

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

#include "ArraySorter.h"

class BubbleSort : public ArraySorter
{
public:
    BubbleSort() = default;

    virtual ~BubbleSort() = default;

    virtual void sort(int32_t * array, const uint64_t arraySize) override;
};


#endif //ARRAYS_SORTING_BUBBLESORT_H
