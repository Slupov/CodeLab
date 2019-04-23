/**
 *  @brief
 *  @date 31.09.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <cstdlib>

//Other libraries headers

//Own components headers
#include "tools/datageneratorlib/DataGenerator.h"

int main(int argc, char* argv[])
{
    //set default values if no params were given
    uint32_t dataSize = 10;
    uint32_t maxNum   = 20;

    if(argc && argv)
    {
        if(argc > 1)
        {
            dataSize = static_cast<uint32_t>(std::strtoul(argv[1], nullptr, 0));
        }

        if (argc > 2)
        {
            maxNum = static_cast<uint32_t>(std::strtoul(argv[2], nullptr, 0));
        }
    }

    DataGenerator gen;
    gen.run(dataSize, maxNum);

    return 0;
}

