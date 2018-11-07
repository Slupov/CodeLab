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

//Other libraries headers

//Own components headers

using namespace std;

void deallocate(int **& matrix, int n)
{
    for(int r = 0; r < n; ++r)
    {
        for(int c = 0; c < n; ++c)
        {
            printf("%5d ", matrix[r][c]);
        }

        delete matrix[r];
        matrix[r] = nullptr;

        printf("\n");
    }

    delete[] matrix;
    matrix = nullptr;
}

void initData(int ** & matrix, int & n)
{
    cin >> n;

    matrix = new int * [n];

    for(int row = 0; row < n; ++row)
    {
        matrix[row] = new int[n];
    }
}

void solve(int ** & matrix, int n)
{
    /**your solution code goes here**/
}

int main()
{
    int n;
    int ** matrix = nullptr;

    initData(matrix, n);
    solve(matrix, n);
    deallocate(matrix, n);

    return 0;
}
