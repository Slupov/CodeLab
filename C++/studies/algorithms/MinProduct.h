#ifndef DUMMY_TEST_MINPRODUCT_H
#define DUMMY_TEST_MINPRODUCT_H



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

class MinProduct : public StudiesProblem
{
    public:
        virtual ~MinProduct() override = default;

        virtual int32_t run() override;

        void run2();

        void run3();
};


#endif //DUMMY_TEST_MINPRODUCT_H
