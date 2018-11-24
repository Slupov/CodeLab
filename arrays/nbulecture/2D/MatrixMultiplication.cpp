/**
 *  @brief
 *  @date 03.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "MatrixMultiplication.h"

//C system headers

//C++ system headers
#include <sstream>

//Other libraries headers

//Own components headers
#include "tools/datageneratorlib/DataGenerator.h"

#define MATRIX_MAX_NUM 100

MatrixMultiplication::MatrixMultiplication() : _matrixA(nullptr),
                                               _matrixARows(0),
                                               _matrixACols(0),
                                               _matrixB(nullptr),
                                               _matrixBRows(0),
                                               _matrixBCols(0)
{

}

MatrixMultiplication::~MatrixMultiplication()
{
    for(int32_t i = 0; i < _matrixARows; ++i)
    {
        delete[] _matrixA[i];
        _matrixA[i] = nullptr;
    }

    delete[] _matrixA;
    _matrixA = nullptr;

    for(int32_t i = 0; i < _matrixBRows; ++i)
    {
        delete[] _matrixB[i];
        _matrixB[i] = nullptr;
    }

    delete[] _matrixB;
    _matrixB = nullptr;
}

void MatrixMultiplication::solve()
{
//    initDataForProblem();
    initRandomDataForProblem();

    //calculate values for result matrix
    for(int32_t row = 0; row < _matrixARows; ++row)
    {
        for(int32_t col = 0; col < _matrixBCols; ++col)
        {
            _data[row][col] = getCellValue(row, col);
        }
    }

    printSolution();
}

int32_t MatrixMultiplication::getCellValue(const int32_t rowIdx,
                                           const int32_t colIdx)
{
    int32_t sum = 0;

    for(int32_t i = 0; i < _matrixACols; ++i)
    {
        sum += _matrixA[rowIdx][i] * _matrixB[i][colIdx];
    }

    return sum;
}

void MatrixMultiplication::initDataForProblem()
{
    printf("---------------START INIT DATA---------------\n");

    printf("Enter matrixA rows: ");
    std::cin >> _matrixARows;

    printf("Enter matrixA cols: ");
    std::cin >> _matrixACols;

    printf("Enter matrixB rows: ");
    std::cin >> _matrixBRows;

    printf("Enter matrixB cols: ");
    std::cin >> _matrixBCols;
    std::cin.ignore(100, '\n'); //ignore the new line cin left in the buffer

    //check if input is valid
    if(_matrixBRows > _matrixARows || _matrixACols > _matrixBCols)
    {
        printf("ILLEGAL MATRIX MULTIPLICATION\n");
        return;
        throw;
    }

    //define matrixA & matrixB
    _matrixA = new int32_t * [_matrixARows];
    _matrixB = new int32_t * [_matrixBRows];

    //define result matrix
    _data      = new int32_t * [_matrixARows];
    _dataSizes = new int32_t[_matrixARows];

    for(int32_t row             = 0; row < _matrixARows; ++row)
    {
        _dataSizes[row] = _matrixBCols;
        _data[row]      = new int32_t[_matrixBCols];
    }

    //read matrixA
    std::string        input;
    std::istringstream iss;
    int32_t            inputNum = 0;

    for(int32_t row = 0; row < _matrixARows; ++row)
    {
        _matrixA[row] = new int32_t[_matrixACols];

        getline(std::cin, input);
        iss.str(input);

        //get the size of the sub-array (count the number of spaces in the input)
        for(int32_t col = 0; col < _matrixACols; ++col)
        {
            iss >> inputNum;
            _data[row][col] = inputNum;
        }
    }

    //read matrixB
    for(int32_t row = 0; row < _matrixBRows; ++row)
    {
        _matrixB[row] = new int32_t[_matrixBCols];

        getline(std::cin, input);
        iss.str(input);

        //get the size of the sub-array (count the number of spaces in the input)
        for(int32_t col = 0; col < _matrixBCols; ++col)
        {
            iss >> inputNum;
            _data[row][col] = inputNum;
        }
    }

    printf("----------------END INIT DATA----------------\n");
}

void MatrixMultiplication::initRandomDataForProblem()
{
    printf("---------------START INIT DATA---------------\n");

    printf("Enter matrixA rows: ");
    std::cin >> _matrixARows;

    printf("Enter matrixA cols: ");
    std::cin >> _matrixACols;

    printf("Enter matrixB rows: ");
    std::cin >> _matrixBRows;

    printf("Enter matrixB cols: ");
    std::cin >> _matrixBCols;
    std::cin.ignore(100, '\n'); //ignore the new line cin left in the buffer

    //check if input is valid
    if(_matrixBRows > _matrixARows || _matrixACols > _matrixBCols)
    {
        printf("ILLEGAL MATRIX MULTIPLICATION\n");
        throw;
    }

    //define matrixA & matrixB
    _matrixA = new int32_t * [_matrixARows];
    _matrixB = new int32_t * [_matrixBRows];

    //define result matrix
    _data      = new int32_t * [_matrixARows];
    _dataSizes = new int32_t[_matrixARows];

    for(int32_t row = 0; row < _matrixARows; ++row)
    {
        _dataSizes[row] = _matrixBCols;
        _data[row]      = new int32_t[_matrixBCols];
    }

    DataGenerator gen;
    gen.seed();

    //read matrixA
    for(int32_t row = 0; row < _matrixARows; ++row)
    {
        _matrixA[row] = new int32_t[_matrixACols];
        gen.populateArray(_matrixA[row], _matrixACols, MATRIX_MAX_NUM);
    }

    //read matrixB
    for(int32_t row = 0; row < _matrixBRows; ++row)
    {
        _matrixB[row] = new int32_t[_matrixBCols];
        gen.populateArray(_matrixB[row], _matrixBCols, MATRIX_MAX_NUM);
    }

    printf("----------------END INIT DATA----------------\n");
}


void MatrixMultiplication::printSolution()
{
    //matrixA X matrixB = data

    for(int32_t i = 0; i < _matrixARows; ++i)
    {
        if(i == _matrixARows / 2)
        {
            printf("%-25sX%25s  =  %-25s",
                   getMatrixRowAsString(_matrixA, i, _matrixACols).c_str(),
                   i < _matrixBRows ?
                   getMatrixRowAsString(_matrixB, i, _matrixBCols).c_str() :
                   "",
                   getMatrixRowAsString(_data, i, _matrixBCols).c_str());
        }
        else
        {
            printf("%-25s %25s     %-25s",
                   getMatrixRowAsString(_matrixA, i, _matrixACols).c_str(),
                   i < _matrixBRows ?
                   getMatrixRowAsString(_matrixB, i, _matrixBCols).c_str() :
                   "",
                   getMatrixRowAsString(_data, i, _matrixBCols).c_str());
        }

        printf("\n");
    }
}

std::string MatrixMultiplication::getMatrixRowAsString(int32_t ** matrix,
                                                       const int32_t rowIdx,
                                                       const int32_t rowSize)
{
    std::string str;
    for(int32_t i = 0; i < rowSize; ++i)
    {
        str.append(std::to_string(matrix[rowIdx][i]));
        str.append(" ");
    }

    return str;
}