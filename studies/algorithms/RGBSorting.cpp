/**
 *  @brief
 *  @date 24.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "RGBSorting.h"

//C system headers

//C++ system headers
#include <unordered_map>
#include <vector>
#include <algorithm>

//Other libraries headers

//Own components headers

void RGBSorting::run()
{
    std::unordered_map<int32_t, char> colorPriority
    {
        std::pair<int32_t, char>('R', 0),
        std::pair<int32_t, char>('G', 1),
        std::pair<int32_t, char>('B', 2)
    };

    int32_t n = 0;
    std::cin >> n;

    //color count, color priority
    std::vector<std::pair<int32_t, int32_t>> rgbs;
    rgbs.reserve(n);

    int32_t temp;
    char tempChar;
    for(int32_t i = 0; i < n; ++i)
    {
        std::cin >> temp;
        std::cin >> tempChar;

        rgbs.emplace_back(
                std::pair<int32_t, char>(temp, colorPriority[tempChar]));
    }

    //sort map using custom comparator
    auto cmp = [](std::pair<int32_t, char> const & a,
                  std::pair<int32_t, char> const & b)
    {
        //different colors
        if(a.second != b.second)
        {
            return a.second < b.second;
        }
        else //same colors
        {
            //compare by key
            return a.first < b.first;
        }
    };

    std::sort(rgbs.begin(), rgbs.end(), cmp);
    std::vector<std::pair<int32_t, int32_t>>::iterator it = rgbs.begin();
    while(it != rgbs.end())
    {
        std::cout << it->first << " ";

        if(0 == it->second)
        {
            std::cout << "R";
        }
        else if(1 == it->second)
        {
            std::cout << "G";
        }
        else if(2 == it->second)
        {
            std::cout << "B";
        }

        std::cout << std::endl;
        ++it;
    }
}
