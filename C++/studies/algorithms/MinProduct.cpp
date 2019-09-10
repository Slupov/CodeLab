/**
 *  @brief
 *  @date 26.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <vector>
#include <climits>
#include <algorithm>

//Other libraries headers

//Own components headers

#include "MinProduct.h"

//-60 -50 -40 -30 -20 -10 5
int32_t MinProduct::run()
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

    std::sort(v.begin(), v.end());

    int32_t minProduct = 0;

    //check if first and last are both negative
    if(v[0] <= 0 && v[n - 1] <= 0)
    {
        minProduct = v[n - 1] * v[n - 2];
    }
    //check if first and last are both positive
    else if(v[0] >= 0 && v[n - 1] >= 0)
    {
        minProduct = v[0] * v[1];
    }
    //check if first and last are different
    else
    {
        minProduct = v[0] * v[n - 1];
    }

    std::cout << minProduct;

    return EXIT_SUCCESS;
}

void MinProduct::run2()
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

    std::sort(v.begin(), v.end());

    int32_t minProduct = 0;

    minProduct = v[0] * v[n - 1];

    std::cout << minProduct;
}

void MinProduct::run3()
{
    int n;
    std::cin >> n;
    std::vector<int> a;

    //input
    int c;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> c;
        a.push_back(c);
    }

    //sort
    sort(a.begin(), a.end());

    if(a.size() == 1)
    {
        std::cout << a[0];
    }
    else
    {
        if(a.front() >= 0)
        {
            if(a.size() >= 2)
            {
                std::cout << a[0] * a[1];
            }
        }
        else if(a.front() < 0 && a.back() >= 0)
        {
            if(a.size() >= 2)
            {
                std::cout << a.front() * a.back();
            }
        }
        else if(a.front() < 0 && a.back() < 0)
        {
            if(a.size() >= 2)
            {
                std::cout << a[a.size() - 2] * a.back();
            }
        }
    }
}