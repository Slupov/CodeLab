#include <iostream>

/**
 *  @brief
 *  @date 02.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <vector>

//Other libraries headers

//Own components headers

int32_t main()
{
    int32_t returnCode = EXIT_SUCCESS;

    struct Point
    {
        int32_t x;
        int32_t y;

        std::vector<bool> genes;
    };

    Point arr [3];

    arr[0].x = 0;
    arr[0].y = 0;
    arr[0].genes.resize(3, false);

    arr[1].x = 1;
    arr[1].y = 1;
    arr[1].genes.resize(3, true);

    arr[2].x = 2;
    arr[2].y = 2;
    arr[2].genes.resize(3, true);


    arr[2] = arr[0];
    arr[2].x = 5;

    std::cout << arr[0].x << " " << arr[0].y << " " << arr[0].genes[0] << std::endl;
    std::cout << arr[2].x << " " << arr[2].y << " " << arr[2].genes[0] << std::endl;

    return returnCode;
}