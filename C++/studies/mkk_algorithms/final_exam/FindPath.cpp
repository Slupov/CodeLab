/**
 *  @brief
 *  @date 16#03#19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "FindPath.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#define MAZE_W 11
#define MAZE_H 10

#define END_POINT 'X'
#define HOR_MOVE '-'
#define VER_MOVE '-'
#define BOTH_DIR_MOVE '+'
#define WALL '#'

int32_t FindPath::run()
{
    int32_t err = EXIT_SUCCESS;

    //NOTE: strings contain terminating symbols
    char maze[MAZE_H][MAZE_W] =
            {
                    "----######",
                    "###|######",
                    "###|######",
                    "###|######",
                    "###---####",
                    "#####|####",
                    "#####|####",
                    "#####|####",
                    "#####|####",
                    "#####----X"
            };

    std::cout << findPath((char **) maze, MAZE_W, MAZE_H, 0, 0);

    return err;
}

bool FindPath::findPath(char ** maze, int32_t width, int32_t height, int32_t x,
                        int32_t y)
{
    if (y < 0 || y >= MAZE_H || x < 0 || x > MAZE_W)
    {
        return false;
    }

    if (maze[y][x] == WALL)
    {
        return false;
    }

    if (maze[y][x] == END_POINT)
    {
        return true;
    }

    char oldCharacter = maze[y][x];
    maze[y][x] = WALL;

    bool checkNext = false;

    //all boolean assignments in below if/else if construction will stop on
    //finding the first true and others will not be executed
    if (oldCharacter == HOR_MOVE)
    {
        checkNext = findPath(maze, MAZE_W, MAZE_H, y, x + 1) ||  //right
                    findPath(maze, MAZE_W, MAZE_H, y, x - 1);    //left
    }
    else if (oldCharacter == VER_MOVE)
    {
        checkNext = findPath(maze, MAZE_W, MAZE_H, y + 1, x) ||  //down
                    findPath(maze, MAZE_W, MAZE_H, y - 1, x);    //up
    }
    else if (oldCharacter == BOTH_DIR_MOVE)
    {
        //keeping in mind direction priority
        checkNext = findPath(maze, MAZE_W, MAZE_H, y, x + 1) ||  //right
                    findPath(maze, MAZE_W, MAZE_H, y + 1, x) ||  //down
                    findPath(maze, MAZE_W, MAZE_H, y, x - 1) ||  //left
                    findPath(maze, MAZE_W, MAZE_H, y - 1, x);    //up
    }

    //recover original maze character for the current position
    maze[y][x] = oldCharacter;

    return checkNext;
}
