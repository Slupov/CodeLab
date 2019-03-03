/**
 *  @brief
 *  @date 03.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "GeneticFlappyBird.h"

//C system headers

//C++ system headers
#include <random>
#include <ctime>

//Other libraries headers

//Own components headers

#define FLAPPY_POPULATION_SIZE 50

#define LEVEL_W 100
#define LEVEL_H 50
#define LEVEL_PIPES 15

#define MAX_PIPE_X_OFFSET 10
#define MAX_PIPE_GAP_HEIGHT 20
#define MAX_PIPE_WIDTH 10
#define MIN_PIPE_WIDTH 1

#define BIRD_FALL true
#define BIRD_JUMP false

GeneticFlappyBird::GeneticFlappyBird() : _population(nullptr)
{

}

int32_t GeneticFlappyBird::run()
{
    int32_t err = EXIT_SUCCESS;

    initLevel();
    initPopulation();
    deinitPopulation();

    return err;
}

void GeneticFlappyBird::initPopulation()
{
    _population = new bool * [FLAPPY_POPULATION_SIZE];

    const uint32_t LEVEL_FRAMES = static_cast<uint32_t >(
            (_level.length) / (HORIZONTAL_VELOCITY * FPS));

    srand((uint32_t) std::time(nullptr));

    for(uint32_t i = 0; i < FLAPPY_POPULATION_SIZE; ++i)
    {
        _population[i] = new bool[LEVEL_FRAMES];

        for(uint32_t j = 0; j < LEVEL_FRAMES; ++j)
        {
            _population[i][j] = rand() % 2 ? BIRD_FALL : BIRD_JUMP;
        }
    }
}

void GeneticFlappyBird::initLevel()
{
    _level.height = LEVEL_H;
    _level.length = LEVEL_W;

    _level.pipes.resize(LEVEL_PIPES);

    std::mt19937 randGen((uint32_t) std::time(nullptr));

    float currentPipeX = 0;
    float randNum = 0;

    //generate random pipes
    for(uint32_t i = 0; i < LEVEL_PIPES; ++i)
    {
        randNum = randGen() % (MAX_PIPE_X_OFFSET + 1);
        _level.pipes[i].center.x = currentPipeX + randNum;

        randNum = randGen() % (LEVEL_H + 1);
        _level.pipes[i].center.y = randNum;

        randNum = randGen() % (MAX_PIPE_GAP_HEIGHT + 1);
        _level.pipes[i].gapHeight = 1 + randNum;

        randNum = randGen() % (MAX_PIPE_WIDTH - MIN_PIPE_WIDTH);
        _level.pipes[i].width = MIN_PIPE_WIDTH + randNum;

        printf("Pipe[%u]: w: %.5f h: %.5f center.x: %.5f center.y: %.5f \n", i,
                _level.pipes[i].width, _level.pipes[i].gapHeight,
                _level.pipes[i].center.x, _level.pipes[i].center.y);
    }
}

void GeneticFlappyBird::deinitPopulation()
{
    for(uint32_t i = 0; i < FLAPPY_POPULATION_SIZE; ++i)
    {
        delete _population[i];
        _population[i] = nullptr;
    }

    delete[] _population;
    _population = nullptr;
}
