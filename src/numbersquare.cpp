#include "numbersquare.h"

using namespace std;

numbersquare::numbersquare()
{
    element = "_";
    uncovered_ = false;
    flagged_ = false;
}

numbersquare::numbersquare(int x, int y)
{
    element = "_";
    uncovered_ = false;
    flagged_ = false;
    xVal = x;
    yVal = y;
}

numbersquare::~numbersquare()
{
    //dtor
}

bool numbersquare::uncoverSquare()
{
    uncovered_ = true;
    return uncovered_;
}

bool numbersquare::amMine()
{
    return false;
}
//Increments number based on how many mines are adjacent
void numbersquare::increment()
{
    numVal++;
    ostringstream convert;
    convert << numVal;
    element = convert.str();
}
