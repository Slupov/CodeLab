/**
 *  @brief
 *  @date 24.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "MinK.h"

//C system headers

//C++ system headers
#include <vector>
#include <algorithm>

//Other libraries headers

//Own components headers

int32_t MinK::run()
{
    int32_t n;
    int32_t k;

    std::cin >> n;
    std::cin >> k;

    std::vector<int32_t> v;
    v.reserve(n);

    int32_t temp;
    for(int32_t i = 0; i < n; ++i)
    {
        std::cin >> temp;
        v.emplace_back(temp);
    }

    std::sort(v.begin(), v.end());
    std::cout << v[k-1];

    return EXIT_SUCCESS;
}
