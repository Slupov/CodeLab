/**
 *  @brief
 *  @date 07.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "BinarySearch.h"

void BinarySearch::initRandomData()
{
    OneDimensionArrayProblem::initRandomData();
}

void BinarySearch::solve()
{
    initRandomDataSorted();
    printArray();

    printf("Enter searched num: ");
    std::cin >> _searchedNum;

    const int32_t BIN_SEARCH_RES = binary_search(0, _dataSize - 1);

    if (BIN_SEARCH_RES == -1)
    {
        printf("Searched num not found.");
    }
    else
    {
        printf("Searched num found at [%d].", BIN_SEARCH_RES);
    }
}

int32_t BinarySearch::binary_search(const int32_t leftIdx, const int32_t rightIdx)
{
    if (leftIdx > rightIdx)
    {
        return -1;
    }

    int32_t mid = (leftIdx + rightIdx) / 2;

    if (_data[mid] == _searchedNum)
    {
        return mid;
    }

    if (_searchedNum < _data[mid])
    {
        return binary_search(leftIdx, mid - 1);
    }

    return binary_search(mid + 1, rightIdx);
}