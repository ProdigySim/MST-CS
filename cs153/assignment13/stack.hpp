//////////////////////////////////////////////////////////////////////
/// @file stack.hpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Stack class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn bool Stack::empty()
/// @brief This function will check if the Stack is empty.
/// @return returns true if empty, false if not empty
//////////////////////////////////////////////////////////////////////

template <class generic>
bool Stack<generic>::empty()
{
	return Slist<generic>::empty();
}

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int Stack::size()
/// @brief This function returns the number of elements in the Stack
/// @return returns size of the Stack
////////////////////////////////////////////////////////////////////// 

template <class generic>
unsigned int Stack<generic>::size()
{
	return Slist<generic>::size();
}

//////////////////////////////////////////////////////////////////////
/// @fn generic & Stack::top();
/// @brief This function returns the first element of the Stack
/// @pre size must be at least 1
/// @post none
/// @return generic element of from the front of the Stack
////////////////////////////////////////////////////////////////////// 

template <class generic>
generic & Stack<generic>::top()
{
	return Slist<generic>::front();
}

//////////////////////////////////////////////////////////////////////
/// @fn Stack::push( generic )
/// @brief This function adds an element to the Stack
/// @pre Must have enough memory for one generic and a node pointer
/// @post size is incremented and a new node is added to the stack
/// @param x holds a variable to add of the same type as the class
//////////////////////////////////////////////////////////////////////

template <class generic>
void Stack<generic>::push(generic x)
{
	Slist<generic>::push_front(x);
}

//////////////////////////////////////////////////////////////////////
/// @fn Stack::pop()
/// @brief This function removes an element from the top of the Stack
/// @pre stack size must be > 0
/// @post size is decremented and an element is deleted from the 
/// top of the Stack
//////////////////////////////////////////////////////////////////////

template <class generic>
void Stack<generic>::pop()
{
	Slist<generic>::pop_front();
}

