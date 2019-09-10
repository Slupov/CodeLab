/**
 *  @brief
 *  @date 03.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "BubbleSort.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

void BubbleSort::sort(int32_t * array, const uint64_t arraySize)
{
    ArraySorter::sort(array, arraySize);

    int32_t temp = 0;

    for(uint64_t end = arraySize - 1; end > 0; --end)
    {
        for(uint64_t i = 0; i < end; ++i)
        {
            //perform a swap
            if(array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }

    printTimeElapsed();
}