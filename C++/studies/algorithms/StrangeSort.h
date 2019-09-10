#ifndef DUMMY_TEST_STRANGESORT_H
#define DUMMY_TEST_STRANGESORT_H



/**
 *  @brief
 *  @date 26.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include "studies/StudiesProblem.h"

class StrangeSort : public StudiesProblem
{
    public:
        virtual ~StrangeSort() override = default;

        virtual int32_t run() override;
};

#endif //DUMMY_TEST_STRANGESORT_H
