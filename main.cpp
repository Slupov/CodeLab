/**
 *  @brief
 *  @date 18.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <cstdlib>
#include <iostream>

//Other libraries headers

//Own components headers
#include "arrays/NQueens.h"
#include "arrays/ContainerWithMostWater.h"

int main(int gc, char * argv[])
{
    if (gc && argv) {}

//    NQueens nQueens;
//    nQueens.solve();

    ContainerWithMostWater containerWithMostWater;
    containerWithMostWater.solve();

    return EXIT_SUCCESS;
}

