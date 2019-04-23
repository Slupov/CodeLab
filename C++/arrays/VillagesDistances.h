#ifndef ARRAYS_VILLAGESDISTANCES_H
#define ARRAYS_VILLAGESDISTANCES_H

/**
 *  @brief На хоризонталната ос са разположени N селища с координати
 *  a1< a2<… < aN. Напишете програма, която да избере едно селище, да речем
 *  i-тото така, че разликата от разстоянията от него до a1 и aN
 *  |(ai – a1)–(aN – ai)| да е минимална.
 *
 *  @date 07.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "OneDimensionArrayProblem.h"

class VillagesDistances : public OneDimensionArrayProblem
{
public:
    virtual void solve() override;

private:
    void solveOnePass();
};


#endif //ARRAYS_VILLAGESDISTANCES_H
