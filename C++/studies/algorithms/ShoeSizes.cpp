/**
 *  @brief
 *  @date 24.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <unordered_map>
#include <algorithm>
#include <vector>

//Other libraries headers

//Own components headers
#include "ShoeSizes.h"

int32_t ShoeSizes::run()
{
    int32_t n = 0;
    std::cin >> n;

    std::unordered_map<int32_t, int32_t> shoes;

    int32_t temp;
    for(int32_t i = 0; i < n; ++i)
    {
        std::cin >> temp;

        if(shoes.find(temp) != shoes.end())
        {
            //found so we increment count
            ++shoes[temp];
        }
        else
        {
            shoes.insert(std::pair<int32_t, int32_t>(temp, 1));
        }
    }

    std::vector<std::pair<int32_t, int32_t>> shoesV(shoes.begin(), shoes.end());

    //sort map using custom comparator
    auto cmp = [](std::pair<int32_t ,int32_t> const & a,
                                    std::pair<int32_t ,int32_t > const & b)
    {
        return a.second != b.second ? a.second > b.second : a.first < b.first;
    };

    std::sort(shoesV.begin(), shoesV.end(), cmp);

    std::vector<std::pair<int32_t, int32_t>>::iterator it = shoesV.begin();
    while(it != shoesV.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        ++it;
    }

    return EXIT_SUCCESS;
}
