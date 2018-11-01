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
#include "arrays/nbulecture/ContainerWithMostWater.h"
#include "arrays/nbulecture/TwoSum.h"

int main(int argc, char* argv[])
{
    if(argc && argv) {}

    ArrayProblem * arrayProblem = nullptr;
//    arrayProblem = new ContainerWithMostWater();
    arrayProblem = new TwoSum();

    arrayProblem->solve();

    delete arrayProblem;

    return 0;
}

