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
void ContainerWithMostWater::initData()
{
    std::string input;
    getline(std::cin, input);

    const uint32_t INPUT_STRING_SIZE = input.size();

    std::istringstream iss(input);

    _dataSize = 0;

    //get the size of the array (count the number of commas in the input)
    for (uint32_t i = 0; i < INPUT_STRING_SIZE; ++i)
    {
        if (input[i] == ' ') _dataSize++;
    }

    //last item is not followed by a comma so increment count
    if (_dataSize != 0)
    {
        ++_dataSize;
    }

    //define array
    _data = new uint32_t[_dataSize];

    //set input values into array
    int32_t num = 0;

    for(uint32_t i = 0; i < _dataSize; ++i)
    {
        iss >> num;
        _data[i] = num;
    }
}

void ContainerWithMostWater::solve()
{
    initData();

    std::cout << "Result: " << solveBruteForce() << std::endl;
    std::cout << "Result: " << solveTwoPointers() << std::endl;

    //free up dynamically allocated memory
    delete[] _data;
}

uint32_t ContainerWithMostWater::solveBruteForce()
{
    uint32_t maxArea = 0;
    uint32_t currentArea = UINT32_MAX;

    uint32_t areaHeight = 0;

    for (uint32_t i = 0; i < _dataSize; ++i)
    {
        for (uint32_t j = i + 1; j < _dataSize; ++j)
        {
            areaHeight = _data[i] < _data[j] ? _data[i] : _data[j];
            currentArea = areaHeight * (j - i);

            if (maxArea < currentArea) maxArea = currentArea;
        }
    }

    return maxArea;
}

uint32_t ContainerWithMostWater::solveTwoPointers()
{
    uint32_t maxArea = 0;
    uint32_t currentArea = UINT32_MAX;

    //store the left and right index positions of the range
    uint32_t left  = 0;
    uint32_t right = _dataSize - 1;

    uint32_t areaHeight = 0;

    while (left < right)
    {
        areaHeight  = _data[left] < _data[right] ? _data[left] : _data[right];
        currentArea = areaHeight * (right - left);

        if (maxArea < currentArea) maxArea = currentArea;

        if (_data[left] < _data[right])
            ++left;
        else
            --right;
    }

    return maxArea;
}