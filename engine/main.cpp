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
#include "arrays/nbulecture/1D/ArrayShift.h"

#include "arrays/nbulecture/2D/MatrixMultiplication.h"

int main(int argc, char* argv[])
{
    if(argc && argv) {}

    ArrayProblem * arrayProblem = nullptr;
    ArraySorter  * arraySorter  = nullptr;

    arraySorter  = new BubbleSort();
    
    if (arraySorter && arrayProblem) {}

//    arrayProblem = new ContainerWithMostWater();
//    arrayProblem = new TwoSum();
//    arrayProblem = new ArrayShift();
    arrayProblem = new MatrixMultiplication();
    arrayProblem->solve();
//    arrayProblem->printArray();

    delete arrayProblem;

    return 0;
}

