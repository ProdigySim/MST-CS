//////////////////////////////////////////////////////////////////////
/// @file vector.h
/// @author Michael Busby CS153 1B
/// @brief Declaration for Vector class
////////////////////////////////////////////////////////////////////// 
#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include "exception.h"

//////////////////////////////////////////////////////////////////////
/// @class Vector
/// @brief This class manages an expandable array of data of any 
/// generic type
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Vector::Vector()
/// @brief This functioninitializes the private variables of the 
/// Vector class
/// @pre Vector should be uninitialized, system must have available
/// memory for potentially (sizeof(generic) * num_items * 2) bytes,
/// where num_items is the number of items stored in the vector.
/// @post m_size and m_max_size are set to 0 and 1 respectively, 
/// and memory is allocated for m_data
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Vector::~Vector()
/// @brief This function frees memory dynamically allocated in the 
/// Vector class
/// @pre Vector should be Initialized
/// @post Memory allocated for m_data is freed, and the vector is
/// essentially uninitialized
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Vector::push_back( generic )
/// @brief This function adds an element to the Vector
/// @pre Must have enough memory for potentially (sizeof(generic) * 
/// num_items * 2) bytes, where num_items is the number of items
/// stored in the vector
/// @post m_size is incremented and m_data has an extra element filled
/// Also, m_max_size may be double if necessary, and memory for m_data
/// reallocated.
/// @param x holds a variable of the same type as the class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Vector::pop_back()
/// @brief This function removes an element from the end of the Vector
/// @pre m_size must be greater than 0
/// @post m_size is decremented. If m_size is one fourth of
/// m_max_size, m_max_size is halved and memory of m_data is
/// reallocated
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn Vector::clear()
/// @brief This function removes all elements from the Vector
/// @pre none
/// @post m_size is set to 0, m_max_size to 1, m_data is destroyed and
/// reallocated m_max_size bytes
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn generic Vector::operator[]( unsigned int )
/// @brief This function returns an element from the Vector using 
/// brackets
/// @pre x must be less than m_size
/// @param x hold the index of the requested Vector element
/// @return Element of index x from the Vector (m_data)
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int Vector::size()
/// @brief This function returns the number of elements in the Vector
/// @return returns m_size
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int Vector::max_size()
/// @brief This function returns the number of elements the Vector can 
/// hold
/// @return returns m_max_size
////////////////////////////////////////////////////////////////////// 

template <class generic>
class Vector
{
    public:
        Vector();
        ~Vector();
        void push_back( generic x );
        void pop_back();
        void clear();
        generic & operator[]( unsigned int x );
        unsigned int size();
        unsigned int max_size();

  private:
    unsigned int m_size;
    unsigned int m_max_size;
    generic * m_data;
};

#include "Vector.hpp"

#endif
