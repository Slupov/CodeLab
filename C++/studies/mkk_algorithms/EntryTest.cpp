#include <iostream>

/**
 *  @brief
 *  @date 02.02.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "EntryTest.h"

//C system headers

//C++ system headers
#include <climits>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

//Other libraries headers

//Own components headers

//-----------------------------PROBLEM 1----------------------------------------

#define PIXEL_COMPONENTS 3
#define MAX_PIXEL_VALUE 255

int32_t problemOne()
{
    //no value range given so we use long integer
    int64_t biggestNum = LONG_MIN;
    int64_t secondBiggestNum = LONG_MIN;

    int64_t inputCount = 0;
    int64_t temp = LONG_MIN;

    while(std::cin >> temp && !std::cin.eof())
    {
        if(temp > biggestNum)
        {
            secondBiggestNum = biggestNum;
            biggestNum = temp;
        }

        ++inputCount;
    }

    if(inputCount == 1 || secondBiggestNum == biggestNum)
    {
        std::cout << "There are no two different numbers in the input!"
                  << std::endl;

        return EXIT_FAILURE;
    }

    std::cout << "Biggest number = " << biggestNum << std::endl;
    std::cout << "Second biggest number = " << secondBiggestNum << std::endl;

    return EXIT_SUCCESS;
}
//-----------------------------PROBLEM 1----------------------------------------

//-----------------------------PROBLEM 2----------------------------------------

// Returns the absolute value of n - mid * mid * mid
double diff(double num, double mid)
{
    if(num > (mid * mid * mid))
    {
        return (num - (mid * mid * mid));
    }
    else
    {
        return ((mid * mid * mid) - num);
    }
}

int32_t problemTwo()
{
    //no value range given so we use long integer
    double num = 0;
    std::cin >> num;

    // Set start and end for binary search
    double start = 0;
    double end = num;

    // Set precision
    const double E = 0.0000001;

    double mid = 0;
    double error = 0;

    while(true)
    {
        mid = (start + end) / 2;
        error = diff(num, mid);

        // If error is less than E then mid is our answer so return mid
        if(error <= E)
        {
            break;
        }

        // If mid * mid * mid is greater than n set end = mid
        if((mid * mid * mid) > num)
        {
            end = mid;
        }
        else
        {
            // If mid * mid * mid is less than n set start = mid
            start = mid;
        }
    }

    std::cout << "Cubic root of " << num << " = " << mid << std::endl;
    return EXIT_SUCCESS;
}

//-----------------------------PROBLEM 2----------------------------------------

//-----------------------------PROBLEM 3----------------------------------------

int32_t problemThree()
{
    uint32_t n = 0;
    std::cin >> n;

    //memory allocation
    int64_t * arr = new int64_t[n];

    uint32_t subsetsCount = 1;

    //pow(2, n)
    for(uint32_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        subsetsCount *= 2;
    }

    std::vector<std::vector<int64_t>> subsets;
    subsets.resize(subsetsCount);

    /* Run counter i from 000..0 to 111..1*/
    for (uint32_t i = 0; i < subsetsCount; i++)
    {
        subsets[i].reserve(n);

        //consider each element in the set
        for (uint32_t j = 0; j < n; j++)
        {
            // Check if jth bit in the i is set. If the bit
            // is set, we consider jth element from set
            if ((i & (1 << j)) != 0)
            {
                subsets[i].emplace_back(arr[j]);
            }
        }

        //print subset
        std::cout << "Printing subset [" << i << "]: ";

        for (int64_t num: subsets[i])
        {
            std::cout << num << " ";
        }

        std::cout << std::endl;
    }


    //memory deallocation
    delete[] arr;
    arr = nullptr;

    return EXIT_SUCCESS;
}
//-----------------------------PROBLEM 3----------------------------------------

//-----------------------------PROBLEM 4----------------------------------------

int32_t problemFour()
{
    std::string current;
    std::cin >> current;

    std::string prev;

    int32_t currentSize = current.size();

    int32_t count = 0;
    std::string type = "1";

    int32_t idx = 0;

    while(true)
    {
        //odd means end of execution
        if (currentSize % 2 != 0)
        {
            break;
        }

        for(int32_t i = 0; i < currentSize - 1; i+=2)
        {
            type.clear();

            count = current[i] - '0';
            type.push_back(current[i + 1]);

            //append that many types
            for(uint32_t j = 0; j < count; ++j)
            {
                prev.append(type);
            }
        }

        ++idx;
        current = prev;

        prev.clear();
        currentSize = current.size();
    }

    std::cout << current << " " << (idx + 1) << std::endl;
}

//-----------------------------PROBLEM 4----------------------------------------


//-----------------------------PROBLEM 5----------------------------------------
struct PVector
{
    int32_t startX;
    int32_t startY;

    int32_t endX;
    int32_t endY;

    /** Note: using integers only will not provide pixel perfect precision but
      * it is a sensible tradeoff for calculation simplicity **/
    int32_t getXAt(const int32_t y)
    {
        int32_t scalar = y / endY; // TODO: FIX division by 0
        return endX * scalar;
    }
};

int32_t problemFive()
{
    PVector ballTrajectory;
    std::cout << "Enter startX and startY of ball trajectory: ";
    std::cin >> ballTrajectory.startX >> ballTrajectory.startY;

    std::cout << "Enter endX and endY of ball trajectory: ";
    std::cin >> ballTrajectory.endX >> ballTrajectory.endY;

    PVector playerPaddle;
    std::cout << "Enter startX and startY of player paddle: ";
    std::cin >> playerPaddle.startX >> playerPaddle.startY;

    std::cout << "Enter endX and endY of player paddle: ";
    std::cin >> playerPaddle.endX >> playerPaddle.endY;

    //check for collision
    const int32_t BALL_X_AT_PADDLE_Y =
            ballTrajectory.getXAt(playerPaddle.startY);

    const bool HAS_COLIDED = (BALL_X_AT_PADDLE_Y >= playerPaddle.startX &&
                              BALL_X_AT_PADDLE_Y <= playerPaddle.endX);

    if (!HAS_COLIDED)
    {
        std::cout << "Ball not colliding with paddle" << std::endl;
        return EXIT_SUCCESS;
    }

    //calculate bounce trajectory
    PVector bounceTrajectory;
    bounceTrajectory.startX = BALL_X_AT_PADDLE_Y;
    bounceTrajectory.startY = playerPaddle.startY;

    const int32_t FIRST_TRAJECTORY_WIDTH =
            BALL_X_AT_PADDLE_Y - ballTrajectory.startX;

    bounceTrajectory.endX = BALL_X_AT_PADDLE_Y + FIRST_TRAJECTORY_WIDTH;
    bounceTrajectory.endY = ballTrajectory.startY;


    std::cout << "Bounce trajectory startX: " << bounceTrajectory.startX
              << " startY: " << bounceTrajectory.startY << " endX: "
              << ballTrajectory.endX << " endY: " << bounceTrajectory.endY
              << std::endl;

    return EXIT_SUCCESS;
}

//-----------------------------PROBLEM 5----------------------------------------

//-----------------------------PROBLEM 6----------------------------------------

struct Pixel
{
        int32_t components [PIXEL_COMPONENTS];

        Pixel()
        {
            alteredValueIdx = 0;
        }

        double getIntensity()
        {
            double result = components[0] + components[1] + components[2];
            return result / PIXEL_COMPONENTS;
        }

        void alterPixel(const bool higher)
        {
            if (higher)
            {
                while(components[alteredValueIdx] == 0)
                {
                    alteredValueIdx = static_cast<uint8_t>(
                            (alteredValueIdx + 1) % PIXEL_COMPONENTS);
                }

                --components[alteredValueIdx];
            }
            else
            {
                while(components[alteredValueIdx] == 255)
                {
                    alteredValueIdx = static_cast<uint8_t>(
                            (alteredValueIdx + 1) % PIXEL_COMPONENTS);
                }

                ++components[alteredValueIdx];
            }

            alteredValueIdx = static_cast<uint8_t>(
                    (alteredValueIdx + 1) % PIXEL_COMPONENTS);
        }

    private:
        //points to either this.r, this.g, this.b
        //switches between them on every alterPixel call for a more distributed
        //alteration

        uint8_t alteredValueIdx;
};

int32_t problemSix()
{
    uint32_t width = 0;
    uint32_t height = 0;

    std::cout << "Enter width and height: " << std::endl;
    std::cin >> width >> height;

    const uint32_t PIXELS_CNT = width * height;

    std::vector<Pixel> pixels;
    pixels.resize(PIXELS_CNT);

    for(uint32_t i = 0; i < PIXELS_CNT; ++i)
    {
        std::cin >> pixels[i].components[0]
                 >> pixels[i].components[1]
                 >> pixels[i].components[2];

        if (pixels[i].components[0] > MAX_PIXEL_VALUE ||
            pixels[i].components[1] > MAX_PIXEL_VALUE ||
            pixels[i].components[2] > MAX_PIXEL_VALUE)
        {
            std::cout << "WRONG INPUT DATA" << std::endl;
            std::cout << "PIXEL COMPONENT CANNOT BE HIGHER THAN "
                      << MAX_PIXEL_VALUE << std::endl;

            return EXIT_FAILURE;
        }
    }

    const double FIRST_INTENSITY = pixels[0].getIntensity();
    double currentPixelIntensity = 0;

    std::cout << "Wanted intensity: " << FIRST_INTENSITY << std::endl;

    //Pixel intensity - the average of all components
    for(uint32_t i = 0; i < PIXELS_CNT; ++i)
    {
        currentPixelIntensity = pixels[i].getIntensity();

        while(FIRST_INTENSITY != currentPixelIntensity)
        {
            pixels[i].alterPixel(FIRST_INTENSITY < currentPixelIntensity);
            currentPixelIntensity = pixels[i].getIntensity();
        }

        //print pixels
        std::cout << "Pixel [" << i << "]: " << pixels[i].components[0] << " "
                  << pixels[i].components[1] << " " << pixels[i].components[2]
                  << std::endl;
    }

    return EXIT_SUCCESS;
}

//-----------------------------PROBLEM 6----------------------------------------

//-----------------------------PROBLEM 7----------------------------------------

bool compareNoCase(const std::string& s1, const std::string& s2)
{
    std::string s1Cpy = s1;
    std::string s2Cpy = s2;

    for(uint32_t i = 0; i < s1.size(); ++i)
    {
        s1Cpy[i] = std::tolower(s1[i]);
    }

    for(uint32_t i = 0; i < s2.size(); ++i)
    {
        s2Cpy[i] = std::tolower(s2[i]);
    }

    return (s1Cpy < s2Cpy);
}

int32_t problemSeven()
{
    std::string path;

    std::cout << "Enter the path to the file to read: ";
    std::cin >> path;

    std::ifstream inputFile;
    inputFile.open(path);

    std::vector<std::string> readWords;
    std::string readLine;

    if(inputFile.is_open())
    {
        while(getline(inputFile, readLine))
        {
            std::stringstream lineStream(readLine);
            std::string word;

            while(std::getline(lineStream, word, ' '))
            {
                readWords.push_back(word);
            }

            // This checks for a trailing comma with no data after it.
            if(!lineStream && word.empty())
            {
                // If there was a trailing space then add an empty element.
                readWords.emplace_back("");
            }
        }

        inputFile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        return EXIT_FAILURE;
    }

    //sort read words alphabetically
    std::sort(readWords.begin(), readWords.end(), compareNoCase);

    //write sorted words in another file
    std::cout << "Enter the path to the file to write to: ";
    std::cin >> path;

    std::ofstream outputFile;
    outputFile.open(path);

    if(outputFile.is_open())
    {
        /* ok, proceed with output */
        for (std::string & str: readWords)
        {
            outputFile << str << "\n";
        }

        inputFile.close();
    }
    else
    {
        std::cout << "Unable to open file to write" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

//-----------------------------PROBLEM 7----------------------------------------

int32_t EntryTest::run()
{
    int32_t returnCode = EXIT_FAILURE;
    returnCode = problemOne();
//    returnCode = problemTwo();
//    returnCode = problemThree();
//    returnCode = problemFour();
//    returnCode = problemFive();
//    returnCode = problemSix();
//    returnCode = problemSeven();
    return returnCode;
}
