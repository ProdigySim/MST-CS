template <class generic>
Block<generic>::Block()
{
	m_front = BLOCK_SIZE;
	m_size = m_back = 0;
}

template <class generic>
Block<generic>::Block(Block<generic> & block)
{
	*this = block;
}

template <class generic>
void Block<generic>::push_front(generic x)
{
	if (!m_front)
	{
		throw Exception(FRONT_FULL, "You fail it. We're out of room (f)");
	} 
	else if (!m_size)
	{
		m_back = BLOCK_SIZE;
	}
	m_data[--m_front] = x;
	m_size++;
}

template <class generic>
void Block<generic>::pop_front()
{
	if(!m_size)
	{
		throw Exception(FRONT_EMPTY, "Emptiness!(f)");
	}
	m_front++;
	if (!(--m_size))
	{
		m_back = 0;
		m_front = BLOCK_SIZE;
	}
}

template <class generic>
void Block<generic>::pop_back()
{
	if(!m_size)
	{
		throw Exception(BACK_EMPTY, "Emptiness!(b)");
	}
	m_back--;
	if (!(--m_size))
	{
		m_back = 0;
		m_front = BLOCK_SIZE;
	}
}

template <class generic>
void Block<generic>::push_back(generic x)
{
	if (m_back == BLOCK_SIZE)
	{
		throw Exception(BACK_FULL, "You fail it. We're out of room (b)");
	} 
	else if (!m_size)
	{
		m_front = 0;
	}
	m_data[m_back++] = x;
	m_size++;
}



template <class generic>
void Block<generic>::clear()
{
	m_front = BLOCK_SIZE;
	m_back = m_size = 0;
}

template <class generic>
Block<generic> & Block<generic>::operator= (const Block<generic> &b)
{
	clear();
	for (unsigned int i = 0; i < b.size(); i++)
	{
		push_back(b[i]);
	}
	return *this;
}


template <class generic>
generic & Block<generic>::operator[] (unsigned int index)
{
	if(index >= m_size)
		throw Exception(OUT_OF_BOUNDS, "Too much spicy for me");
	return m_data[m_front+index];
}

template <class generic>
generic & Block<generic>::operator[] (unsigned int index) const
{
	if(index >= m_size)
		throw Exception(OUT_OF_BOUNDS, "Too much spicy for me");
	return m_data[m_front+index];
}

template <class generic>
void Block<generic>::display()
{
	unsigned int i;
	
	std::cout << "Actual: ";
	for (i = 0; i < BLOCK_SIZE; i++)
	{
		if (i < m_front+m_size && i >= m_front)
			std::cout << "[" << m_data[i] << "] ";
		else
			std::cout << "[x] ";
	}
	
	std::cout << std::endl << "Interface: ";
	for (i = 0; i < m_size; i++)
		std::cout << "[" << (*this)[i] << "] ";
	while (i++ < BLOCK_SIZE)
		std::cout << "[x] ";
	
	std::cout << std::endl;
}

template <class generic>
unsigned int Block<generic>::size() const
{
	return m_size;
}

template <class generic>
unsigned int Block<generic>::max_size() const
{
	return BLOCK_SIZE;
}

template <class generic>
bool Block<generic>::empty() const
{
	return !m_size;
}
