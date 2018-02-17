#include "minesweeper.h"

#include <iostream>

using namespace std;

minesweeper::minesweeper()
{
    //Ask for level of difficulty
    string input;
    cout << "What level would you like to play?" << endl;
    cout << "1 - Beginner, 2 - Intermediate, 3 - Advanced, 0 - Quit" << endl;
    cin >> input;

    //Creates the grid dynamically depending on the level of difficulty

    if (input.compare("1") == 0)
    {
        g = new grid(8, 8, 5);
        cout << "Level 1 about to begin!" << endl;
    }

    else if (input.compare("2") == 0)
    {
        g = new grid(16, 16, 40);
        cout << "Level 2 about to begin!" << endl;
    }

    else
    {
        g = new grid(16, 30, 99);
        cout << "Level 3 about to begin!" << endl;
    }
    //Keeps playing the game while input isn't equal to 0
    while  (input.compare("0") != 0)
    {
        char a;
        int b, c;
        g->display();

        cout << "\n" << "What next?" << endl;
        cout << "Options: (U)ncover r c, (F)lag r c, (Q)uit" << endl;

        cin >> a;
        if (a == 'Q' || a == 'q')
        {
            cout << "Thanks for playing!";
            input = "0";    //Ends session
        }

        else if (a == 'F' || a == 'f')
        {
            cin >> b;
            cin >> c;
            g->flag(b, c);      //Flag the square

        }

        else
        {
            cin >> b;       //Get the numbers
            cin >> c;
            bool mine = g->uncover(b, c);
            if (mine == true)   //If the square you just uncovered is mine, end the session
            {
                g->display();
                cout << "\n" << "Better luck next time!";
                input = "0";
            }

            if (g->getSquaresLeft() == 0)
            {
                cout << "\n" << "Congratulations! You avoided all the mines!";
                input = "0";
            }
        }
    }

    //While input is not equal to 0, play game
}

minesweeper::~minesweeper()
{
    //dtor
}
