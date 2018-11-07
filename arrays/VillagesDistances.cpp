/**
 *  @brief На хоризонталната ос са разположени N селища с координати
 *  a1< a2<… < aN. Напишете програма, която да избере едно селище, да речем
 *  i-тото така, че разликата от разстоянията от него до a1 и aN
 *  |(ai – a1)–(aN – ai)| да е минимална.
 *
 *  @date 07.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "VillagesDistances.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

void VillagesDistances::solve()
{
    OneDimensionArrayProblem::solve();
    printArray();
    solveOnePass();
}

//iterates through every single item and calculates its distance
void VillagesDistances::solveOnePass()
{
    int32_t minDifference     = INT32_MAX;
    int32_t bestIdx           = -1;
    int32_t currentDifference = 0;

    for(int32_t i = 0; i < _dataSize; ++i)
    {
        currentDifference =
                (_data[i] - _data[0]) - (_data[_dataSize - 1] - _data[i]);
        
        if (currentDifference < 0)
        {
            currentDifference *= (-1);
        }

        if (minDifference > currentDifference)
        {
            minDifference = currentDifference;
            bestIdx = i;
        }
    }

    printf("Min difference   : %d\n", minDifference);
    printf("Best village idx : %d\n", bestIdx);
}
