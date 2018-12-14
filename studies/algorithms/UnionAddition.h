#ifndef DUMMY_TEST_UNIONADDITION_H
#define DUMMY_TEST_UNIONADDITION_H



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
#include <studies/StudiesProblem.h>

class UnionAddition : public StudiesProblem
{
    public:
        virtual ~UnionAddition() override = default;

        virtual void run() override;

        void run2();
};


#endif //DUMMY_TEST_UNIONADDITION_H
