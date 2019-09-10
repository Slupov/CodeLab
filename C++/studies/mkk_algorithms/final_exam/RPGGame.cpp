/**
 *  @brief
 *  @date 16.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "RPGGame.h"

//C system headers

//C++ system headers
#include <unordered_map> //open hashing
#include <unordered_set> //open hashing
#include <sstream>

//Other libraries headers

//Own components headers


struct Monster
{
    std::string name;
};

int32_t RPGGame::run()
{
    int32_t err = EXIT_SUCCESS;

    int32_t n = 0;
    std::cin >> n;

    //monster name   |    vulnerability attack types
    std::unordered_map<std::string, std::unordered_set<std::string>> monstersData;

    std::string inputLine = "";

    std::string attackType = "";
    int32_t attackInteger = 0;
    std::string monsterName = "";

    std::stringstream ss;

    //read attacks descriptions
    for(int32_t i = 0; i < n; ++i)
    {
        getline(std::cin, inputLine, ' '); //space as delimiter

        //read data from line
        ss.str(inputLine);
        ss >> attackType;
        ss >> attackInteger;

        //read all monster names vulnerable to this attack
        while(ss >> monsterName)
        {
            //no such monster found in data map
            if (monstersData.find(monsterName) == monstersData.end())
            {
                std::unordered_set<std::string> newSet;
                monstersData.insert(std::pair<std::string,
                        std::unordered_set<std::string>>(monsterName, newSet));
            }

            //add vulnerability attack to monster's data
            monstersData[monsterName].insert(attackType);
        }
    }

    //start reading input for querying
    int32_t m = 0;
    std::cin >> m;

    bool hasVulnerability = false;

    for(uint32_t j = 0; j < m; ++j)
    {
        std::cin >> monsterName;

        //const reference to avoid copying
        for (const std::string & vul: monstersData[monsterName])
        {
            std::cout << vul << " ";
            hasVulnerability = true;
        }

        if (!hasVulnerability)
        {
            std::cout << "[none]";
        }

        std::cout << std::endl;
    }

    return err;
}
