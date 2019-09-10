/**
 *  @brief
 *  @date 03.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "ArraySorter.h"

void ArraySorter::printTimeElapsed()
{
    const clock_t ELAPSED_TIME = clock() - _startTime;

    std::cout << "Sorting elapsed time: " << ELAPSED_TIME << " ms. (" <<
              static_cast<double>(ELAPSED_TIME) / CLOCKS_PER_SEC <<
              " sec.)" << std::endl;
}

void ArraySorter::sort(int32_t * array, const uint64_t arraySize)
{
    //dummy check to satisfy compilers unused-param warning
    if(array && arraySize)
    {}

    _startTime = clock();
}
