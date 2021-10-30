template <class generic>
Dequeue<generic>::Dequeue () : m_data (NULL), m_size (0), m_blocks (1)
{
    m_data = new Block<generic>*[m_blocks];
    m_data[0] = new Block<generic>;
	m_block_size = m_data[0]->max_size();
}

template <class generic>
Dequeue<generic>::Dequeue (Dequeue<generic> & _copy_queue) : m_data (NULL), m_size (0), m_blocks (0)
{
    *this = _copy_queue;
}

template <class generic>
Dequeue<generic>::~Dequeue ()
{
    for (unsigned int i = 0; i < m_blocks; i++)
	{
	    delete m_data[i];
	}
	
    delete [] m_data;
}

template <class generic>
void Dequeue<generic>::push_front (generic _data)
{
    if (m_data[0]->ffull ())
	{
	    Block<generic> ** temp = m_data;
		m_data = new Block<generic>*[++m_blocks];
		m_data[0] = new Block<generic>;
		
		for (unsigned int i = 1; i < m_blocks; i++)
		{
		    m_data[i] = temp[i - 1];
		}
		
		delete [] temp;
	}
	
    m_data[0]->push_front (_data);
	m_size++;
}

template <class generic>
void Dequeue<generic>::pop_front ()
{
    if (empty ())
	{
	    throw Exception (CONTAINER_EMPTY, "Can not pop when the container is empty.");
	}

    if (m_data[0]->empty ())
	{
	    Block<generic> ** temp = m_data;
		m_data = new Block<generic>*[--m_blocks];
		delete temp[0];
		
		for (unsigned int i = 0; i < m_blocks; i++)
		{
		    m_data[i] = temp[i + 1];
		}
		
		delete [] temp;
	}

	m_data[0]->pop_front ();
	m_size--;
}

template <class generic>
void Dequeue<generic>::push_back (generic _data)
{
    if (m_data[m_blocks - 1]->bfull ())
	{
	    Block<generic> ** temp = m_data;
		m_data = new Block<generic>*[++m_blocks];
		m_data[m_blocks-1] = new Block<generic>;
		
		for (unsigned int i = 0; i < m_blocks - 1; i++)
		{
		    m_data[i] = temp[i];
		}
		
		delete [] temp;
	}

	m_data[m_blocks - 1]->push_back (_data);
	m_size++;
}

template <class generic>
void Dequeue<generic>::pop_back ()
{
    if (empty ())
	{
	    throw Exception (CONTAINER_EMPTY, "Can not pop when the container is empty.");
	}
	
    if (m_data[m_blocks - 1]->empty ())
	{
	    Block<generic> ** temp = m_data;
		m_data = new Block<generic>*[--m_blocks];
		delete temp[m_blocks];
		
		for (unsigned int i = 0; i < m_blocks; i++)
		{
		    m_data[i] = temp[i];
		}
		
		delete [] temp;
	}

	m_data[m_blocks - 1]->pop_back ();
	m_size--;
}

template <class generic>
void Dequeue<generic>::clear ()
{
    for (unsigned int i = 0; i < m_blocks; i++)
	{
	    delete m_data[i];
	}

    delete [] m_data;
    m_size = 0;
	m_blocks = 1;
    m_data = new Block<generic>*[m_blocks];
    m_data[0] = new Block<generic>;
	m_block_size = m_data[0]->max_size();
}

template <class generic>
Dequeue<generic> & Dequeue<generic>::operator= (const Dequeue<generic> & _copy_block)
{
    clear ();

    for (unsigned int i = 0; i < _copy_block.size(); i++)
	{
	    push_back (_copy_block[i]);
	}
	
	return *this;
}

template <class generic>
generic & Dequeue<generic>::operator[] (unsigned int _index)
{
    if (_index >= m_size)
	{
	    throw Exception (OUT_OF_BOUNDS, "Can not access that element.  It does not exist.");
	}

    unsigned int front_block_size = m_data[0]->size();
	unsigned int x = 0;
	unsigned int y = _index;
	
	if (_index >= front_block_size)
    {
	    x = ((m_block_size - front_block_size) + _index) / m_block_size;
		y = ((m_block_size - front_block_size) + _index) % m_block_size;
	}
	
	return m_data[x]->operator[](y);
}

template <class generic>
generic & Dequeue<generic>::operator[] (unsigned int _index) const
{
    if (_index >= m_size)
	{
	    throw Exception (OUT_OF_BOUNDS, "Can not access that element.  It does not exist.");
	}
	
    unsigned int front_block_size = m_data[0]->size();
	unsigned int x = 0;
	unsigned int y = _index;
	
	if (_index >= front_block_size)
    {
	    x = ((m_block_size - front_block_size) + _index) / m_block_size;
		y = ((m_block_size - front_block_size) + _index) % m_block_size;
	}
	
	return m_data[x]->operator[](y);
}

template <class generic>
unsigned int Dequeue<generic>::size () const
{
    return m_size;
}

template <class generic>
bool Dequeue<generic>::empty () const
{
    return m_size == 0 ? true : false;
}
