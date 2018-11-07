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
#include <ctime>

//Other libraries headers

//Own components headers

#define RANDOM_MIN_VALUE 0
#define RANDOM_MAX_VALUE 100

using namespace std;

//-------------------START ARRAY FUNCTIONS-------------------

void inputArray(int *& outarray, int & outCols)
{
    cout << "Enter cols: ";
    cin >> outCols;

    cout << "Enter array elements: ";
    for(int col = 0; col < outCols; ++col)
    {
        cin >> outarray[col];
    }

    outarray = new int[outCols];
}

void inputArrayRandom(int *& outarray, int cols)
{
    outarray = new int[cols];
    for(int col = 0; col < cols; ++col)
    {
        outarray[col] = rand() % (RANDOM_MAX_VALUE - RANDOM_MIN_VALUE - 1) +
                RANDOM_MIN_VALUE;
    }
}

void printArray(int * array, int cols)
{
    for(int col = 0; col < cols; ++col)
    {
        cout << array[col] << " ";
    }

    cout << endl;
}

void deallocateArray(int *& array)
{
    delete[] array;
    array = nullptr;
}

//--------------------END ARRAY FUNCTIONS--------------------

//-------------------START MATRIX FUNCTIONS-------------------
void inputMatrix(int **& outMatrix, int & outRows, int & outCols)
{
    cout << "Enter rows: ";
    cin >> outRows;

    cout << "Enter cols: ";
    cin >> outCols;

    //define array of int pointers
    outMatrix = new int * [outRows];

    for(int row = 0; row < outRows; ++row)
    {
        outMatrix[row] = new int[outCols];

        cout << "Enter sub-array[" << row << "]: ";

        //each row element on new line
        for(int col = 0; col < outCols; ++col)
        {
            cin >> outMatrix[row][col];
        }
    }
}

void inputMatrixRandom(int **& outMatrix, int & outRows, int & outCols)
{
    cout << "Enter rows: ";
    cin >> outRows;

    cout << "Enter cols: ";
    cin >> outCols;

    //define array of int pointers
    outMatrix = new int * [outRows];

    for(int row = 0; row < outRows; ++row)
    {
        outMatrix[row] = new int[outCols];

        inputArrayRandom(outMatrix[row], outCols);
    }
}

void printMatrix(int ** matrix, int rows, int cols)
{
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            cout << matrix[row][col] << " ";
        }

        cout << endl;
    }
};

void deallocateMatrix(int **& matrix, int rows)
{
    for(int row = 0; row < rows; ++row)
    {
        delete[] matrix[row];
        matrix[row] = nullptr;
    }

    delete[] matrix;
    matrix = nullptr;
}

//-------------------END MATRIX FUNCTIONS-------------------

int main()
{
    //seed randomizer
    srand((unsigned) time(nullptr));

//    int * array = nullptr;
//    int arrayCols = 0;
//    cout << "Enter cols: ";
//    cin >> arrayCols;
//
//    inputArrayRandom(array,arrayCols);
//    printArray(array, arrayCols);


    int ** matrix = nullptr;
    int rows = 0;
    int cols = 0;

    inputMatrixRandom(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    deallocateMatrix(matrix, rows);

    return 0;
}
