//////////////////////////////////////////////////////////////////////
/// @file slist.h
/// @author Michael Busby CS153 1B
/// @brief Declaration for Slist class
////////////////////////////////////////////////////////////////////// 
#ifndef SLIST_H
#define SLIST_H

#include "exception.h"
#include "snode.h"

//////////////////////////////////////////////////////////////////////
/// @class Slist
/// @brief This class manages an expandable array of data of any 
/// generic type
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Slist::Slist()
/// @brief This functioninitializes the private variables of the 
/// Slist class
/// @pre Slist should be uninitialized
/// @post m_size is set to 0 and m_front is set to NULL
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Slist::~Slist()
/// @brief This function frees memory dynamically allocated in the 
/// Slist class upon leaving scope
/// @pre Slist should be Initialized
/// @post Calls m_clear(), memory allocated for list is destoryed
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Slist::push_front( generic )
/// @brief This function adds an element to the Slist
/// @pre Must have enough memory for one generic and a node pointer
/// @post m_size is incremented and another generic node is added
/// to the list
/// @param x holds a variable to add of the same type as the class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Slist::pop_front()
/// @brief This function removes an element from the front of the Slist
/// @pre m_size must be greater than 0
/// @post m_size is decremented, the node on the front of the list is
/// destroyed and m_front is set to point to the next node
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn generic & Slist::front();
/// @brief This function returns the first element of the Slist
/// @pre m_size must be at least 1
/// @post none
/// @return generic element of from the front of the Slist
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Slist::clear()
/// @brief This function removes all elements from the Slist
/// @pre m_size must be greater than 0
/// @post all elements removed, m_front is null, m_size is 0
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int Slist::size()
/// @brief This function returns the number of elements in the Slist
/// @return returns m_size
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn bool Slist::empty()
/// @brief This function will check if the Slist is empty.
/// @return returns true if empty, false if not empty
//////////////////////////////////////////////////////////////////////

#include "exception.h"
#include "snode.h"

template <class generic>
class Slist
{
  public:
    Slist();
    ~Slist();
    void push_front( generic x );
    void pop_front();
    void remove( generic x );
    generic & front();
    void clear();
    unsigned int size();
    bool empty();

  private:
    unsigned int m_size;
    Snode<generic> * m_front;
};

#include "slist.hpp"
#endif
