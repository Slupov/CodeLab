/**
 *  @brief
 *  @date 16.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "TransformTreeNode.h"

//C system headers

//C++ system headers
#include <algorithm>
#include <random>
#include <vector>
#include <ctime>

//Other libraries headers

//Own components headers

#define NUMBERS_ARRAY_SIZE 50
#define MAX_NUMBER 100

struct TreeNode
{
    TreeNode * left;
    TreeNode * right;
    int32_t data;
};

int32_t TransformTreeNode::run()
{
    int32_t err = EXIT_SUCCESS;

    std::vector<int32_t> numbers;
    numbers.resize(NUMBERS_ARRAY_SIZE);

    //random input data
    std::mt19937 gen((uint32_t) std::time(nullptr));

    for(uint32_t i = 0; i < NUMBERS_ARRAY_SIZE; ++i)
    {
        numbers[i] = static_cast<int32_t>(gen() % MAX_NUMBER);
    }

    std::sort(numbers.begin(), numbers.end());

    Transform(&numbers[0], NUMBERS_ARRAY_SIZE);
    return err;
}

TreeNode * TransformTreeNode::Transform(int32_t * arr, int32_t size)
{
    return inorder(arr, 0, size - 1);
}

//NOTE !!!: Missing memory management because of time limitations of the exam.
//Low priority for a contest solution

TreeNode * TransformTreeNode::inorder(int32_t * arr, int32_t low, int32_t high)
{
    if(low > high)
    {
        return nullptr;
    }

    int mid = low + (high - low) / 2;

    //center val of sorted array as the root of the bst
    TreeNode * head = new TreeNode();
    head->data = arr[mid];

    //smaller values go to the left of this node
    head->left = inorder(arr, low, mid - 1);

    //bigger go to the right of this node
    head->right = inorder(arr, mid + 1, high);

    return head;
}
