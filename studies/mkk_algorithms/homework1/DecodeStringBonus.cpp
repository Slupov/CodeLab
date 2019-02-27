/**
 *  @brief
 *  @date 26.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "DecodeStringBonus.h"

//C system headers

//C++ system headers
#include <string>
#include <stack>

//Other libraries headers

//Own components headers

#define OPENING_BRACKET '('
#define CLOSING_BRACKET ')'

int32_t DecodeStringBonus::run()
{
    int32_t err = EXIT_SUCCESS;

    std::string input;
    getline(std::cin, input);

    std::string res = "";
    std::stack<uint32_t> digitsStack;
    std::stack<std::string> resultsStack;

    uint32_t idx = 0;
    const uint32_t INPUT_SIZE = static_cast<const uint32_t>(input.size());

    uint32_t count = 0;
    std::string temp = "";

    while (idx < INPUT_SIZE)
    {
        if (std::isdigit(input[idx])) /** is digit **/
        {
            count = 0;

            //123 -> 10 * 0 + 1 = 1;  10 * 1 + 2 = 12; 10 * 12 + 3 = 123;
            while (std::isdigit(input[idx]))
            {
                //(input[idx] - 48) -> gets real digit value from ASCII table
                count = 10 * count + (input[idx] - '0');
                idx++;
            }

            digitsStack.push(count);
        }
        else if (input[idx] == OPENING_BRACKET) /** is opening bracket **/
        {
            resultsStack.push(res);
            res = "";
            idx++;
        }
        else if (input[idx] == CLOSING_BRACKET) /** is closing bracket **/
        {
            temp.clear();
            temp = resultsStack.top();

            uint32_t repetitions = digitsStack.top();

            resultsStack.pop();
            digitsStack.pop();

            for (uint32_t i = 0; i < repetitions; i++)
            {
                temp.append(res);
            }

            res = temp;
            idx++;
        }
        else /** a single character **/
        {
            std::string appStr = "";
            appStr += input[idx++];
            res.append(appStr);
        }
    }

    std::cout << res;
    return err;
}