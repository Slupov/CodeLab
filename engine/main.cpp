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
#include <studies/mkk_algorithms/homework2/AllSumsOfANumber.h>
#include <studies/mkk_algorithms/homework2/AllSumsOfANumberRestricted.h>
#include "studies/mkk_algorithms/homework1/LargeFloatProblem.h"
#include "studies/mkk_algorithms/homework1/IntegratingFunction.h"
#include "studies/algorithms/PhoneBills.h"
#include "studies/algorithms/ShoeSizes.h"
#include "studies/algorithms/MinK.h"
#include "studies/algorithms/MinProduct.h"

#include "studies/mkk_algorithms/FileStreams.h"

#include "arrays/ArrayHeaders.h"

#include "studies/StudiesProblem.h"

void runArrayProblem();

void runStudiesProblem();

void runMKKProblem();

int main(int argc, char * argv[])
{
    if(argc && argv)
    {
    }

//    runArrayProblem();
//    runStudiesProblem();
    runMKKProblem();

    return 0;
}

void runArrayProblem()
{
    ArrayProblem * arrayProblem = nullptr;
    ArraySorter * arraySorter = nullptr;

//    arraySorter  = new BubbleSort();
    arraySorter = new ParitySort();

    if(arraySorter && arrayProblem)
    {
    }

    arrayProblem = new OneDimensionArrayProblem();
//    arrayProblem->solve();

    arrayProblem->initRandomData();
    arrayProblem->printArray();
    arrayProblem->sortArray(arraySorter);
    arrayProblem->printArray();
    printf("\n");
//    arrayProblem->sortArray(arraySorter);
//    arrayProblem->printArray();

    delete arrayProblem;
}

void runStudiesProblem()
{
    StudiesProblem * problem = nullptr;

    delete problem;
    problem = nullptr;
}

void runMKKProblem()
{
    StudiesProblem * problem = nullptr;

//    problem = new FileStreams();
//    problem = new LargeFloatProblem();
//    problem = new IntegratingFunction();
//    problem = new LargeFloatProblem();
//    problem = new AllSumsOfANumber();
    problem = new AllSumsOfANumberRestricted();
    problem->run();

    delete problem;
    problem = nullptr;
}