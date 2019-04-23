#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_COVEREDAREA_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_COVEREDAREA_H



/**
 *  @brief
 *  @date 16.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "studies/StudiesProblem.h"

#define DISKS_COUNT 5

class CoveredArea : public StudiesProblem
{
    struct Disk
    {
        float x, y;
        float radius;
    };

    public:
        CoveredArea();

        virtual int32_t run() override;

        float coveredArea(Disk disks[DISKS_COUNT]);

        float getDiskArea(const Disk & disk);

        float getIntersectedDisksArea(const Disk & disk1, const Disk & disk2);

        bool areIntersected(const Disk & disk1, const Disk & disk2);

        bool isInDisk(const float x, const float y,
                      const CoveredArea::Disk & disk);

        virtual ~CoveredArea() override = default;

    private:
        //current Overlapping Circles Distance (so we dont recalculate it twice)
        float _D;
};


#endif //CODELAB_STUDIES_MKK_ALGORITHMS_FINAL_EXAM_COVEREDAREA_H
