/**
 *  @brief
 *  @date 30-Oct-18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <sstream>
#include <string>
#include <climits>

//Other libraries headers

//Own components headers
#include "ContainerWithMostWater.h"

//Tests
//1 8 6 2 5 4 8 3 7

void ContainerWithMostWater::solve()
{
    OneDimensionArrayProblem::solve();

    std::cout << "Brute force approach output: " << solveBruteForce()
              << std::endl;

    std::cout << "Two pointers approach output: " << solveTwoPointers()
              << std::endl;
}

uint32_t ContainerWithMostWater::solveBruteForce()
{
    int32_t maxArea     = 0;
    int32_t currentArea = UINT32_MAX;

    int32_t areaHeight = 0;

    for(int32_t i = 0; i < _dataSize; ++i)
    {
        for(int32_t j = i + 1; j < _dataSize; ++j)
        {
            areaHeight  = _data[i] < _data[j] ? _data[i] : _data[j];
            currentArea = areaHeight * (j - i);

            if(maxArea < currentArea)
            { maxArea = currentArea; }
        }
    }

    return maxArea;
}

uint32_t ContainerWithMostWater::solveTwoPointers()
{
    int32_t maxArea     = 0;
    int32_t currentArea = UINT32_MAX;

    //store the left and right index positions of the range
    int32_t left  = 0;
    int32_t right = _dataSize - 1;

    int32_t areaHeight = 0;

    while(left < right)
    {
        areaHeight  = _data[left] < _data[right] ? _data[left] : _data[right];
        currentArea = areaHeight * (right - left);

        if(maxArea < currentArea)
        { maxArea = currentArea; }

        if(_data[left] < _data[right])
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    return maxArea;
}