/**
 *  @brief
 *  @date   ${Current_day}
 *  @author ${Faculty_number}
 */

//Corresponding header

//C system headers

//C++ system headers
#include <iostream>
#include <string>
#include <sstream>
#include <set>
//Other libraries headers

//Own components headers

//TODO: DO NOT COMMIT
int main()
{
    //read n and m
    int32_t m;
    int32_t n;

    std::string input;
    getline(std::cin, input);

    std::istringstream iss(input);

    iss >> std::skipws;
    iss >> m;
    iss >> n;

    //read bills that need to be paid
    getline(std::cin, input);
    iss.str(input);

    std::multiset<double> leftToPay;

    iss.clear();
    iss.str(input);

    double num;
    while(iss >> num)
    {
        leftToPay.insert(num);
    }

    //read paid bills
    getline(std::cin, input);
    iss.clear();
    iss.str(input);

    std::multiset<double>::iterator it;

    while(iss >> num)
    {
        it = leftToPay.find(num);

        //found it
        if(it != leftToPay.end())
        {
            leftToPay.erase(it);
        }
        else
        {
            leftToPay.insert(num);
        }
    }

    //print left to pay
    for(std::multiset<double>::iterator itt = leftToPay.begin();
        itt != leftToPay.end(); ++itt)
    {
        std::cout << * itt << " ";
    }

    return 0;
}
