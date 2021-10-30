//////////////////////////////////////////////////////////////////////
/// @file slist.hpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Slist class
////////////////////////////////////////////////////////////////////// 

#include <string>

using std::string;

//////////////////////////////////////////////////////////////////////
/// @fn Slist::Slist()
/// @brief This functioninitializes the private variables of the 
/// Slist class
/// @pre Slist should be uninitialized
/// @post m_size is set to 0 and m_front is set to NULL
////////////////////////////////////////////////////////////////////// 

template <class generic>
Slist<generic>::Slist()
{
	m_size = 0;
	m_front = NULL;
}

//////////////////////////////////////////////////////////////////////
/// @fn Slist::~Slist()
/// @brief This function frees memory dynamically allocated in the 
/// Slist class upon leaving scope
/// @pre Slist should be Initialized
/// @post Calls m_clear(), memory allocated for list is destoryed
////////////////////////////////////////////////////////////////////// 

template <class generic>
Slist<generic>::~Slist()
{
	clear();
}

//////////////////////////////////////////////////////////////////////
/// @fn Slist::push_front( generic )
/// @brief This function adds an element to the Slist
/// @pre Must have enough memory for one generic and a node pointer
/// @post m_size is incremented and another generic node is added
/// to the list
/// @param x holds a variable to add of the same type as the class
//////////////////////////////////////////////////////////////////////

template <class generic>
void Slist<generic>::push_front( generic x )
{
	Snode<generic> * temp = new Snode<generic>;
	if (temp == NULL)
	{
		throw( exception( string("Couldn't allocate memory for container") ) );
	}
	else
	{
		temp->data = x;
		temp->forward = m_front;
		m_front = temp;
		m_size++;
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn Slist::pop_front()
/// @brief This function removes an element from the front of the Slist
/// @pre m_size must be greater than 0
/// @post m_size is decremented, the node on the front of the list is
/// destroyed and m_front is set to point to the next node
//////////////////////////////////////////////////////////////////////

template <class generic>
void Slist<generic>::pop_front()
{
	Snode<generic> * temp;
	if (!m_size)
	{
		throw ( exception ( string ("Container is empty, no elements to remove") ) );
	}
	else
	{
		temp = m_front->forward;
		delete m_front;
		m_front = temp;
		m_size--;
	}
	
}

//////////////////////////////////////////////////////////////////////
/// @fn Slist::remove( generic )
/// @brief This function removes all elements of a given value from 
/// the Slist
/// @pre At least one element with value x should exist in the list
/// @post m_size is decremented for each element, and their nodes
/// are removed from the list
/// @param x holds the value for which elements should be removed
//////////////////////////////////////////////////////////////////////

template <class generic>
void Slist<generic>::remove( generic x )
{
	Snode<generic> * temp;
	int size = m_size;
	while (m_size && m_front->data == x)
	{
		pop_front();
	}
	temp = m_front;
	if (temp != NULL)
	{
		while (temp->forward != NULL)
		{
			if (temp->forward->data == x)
			{
				Snode<generic> * temp2;
				temp2 = temp->forward;
				temp->forward = temp->forward->forward;
				delete temp2;
				m_size--;
			}
			temp = temp->forward;
		}
	}
	if (size - m_size == 0)
	{
		throw ( exception ( string ("No such element found in the container") ) );
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn generic & Slist::front();
/// @brief This function returns the first element of the Slist
/// @pre m_size must be at least 1
/// @post none
/// @return generic element of from the front of the Slist
////////////////////////////////////////////////////////////////////// 

template <class generic>
generic & Slist<generic>::front()
{
	if (m_size)
	{
		return m_front->data;
	}
	throw ( exception ( string ("Container is empty, requested element does not exist")));
}

//////////////////////////////////////////////////////////////////////
/// @fn Slist::clear()
/// @brief This function removes all elements from the Slist
/// @pre m_size must be greater than 0
/// @post all elements removed, m_front is null, m_size is 0
//////////////////////////////////////////////////////////////////////

template <class generic>
void Slist<generic>::clear()
{
	while (m_size)
	{
		pop_front();
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int Slist::size()
/// @brief This function returns the number of elements in the Slist
/// @return returns m_size
////////////////////////////////////////////////////////////////////// 

template <class generic>
unsigned int Slist<generic>::size()
{
	return m_size;
}

//////////////////////////////////////////////////////////////////////
/// @fn bool Slist::empty()
/// @brief This function will check if the Slist is empty.
/// @return returns true if empty, false if not empty
//////////////////////////////////////////////////////////////////////

template <class generic>
bool Slist<generic>::empty()
{
	return !m_size;
}
