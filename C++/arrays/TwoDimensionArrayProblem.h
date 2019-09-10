#ifndef CODELAB_ARRAYS_TWODIMENSIONARRAYPROBLEM_H
#define CODELAB_ARRAYS_TWODIMENSIONARRAYPROBLEM_H

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

class TwoDimensionArrayProblem : public ArrayProblem
{
public:
    TwoDimensionArrayProblem();

    virtual ~TwoDimensionArrayProblem();

    /**
     * @brief Takes input data in format %d %d %d %d %d ... %d
     * and saves it into dynamically allocated array _data
     * **/
    virtual void initData() override;

    /**
     * @brief A simpler way of inputing the data. The user gives rows and cols
     * values beforehand
     * **/
    virtual void initDataSimple() override;

    virtual void initRandomData() override;

    virtual void initRandomDataSorted() override;

    virtual void solve() override;

    virtual void sortArray(ArraySorter * arraySorter) override;

    virtual void printArray() override;

protected:
    int32_t ** _data;
    int32_t  * _dataSizes; //each row's column count

    int32_t    _rows;

};


#endif //CODELAB_ARRAYS_TWODIMENSIONARRAYPROBLEM_H
