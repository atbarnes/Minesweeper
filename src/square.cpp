#include "square.h"

square::square()
{
    //ctor
}

square::~square()
{
    //dtor
}

void square::flagsquare()
{
    if (flagged_ == true)
    {
        flagged_ = false;
    }
    else
    {
        flagged_ = true;
    }
}

void square::clearsquare()
{
    flagged_ = false;
}

bool square::isUncovered()
{
    return uncovered_;
}

string square::getSquare()
{
    if (uncovered_ == true)
    {
        return element;
    }
    else if (flagged_ == true)
    {
        return "f";
    }

    else
    {
        return "x";
    }

}
