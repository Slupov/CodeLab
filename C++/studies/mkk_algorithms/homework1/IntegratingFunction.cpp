/**
 *  @brief
 *  @date 14.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "IntegratingFunction.h"

//C system headers

//C++ system headers
#include <cmath>

//Other libraries headers

//Own components headers
#include "FunctionIntegrator.h"
#include "Range.hpp"

#define RANGES_CNT 3
#define TESTING_FUNCTIONS 3

double constantFunction(const double x)
{
    //dummy check to satisfy compiler's warning for unused parameter
    if (x)
    {
    }

    return 10;
}

int32_t IntegratingFunction::run()
{
    int32_t err = EXIT_SUCCESS;

    Range ranges[RANGES_CNT] = {
            {1, 5},
            {2, 9},
            {3, 7}
    };

    const char * FUNC_NAMES [TESTING_FUNCTIONS]
    {
        "Testng CONST function: ",
        "Testing SIN function: ",
        "Testing COS function: "
    };

    // array of testing functions' pointers
    double (* FUNCS [])(double)
    {
          constantFunction,
          sin,
          cos
    };

    double integrationResults[RANGES_CNT] = {0,};
    uint32_t integrationSteps[RANGES_CNT] = {0,};

    //print results
    for(uint32_t i = 0; i < TESTING_FUNCTIONS; ++i)
    {
        integrateFunction(ranges, integrationResults, integrationSteps,
                          RANGES_CNT, FUNCS[i]);

        std::cout << FUNC_NAMES[i] << std::endl;

        for(uint32_t j = 0; j < RANGES_CNT; ++j)
        {
            std::cout << "For [" << ranges[j].a << ", "   << ranges[j].b
                      << "] = "  << integrationResults[j] << " with "
                      << integrationSteps[j] << " integration steps.\n";
        }

        std::cout << std::endl;
    }

    return err;
}


void IntegratingFunction::integrateFunction(Range * inRanges,
        double * outResults, uint32_t * outIntegrationSteps,
        const uint32_t inputCount, double (* func)(double))
{
    FunctionIntegrator integrator;
    if (EXIT_SUCCESS != integrator.init(inRanges, inputCount, func))
    {
        return;
    }

    for(uint32_t i = 0; i < inputCount; ++i)
    {
        outResults[i] = integrator.integrate(i);
        outIntegrationSteps[i] = integrator.getIntegrationSteps();
    }
}
