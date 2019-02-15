/**
 *  @brief
 *  @date 26.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <unordered_set>
#include <climits>
#include <vector>

//Other libraries headers

//Own components headers

#include "UnionAddition.h"

//CHECK FOR DUPLICATES
int32_t UnionAddition::run()
{
    int32_t m;
    int32_t n;
    int32_t u;

    std::cin >> m;
    std::cin >> n;
    std::cin >> u;

    std::vector<int32_t> AB((u+1), 0);

    int32_t temp;
    for(int32_t i = 0; i < m; ++i)
    {
        std::cin >> temp;
        ++AB[temp];
    }

    for(int32_t i = 0; i < n; ++i)
    {
        std::cin >> temp;
        ++AB[temp];
    }

    bool hasSolution = false;
    for(int32_t i = 1; i <= u; ++i)
    {
        //found missing
        if(AB[i] == 0)
        {
            hasSolution = true;
            std::cout << i << " ";
        }
    }

    if(!hasSolution)
    {
        std::cout << "Empty";
    }

    return EXIT_SUCCESS;
}

void UnionAddition::run2()
{
    int n, m, u;

    std::cin >> n >> m >> u;
    std::vector<int> a((u + 1), 0);

    bool empty = true;
    for(int j = 1; j <= u; ++j)
    {
        if(a[j] == 0)
        {
            empty = false;
            std::cout << j << " ";
        }
    }
    if(empty)
    {
        std::cout << "Empty";
    }
}
