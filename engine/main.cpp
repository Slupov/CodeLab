/**
 *  @brief
 *  @date 31.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "arrays/sorting/BubbleSort.h"

#include "arrays/nbulecture/1D/ContainerWithMostWater.h"
#include "arrays/nbulecture/1D/TwoSum.h"

int main(int argc, char* argv[])
{
    if(argc && argv) {}

    ArrayProblem * arrayProblem = nullptr;
    ArraySorter  * arraySorter  = nullptr;

    arraySorter  = new BubbleSort();

//    arrayProblem = new ContainerWithMostWater();
    arrayProblem = new TwoSum();

//    arrayProblem->solve();
    arrayProblem->initData();
    arrayProblem->sortArray(arraySorter);
    arrayProblem->printArray();

    delete arrayProblem;

    return 0;
}

