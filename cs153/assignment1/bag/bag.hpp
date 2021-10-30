//////////////////////////////////////////////////////////////////////
/// @file bag.hpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Bag class
////////////////////////////////////////////////////////////////////// 


//////////////////////////////////////////////////////////////////////
/// @fn Bag::Bag
/// @brief initializes the private variables of the Bag class
/// @pre Class uninitialized
/// @post m_size and m_max_size are set to 0 and 20 respectively
////////////////////////////////////////////////////////////////////// 
template <class generic>
Bag<generic>::Bag()
{
    m_size = 0;
    m_max_size = 20;
}

//////////////////////////////////////////////////////////////////////
/// @fn Bag::push_back
/// @brief adds an element to the bag
/// @pre m_size must be less than m_max_size
/// @post m_size is incremented and m_data has an extra element filled
/// @param generic x: variable of class type
////////////////////////////////////////////////////////////////////// 
template <class generic>
void Bag<generic>::push_back( generic x )
{
    if (m_size < m_max_size)
        m_data[m_size++] = x;
    else
        throw( exception( std::string("The bag is full.") ) );
}

//////////////////////////////////////////////////////////////////////
/// @fn Bag::pop_back
/// @brief removes an element from the end of the bag
/// @pre m_size must be greater than 0
/// @post m_size is decremented
////////////////////////////////////////////////////////////////////// 
template <class generic>
void Bag<generic>::pop_back()
{
    if (m_size > 0)
        m_size--;
    else
        throw( exception( std::string("The bag is exmpty.") ) );
}

//////////////////////////////////////////////////////////////////////
/// @fn Bag::clear
/// @brief removes all elements from the bag
/// @post m_size is set to 0
////////////////////////////////////////////////////////////////////// 
template <class generic>
void Bag<generic>::clear()
{
    m_size = 0;
}

//////////////////////////////////////////////////////////////////////
/// @fn Bag::operator[]
/// @brief Get an element from the bag using brackets
/// @pre x must be less than m_size
/// @param unsigned int x: index of bag element
/// @return element from the bag
////////////////////////////////////////////////////////////////////// 
template <class generic>
generic & Bag<generic>::operator[]( unsigned int x )
{
    if (x < m_size)
        return m_data[x];
    throw( exception( std::string("Attempt to access uninitialized data.") ) );

}

//////////////////////////////////////////////////////////////////////
/// @fn Bag::size
/// @brief Get the number of elements in the bag
/// @return returns m_size
////////////////////////////////////////////////////////////////////// 
template <class generic>
unsigned int Bag<generic>::size()
{
    return m_size;
}

//////////////////////////////////////////////////////////////////////
/// @fn Bag::max_size
/// @brief Get the number of elements the bag can hold
/// @return returns m_max_size
////////////////////////////////////////////////////////////////////// 
template <class generic>
unsigned int Bag<generic>::max_size()
{
    return m_max_size;
}

