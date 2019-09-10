/**
 *  @brief
 *  @date 04.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "OneTwoBitCharacter.h"

void OneTwoBitCharacter::solve()
{
    OneDimensionArrayProblem::solve();

    int32_t i = 0;
    while (i < _dataSize - 1)
    {
        i += _data[i] + 1;
    }

    printf("Output: %s\n", (i == _dataSize - 1) ? "true" : "false");
}
