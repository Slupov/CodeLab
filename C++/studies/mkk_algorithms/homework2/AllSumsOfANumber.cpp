/**
 *  @brief
 *  @date 19.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "AllSumsOfANumber.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

int32_t AllSumsOfANumber::run()
{
    int32_t err = EXIT_SUCCESS;

    int32_t n;
    std::cin >> n;

    //stores answers (addends)
    int32_t * a = new int32_t[n];

    for(uint32_t i = 0; i < n; ++i)
    {
        a[i] = 0;
    }

    calculateSum(n, a, 0);

    delete[] a;
    a = nullptr;

    return err;
}

void print(int32_t n, int32_t * a)
{
    for(int32_t i = 0; i <= n; i++)
    {
        std::cout << a[i];

        if(i != n)
        {
            std::cout << " + ";
        }
    }

    std::cout << "\n";
}

void AllSumsOfANumber::calculateSum(int32_t n, int32_t * storage, int32_t level)
{
    //edge case
    if(n < 1)
    {
        return;
    }

    storage[level] = n;
    print(level, storage);

    const int32_t LOOP_END = n / 2;
    int32_t first = (level == 0) ? 1 : storage[level - 1];

    for(int32_t i = first; i <= LOOP_END; i++)
    {
        //replace last
        storage[level] = i;

        //set next level numbers
        calculateSum(n - i, storage, level + 1);
    }
}