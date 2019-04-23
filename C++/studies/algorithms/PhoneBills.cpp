/**
 *  @brief
 *  @date 24.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "PhoneBills.h"

//C system headers

//C++ system headers
#include <set>
#include <vector>
#include <iomanip>
#include <algorithm>

//Other libraries headers

//Own components headers

int32_t PhoneBills::run()
{
    runVector();

    return EXIT_SUCCESS;
}

void PhoneBills::runMultiset()
{
    //read n and m
    int32_t m;
    int32_t n;

    std::cin >> m;
    std::cin >> n;

    std::multiset<double> leftToPay;

    double      temp = 0;
    for(int32_t i    = 0; i < m; ++i)
    {
        std::cin >> temp;
        leftToPay.insert(temp);
    }

    std::multiset<double>::iterator it;

    for(int32_t i = 0; i < n; ++i)
    {
        std::cin >> temp;
        it = leftToPay.find(temp);

        it != leftToPay.end() ? leftToPay.erase(it) : leftToPay.insert(temp);
    }

    it = leftToPay.begin();

    while(it != leftToPay.end())
    {
        std::cout << std::fixed << std::setprecision(2) << * it << " ";
        ++it;
    }
}

/**
 * @param v - sorted vector instance
 * @param data - value to search
 * @return 0-based index if data found, -1 otherwise
*/
int32_t binary_search_find_index(std::vector<double> & v, double data)
{
    auto it = std::lower_bound(v.begin(), v.end(), data);
    if(it == v.end() || * it != data)
    {
        return -1;
    }
    else
    {
        std::size_t index = std::distance(v.begin(), it);
        return index;
    }
}

void PhoneBills::runVector()
{
    //read n and m
    int32_t m;
    int32_t n;

    std::cin >> m;
    std::cin >> n;

    std::vector<double> leftToPay;
    leftToPay.reserve(static_cast<uint64_t>(m));

    double      temp = 0;
    for(int32_t i    = 0; i < m; ++i)
    {
        std::cin >> temp;
        leftToPay.emplace_back(temp);
    }

    std::sort(leftToPay.begin(), leftToPay.end());
    int32_t binarySearchIndexResult = -1;

    for(int32_t i = 0; i < n; ++i)
    {
        std::cin >> temp;
        binarySearchIndexResult = binary_search_find_index(leftToPay, temp);

        if(-1 != binarySearchIndexResult)
        {
            leftToPay.erase(leftToPay.begin() + binarySearchIndexResult);
        }
    }

    for(double num : leftToPay)
    {
        std::cout << std::fixed << std::setprecision(2) << num << " ";
    }
}