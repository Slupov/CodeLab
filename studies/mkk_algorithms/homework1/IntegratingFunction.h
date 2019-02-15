#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_INTEGRATINGFUNCTION_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_INTEGRATINGFUNCTION_H

/**
 *  @brief Homework 1 - Problem 2 & 3
 *  @date 14.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "studies/StudiesProblem.h"

//Forward declarations
struct Range;

class IntegratingFunction : public StudiesProblem
{
    public:
        virtual int32_t run() override;

    private:
        void integrateFunction(Range * inRanges, double * outResults,
                const uint32_t inputCount, double (* func)(double));
};

#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_INTEGRATINGFUNCTION_H
