/**
 *  @brief
 *  @date 01-Nov-18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <unordered_map>

//Other libraries headers

//Own components headers
#include "TwoSum.h"

void TwoSum::solve()
{
    OneDimensionArrayProblem::solve();

    std::cout << "Enter a target : ";

    int32_t target = 0;
    std::cin >> target;

    std::cout << "Brute force approach output: " << std::endl;
    solveBruteForce(target);

    std::cout << std::endl << "One-pass hash table approach output: "
                                                                   << std::endl;
    solveHashTable(target);
}

void TwoSum::solveBruteForce(const int32_t target)
{
    bool isSolutionFound = false;

    for(int32_t i = 0; i < _dataSize; i++)
    {
        for(int32_t j = i + 1; j < _dataSize; j++)
        {
            if(_data[j] == (target - _data[i]))
            {
                printf("Result : [%d, %d]\n", _data[i], _data[j]);
                isSolutionFound = true;
            }
        }
    }

    if (!isSolutionFound)
    {
        printf("No solution found...\n");
    }
}

void TwoSum::solveHashTable(const int32_t target)
{
    bool isSolutionFound = false;

    //key - complement, value - index
    std::unordered_map<int32_t, int32_t> map;

    //a number required to make the sum complete.
    int32_t complement = 0;

    for(int32_t i = 0; i < _dataSize; i++)
    {
        complement = target - _data[i];

        if(map.find(complement) != map.end())
        {
            printf("Result : [%d, %d]\n", _data[map[complement]], _data[i]);
            isSolutionFound = true;
        }

        map.insert(std::pair<int32_t, int32_t>(_data[i], i));
    }

    if (!isSolutionFound)
    {
        printf("No solution found...\n");
    }
}
