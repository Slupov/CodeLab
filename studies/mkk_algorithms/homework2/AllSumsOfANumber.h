#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK2_ALLSUMSOFANUMBER_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK2_ALLSUMSOFANUMBER_H

/**
 *  @brief
 *  @date 19.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "studies/StudiesProblem.h"

class AllSumsOfANumber : public StudiesProblem
{
    public:
        virtual int32_t run() override;

    private:
        void calculateSum(int32_t n, int32_t * storage, int32_t level);
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK2_ALLSUMSOFANUMBER_H
