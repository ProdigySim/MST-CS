template <class generic>
Block<generic>::Block () : m_size (0), m_max_size (3), m_back (0)
{
	m_data = new generic[m_max_size];
	m_front = m_max_size -1;
}

template <class generic>
Block<generic>::Block (Block<generic> & _copy_block) : m_data (NULL)
{
    *this = _copy_block;
}

template <class generic>
Block<generic>::~Block ()
{
    delete [] m_data;
}

template <class generic>
void Block<generic>::push_front (generic _data)
{
    if (m_front >= m_max_size)
	{
	    throw Exception(FRONT_FULL, "Can not push any more items to the front of the block" );
	}
	else if (m_front == (m_max_size - 1))
	{
	    m_back = m_max_size;
	}
	
	m_data[m_front--] = _data;
	m_size++;
}

template <class generic>
void Block<generic>::pop_front ()
{
    if (m_size-- == 0)
	{
	    throw Exception(FRONT_EMPTY, "Can not pop any more items from the front of the block" );
	}
	else if (m_size == 0)
	{
	    m_back = 0;
		m_front = m_max_size -1;
	}
	else
	{
	    m_front++;
	}
}

template <class generic>
void Block<generic>::push_back (generic _data)
{
    if (m_back >= m_max_size)
	{
	    throw Exception(BACK_FULL, "Can not push any more items to the back of the block" );
	}
	else if (m_back == 0)
	{
	    m_front = UINT_MAX;
	}
	
	m_data[m_back++] = _data;
	m_size++;
}

template <class generic>
void Block<generic>::pop_back ()
{
    if (m_size-- == 0)
	{
	    throw Exception(BACK_EMPTY, "Can not pop any more items from the front of the block" );
	}
	else if (m_size == 0)
	{
	    m_back = 0;
		m_front = m_max_size -1;
	}
	else
	{
	    m_back--;
	}
}

template <class generic>
void Block<generic>::clear ()
{
    m_size = 0;
	m_front = m_max_size -1;
	m_back = 0;
}

template <class generic>
Block<generic> & Block<generic>::operator= (const Block<generic> & _copy_block)
{
    clear();
	m_max_size = _copy_block.max_size ();
	delete [] m_data;
	m_data = new generic[m_max_size];
	
	for (unsigned int i = 0; i < _copy_block.size (); i++)
	{
	    push_back (_copy_block[i]);
	}
	
	return *this;
}

template <class generic>
generic & Block<generic>::operator[] (unsigned int _index)
{
    if (m_size == 0 || (m_front + 1) + _index >= m_back)
    {
	    throw Exception(OUT_OF_BOUNDS, "Can access that element.  It is out of bounds." );
	}
	
    return m_data[(m_front + 1) + _index];
}

template <class generic>
generic & Block<generic>::operator[] (unsigned int _index) const
{
    if (m_size == 0 || (m_front + 1) + _index >= m_back)
    {
	    throw Exception(OUT_OF_BOUNDS, "Can access that element.  It is out of bounds." );
	}
	
    return m_data[(m_front + 1) + _index];
}

template <class generic>
unsigned int Block<generic>::size () const
{
    return m_size;
}

template <class generic>
unsigned int Block<generic>::max_size () const
{
    return m_max_size;
}

template <class generic>
bool Block<generic>::ffull () const
{
    return m_front >= m_max_size ? true : false;
}

template <class generic>
bool Block<generic>::bfull () const
{
    return m_back >= m_max_size ? true : false;
}

template <class generic>
bool Block<generic>::empty () const
{
    return m_size == 0 ? true : false;
}
