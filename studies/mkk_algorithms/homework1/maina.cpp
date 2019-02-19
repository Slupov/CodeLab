/**
 *  @brief
 *  @date 18.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include <studies/StudiesProblem.h>
#include "LargeFloatProblem.h"
#include "IntegratingFunction.h"

int32_t main(int argc, char * argv[])
{
    if(argc && argv)
    {
    }

    StudiesProblem * problem = nullptr;
    int32_t err = EXIT_SUCCESS;

    problem = new LargeFloatProblem();
//    err     = problem->run(); //UNCOMMENT TO RUN

    problem = new IntegratingFunction();
    err     = problem->run();

    return err;
}