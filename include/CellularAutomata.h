#ifndef CELLULARAUTOMATA_H
#define CELLULARAUTOMATA_H


#define LIMIT_LENGTH 10                        // for, for now, setting the boundaries of the Cellular Automata's lattice ( grid ), for two reasons: visibility in the currently limited size on the monitor (or screen, where the Celular Automata will be displayed, for humans)
                                                                      // and, the limitations set by the computer's memory // I wish, everyone, regardless of availble sophistication in resources, should be able to appreciate, and realise the Cellular Automata, implemented by me, and the availability or unavailability of the resources shall not come in between the way of the realisation.



class CellularAutomata
{
     private:
          int *grid_Begin;
           int limit_length;

     protected:
        int* neighbourhood;

     public:



        CellularAutomata();

        int readCell(int row, int column);
        void setCell(int row, int column, int value);


         //Methods for the cells to interact
           void countNeighbourhood( );
           void updateCells( );




          int behavior(unsigned int);
          int behavior_gameOfLife(unsigned int);




        void displayGrid();


        ~CellularAutomata();




};




#endif // CELLULARAUTOMATA_H
