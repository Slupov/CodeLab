#ifndef CODELAB_STUDIES_ALGORITHMS_PHONEBILLS_H
#define CODELAB_STUDIES_ALGORITHMS_PHONEBILLS_H



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

class PhoneBills : public StudiesProblem
{
public:
    PhoneBills() = default;

    virtual ~PhoneBills() = default;

    virtual void run() override;

private:
    void runVector();

    void runMultiset();
};


#endif //CODELAB_STUDIES_ALGORITHMS_PHONEBILLS_H
