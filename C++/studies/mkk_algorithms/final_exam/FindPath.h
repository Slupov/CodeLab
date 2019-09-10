#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_FINDPATH_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_FINDPATH_H

/**
 *  @brief
 *  @date 16.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "studies/StudiesProblem.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

class FindPath : public StudiesProblem
{
    public:
        virtual ~FindPath() override = default;

        virtual int32_t run() override;

    private:

        bool findPath(char **maze, int32_t width, int32_t height,
                      int32_t x, int32_t y);
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_FINDPATH_H
