#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_FUNCTIONINTEGRATOR_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_FUNCTIONINTEGRATOR_H

/**
 *  @brief Homework 1 - Problem 3 helper
 *  @date 14.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>

//Other libraries headers

//Own components headers

//Forward declarations
struct Range;

class FunctionIntegrator
{
    public:
        FunctionIntegrator();
        ~FunctionIntegrator();

        int32_t init(Range * ranges,
                     const uint32_t rangesCnt,
                     double (* func)(double));

        /**
         * @brief Integrates a function by using the Left Riemann sum algorithm
         * @param rangeIdx - the index of the range coordinates pairs
         * **/
        double integrate(const uint32_t rangeIdx);

        inline uint32_t getIntegrationSteps()
        {
            return _integrationSteps;
        }

    private:
        /**
         * @brief calculates the number of "optimal" steps (rectangles) the area
         * under the function's graph should be split into
         * **/
        uint32_t calculateSteps(const double a, const double b);

        uint32_t _rangesCount;
        uint32_t _integrationSteps;

        Range *  _ranges;

        double (* _func)(double a);
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK1_FUNCTIONINTEGRATOR_H
