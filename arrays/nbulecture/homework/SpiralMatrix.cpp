/**
 *  @brief
 *  @date 04.11.18
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "SpiralMatrix.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

#define UNPOPULATED_CELL INT32_MIN

void SpiralMatrix::solve()
{
    initData();

    const int32_t ELEMENTS_COUNT = _rows * _dataSizes[0];

    //start from [0,0]
    int32_t row = 0;
    int32_t col = 0;

    //Start with Direction::Right
    _xSpeed = 1;
    _ySpeed = 0;

    for(int32_t i = 1; i <= ELEMENTS_COUNT; ++i)
    {
        _data[row][col] = i;

        //change direction, row and col
        if(_xSpeed == 1) //Direction::Right
        {
            //check for out-of-bounds or set element to the right
            if((col == _dataSizes[row] - 1) ||
               (_data[row][col + 1] != UNPOPULATED_CELL))
            {
                //Direction::Down
                _xSpeed = 0;
                _ySpeed = 1;
            }
        }
        else if(_ySpeed == 1) //Direction::Down
        {
            //check for out-of-bounds or set element below
            if((row == _rows - 1) ||
               (_data[row + 1][col] != UNPOPULATED_CELL))
            {
                //Direction::Left
                _xSpeed = -1;
                _ySpeed = 0;
            }
        }
        else if (_xSpeed == -1) //Direction::Left
        {
            //check for out-of-bounds or set element to the left
            if((col == 0) || (_data[row][col - 1] != UNPOPULATED_CELL))
            {
                //Direction::Up
                _xSpeed = 0;
                _ySpeed = -1;
            }
        }
        else if(_ySpeed == -1) //Direction::Up
        {
            //check for set element above
            /**Note - no need to check for out-of-bounds since first row is
             * populated first **/
            if(_data[row - 1][col] != UNPOPULATED_CELL)
            {
                //Direction::Right
                _xSpeed = 1;
                _ySpeed = 0;
            }
        }

        //change current row and col
        row += _ySpeed;
        col += _xSpeed;
    }
}

void SpiralMatrix::initData()
{
    printf("Enter n for row_cells and cols: ");
    std::cin >> _rows;

    _data      = new int32_t * [_rows];
    _dataSizes = new int32_t[_rows];

    for(int32_t row = 0; row < _rows; ++row)
    {
        _dataSizes[row] = _rows;
        _data[row]      = new int32_t[_rows];

        for(int32_t col = 0; col < _rows; ++col)
        {
            _data[row][col] = UNPOPULATED_CELL;
        }
    }

    _xSpeed = 0;
    _ySpeed = 0;
}

void SpiralMatrix::initDataSimple()
{
    initData();
}

void SpiralMatrix::initRandomData()
{
    initData();
}

void SpiralMatrix::printArray()
{
    for(int32_t r = 0; r < _rows; ++r)
    {
        for(int32_t i = 0; i < _dataSizes[r]; ++i)
        {
            printf("%5d ", _data[r][i]);
        }

        printf("\n");
    }
}
