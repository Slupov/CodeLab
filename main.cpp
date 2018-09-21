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

int main(int gc, char * argv[])
{
    if (gc && argv) {}

    NQueens nQueens;
    nQueens.solve();

    return EXIT_SUCCESS;
}

