/**
 *  @brief
 *  @date 26.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <vector>
#include <algorithm>

//Other libraries headers

//Own components headers
#include "StrangeSort.h"

int32_t StrangeSort::run()
{
    int32_t n;
    std::cin >> n;

    std::vector<int32_t> v;
    v.reserve(n);

    int32_t temp;
    for(int32_t i = 0; i < n; ++i)
    {
        std::cin >> temp;
        v.emplace_back(temp);
    }

    //sort map using custom comparator
    auto cmp = [](int32_t const & a, int32_t const & b)
    {
        bool isAEven = a % 2;
        bool isBEven = b % 2;

        //different parity
        if(isAEven != isBEven)
        {
            return isAEven < isBEven;
        }
        else //equal parity
        {
            //both are even
            if (isAEven)
            {
                return a > b;
            }
            else //both are odd
            {
                return a < b;
            }
        }
    };

    std::sort(v.begin(), v.end(), cmp);

    for(int32_t i = 0; i < n; ++i)
    {
        std::cout << v[i] << " ";
    }

    return EXIT_SUCCESS;
}
