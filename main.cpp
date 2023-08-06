#include <iostream>
#include "CellularAutomata.h"

#include <cstdlib>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    cout <<"\n"  << "---------------Game of Life -------------------" << endl;
    cout << "\n Implemented By: Tarang Soni" << endl;
    cout << "                               Under the Guidance of Prof. Manish Gupta" << endl;

    CellularAutomata ca1;

    //Initialising the grid .
    //User can set the grid


     ca1.setCell( 4, 7, 1 );
     ca1.setCell( 4, 6, 1 );
     ca1.setCell( 5, 6, 1 );
     ca1.setCell( 6, 5, 1 );
     ca1.setCell( 6, 4, 1 );
     ca1.setCell( 7, 5, 1 );
     ca1.setCell( 7, 4, 1 );


     CellularAutomata ca2;

     //For Cellular Automata CA2;
    ca2.setCell( 4, 4, 1);
     ca2.setCell( 4, 6 , 1 );
     ca2.setCell( 5, 4 , 1 );
     ca2.setCell( 5, 5 , 1 );
     ca2.setCell( 5, 6 , 1 );
     ca2.setCell( 6, 5 , 1 );


    getchar();    //As soon as the user give the signal, i.e. presses key, the game

     ca1.displayGrid();

     cout << "\n" << endl;

   //ca1.behavior(1);

   cout << "Game of Life, instance 2" << endl;

   unsigned int numberOfGenerations;

   ca2.displayGrid();

    cout << "Enter the number of Generations you want the life in the initial configuration, you want to evolve By: " << endl;
    scanf("%u", &numberOfGenerations );


    cout << "\n" << endl;

    ca2.behavior_gameOfLife(numberOfGenerations);

    int numberOfAliveCells0;
    int set_row, set_column;


    CellularAutomata ca3;
    cout << "You can set your own configuration! "<< endl;




    cout << "Enter the number of cells that you want to be alive, initially:   ";
    cin >>numberOfAliveCells0;

    cout << "--Position to be entered in [ <row> <space> <column>] form) --" << endl;
   cout << "\n" << endl;

   for(int i=0; i<numberOfAliveCells0; i++)
   {
       cout << "Enter position#" << i << ": ";
       scanf("%d %d", &set_row, &set_column);

       ca3.setCell(set_row + (LIMIT_LENGTH)/2, set_column, 1);

   }

  cout << "---" << endl;

   ca3.displayGrid();


   cout << "Enter the number of generations: " << endl;
    scanf("%u", &numberOfGenerations);

   ca3.behavior_gameOfLife(numberOfGenerations);

    ca3.displayGrid();



    return 0;

}
