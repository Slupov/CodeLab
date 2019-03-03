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

//Other libraries headers

//Own components headers
#include "studies/StudiesProblem.h"
#include "Flappy.h"

class GeneticFlappyBird : public StudiesProblem
{
    public:
        GeneticFlappyBird();

        virtual int32_t run() override;

    private:

        /** Initializes the first generation of the genetic algorithm.
         *  Must be called only once. **/
        void initPopulation();

        void deinitPopulation();

        void initLevel();

        LevelDescription _level;

        /** A 2D array whose elements are current generation's individuals.
         *  Each individual is an array of decisions**/
        bool ** _population;
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_GENETICFLAPPYBIRD_H
