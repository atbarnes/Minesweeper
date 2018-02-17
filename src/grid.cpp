#include "grid.h"

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <queue>

using namespace std;

grid::grid()
{

}

grid::grid(int h, int w, int m)
{
    //Random Number generator
    srand( time(NULL) );
    int randNumX;
    int randNumY;

    //Set height, width, numMines
    height = h;
    width = w;

    numMines = m;
    squaresLeft = (height * width) - numMines;
    //Create grid
    g = new square**[height];
    for (int i = 0; i < height; i++)
    {
        g[i] = new square*[width];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            g[i][j] = new numbersquare(i, j);
        }
    }
    //create mines
    for (int i = 0; i < numMines; i++)
    {
        randNumX = rand() % height;
        randNumY = rand() % width;
        square * s = g[randNumX][randNumY];
        if (s->amMine()== false)
        {
            g[randNumX][randNumY] = new minesquare();
        }
        else
        {
            i--;
        }
    }
   for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            square *sq = g[i][j];
            if (sq->amMine() == true)
            {

            }

            else
            {
                nsq = dynamic_cast<numbersquare*>(sq);
                getNeighbors(i, j);
                checkNeighbors();

            }

        }
    }




}

grid::~grid()
{
    //dtor
}

void grid::display()
{
    cout << "  ";

    for (int i = 0; i < width; i++)
    {
        cout << " " << i % 10;
    }

    for(int i = 0; i < height; i++)
    {
        cout << "\n" << i % 10 << " ";

        for(int j = 0; j < width; j++)
        {
            cout << " " << g[i][j]->getSquare();
        }
    }
}

bool grid::uncover(int x, int y)
{
    int i = x;
    int j = y;
    square * q = g[i][j];
    //Checks if square is already uncovered
    if (g[i][j]->isUncovered() == true)
    {

    }

    else
    {
        q->uncoverSquare(); //Uncover the square
        squaresLeft--;
    }

    if(q->getSquare().compare("*") == 0)        //If it is a mine, uncover and return true
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if (g[i][j]->getUncoveredSquare().compare("*") == 0)
                {
                    g[i][j]->uncoverSquare();
                }

            }
        }

        return true;
    }

    else    //Else, check if neighbors are blank too
    {
        nsq = dynamic_cast<numbersquare*>(q);
        if(nsq->getNumberSquare().compare("_") == 0)
        {
            getNeighbors(i, j);
            for (int i = neighbors.size(); i > 0; i--)
            {
                numbersquare * n = dynamic_cast<numbersquare*>(neighbors.front());
                if(n->getNumberSquare().compare("_") == 0 && n->isUncovered( ) == false)  //If neighbor is _ add to blank queue and uncover
                {
                        blanks.push(n);
                        g[n->getX()][n->getY()]->uncoverSquare();
                        squaresLeft--;
                }

                else if (n->isUncovered() == false)
                {
                    g[n->getX()][n->getY()]->uncoverSquare(); //Else just uncover it
                    squaresLeft--;
                }

                else
                {

                }

                neighbors.pop();

            }
        }


    }
    //Goes through the covered blanks and uncovers them
    while (blanks.size() != 0)
    {

        numbersquare * b = blanks.front();
        blanks.pop();
        uncover(b->getX(), b->getY());
    }

    return false;   //Used to check if program uncovered a mine

}

void grid::flag(int x, int y)
{
    int xx = x;
    int yy = y;
    g[xx][yy]->flagsquare();
}
//Function for getting all the neighbors of a square
void grid::getNeighbors(int x, int y)
{
    int i = x;
    int j = y;

    if(nsq->getX() == 0 && nsq->getY() == 0)
    {
        neighbors.push(g[i+1][j]);
        neighbors.push(g[i+1][j+1]);
        neighbors.push(g[i][j+1]);
    }

    else if(nsq->getX() == height-1 && nsq->getY() == 0)
    {
        neighbors.push(g[i-1][j]);
        neighbors.push(g[i-1][j+1]);
        neighbors.push(g[i][j+1]);
    }

    else if(nsq->getX() == 0 && nsq->getY() == width-1)
    {
        neighbors.push(g[i][j-1]);
        neighbors.push(g[i+1][j-1]);
        neighbors.push(g[i+1][j]);
    }

    else if(nsq->getX() == height-1 && nsq->getY() == width-1)
    {
        neighbors.push(g[i-1][j]);
        neighbors.push(g[i-1][j-1]);
        neighbors.push(g[i][j-1]);
    }

    else if (nsq->getY() == 0)
    {
        neighbors.push(g[i-1][j]);
        neighbors.push(g[i-1][j+1]);
        neighbors.push(g[i][j+1]);
        neighbors.push(g[i+1][j+1]);
        neighbors.push(g[i+1][j]);
    }

    else if (nsq->getX() == 0)
    {
        neighbors.push(g[i][j-1]);
        neighbors.push(g[i+1][j-1]);
        neighbors.push(g[i+1][j]);
        neighbors.push(g[i+1][j+1]);
        neighbors.push(g[i][j+1]);
    }

    else if (nsq->getX() == height-1)
    {
        neighbors.push(g[i][j-1]);
        neighbors.push(g[i-1][j-1]);
        neighbors.push(g[i-1][j]);
        neighbors.push(g[i-1][j+1]);
        neighbors.push(g[i][j+1]);
    }

    else if (nsq->getY() == width-1)
    {
        neighbors.push(g[i-1][j]);
        neighbors.push(g[i-1][j-1]);
        neighbors.push(g[i][j-1]);
        neighbors.push(g[i+1][j-1]);
        neighbors.push(g[i+1][j]);
    }

    else
    {
        neighbors.push(g[i-1][j]);
        neighbors.push(g[i-1][j-1]);
        neighbors.push(g[i][j-1]);
        neighbors.push(g[i+1][j-1]);
        neighbors.push(g[i+1][j]);
        neighbors.push(g[i+1][j+1]);
        neighbors.push(g[i][j+1]);
        neighbors.push(g[i-1][j+1]);
    }
}
//Function for checking the neighbors and if it is a mine, increment number square
void grid::checkNeighbors()
{
    for (int i = neighbors.size(); i > 0; i--)
    {
        square * squ = neighbors.front();
        if (squ->getUncoveredSquare().compare("*") == 0)
        {
            nsq->increment();
        }

        neighbors.pop();
    }
    g[nsq->getX()][nsq->getY()] = nsq;
}
