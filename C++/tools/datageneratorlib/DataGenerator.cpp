/**
 *  @brief
 *  @date 31-Oct-18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "DataGenerator.h"

//C system headers

//C++ system headers
#include <ctime>
#include <random>

//Other libraries headers

//Own components headers

void DataGenerator::run(const uint32_t dataSize, const uint32_t maxNum)
{
    if(0 == dataSize)
    {
        return;
    }

    seed();

    printf("%u", static_cast<uint32_t>(gen() % (maxNum + 1)));

    for(uint32_t i = 1; i < dataSize; i++)
    {
        printf(" %u", static_cast<uint32_t>(gen() % (maxNum + 1)));
    }

    printf("\n");
}

void DataGenerator::populateArray(int32_t * array, const uint32_t arraySize,
                                  const uint32_t maxNum)
{
    for(uint32_t i = 0; i < arraySize; i++)
    {
        array[i] = static_cast<int32_t>(gen() % (maxNum + 1));
    }
}

void DataGenerator::seed()
{
    gen.seed((uint32_t) std::time(nullptr));
}

void DataGenerator::populateArraySorted(int32_t * array,
                                        const uint32_t arraySize,
                                        const uint32_t maxNum)
{
    int32_t randNum = static_cast<int32_t>(gen() % (maxNum + 1));

    array[0] = randNum;
    for(uint32_t i = 1; i < arraySize; ++i)
    {
        randNum += static_cast<int32_t>(gen() % maxNum + 1);
        array[i] = randNum;
    }
}
