/*
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

using namespace std;

void deallocateMemory(int * & array)
{
    delete[] array;
    array = nullptr;
}

void initData(int * & array, int & n)
{
    std::string input;
    getline(std::cin, input);

    const uint32_t INPUT_STRING_SIZE = static_cast<const uint32_t>(input.size());

    std::istringstream iss(input);
    n = 0;

    //get the size of the array (count the number of commas in the input)
    for(uint32_t i = 0; i < INPUT_STRING_SIZE; ++i)
    {
        if(input[i] == ' ')
        {
            ++n;
        }
    }

    //last item is not followed by a comma so increment count
    if(n != 0)
    {
        ++n;
    }
    else //data size still 0 but might be a single number without spaces
    {
        if (INPUT_STRING_SIZE >= 1)
        {
            n = 1;
        }
    }

    //define array
    array = new int32_t[n];

    //set input values into array
    int32_t num = 0;

    for(int32_t i = 0; i < n; ++i)
    {
        iss >> num;
        array[i] = num;
    }
}

void solve(int * & array, int n)
{
    /**your solution code goes here**/
    if (array && n)
    {
         
    }

    /*print output*/
    //change this condition to true to print "true" or false to print "false"
    //hint: assign outputCondition to some boolean expression
    bool outputCondition = true;
    printf("%s", outputCondition ? "true" : "false");
}

int main()
{
    int n;
    int * array = nullptr;

    initData(array, n);
    solve(array, n);
    deallocateMemory(array);

    return 0;
}
