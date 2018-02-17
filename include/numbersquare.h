#ifndef NUMBERSQUARE_H
#define NUMBERSQUARE_H

#include <square.h>
#include <sstream>

using namespace std;

class numbersquare : public square
{
    public:
        numbersquare();
        numbersquare(int x, int y);
        virtual ~numbersquare();

        string getNumberSquare(){return element;}
        int getX(){return xVal;}
        int getY(){return yVal;}
        void increment();

        bool uncoverSquare();
        bool amMine();

    protected:

    private:
        int numVal = 0;
        int xVal;
        int yVal;
};

#endif // NUMBERSQUARE_H
