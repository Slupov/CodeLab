/**
 *  @brief
 *  @date   ${Current_day}
 *  @author ${Faculty_number}
 */

//Corresponding header

//C system headers

//C++ system headers
#include <iostream>
#include <cstdio>
#include <sstream>

//Other libraries headers

//Own components headers

#define UNPOPULATED_CELL INT32_MIN

using namespace std;

void deallocateMemory(int **& matrix, int rows)
{
    for(int r = 0; r < rows; ++r)
    {
        delete matrix[r];
        matrix[r] = nullptr;
    }

    delete[] matrix;
    matrix = nullptr;
}

void initData(int ** & matrix, int & rows, int & cols)
{
    cin >> rows;
    cin >> cols;
    std::cin.ignore(100, '\n'); //ignore the new line cin left in the buffer

    matrix = new int * [rows];

    std::string input;
    int32_t     inputNum = 0;

    for(int row = 0; row < rows; ++row)
    {
        matrix[row] = new int[cols];

        getline(std::cin, input);
        std::istringstream iss(input);

        //get the size of the sub-array (count the number of spaces in the input)
        for(int32_t col = 0; col < cols; ++col)
        {
            iss >> inputNum;
            matrix[row][col] = inputNum;
        }
    }
}

void solve(int ** & matrix, int rows, int cols)
{
    /**your solution code goes here**/
    if (matrix && rows && cols)
    {

    }
}

int main()
{
    int rows, cols;
    int ** matrix = nullptr;

    initData(matrix, rows, cols);
    solve(matrix, rows, cols);
    deallocateMemory(matrix, rows);

    return 0;
}
