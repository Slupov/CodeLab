/**
 *  @brief
 *  @date 19.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include <algorithm>
#include "AllSumsOfANumberRestricted.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers


bool comp(int i, int j) {
	return i > j;
}

int32_t AllSumsOfANumberRestricted::run()
{
    int32_t err = EXIT_SUCCESS;

    uint32_t n;
    uint32_t k;

    std::cin >> n >> k;

    //stores coins (addends to use)
    uint32_t * coins = new uint32_t[k];
    uint32_t * counts = new uint32_t[k];

    for(uint32_t i = 0; i < k; ++i)
    {
        std::cin >> coins[i];
        counts[i] = 0;
    }

    //sort coins in descending order
    std::sort(coins, coins + k, comp);

    printCombination(coins, k, counts, 0, n);

    delete[] coins;
    coins = nullptr;

    return err;
}

void print(uint32_t * coins, uint32_t * counts, uint32_t coinsCount)
{
    uint32_t leftToPrint = 0;

    //get total number of coins
    for(uint32_t i = 0; i < coinsCount; ++i)
    {
        leftToPrint += counts[i];
    }

    --leftToPrint;

    //we have processed them all
    for(uint32_t i = 0; i < coinsCount; ++i)
    {
        for(uint32_t j = 0; j < counts[i]; ++j)
        {
            std::cout << coins[i];

            if (leftToPrint > 0)
            {
                std::cout << " + ";
                --leftToPrint;
            }
        }
    }

    std::cout << "\n";
}

void AllSumsOfANumberRestricted::printCombination(
        uint32_t * coins, uint32_t coinsCount, uint32_t * counts,
        uint32_t startIdx, uint32_t totalAmount)
{
    //check if we have processed all coins
    if (startIdx >= coinsCount)
    {
        print(coins, counts, coinsCount);
        return;
    }

    /** if startIdx is the last one, we need to check if it can be divided by
      * the smallest coin
      * a) if so => good combination
      * b) otherwise => impossible combination => discarded **/
    if (startIdx == coinsCount - 1)
    {
         if (totalAmount % coins[startIdx] == 0) //good combination
         {
            //set the counts of coins at start index
            counts[startIdx] = totalAmount / coins[startIdx];

            //proceed to recursive call
            printCombination(coins, coinsCount, counts, startIdx + 1, 0);
         }
    }
    else //we still have option to choose 0-N larger coins
    {
        for(uint32_t i = 0; i <= totalAmount / coins[startIdx]; ++i)
        {
            //for every iteration we choose an arbitrary number of larger coins
            //and proceed next
            counts[startIdx] = i;

            //update the remaining amount and startIdx
            printCombination(coins, coinsCount, counts, startIdx + 1,
                             totalAmount - coins[startIdx] * i);

        }
    }
}
