#ifndef NODE_H
#define NODE_H

template <class generic>
struct Node
{
    Node<generic> * forward; // Points to the next node in the list
    Node<generic> * backward; // Points to the previous node in the list
    generic data; // Holds the generic user data for the node
};

#endif
