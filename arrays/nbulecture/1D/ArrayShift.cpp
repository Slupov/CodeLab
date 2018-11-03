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

#include "ArrayShift.h"

void ArrayShift::solve()
{
    OneDimensionArrayProblem::solve();

    printf("Enter number of rotations: ");

    int32_t shifts = 0;
    std::cin >> shifts;

//    solveCyclicReplacements(shifts);
    solveAdditionalArray(shifts);
}

void ArrayShift::solveCyclicReplacements(const int32_t shifts)
{
    int32_t actualShifts    = shifts % _dataSize;
    int32_t count           = 0;

    int32_t currentIdx;
    int32_t prevValue;
    int32_t nextIdx;
    int32_t temp;

    for(int32_t i = 0; count < _dataSize; i++)
    {
        currentIdx   = i;
        prevValue    = _data[i];

        do
        {
            nextIdx = (currentIdx + actualShifts) % _dataSize;

            //swap elements
            temp            = _data[nextIdx];
            _data[nextIdx]  = prevValue;
            prevValue       = temp;

            currentIdx = nextIdx;
            count++;
        }
        while(i != currentIdx);
    }
}

void ArrayShift::solveAdditionalArray(const int32_t shifts)
{
    //saves original state of working array
    int32_t * arrayCopy = new int32_t[_dataSize];

    for (int32_t i = 0; i < _dataSize; i++)
    {
        arrayCopy[(i + shifts) % _dataSize] = _data[i];
    }

    //copy shifted array back to the working (original) array
    for (int32_t i = 0; i < _dataSize; i++)
    {
        _data[i] = arrayCopy[i];
    }

    delete[] arrayCopy;
}
