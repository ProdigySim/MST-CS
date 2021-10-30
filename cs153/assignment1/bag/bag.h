//////////////////////////////////////////////////////////////////////
/// @file bag.h
/// @author Michael Busby CS153 1B
/// @brief Declaration for Bag class
////////////////////////////////////////////////////////////////////// 
#ifndef BAG_H
#define BAG_H

#include <string>
#include "exception.h"

//////////////////////////////////////////////////////////////////////
/// @class Bag
/// @brief Manages an array of data of any generic type
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bag::Bag
/// @brief initializes the private variables of the Bag class
/// @pre Class uninitialized
/// @post m_size and m_max_size are set to 0 and 20 respectively
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bag::push_back
/// @brief adds an element to the bag
/// @pre m_size must be less than m_max_size
/// @post m_size is incremented and m_data has an extra element filled
/// @param generic x: variable of class type
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bag::pop_back
/// @brief removes an element from the end of the bag
/// @pre m_size must be greater than 0
/// @post m_size is decremented
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bag::clear
/// @brief removes all elements from the bag
/// @post m_size is set to 0
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bag::operator[]
/// @brief Get an element from the bag using brackets
/// @pre x must be less than m_size
/// @param unsigned int x: index of bag element
/// @return element from the bag
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bag::size
/// @brief Get the number of elements in the bag
/// @return returns m_size
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bag::max_size
/// @brief Get the number of elements the bag can hold
/// @return returns m_max_size
////////////////////////////////////////////////////////////////////// 
template <class generic>
class Bag    
{
    public:
        Bag();
        void push_back( generic x );
        void pop_back();
        void clear();
        generic & operator[]( unsigned int x );
        unsigned int size();
        unsigned int max_size();

    private:
        generic m_data[20]; ///< holds the bag items
        unsigned int m_size; ///< holds the number of items in the array
        unsigned int m_max_size; ///< holds the max number of items the array can store
};

#include "bag.hpp"

#endif
