#ifndef GRID_H
#define GRID_H

#include "square.h"
#include "minesquare.h"
#include "numbersquare.h"
#include <queue>

class grid
{
    public:
        grid();
        grid(int h, int w, int m); //height, width, number of mines
        virtual ~grid();

        void display();
        bool uncover(int x, int y); //Uses the square classes to uncover grid squares
        void flag(int x, int y);    //Uses the square classes to flag grid squares
        int getSquaresLeft(){return squaresLeft;} //Used to check how many numbers are still in play

        square ***g;
        numbersquare * nsq; //Used for downcasting
        queue <square*> neighbors;  //Queues used for neighbor squares and blank neighbor squares
        queue <numbersquare*> blanks;

    protected:
    private:
        void checkNeighbors();  //private functions used for getting the neighbors and checking neighbors
        void getNeighbors(int x, int y);
        int height;
        int width;
        int numMines;
        int squaresLeft; //Used to check how many numbers are still in play
};

#endif // GRID_H
