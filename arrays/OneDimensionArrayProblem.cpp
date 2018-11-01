/**
 *  @brief
 *  @date 01-Nov-18
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

#include "OneDimensionArrayProblem.h"

OneDimensionArrayProblem::OneDimensionArrayProblem() : _data(nullptr),
                                                       _dataSize(0)
{}

OneDimensionArrayProblem::~OneDimensionArrayProblem()
{
    //free up dynamically allocated memory
    delete[] _data;
    _data = nullptr;

    _dataSize = 0;
}


void OneDimensionArrayProblem::initData()
{
    std::string input;
    getline(std::cin, input);

    const uint32_t INPUT_STRING_SIZE = input.size();

    std::istringstream iss(input);

    _dataSize = 0;

    //get the size of the array (count the number of commas in the input)
    for(uint32_t i = 0; i < INPUT_STRING_SIZE; ++i)
    {
        if(input[i] == ' ')
        {
            ++_dataSize;
        }
    }

    //last item is not followed by a comma so increment count
    if(_dataSize != 0)
    {
        ++_dataSize;
    }

    //define array
    _data = new int32_t[_dataSize];

    //set input values into array
    int32_t num = 0;

    for(int32_t i = 0; i < _dataSize; ++i)
    {
        iss >> num;
        _data[i] = num;
    }
}

void OneDimensionArrayProblem::solve()
{
    initData();
}