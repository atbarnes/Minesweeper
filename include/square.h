#ifndef SQUARE_H
#define SQUARE_H
#include <string>

using namespace std;

class square
{
    public:
        square();
        virtual ~square();
        void flagsquare();
        void clearsquare();

        string getUncoveredSquare(){return element;}
        string getSquare();

        bool isUncovered();
        virtual bool uncoverSquare() = 0; //uncovers square
        virtual bool amMine() = 0;  //Checks if square is a mine

    protected:
        bool flagged_ = false;
        bool uncovered_ = false;
        string element;
    private:

};

#endif // SQUARE_H
