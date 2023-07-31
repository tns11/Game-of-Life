#include "CellularAutomata.h"
#include <stdlib.h>
#include <Stack.h>


#include <iostream>

CellularAutomata::CellularAutomata()
 {
        limit_length = LIMIT_LENGTH;

    // Dynamic memory  alloction using calloc
         /* grid_Begin = (int *) calloc(limit_length*limit_length, sizeof(int)); */

   // Initialising the memory for the grid, using the new operator
     grid_Begin = new int [limit_length*limit_length]();

  // array, or equivalently, matrix, and grid, neighbourhood's purpose is to
    neighbourhood = new int[limit_length*limit_length]();        //  keep the information about neighbourhood



 }


void CellularAutomata::setCell(int row, int column, int value)
{

  if(row < limit_length && column < limit_length)
    *( grid_Begin + (row -1)*limit_length + (column - 1)) = value;
}

int CellularAutomata::readCell(int row, int column)
{
    if(row <= limit_length && column <= limit_length)
       return *(grid_Begin+ (row - 1)*limit_length + (column - 1));

    else
        return 0;         //Beyond boundaries, it is, at-least as if, cells are not present...

}

int CellularAutomata::behavior(unsigned int i = 100)
{

    static int iteration  = 0;

    for(int i=0; i<limit_length; i++)
        for(int j = 0; j<limit_length; j++)
    {
        if(*(grid_Begin + i*limit_length + j + 1) == 1)
        *(grid_Begin + i*limit_length + j) = 0;

       else
        *(grid_Begin + i*limit_length + j) = 1;

    }

      iteration++;

          return iteration;


}


 void CellularAutomata::countNeighbourhood()
  {

        for(int i=0; i<limit_length; i++)
        {
                for(int j=0; j<limit_length;  j++)
                   {

                         if( readCell( i + 1,  j + 1) > 0 )      //The value at grid  position of the grid of cellular automata, being positive, represents the presence at that position of cell  //
                            {

                                ++neighbourhood[ ( i - 1 )*limit_length + ( j -1 )   ];
                                ++neighbourhood[ ( i - 1 )*limit_length + (   j  )    ];
                                ++neighbourhood[ ( i - 1 )*limit_length + ( j + 1 ) ];

                                ++neighbourhood[ (   i   )*limit_length + ( j - 1 )   ];
                                ++neighbourhood[ (   i   )*limit_length + ( j + 1)   ];

                                ++neighbourhood[ ( i + 1 )*limit_length + ( j - 1 )  ];
                                ++neighbourhood[ ( i + 1 )*limit_length +  (   j   )   ];
                                ++neighbourhood[ ( i + 1 )*limit_length +  ( j + 1 ) ];

                            }

                   }

            }

  }



  //The method for updating the cells is implemented as follows.
  // Note, this process of updating follows the rules of Cellular Automata

 void CellularAutomata::updateCells( )
   {

            for(int i=0; i<limit_length; i++)
               for(int j=0; j<limit_length; j++)
                    {
                             //Case1: The cell does not exist
                                 if(readCell(i + 1, j +1) == 0)
                                   {
                                       if(neighbourhood[i*limit_length + j] == 3)
                                          {
                                             setCell(i + 1, j + 1, 1);   //the cell is, born
                                             std::cout << "The cell appears, alive" << std::endl;
                                          }
                                   }

                             //Case2: The cell is alive
                                 if(readCell(i + 1, j +1) == 1)
                                   {
                                            if(neighbourhood[i*limit_length + j] < 2  || neighbourhood[i*limit_length + j] > 3)
                                              {
                                                  setCell(i + 1, j + 1, 0);   // the cell does not exist, any more as a rule of the present game
                                                  std::cout << "The cell is not existent, more" << std::endl;
                                              }
                                    }

                    }

   }


int CellularAutomata::behavior_gameOfLife(unsigned int iterations)
{
    static unsigned int iterationNo;

         iterationNo = 1;

         std::cout << "Generation0: "<< std::endl;
         displayGrid();

         while (iterationNo < iterations + 1)
         {


                countNeighbourhood();
                updateCells();

                printf("\n   Generation   #%d \n", iterationNo);
                displayGrid();

                for(int i=0; i<LIMIT_LENGTH; i++)
                    for(int j=0; j<LIMIT_LENGTH; j++)
                        neighbourhood[i*LIMIT_LENGTH + j] = 0;

                  iterationNo++;

         }

     return 0;

}



void CellularAutomata::displayGrid()
{
    for(int i = 1; i<= limit_length; i++)
    {
        for(int j=1; j<= limit_length; j++)
        {
            std::cout <<readCell(i, j )<< "  ";
        }

        std::cout << " " << std::endl;
    }
}


CellularAutomata:: ~CellularAutomata()
{
    std::cout << "Destructor has been called" << std::endl;

     free(grid_Begin);

    delete [] neighbourhood;
}



