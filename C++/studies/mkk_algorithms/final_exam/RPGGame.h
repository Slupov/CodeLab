#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_RPGGAME_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_RPGGAME_H

/**
 *  @brief
 *  @date 16.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "studies/StudiesProblem.h"

class RPGGame : public StudiesProblem
{
    public:
        virtual ~RPGGame() override = default;

        virtual int32_t run() override;
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_RPGGAME_H
