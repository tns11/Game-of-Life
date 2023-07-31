#include "Stack.h"


#include "Node_LinkedList.h"

#include <stdio.h>

const int  LIMIT_LENGTH = 10;

Stack::Stack()
{
    head = nullptr;
    top = nullptr;

    counter = 0;
}

void Stack::push(int row, int column, int updateBy)
{
    if(head == nullptr)
    {
        head = new node;

        if(head != nullptr)
        {
            head->row = row;
            head->column = column;
            head->updateToCell = updateBy;

            head->next = nullptr;

            top = head;

            counter++;

            printf("\nPushing given data into the node successful!");
        }

        else
        {

            printf("\nSome error occurred while pushing");
        }


    }

    else
    {

        node* temp;
        temp = new node;

        if(temp != nullptr)
        {
            temp->next = nullptr;

            top->next  = temp;


            top = top->next;

            top->row = row;
            top->column = column;
            top->updateToCell = updateBy;


            counter++;

            printf("Pushing given data into the node successful!");

        }

        else
        {
            printf("Some error occurred while pushing");
        }


    }

}


int Stack::pop()
{

    int data_toBePopped = 0;

    if(isEmpty())
    {
        printf("\nStack Underflow");
        return '\0';
    }


    else{


          data_toBePopped = (LIMIT_LENGTH*(top->row) + top->column);

         node *current = head;

         if(top == head && head->next == nullptr)
         {



             delete top;
             head = nullptr;
             top = nullptr;

             printf("\nThe operation pop on the stack was successful");

            counter--;

            return data_toBePopped;
         }

         else{

           while(current->next != top)
            {
                current = current->next;


            }

           // printf("%d ", top->data);

            delete top;

            //printf("%d ", top->data);

            top = current;
            top->next = nullptr;


             counter--;


              printf("\nThe operation pop on the stack was successful");

           return data_toBePopped;



         }


    }

}

int Stack::peek()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW");
        return '\0';
    }

    else
        return (-1)*(LIMIT_LENGTH*(top->row) + top->column);

}


bool Stack::isEmpty()
{
    if(counter==0 && head== nullptr && top == nullptr )
        return true;

    else
        return false;

}


int Stack::size()
{
    return counter;
}

Stack::~Stack()
{
      printf("Deleting...");

while(!isEmpty())
{
    pop();

    printf("Deleted Stack at #%d", counter);

}
}



