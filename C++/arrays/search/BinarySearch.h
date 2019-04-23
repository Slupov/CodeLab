#ifndef ARRAYS_SEARCH_BINARYSEARCH_H
#define ARRAYS_SEARCH_BINARYSEARCH_H

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
#include "arrays/OneDimensionArrayProblem.h"

class BinarySearch : public OneDimensionArrayProblem
{
public:
    virtual void initRandomData() override;

    virtual void solve() override;

private:
    int32_t binary_search(const int32_t leftIdx, const int32_t rightIdx);

    int32_t _searchedNum;
};


#endif //ARRAYS_SEARCH_BINARYSEARCH_H
