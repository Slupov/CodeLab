#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_GENETICFLAPPYBIRD_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_GENETICFLAPPYBIRD_H

/**
 *  @brief
 *  @date 03.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <vector>

//Other libraries headers

//Own components headers
#include "studies/StudiesProblem.h"
#include "flappy.h"

#define FLAPPY_POPULATION_SIZE 50

//Forward declarations
class ThreadPool;

struct Genome
{
    public:
        std::vector<bool> genes;

        uint32_t fitness = 0;

        void mutate(const float mutationRate);

        void crossover(const Genome & partner, Genome & outChild);

        void print();
};

class GeneticFlappyBird : public StudiesProblem
{
    public:
        GeneticFlappyBird();
        virtual ~GeneticFlappyBird();

        virtual int32_t run() override;

        inline void setLevel(const LevelDescription & level)
        {
            _level = level;
        }

        inline std::vector<bool> getSolution()
        {
            return _population[0].genes;
        }

    private:

        /** Initializes the first generation of the genetic algorithm.
         *  Must be called only once. **/
        void initPopulation();

        void initLevel();

        void calculateFitness();

        void sortPopulation();

        /// Multithread merge sort
        void mergesort(Genome * array, uint32_t low, uint32_t high);

        void merge(Genome * array, uint32_t low, uint32_t mid, uint32_t high);

        /// GENOMES SPECIFIC FUNCTIONS

        void calculateGenomeFitness(const uint32_t idx);

        LevelDescription _level;

        ThreadPool * _threadPool;

        uint32_t _levelFrames;

        /** A 2D array whose elements are current generation's individuals.
         *  Each individual is an array of decisions**/
        Genome _population [FLAPPY_POPULATION_SIZE];

        bool _solutionFound;

        void printPopulation();
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_GENETICFLAPPYBIRD_H
