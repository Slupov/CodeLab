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
#include "ThreadPool.h"

#define LEVEL_W 10
#define LEVEL_H 50
#define LEVEL_PYLONS 1

#define MAX_PIPE_X_OFFSET 10
#define MAX_PIPE_GAP_HEIGHT 20
#define MAX_PIPE_WIDTH 10
#define MIN_PIPE_WIDTH 1

#define BIRD_FALL true
#define BIRD_JUMP false

#define MUTATION_RATE 0.1

#define THREADS_COUNT 8

GeneticFlappyBird::GeneticFlappyBird() : _levelFrames(0),
                                         _solutionFound(false)
{
#if MULTITHREADING_FLAPPY
    _threadPool = new ThreadPool(THREADS_COUNT);
#endif
}

GeneticFlappyBird::~GeneticFlappyBird()
{
#if MULTITHREADING_FLAPPY
    delete _threadPool;
    _threadPool = nullptr;
#endif
}

std::vector<bool> getAgentDecisions(const LevelDescription &level)
{
    GeneticFlappyBird flappyBirdProblem;
    flappyBirdProblem.setLevel(level);

    return flappyBirdProblem.getSolution();
}

int32_t GeneticFlappyBird::run()
{
    int32_t err = EXIT_SUCCESS;

    srand((uint32_t) std::time(nullptr));

    initLevel(); //TODO Remove when submitting !!!
    initPopulation();

    while(true)
    {
        calculateFitness();
        sortPopulation();
        breedPopulation();

        printPopulation();

        if (_population[0].fitness == _levelFrames)
        {
            //solution found
            break;
        }
    }

    return err;
}

void GeneticFlappyBird::initPopulation()
{
    _levelFrames = static_cast<uint32_t >(_level.length / HORIZONTAL_VELOCITY);


    for(uint32_t i = 0; i < FLAPPY_POPULATION_SIZE; ++i)
    {
        _population[i].genes.resize(_levelFrames);

        for(uint32_t j = 0; j < _levelFrames; ++j)
        {
            _population[i].genes[i] = rand() % 2 ? BIRD_FALL : BIRD_JUMP;
        }
    }
}

void GeneticFlappyBird::initLevel()
{
    std::cout << "Initiating level ..." << std::endl;

    _level.height = LEVEL_H;
    _level.length = LEVEL_W;

    _level.pylons.resize(LEVEL_PYLONS);

//    std::mt19937 randGen((uint32_t) std::time(nullptr));
    std::mt19937 randGen(5);

    float currentPipeX = 0;
    float randNum = 0;

    _level.pylons[0].gapHeight = 2.2f;
    _level.pylons[0].width = 2.2f;
    _level.pylons[0].center.x = 3.0f;
    _level.pylons[0].center.y = 3.0f;

    //generate random pylons
    for(uint32_t i = 0; i < LEVEL_PYLONS; ++i)
    {
//        randNum = randGen() % (MAX_PIPE_X_OFFSET + 1);
//        _level.pylons[i].center.x = currentPipeX + randNum;
//
//        randNum = randGen() % (LEVEL_H + 1);
//        _level.pylons[i].center.y = randNum;
//
//        randNum = randGen() % (MAX_PIPE_GAP_HEIGHT + 1);
//        _level.pylons[i].gapHeight = 1 + randNum;
//
//        randNum = randGen() % (MAX_PIPE_WIDTH - MIN_PIPE_WIDTH);
//        _level.pylons[i].width = MIN_PIPE_WIDTH + randNum;

        printf("Pipe[%2u]: w: %.5f h: %.5f center.x: %.5f center.y: %.5f \n", i,
                _level.pylons[i].width, _level.pylons[i].gapHeight,
                _level.pylons[i].center.x, _level.pylons[i].center.y);
    }
}

void GeneticFlappyBird::calculateFitness()
{
    //enqueue tasks into the thread pool
    for(uint32_t i = 0; i < FLAPPY_POPULATION_SIZE; ++i)
    {
#if MULTITHREADING_FLAPPY
        _threadPool->enqueue([&] { calculateGenomeFitness(i); });
#else
        calculateGenomeFitness(i);
#endif
    }
}

void GeneticFlappyBird::sortPopulation()
{
    //do work
    mergesort(_population, 0, FLAPPY_POPULATION_SIZE - 1);
}

void GeneticFlappyBird::mergesort(Genome * array, uint32_t low, uint32_t high)
{
    if(low < high)
    {
        uint32_t middle = (low + high) / 2;

#if MULTITHREADING_FLAPPY
        // Create two sub-tasks
        _threadPool->enqueue([&] {
            mergesort(array, low, middle); });

        _threadPool->enqueue([&] {
            mergesort(array, middle + 1, high); });
#else
        mergesort(array, low, middle);
        mergesort(array, middle + 1, high);
#endif
        merge(array, low, middle, high);
    }
}

void GeneticFlappyBird::merge(Genome * array, uint32_t low, uint32_t mid,
                              uint32_t high)
{
    const uint32_t L_SIZE = mid - low + 1;
    const uint32_t R_SIZE = high - mid;

    //yea, i know i takes more space
    std::vector<Genome> tLeft(L_SIZE);
    std::vector<Genome> tRight(R_SIZE);

    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;

    /* Copy data to temp arrays */
    for (i = 0; i < L_SIZE; i++)
        tLeft[i] = array[low + i];

    for (j = 0; j < R_SIZE; j++)
        tRight[j] = array[mid + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;   // Initial index of first subarray
    j = 0;   // Initial index of second subarray
    k = low; // Initial index of merged subarray

    while (i < L_SIZE && j < R_SIZE)
    {
        if (tLeft[i].fitness <= tRight[j].fitness)
        {
            array[k] = tLeft[i];
            i++;
        }
        else
        {
            array[k] = tRight[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < L_SIZE)
    {
        array[k] = tLeft[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < R_SIZE)
    {
        array[k] = tRight[j];
        j++;
        k++;
    }
}

void GeneticFlappyBird::calculateGenomeFitness(const uint32_t idx)
{
    const uint32_t LEVEL_PYLONS_COUNT = _level.pylons.size();
    bool checkForPylon = LEVEL_PYLONS_COUNT != 0;

    Genome & genome = _population[idx];
    genome.fitness  = 0;

    Point2d birdPos;
    birdPos.x = 0;
    birdPos.y = _level.height / 2;

    uint32_t pylonIndex = 0;

    LevelDescription::Pylon * pylonCheck = nullptr;
    float pylonCheckX = 0;
    float pylonCheckY = 0;

    if (checkForPylon)
    {
        pylonCheck = & _level.pylons[pylonIndex];
        pylonCheckX = pylonCheck->center.x - pylonCheck->width / 2;
        pylonCheckY = pylonCheck->center.y + pylonCheck->gapHeight / 2;
    }

    bool isWallCollision = false;
    bool isPylonCollision = false;

    for(uint32_t i = 0; i < _levelFrames; ++i)
    {
        //update location
        birdPos.x += HORIZONTAL_VELOCITY;

        if (BIRD_FALL == genome.genes[i])
        {
            birdPos.y += VERTICAL_ACCELERATION;
        }
        else //BIRD_JUMP == genome.genes[i]
        {
            birdPos.y -= JUMP_ACCELERATION;
        }

        isWallCollision = birdPos.y <= 0 || birdPos.y >= _level.height;

        if (checkForPylon)
        {
            isPylonCollision =
                    (birdPos.x >= pylonCheckX &&
                     birdPos.x <= pylonCheckX + pylonCheck->width) &&
                    (birdPos.y <= pylonCheckY &&
                     birdPos.y >= pylonCheckY + pylonCheck->gapHeight);
        }

        //check for collision
        if (isWallCollision || isPylonCollision)
        {
            //death
            genome.fitness = i;

            return;
        }

        //no collision detected
        if (checkForPylon)
        {
            //try update to next pylon
            ++pylonIndex;
            if (pylonIndex >= LEVEL_PYLONS_COUNT)
            {
                checkForPylon = false;
                continue;
            }

            pylonCheck = & _level.pylons[pylonIndex];
            pylonCheckX = pylonCheck->center.x - pylonCheck->width / 2;
            pylonCheckY = pylonCheck->center.y + pylonCheck->gapHeight / 2;
        }
    }
}

void GeneticFlappyBird::printPopulation()
{
    for(uint32_t i = 0; i < FLAPPY_POPULATION_SIZE; ++i)
    {
        printf("Genome[%02u]: ", i);
        _population[i].print();
        printf("\n");
    }
}

void GeneticFlappyBird::breedPopulation()
{
    //breed first half (best) of population with second (worst)
    for(uint32_t i = 0; i < FLAPPY_POPULATION_SIZE / 2; ++i)
    {
        _population[FLAPPY_POPULATION_SIZE - 1 - i].crossover(_population[i]);
        _population[FLAPPY_POPULATION_SIZE - 1 - i].mutate(MUTATION_RATE);
        _population[i].mutate(MUTATION_RATE);
    }
}

void Genome::mutate(const float mutationRate)
{
    const uint32_t GENES_SIZE = genes.size();

    float r2 = (static_cast<float>(rand())) /
               (static_cast <float>(RAND_MAX / 100.00));

    for(uint32_t i = 0; i < GENES_SIZE; ++i)
    {
        if (r2 < mutationRate)
        {
            genes[i] = rand() % 2 ? BIRD_FALL : BIRD_JUMP;
        }
    }
}

void Genome::crossover(const Genome & partner)
{
    const uint32_t GENES_SIZE =
            static_cast<const uint32_t>(partner.genes.size());

    //pick a random midpoint
    uint32_t midpoint = rand() % GENES_SIZE;

    //half from one, half from the other
    for(uint32_t i = 0; i < GENES_SIZE; ++i)
    {
        if (i < midpoint)
        {
            genes[i] = partner.genes[i];
        }
    }
}

void Genome::print()
{
    for (const bool & gene: genes)
    {
        printf("%d", gene);
    }
}
