#ifndef DATAGENERATOR_DATAGENERATOR_H
#define DATAGENERATOR_DATAGENERATOR_H



/**
 *  @brief
 *  @date 31-Oct-18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <cstdint>
#include <random>

//Other libraries headers

//Own components headers

class DataGenerator
{
public:
    void seed();

    void run(const uint32_t dataSize, const uint32_t maxNum);

    void populateArray(int32_t * array, const uint32_t arraySize,
                       const uint32_t maxNum);

private:
    std::mt19937 gen;
};


#endif //DATAGENERATOR_DATAGENERATOR_H
