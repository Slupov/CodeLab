/**
 *  @brief
 *  @date 14.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "FunctionIntegrator.h"

//C system headers

//C++ system headers
#include <cstdlib>
#include <cstdio>

//Other libraries headers

//Own components headers
#include "Range.hpp"

#define EPS 0.0001

FunctionIntegrator::FunctionIntegrator() : _rangesCount(UINT32_MAX),
                                           _integrationSteps(UINT32_MAX),
                                           _func(nullptr)
{

}

FunctionIntegrator::~FunctionIntegrator()
{
    //deallocate memory
    if (_ranges)
    {
        delete _ranges;
        _ranges = nullptr;
    }
}

int32_t FunctionIntegrator::init(Range * ranges,
                                 const uint32_t rangesCnt,
                                 double (* func)(double))
{
    int32_t err = EXIT_SUCCESS;

    if (EXIT_SUCCESS == err)
    {
        if (nullptr == func)
        {
            printf("Error! Nullptr function pointer passed!");
            err = EXIT_FAILURE;
        }
    }

    if (EXIT_SUCCESS == err)
    {
        _func = func;

        if (nullptr == ranges)
        {
            printf("Error! Nullptr ranges array passed!");
            err = EXIT_FAILURE;
        }
    }

    if (EXIT_SUCCESS == err)
    {
        if (rangesCnt == 0)
        {
            printf("Error! 0 ranges passed!");
            err = EXIT_FAILURE;
        }
    }

    if (EXIT_SUCCESS == err)
    {
        _rangesCount = rangesCnt;
        _ranges = new Range[rangesCnt];

        if (nullptr == _ranges)
        {
            printf("Error allocating memory for ranges array!!!");
            err = EXIT_FAILURE;
        }
    }

    if (EXIT_SUCCESS == err)
    {
        //assign given function to its callback
        _func = func;

        //copy input array into the working one
        for(uint32_t i = 0; i < _rangesCount; ++i)
        {
            _ranges[i].a = ranges[i].a;
            _ranges[i].b = ranges[i].b;
        }
    }

    return err;
}

double FunctionIntegrator::integrate(const uint32_t rangeIdx)
{
    const Range RANGE = _ranges[rangeIdx];
    _integrationSteps = calculateSteps(RANGE.a, RANGE.b);

    // width of each small rectangle
    double step = (RANGE.b - RANGE.a) / _integrationSteps;
    // signed area
    double area = 0.0;

    double x = 0;
    double height = 0;

    for (uint32_t i = 0; i < _integrationSteps; i ++)
    {
        // sum up each small rectangle
        x = RANGE.a + (i + 0.5) * step;
        height = _func(x);

        if (height < 0)
        {
            height *= (-1);
        }

        area += height * step;
    }

    return area;
}

uint32_t FunctionIntegrator::calculateSteps(const double a, const double b)
{
    uint32_t returnValue = 0;
    const double RANGE = (b - a);
    const double RANGE_RATIO = b / a;

    //range is super small -> return 0 steps
    if (RANGE <= EPS)
    {
        return returnValue;
    }

    //TODO Stoyan Lupov 15-02-2019 I perfectly know this is a "shano" way of
    //doing it but cannot come up with anything else at the moment. Change when
    //not drunk.
    if (RANGE_RATIO >= 3.0)
    {
        returnValue = 30;
    }
    else
    {
        returnValue = static_cast<uint32_t>(RANGE_RATIO * 10);
    }

    return returnValue;
}
