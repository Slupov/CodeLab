/**
 *  @brief
 *  @date 03-Nov-18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "TwoDimensionArrayProblem.h"

//C system headers

//C++ system headers
#include <sstream>
#include <string>
#include <climits>

//Other libraries headers

//Own components headers
#include "sorting/ArraySorter.h"

#include "tools/datageneratorlib/DataGenerator.h"

#define MATRIX_MAX_NUM 100

TwoDimensionArrayProblem::TwoDimensionArrayProblem() : _data(nullptr),
                                                       _dataSizes(nullptr)
{
}

TwoDimensionArrayProblem::~TwoDimensionArrayProblem()
{
    //Free each sub-array
    for(int32_t r = 0; r < _rows; ++r)
    {

        delete[] _data[r];
        _data[r] = nullptr;
    }

    //Free the array of pointers
    delete[] _data;
    _data = nullptr;

    delete _dataSizes;
    _dataSizes = nullptr;

}

void TwoDimensionArrayProblem::initData()
{
    printf("---------------START INIT DATA---------------\n");

    printf("Enter Rows: ");
    std::cin >> _rows;
    std::cin.ignore(100, '\n'); //ignore the new line cin left in the buffer

    _data                       = new int32_t * [_rows];
    _dataSizes                  = new int32_t[_rows];

    std::string input;
    uint64_t    inputStringSize = 0;
    int32_t     inputNum        = 0;

    for(int32_t r = 0; r < _rows; ++r)
    {
        printf("Enter sub-array[%d]: ", r);

        //read whole input line into input string
        getline(std::cin, input);
        inputStringSize = input.size();

        std::istringstream iss(input);

        _dataSizes[r] = 0;

        //get the size of the sub-array (count the number of spaces in the input)
        for(uint32_t i = 0; i < inputStringSize; ++i)
        {
            if(input[i] == ' ')
            {
                ++_dataSizes[r];
            }
        }

        //last item is not followed by a comma so increment count
        if(_dataSizes[r] != 0)
        {
            ++_dataSizes[r];
        }
        else //data size still 0 but might be a single number without spaces
        {
            //!!! provided that input is always valid
            if (inputStringSize >= 1)
            {
                _dataSizes[r] = 1;
            }
        }

        //define array
        _data[r] = new int32_t[_dataSizes[r]];

        //set input values into array
        inputNum = 0;

        for(int32_t i = 0; i < _dataSizes[r]; ++i)
        {
            iss >> inputNum;
            _data[r][i] = inputNum;
        }
    }

    printf("----------------END INIT DATA----------------\n");
}

void TwoDimensionArrayProblem::initDataSimple()
{
    printf("---------------START INIT DATA---------------\n");

    int32_t cols = 0;

    printf("Enter row_cells: ");
    std::cin >> _rows;

    printf("Enter cols: ");
    std::cin >> cols;
    std::cin.ignore(100, '\n'); //ignore the new line cin left in the buffer

    _data                = new int32_t * [_rows];
    _dataSizes           = new int32_t[_rows];

    std::string input;
    int32_t     inputNum = 0;

    for(int32_t row = 0; row < _rows; ++row)
    {
        _dataSizes[row] = cols;
        _data[row]      = new int32_t[cols];

        printf("Enter sub-array[%d]:", row);

        getline(std::cin, input);
        std::istringstream iss(input);

        //get the size of the sub-array (count the number of spaces in the input)
        for(int32_t i = 0; i < cols; ++i)
        {
            iss >> inputNum;
            _data[row][i] = inputNum;
        }
    }

    printf("----------------END INIT DATA----------------\n");
}

void TwoDimensionArrayProblem::solve()
{
//    initData();
//    initDataSimple();
      initRandomData();
}

void TwoDimensionArrayProblem::printArray()
{
    for(int32_t r = 0; r < _rows; ++r)
    {
        for(int32_t i = 0; i < _dataSizes[r]; ++i)
        {
            printf("%5d ", _data[r][i]);
        }

        printf("\n");
    }
}

void TwoDimensionArrayProblem::sortArray(ArraySorter * arraySorter)
{
    for(int32_t r = 0; r < _rows; ++r)
    {
        arraySorter->sort(_data[r], _dataSizes[r]);
    }
}

void TwoDimensionArrayProblem::initRandomData()
{
    printf("---------------START INIT RANDOM DATA---------------\n");

    int32_t rows = 0;
    int32_t cols = 0;

    printf("Enter row_cells: ");
    std::cin >> rows;
    _rows = rows;

    printf("Enter cols: ");
    std::cin >> cols;
    std::cin.ignore(100, '\n'); //ignore the new line cin left in the buffer

    //define array
    _data      = new int32_t * [_rows];
    _dataSizes = new int32_t[_rows];

    DataGenerator gen;
    gen.seed();

    for(int32_t i = 0; i < _rows; ++i)
    {
        _data[i] = new int32_t[cols];
        _dataSizes[i] = cols;

        gen.populateArray(_data[i], cols, MATRIX_MAX_NUM);
    }

    printf("----------------END INIT RANDOM DATA----------------\n");
}

void TwoDimensionArrayProblem::initRandomDataSorted()
{
    printf("---------------START INIT RANDOM DATA SORTED---------------\n");

    int32_t rows = 0;
    int32_t cols = 0;

    printf("Enter row_cells: ");
    std::cin >> rows;
    _rows = rows;

    printf("Enter cols: ");
    std::cin >> cols;
    std::cin.ignore(100, '\n'); //ignore the new line cin left in the buffer

    //define array
    _data      = new int32_t * [_rows];
    _dataSizes = new int32_t[_rows];

    DataGenerator gen;
    gen.seed();

    for(int32_t i = 0; i < _rows; ++i)
    {
        _data[i] = new int32_t[cols];
        _dataSizes[i] = cols;

        gen.populateArraySorted(_data[i], cols, MATRIX_MAX_NUM);
    }

    printf("----------------END INIT RANDOM DATA SORTED----------------\n");
}
