//////////////////////////////////////////////////////////////////////
/// @file vector.hpp
/// @author Michael Busby CS153 1B
/// @brief Definitions of member functions for Vector class
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

template <class generic>
Vector<generic>::Vector()
{
	m_size = 0;
	m_max_size = 1;
	
	try 
	{
		m_data = new generic[m_max_size];
	}
	catch( const std::bad_alloc &)
	{
		throw( exception( std::string("Couldn't allocate memory for vector") ) );
	}
	if (m_data == NULL)
	{
		throw( exception( std::string("Couldn't allocate memory for vector") ) );
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn Vector::~Vector()
/// @brief This function frees memory dynamically allocated in the 
/// Vector class
/// @pre Vector should be Initialized
/// @post Memory allocated for m_data is freed, and the vector is
/// essentially uninitialized
////////////////////////////////////////////////////////////////////// 

template <class generic>
Vector<generic>::~Vector()
{
	delete [] m_data;
}

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

template <class generic>
void Vector<generic>::push_back( generic x )
{
	if (m_size >= m_max_size)
	{
		generic *temp = m_data;
		
		m_max_size *=2;
		
		try 
		{
			m_data = new generic[m_max_size];
		}
		catch( const std::bad_alloc &)
		{
			throw( exception( std::string("Couldn't allocate memory for vector") ) );
		}
		if (m_data == NULL)
		{
			throw( exception( std::string("Couldn't allocate memory for vector") ) );
		}
		
		memcpy(m_data, temp, m_size*sizeof(generic));
		
		delete [] temp;
	}

	m_data[m_size++] = x;

}

//////////////////////////////////////////////////////////////////////
/// @fn Vector::pop_back()
/// @brief This function removes an element from the end of the Vector
/// @pre m_size must be greater than 0
/// @post m_size is decremented. If m_size is one fourth of
/// m_max_size, m_max_size is halved and memory of m_data is
/// reallocated
//////////////////////////////////////////////////////////////////////  

template <class generic>
void Vector<generic>::pop_back()
{
	if (m_size > 0)
	{
		m_size--;
	}
	else
	{
		throw( exception( std::string("The vector is exmpty.") ) );
	}
	
	if (m_size && m_size <= (m_max_size / 4))
	{
		generic *temp = m_data;
		
		m_max_size /=2;
		
		try 
		{
			m_data = new generic[m_max_size];
		}
		catch( const std::bad_alloc &)
		{
			throw( exception( std::string("Couldn't allocate memory for vector") ) );
		}
		if (m_data == NULL)
		{
			throw( exception( std::string("Couldn't allocate memory for vector") ) );
		}
		
		memcpy(m_data, temp, m_size*sizeof(generic));
		
		delete [] temp;
	}
		
}

//////////////////////////////////////////////////////////////////////
/// @fn Vector::clear()
/// @brief This function removes all elements from the Vector
/// @pre none
/// @post m_size is set to 0, m_max_size to 1, m_data is destroyed and
/// reallocated m_max_size bytes
//////////////////////////////////////////////////////////////////////  

template <class generic>
void Vector<generic>::clear()
{
	m_size = 0;
	m_max_size = 1;
	
	delete [] m_data;
	
	try 
	{
		m_data = new generic[m_max_size];
	}
	catch( const std::bad_alloc &)
	{
		throw( exception( std::string("Couldn't allocate memory for vector") ) );
	}
	if (m_data == NULL)
	{
		throw( exception( std::string("Couldn't allocate memory for vector") ) );
	}
}

//////////////////////////////////////////////////////////////////////
/// @fn generic Vector::operator[]( unsigned int )
/// @brief This function returns an element from the Vector using 
/// brackets
/// @pre x must be less than m_size
/// @param x hold the index of the requested Vector element
/// @return Element of index x from the Vector (m_data)
//////////////////////////////////////////////////////////////////////

template <class generic>
generic & Vector<generic>::operator[]( unsigned int x )
{
	if (x < m_size)
	{
		return m_data[x];
	}
	
	throw( exception( std::string("Attempt to access uninitialized data.") ) );
}

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int Vector::size()
/// @brief This function returns the number of elements in the Vector
/// @return returns m_size
//////////////////////////////////////////////////////////////////////

template <class generic>
unsigned int Vector<generic>::size()
{
	return m_size;
}

//////////////////////////////////////////////////////////////////////
/// @fn unsigned int Vector::max_size()
/// @brief This function returns the number of elements the Vector can 
/// hold
/// @return returns m_max_size
//////////////////////////////////////////////////////////////////////

template <class generic>
unsigned int Vector<generic>::max_size()
{
	return m_max_size;
}

