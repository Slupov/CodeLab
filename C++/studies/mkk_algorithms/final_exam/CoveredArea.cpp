/**
 *  @brief
 *  @date 16.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "CoveredArea.h"

//C system headers

//C++ system headers
#include <cmath>

//Other libraries headers

//Own components headers

#define AREA_W 1.0f
#define AREA_H 1.0f

CoveredArea::CoveredArea(): _D(0)
{

}


//дисковете може да се застъпват, може и да излизат извън правоъгълната площ!!!
int32_t CoveredArea::run()
{
    int32_t err = EXIT_SUCCESS;

    Disk disks[5];
//    disks[0].x = 0;
//    disks[0].y = 0;
//    disks[0].radius = 0;
//
//    disks[1].x = 0;
//    disks[1].y = 0;
//    disks[1].radius = 0;
//
//    disks[2].x = 0;
//    disks[2].y = 0;
//    disks[2].radius = 0;
//
//    disks[3].x = 0;
//    disks[3].y = 0;
//    disks[3].radius = 0;
//
//    disks[4].x = 0;
//    disks[4].y = 0;
//    disks[4].radius = 0;

    std::cout << coveredArea(disks);
    return err;
}

float getDistance(const float toX, const float fromX,
        const float toY, const float fromY)
{
    return static_cast<float>(
            sqrt((toX - fromX) * (toX - fromX) +
            (toY - fromY) * (toY - fromY)));
}

float CoveredArea::coveredArea(CoveredArea::Disk * disks)
{
    float result = 0.0f;

    //stores whether a given disk is being overlapped
    bool isOverlappingWithOther[DISKS_COUNT];

    //check for intersecting disks
    for(uint32_t i = 0; i < DISKS_COUNT; ++i)
    {
        isOverlappingWithOther[i] = false;

        for(uint32_t j = 0; j < DISKS_COUNT; ++j)
        {
            //same disks
            if (i == j)
            {
                continue;
            }

            //check if they are overlapping
            if (areIntersected(disks[i], disks[j]))
            {
                isOverlappingWithOther[i] = true;
                isOverlappingWithOther[j] = true;

                result += getIntersectedDisksArea(disks[i], disks[j]);
            }
        }

        //add its area only if its not overlapping with others
        if (!isOverlappingWithOther[i])
        {
            result += getDiskArea(disks[i]);
        }

        //TODO Subtract disks[i]'s area that is out of the whole area rectangle.
        //Use circular segment area formula
        // A = R^2/2(Alpha - sin(Alpha)) = ...
    }

    return result;
}

bool CoveredArea::isInDisk(const float x, const float y,
                           const CoveredArea::Disk & disk)
{
    return getDistance(disk.x, x, disk.y, y) <= disk.radius;
}

float CoveredArea::getDiskArea(const CoveredArea::Disk & disk)
{
    return static_cast<float>(M_PI * disk.radius * disk.radius);
}

float CoveredArea::getIntersectedDisksArea(const CoveredArea::Disk & disk1,
                                           const CoveredArea::Disk & disk2)
{
    // Area according to Heron's formula
    //----------------------------------
    float a1 = _D + disk1.radius + disk2.radius;
    float a2 = _D + disk1.radius - disk2.radius;
    float a3 = _D - disk1.radius + disk2.radius;
    float a4 = -_D + disk1.radius + disk2.radius;

    return std::sqrt(a1 * a2 * a3 * a4) / 4;
}

bool CoveredArea::areIntersected(const CoveredArea::Disk & disk1,
                                 const CoveredArea::Disk & disk2)
{
    const float ADDANT_1 = disk1.x - disk2.x;
    const float ADDANT_2 = disk1.y - disk2.y;

    //Distance between two circles centers
    _D = std::sqrt(ADDANT_1 * ADDANT_1 + ADDANT_2 * ADDANT_2);

    //get abs value of radius difference
    float radiusDiff = disk1.radius - disk2.radius;
    if (radiusDiff < 0)
    {
        radiusDiff *= -1;
    }

    return (disk1.radius + disk2.radius > _D) &&
           (_D > radiusDiff);
}