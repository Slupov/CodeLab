#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_TRANSFORMTREENODE_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_TRANSFORMTREENODE_H



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

//Forward declarations
class TreeNode;

class TransformTreeNode : public StudiesProblem
{
    public:
        virtual ~TransformTreeNode() override = default;

        virtual int32_t run() override;

        TreeNode* Transform(int32_t * arr, int32_t size);

    private:
        TreeNode* inorder(int32_t * arr, int32_t low, int32_t high);

};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_TRANSFORMTREENODE_H
