#ifndef NODE_LINKEDLIST_H_INCLUDED
#define NODE_LINKEDLIST_H_INCLUDED

struct node
{
    unsigned int row;
    unsigned int column;

    int updateToCell;

    node* next;
};



#endif // NODE_LINKEDLIST_H_INCLUDED
