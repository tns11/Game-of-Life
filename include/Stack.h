#ifndef STACK_H
#define STACK_H


#include "Node_LinkedList.h"



class Stack
{

   private:
       node* head;
       node *top;

       int counter;   //For counting current number of elements in the linked list

   public:
    Stack();
    ~Stack();

    void push(int row, int column, int updateBy);
    int pop();
    int peek();

    bool isEmpty();

    //isFull() is not applicable a stack implemented using Linked List as the nodes are dynamically created as when required. The ultimate limit is the memory space available to the program



    int size();



};

#endif // STACK_H
