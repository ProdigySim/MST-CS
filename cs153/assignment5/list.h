//////////////////////////////////////////////////////////////////////
/// @file list.h
/// @author Michael Busby CS153 1B
/// @brief Declaration for List class
////////////////////////////////////////////////////////////////////// 
#ifndef LIST_H
#define LIST_H

#include "exception.h"
#include "node.h"

//////////////////////////////////////////////////////////////////////
/// @class List
/// @brief This class manages an expandable array of data of any 
/// generic type
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn List::List()
/// @brief This functioninitializes the private variables of the 
/// List class
/// @pre List should be uninitialized
/// @post m_size is set to 0 and m_front is set to NULL
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn List::~List()
/// @brief This function frees memory dynamically allocated in the 
/// List class upon leaving scope
/// @pre List should be Initialized
/// @post Calls m_clear(), memory allocated for list is destoryed
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn List::push_front( generic )
/// @brief This function adds an element to the List
/// @pre Must have enough memory for one generic and a node pointer
/// @post m_size is incremented and another generic node is added
/// to the list
/// @param x holds a variable to add of the same type as the class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn List::push_back( generic )
/// @brief This function adds an element to the back of the List
/// @pre Must have enough memory for one generic and two node pointers
/// @post m_size is incremented and another generic node is added
/// to the back of the list
/// @param x holds a variable to add of the same type as the class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn List::pop_front()
/// @brief This function removes an element from the front of the List
/// @pre m_size must be greater than 0
/// @post m_size is decremented, the node on the front of the list is
/// destroyed and m_front is set to point to the next node
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn List::pop_back()
/// @brief This function removes an element from the back of the List
/// @pre m_size must be greater than 0
/// @post m_size is decremented, the node on the back of the list is
/// destroyed and m_back is set to point to the next node
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn generic & List::front();
/// @brief This function returns the first element of the List
/// @pre m_size must be at least 1
/// @post none
/// @return generic element of from the front of the List
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn generic & List::back();
/// @brief This function returns the last element of the List
/// @pre m_size must be at least 1
/// @post none
/// @return generic element of from the back of the List
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn List::remove( generic )
/// @brief This function removes all elements of a given value from 
/// the List
/// @pre At least one element with value x should exist in the list
/// @post m_size is decremented for each element, and their nodes
/// are removed from the list
/// @param x holds the value for which elements should be removed
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn List::clear()
/// @brief This function removes all elements from the List
/// @pre m_size must be greater than 0
/// @post all elements removed, m_front is null, m_size is 0
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int List::size()
/// @brief This function returns the number of elements in the List
/// @return returns m_size
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn bool List::empty()
/// @brief This function will check if the List is empty.
/// @return returns true if empty, false if not empty
//////////////////////////////////////////////////////////////////////

#include "exception.h"
#include "node.h"

template <class generic>
class List
{
  public:
    List();
    ~List();
    void push_front( generic x );
    void push_back( generic x );
    void pop_front();
    void pop_back();
    void remove( generic x );
    generic & front();
    generic & back();
    void clear();
    unsigned int size();
    bool empty();

  private:
    unsigned int m_size;
    Node<generic> * m_front;
    Node<generic> * m_back;
};

#include "list.hpp"
#endif
