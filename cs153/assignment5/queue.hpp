//////////////////////////////////////////////////////////////////////
/// @fn bool Queue::empty()
/// @brief This function will check if the Queue is empty.
/// @return returns true if empty, false if not empty
//////////////////////////////////////////////////////////////////////

template <class generic>
bool Queue<generic>::empty()
{
	return List<generic>::empty();
}

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int Queue::size()
/// @brief This function returns the number of elements in the Queue
/// @return returns size of the Queue
////////////////////////////////////////////////////////////////////// 

template <class generic>
unsigned int Queue<generic>::size()
{
	return List<generic>::size();
}

//////////////////////////////////////////////////////////////////////
/// @fn generic & Queue::front();
/// @brief This function returns the first element of the Queue
/// @pre m_size must be at least 1
/// @post none
/// @return generic element of from the front of the Queue
////////////////////////////////////////////////////////////////////// 

template <class generic>
generic & Queue<generic>::front()
{
	return List<generic>::front();
}

//////////////////////////////////////////////////////////////////////
/// @fn generic & Queue::back();
/// @brief This function returns the last element of the Queue
/// @pre size must be at least 1
/// @post none
/// @return generic element of from the back of the Queue
////////////////////////////////////////////////////////////////////// 

template <class generic>
generic & Queue<generic>::back()
{
	return List<generic>::back();
}

//////////////////////////////////////////////////////////////////////
/// @fn Queue::push( generic )
/// @brief This function adds an element to the back of the Queue
/// @pre Must have enough memory for one generic and two node pointers
/// @post size is incremented and another generic node is added
/// to the back of the queue
/// @param x holds a variable to add of the same type as the class
//////////////////////////////////////////////////////////////////////

template <class generic>
void Queue<generic>::push(generic x)
{
	List<generic>::push_back(x);
}

//////////////////////////////////////////////////////////////////////
/// @fn Queue::pop()
/// @brief This function removes an element from the back of the Queue
/// @pre size must be greater than 0
/// @post size is decremented, the node on the back of the queue is
/// destroyed
//////////////////////////////////////////////////////////////////////

template <class generic>
void Queue<generic>::pop()
{
	List<generic>::pop_front();
}
