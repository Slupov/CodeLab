#ifndef ARRAYS_SORTING_ARRAYSORTER_H
#define ARRAYS_SORTING_ARRAYSORTER_H

/**
 *  @brief
 *  @date 03.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <cstdint>
#include <ctime>

//Other libraries headers

//Own components headers


class ArraySorter
{
public:
    ArraySorter() = default;

    virtual ~ArraySorter() = default;

    virtual void sort(int32_t * array, const uint64_t arraySize);

    void printTimeElapsed();

private:
    clock_t _startTime;
};


#endif //ARRAYS_SORTING_ARRAYSORTER_H
