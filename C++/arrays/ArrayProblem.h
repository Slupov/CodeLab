#ifndef ARRAYS_ARRAYPROBLEM_H
#define ARRAYS_ARRAYPROBLEM_H

/**
 *  @brief
 *  @date 19.09.18
 *  @author Stoyan Lupov
 *  @TODO Try to unify the 1D and 2D array problem classes into one by storing
 *  pointers to different dimensions inside a vector. [0] - last dimension,
 *  [n-1] - first dimension. Also make the class a template so we're not limited
 *  to a single data type
 */

//Corresponding header

//C system headers

//C++ system headers
#include <vector>

//Other libraries headers

//Own components headers
#include "Problem.h"

//Forward declarations
class ArraySorter;

class ArrayProblem : public Problem
{
    public:
        virtual ~ArrayProblem() = default;

        virtual void initData() = 0;

        virtual void initDataSimple() = 0;

        virtual void initRandomData() = 0;

        virtual void initRandomDataSorted() = 0;

        virtual void solve() = 0;

        virtual void sortArray(ArraySorter * arraySorter) = 0;

        virtual void printArray() = 0;
};


#endif //ARRAYS_ARRAYPROBLEM_H
