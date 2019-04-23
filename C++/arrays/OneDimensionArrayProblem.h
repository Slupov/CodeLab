#ifndef CODELAB_ARRAYS_ONEDIMENSIONARRAYPROBLEM_H
#define CODELAB_ARRAYS_ONEDIMENSIONARRAYPROBLEM_H

/**
 *  @brief
 *  @date 01-Nov-18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "ArrayProblem.h"

class OneDimensionArrayProblem : public ArrayProblem
{
public:
    OneDimensionArrayProblem();

    virtual ~OneDimensionArrayProblem();

    /**
     * @brief Takes input data in format %d %d %d %d %d ... %d
     * and saves it into dynamically allocated array _data
     * **/
    virtual void initData() override;

    virtual void initDataSimple() override;

    virtual void initRandomData() override;

    virtual void initRandomDataSorted() override;

    virtual void solve() override;

    virtual void sortArray(ArraySorter * arraySorter) override;

    virtual void printArray() override;


protected:
    int32_t * _data;
    int32_t   _dataSize;
};


#endif //CODELAB_ARRAYS_ONEDIMENSIONARRAYPROBLEM_H
