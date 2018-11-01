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

    solveBruteForce(target);
    solveHashTable(target);
}

void TwoSum::solveBruteForce(const int32_t target)
{
    for(int32_t i = 0; i < _dataSize; i++)
    {
        for(int32_t j = i + 1; j < _dataSize; j++)
        {
            if(_data[j] == (target - _data[i]))
            {
                printf("Result : [%d, %d]\n", _data[i], _data[j]);
            }
        }
    }
}

void TwoSum::solveHashTable(const int32_t target)
{
    std::unordered_map<int32_t, int32_t> map;
    int32_t complement = 0;

    for(int32_t i = 0; i < _dataSize; i++)
    {
        complement = target - _data[i];

        if(map.find(complement) != map.end())
        {
            //TODO FIND ERROR
            //found
            printf("Result : [%d, %d]\n", _data[map[i]], _data[i]);
        }

        map.insert(std::pair<int32_t, int32_t>(_data[i], i));
    }
}
