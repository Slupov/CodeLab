/**
 *  @brief
 *  @date 01.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "FileStreams.h"

//C system headers

//C++ system headers
#include <iostream>
#include <fstream>
#include <vector>

#include <sstream>
#include <string>

//Other libraries headers

//Own components headers

/**
 *  @brief Writes lines to a file
 *  @date 01.02.19
 */
void writeToFile()
{
    std::cout << "WRITING TO A FILE\n";

    std::ofstream myfile;
    myfile.open("../ofstream_test.txt", std::ios::out | std::ios::app);

    if(myfile.is_open())
    {
        /* ok, proceed with output */
        myfile << "Writing something simple to a file.\n";
        myfile << "Will you come with me if outside is shiban stud ?!\n";

        myfile.close();
    }
}

/**
 *  @brief Reads lines from a file
 *  @date 01.02.19
 */
void readFromFile()
{
    std::ifstream myfile;
    myfile.open("../ofstream_test.txt");

    std::string line;

    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            std::cout << line << '\n';
        }

        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
}

class CSVRow
{
    public:
        std::string const & operator[](std::size_t index) const
        {
            return row_cells[index];
        }

        std::size_t size() const
        {
            return row_cells.size();
        }

        void readNextRow(std::istream & outStr)
        {
            std::string line;
            std::getline(outStr, line);

            std::stringstream lineStream(line);
            std::string cell;

            row_cells.clear();
            while(std::getline(lineStream, cell, ','))
            {
                row_cells.push_back(cell);
            }

            // This checks for a trailing comma with no data after it.
            if(!lineStream && cell.empty())
            {
                // If there was a trailing comma then add an empty element.
                row_cells.emplace_back("");
            }
        }

    private:
        std::vector<std::string> row_cells;
};

std::istream & operator>>(std::istream & str, CSVRow & data)
{
    data.readNextRow(str);
    return str;
}

int32_t FileStreams::run()
{
    writeToFile();
    readFromFile();

    std::ifstream file("../../studies/mkk_algorithms/test.csv");

    CSVRow row;

    while(file >> row)
    {
        std::cout << "4th Element(" << row[3] << ")\n";
    }

    return EXIT_SUCCESS;
}