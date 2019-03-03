#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_FLAPPY
#define CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_FLAPPY

/**
 *  @brief The provided header for the homework. Given inside the homework
 *  assignment by poseidon4o.
 *  @date 03.03.19
 *  @author poseidon4o (MNK)
 */

//Corresponding header

//C system headers

//C++ system headers
#include <vector>

//Other libraries headers

//Own components headers

struct Point2d
{
    float x;
    float y;
};

const float FPS = 60.f;

const float HORIZONTAL_VELOCITY = 0.6f / FPS;
const float VERTICAL_ACCELERATION = 9.8f / FPS;
const float JUMP_ACCELERATION = VERTICAL_ACCELERATION * 2.f;

struct LevelDescription
{
    /// Total length of the level
    float length;

    /// Total height of the level
    float height;

    //REVISED by Stoyan Lupov (03.03.2019) The "Pylon" class name was changed
    //to "Pipe" because it sounded too striptease-y to me.
    //Original "Flappy Bird" ® game uses the "pipe" term.
    struct Pipe
    {
        /** Center is between [0, 0] and [width, height]
          * Refers to the point in the middle of the gap between top and bottom
          * part of the pylon **/
        Point2d center;

        /** Width of the pylon **/
        float width;

        /** The hight of the gap between top and bottom part of the pylon **/
        float gapHeight;
    };

    /** Each pylon in the level **/
    std::vector<Pipe> pipes;
};

/// Expected number of decisions is (level.length) / (HORIZONTAL_VELOCITY * FPS))
std::vector<bool> getAgentDecisions(const LevelDescription &level);

#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_FLAPPY
