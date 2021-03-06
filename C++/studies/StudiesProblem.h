#ifndef CODELAB_STUDIES_ALGORITHMS_STUDIESPROBLEM_H
#define CODELAB_STUDIES_ALGORITHMS_STUDIESPROBLEM_H

/**
 *  @brief
 *  @date 24.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <iostream>
#include <cstdint>

//Other libraries headers

//Own components headers

class StudiesProblem
{
public:
    virtual ~StudiesProblem() = default;

    /**
     * @brief Driver function for testing/running the given problem
     * **/
    virtual int32_t run() = 0;
};


#endif //CODELAB_STUDIES_ALGORITHMS_STUDIESPROBLEM_H
