#include "minesquare.h"


minesquare::minesquare()
{
    element = "*";
}

minesquare::~minesquare()
{
    //dtor
}

bool minesquare::uncoverSquare()
{
    uncovered_ = true;
}

bool minesquare::amMine()
{
    return true;
}
