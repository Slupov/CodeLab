#ifndef CODELAB_STUDIES_ALGORITHMS_RGBSORTING_H
#define CODELAB_STUDIES_ALGORITHMS_RGBSORTING_H

/**
 *  @brief
 *  @date 24.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "studies/StudiesProblem.h"

class RGBSorting : public StudiesProblem
{
    public:
        virtual ~RGBSorting() override = default;

        virtual int32_t run() override;
};

#endif //CODELAB_STUDIES_ALGORITHMS_RGBSORTING_H
