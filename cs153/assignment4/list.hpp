//////////////////////////////////////////////////////////////////////
/// @file list.hpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for List class
////////////////////////////////////////////////////////////////////// 

#include <string>

//#define DEBUG_LIST

#ifdef DEBUG_LIST
#include <iostream>
#endif

//////////////////////////////////////////////////////////////////////
/// @fn List::List()
/// @brief This functioninitializes the private variables of the 
/// List class
/// @pre List should be uninitialized
/// @post m_size is set to 0 and m_front is set to NULL
////////////////////////////////////////////////////////////////////// 

template <class generic>
List<generic>::List()
{
	m_size = 0;
	m_front = m_back = NULL;
}

//////////////////////////////////////////////////////////////////////
/// @fn List::~List()
/// @brief This function frees memory dynamically allocated in the 
/// List class upon leaving scope
/// @pre List should be Initialized
/// @post Calls m_clear(), memory allocated for list is destoryed
////////////////////////////////////////////////////////////////////// 

template <class generic>
List<generic>::~List()
{
	clear();
}

//////////////////////////////////////////////////////////////////////
/// @fn List::push_front( generic )
/// @brief This function adds an element to the front of the List
/// @pre Must have enough memory for one generic and two node pointers
/// @post m_size is incremented and another generic node is added
/// to the front of the list
/// @param x holds a variable to add of the same type as the class
//////////////////////////////////////////////////////////////////////

template <class generic>
void List<generic>::push_front( generic x )
{
	if (m_front != NULL)
	{
		m_front->backward = new Node<generic>;
		if (m_front->backward == NULL)
		{
			throw( exception( std::string("Couldn't allocate memory for list") ) );
		}
		m_front->backward->forward = m_front;
		m_front = m_front->backward;
	}
	else
	{
		m_front = new Node<generic>;
		if (m_front == NULL)
		{
			throw( exception( std::string("Couldn't allocate memory for list") ) );
		}
		m_front->forward = NULL;
		m_back = m_front;
	}
	m_front->backward = NULL;
	m_front->data = x;
	m_size++;
}

//////////////////////////////////////////////////////////////////////
/// @fn List::push_back( generic )
/// @brief This function adds an element to the back of the List
/// @pre Must have enough memory for one generic and two node pointers
/// @post m_size is incremented and another generic node is added
/// to the back of the list
/// @param x holds a variable to add of the same type as the class
//////////////////////////////////////////////////////////////////////

template <class generic>
void List<generic>::push_back( generic x )
{
	if (m_back != NULL)
	{
		m_back->forward = new Node<generic>;
		if (m_back->forward == NULL)
		{
			throw( exception( std::string("Couldn't allocate memory for list") ) );
		}
		m_back->forward->backward = m_back;
		m_back = m_back->forward;	
	}
	else
	{
		m_back = new Node<generic>;
		if (m_back == NULL)
		{
			throw( exception( std::string("Couldn't allocate memory for list") ) );
		}
		m_back->backward = NULL;
		m_front = m_back;
	}
	m_back->forward = NULL;
	m_back->data = x;
	m_size++;
}

//////////////////////////////////////////////////////////////////////
/// @fn List::pop_front()
/// @brief This function removes an element from the front of the List
/// @pre m_size must be greater than 0
/// @post m_size is decremented, the node on the front of the list is
/// destroyed and m_front is set to point to the next node
//////////////////////////////////////////////////////////////////////

template <class generic>
void List<generic>::pop_front()
{
	if (!m_size)
	{
		throw ( exception ( std::string ("List is empty, no elements to remove from the list.") ) );
	}
	else
	{
		if (m_front->forward == NULL)
		{
			delete m_front;
			m_front = m_back = NULL;
		}
		else
		{
			m_front = m_front->forward;
			delete m_front->backward;
			m_front->backward = NULL;
		}
		m_size--;
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn List::pop_back()
/// @brief This function removes an element from the back of the List
/// @pre m_size must be greater than 0
/// @post m_size is decremented, the node on the back of the list is
/// destroyed and m_back is set to point to the next node
//////////////////////////////////////////////////////////////////////

template <class generic>
void List<generic>::pop_back()
{
	if (!m_size)
	{
		throw ( exception ( std::string ("List is empty, no elements to remove from the list.") ) );
	}
	else
	{
		if (m_back->backward == NULL)
		{
			delete m_back;
			m_front = m_back = NULL;
		}
		else
		{
			m_back = m_back->backward;
			delete m_back->forward;
			m_back->forward = NULL;
		}
		m_size--;
	}
	
}

//////////////////////////////////////////////////////////////////////
/// @fn List::remove( generic )
/// @brief This function removes all elements of a given value from 
/// the List
/// @pre At least one element with value x should exist in the list
/// @post m_size is decremented for each element, and their nodes
/// are removed from the list
/// @param x holds the value for which elements should be removed
//////////////////////////////////////////////////////////////////////

template <class generic>
void List<generic>::remove( generic x )
{
	Node<generic> * temp = m_front;
	unsigned int size = m_size;
	while (temp != NULL)
	{
		Node<generic> * temp2 = temp->forward;
		if (temp->data == x)
		{
			
			if (temp->backward != NULL)
			{
				temp->backward->forward = temp->forward;
			}
			else
			{
				m_front = temp->forward;
			}
			if (temp->forward != NULL)
			{
				temp->forward->backward = temp->backward;
			}
			else
			{
				m_back = temp->backward;
			}
			delete temp;
			m_size--;
		}
		temp = temp2;
	}
	if (size - m_size == 0)
	{
		throw ( exception ( std::string ("No such element found in the list.") ) );
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn generic & List::front();
/// @brief This function returns the first element of the List
/// @pre m_size must be at least 1
/// @post none
/// @return generic element of from the front of the List
////////////////////////////////////////////////////////////////////// 

template <class generic>
generic & List<generic>::front()
{
	if (m_size)
	{
		return m_front->data;
	}
	throw ( exception ( std::string ("List is empty, front element is null")));
}

//////////////////////////////////////////////////////////////////////
/// @fn generic & List::back();
/// @brief This function returns the last element of the List
/// @pre m_size must be at least 1
/// @post none
/// @return generic element of from the back of the List
////////////////////////////////////////////////////////////////////// 

template <class generic>
generic & List<generic>::back()
{
	if (m_size)
	{
		return m_back->data;
	}
	throw ( exception ( std::string ("List is empty, back element is null")));
}

//////////////////////////////////////////////////////////////////////
/// @fn List::clear()
/// @brief This function removes all elements from the List
/// @pre m_size must be greater than 0
/// @post all elements removed, m_front is null, m_size is 0
//////////////////////////////////////////////////////////////////////

template <class generic>
void List<generic>::clear()
{
	
	while (m_front != NULL)
	{
		if (m_front->forward == NULL)
		{
			delete m_front;
			m_front = m_back = NULL;
		}
		else 
		{
			m_front = m_front->forward;
			delete m_front->backward;
		}
	}
	m_size = 0;
}

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int List::size()
/// @brief This function returns the number of elements in the List
/// @return returns m_size
////////////////////////////////////////////////////////////////////// 

template <class generic>
unsigned int List<generic>::size()
{
	return m_size;
}

//////////////////////////////////////////////////////////////////////
/// @fn bool List::empty()
/// @brief This function will check if the List is empty.
/// @return returns true if empty, false if not empty
//////////////////////////////////////////////////////////////////////

template <class generic>
bool List<generic>::empty()
{
	return !m_size;
}
