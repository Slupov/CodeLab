/**
 *  @brief
 *  @date 01-Nov-18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "OneDimensionArrayProblem.h"

//C system headers

//C++ system headers
#include <sstream>
#include <string>
#include <climits>

//Other libraries headers

//Own components headers
#include "sorting/ArraySorter.h"

#include "tools/datageneratorlib/DataGenerator.h"

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
    printf("---------------START INIT DATA---------------\n");

    printf("Enter array: ");

    std::string input;
    getline(std::cin, input);

    const uint32_t INPUT_STRING_SIZE = static_cast<const uint32_t>(input.size());

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
    else //data size still 0 but might be a single number without spaces
    {
        //!!! provided that input is always valid
        if(INPUT_STRING_SIZE >= 1)
        {
            _dataSize = 1;
        }
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

    printf("----------------END INIT DATA----------------\n");
}

void OneDimensionArrayProblem::initDataSimple()
{
    printf("---------------START INIT DATA---------------\n");

    printf("Enter cols: ");
    std::cin >> _dataSize;
    std::cin.ignore(100, '\n'); //ignore the new line cin left in the buffer

    //define array
    _data = new int32_t[_dataSize];

    //set input values into array
    int32_t num = 0;

    printf("Enter array: ");

    std::string input;
    getline(std::cin, input);

    std::istringstream iss(input);

    for(int32_t i = 0; i < _dataSize; ++i)
    {
        iss >> num;
        _data[i] = num;
    }

    printf("----------------END INIT DATA----------------\n");
}

void OneDimensionArrayProblem::solve()
{
//    initData();
//    initDataSimple();
//    initRandomData();
//    initRandomDataSorted();
}

void OneDimensionArrayProblem::printArray()
{
    for(int32_t i = 0; i < _dataSize; ++i)
    {
        printf("%d ", _data[i]);
    }

    printf("\n");
}

void OneDimensionArrayProblem::sortArray(ArraySorter * arraySorter)
{
    arraySorter->sort(_data, _dataSize);
}

void OneDimensionArrayProblem::initRandomData()
{
    printf("---------------START INIT RANDOM DATA---------------\n");

    uint32_t maxNum = 0;

    printf("Enter cols: ");
    std::cin >> _dataSize;

    printf("Enter max num: ");
    std::cin >> maxNum;

    //define array
    _data = new int32_t[_dataSize];

    DataGenerator gen;
    gen.seed();
    gen.populateArray(_data, _dataSize, maxNum);

    printf("----------------END INIT RANDOM DATA----------------\n");
}

void OneDimensionArrayProblem::initRandomDataSorted()
{
    printf("---------------START INIT RANDOM DATA SORTED---------------\n");

    uint32_t maxNum = 0;

    printf("Enter cols: ");
    std::cin >> _dataSize;

    printf("Enter max num: ");
    std::cin >> maxNum;

    //define array
    _data = new int32_t[_dataSize];

    DataGenerator gen;
    gen.seed();
    gen.populateArraySorted(_data, _dataSize, maxNum);

    printf("----------------END INIT RANDOM DATA SORTED----------------\n");
}
