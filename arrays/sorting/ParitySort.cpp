/**
 *  @brief
 *  @date 06.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "ParitySort.h"

void ParitySort::sort(int32_t * array, const uint64_t arraySize)
{
    ArraySorter::sort(array, arraySize);

    int32_t evenIdx = 0;
    int32_t oddIdx = arraySize - 1;

    while (evenIdx < oddIdx)
    {
        //both in wrong places
        if (array[evenIdx] % 2 > array[oddIdx] % 2)
        {
            //swap
            int32_t temp = array[evenIdx];
            array[evenIdx] = array[oddIdx];
            array[oddIdx] = temp;
        }

        if (array[evenIdx] % 2 == 0) evenIdx++;
        if (array[oddIdx] % 2 == 1) oddIdx--;
    }

}
