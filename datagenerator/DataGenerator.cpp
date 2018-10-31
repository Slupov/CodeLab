/**
 *  @brief
 *  @date 31-Oct-18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "DataGenerator.h"

//C system headers

//C++ system headers
#include <cstdlib>
#include <ctime>
#include <random>

//Other libraries headers

//Own components headers

void DataGenerator::run(const uint32_t dataSize, const uint32_t maxNum)
{
    //create a seed sequence with current timestamp
    std::mt19937 gen((uint32_t) std::time(nullptr));

    for(uint32_t i = 0; i < dataSize; i++)
    {
        printf("%u ", static_cast<uint32_t>(gen() % maxNum + 1));
    }
}
