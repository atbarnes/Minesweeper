#ifndef MINESQUARE_H
#define MINESQUARE_H

#include <square.h>

using namespace std;

class minesquare : public square
{
    public:
        minesquare();
        virtual ~minesquare();

        string getMineSquare(){return element;};

        bool uncoverSquare(); //uncovers square
        bool amMine(); //Checks if square is a mine

    protected:
    private:

};

#endif // MINESQUARE_H
