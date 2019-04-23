#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK2_ALLSUMSOFANUMBERRESTRICTED_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK2_ALLSUMSOFANUMBERRESTRICTED_H

/**
 *  @brief A typical coin change problem
 *  @date 19.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#include <studies/StudiesProblem.h>

class AllSumsOfANumberRestricted : public StudiesProblem
{
    public:
        virtual int32_t run() override;

    private:

        /**
         * @param coins - sorted coins in descending order
         * @param counts - the number of coins at certain denomination
         * @param startIdx - the index of the coin we start processing from
         * @param totalAmount - remaining amount left processing
         * **/
        void printCombination(uint32_t * coins, uint32_t coinsCount,
                uint32_t * counts, uint32_t startIdx, uint32_t totalAmount);
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK2_ALLSUMSOFANUMBERRESTRICTED_H
