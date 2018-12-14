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
#include <studies/algorithms/PhoneBills.h>
#include <studies/algorithms/ShoeSizes.h>
#include <studies/algorithms/MinK.h>
#include <studies/algorithms/MinProduct.h>
#include "arrays/ArrayHeaders.h"

#include "studies/StudiesProblem.h"

void runArrayProblem();

void runStudiesProblem();

int main(int argc, char * argv[])
{
    if(argc && argv)
    {
    }

//    runArrayProblem();
    runStudiesProblem();

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
//    arrayProblem = new TwoDimensionArrayProblem();
//    arrayProblem = new ContainerWithMostWater();
//    arrayProblem = new TwoSum();
//    arrayProblem = new ArrayShift();
//    arrayProblem = new MatrixMultiplication();
//    arrayProblem = new TransposeMatrix();
//    arrayProblem = new OneTwoBitCharacter();
//    arrayProblem = new ToeplitzMatrix();
//    arrayProblem = new SpiralMatrix();
//    arrayProblem = new FlippingAnImage();
//    arrayProblem = new MaxHourGlass();
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
//    problem = new PhoneBills();
//    problem = new ShoeSizes();
//    problem = new MinK();
    problem = new MinProduct();

    problem->run();

    delete problem;
    problem = nullptr;
}