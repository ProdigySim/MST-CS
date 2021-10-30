#ifndef BLOCK_H
#define BLOCK_H

#include "exception.h"

template <class generic>
class Block
{
  public:
    Block ();
	Block (Block &);
    ~Block ();
	void push_front (generic);
    void pop_front ();
    void push_back (generic);
    void pop_back ();
	void clear ();
	Block & operator= (const Block &);
	generic & operator[] (unsigned int);
    generic & operator[] (unsigned int) const;
    unsigned int size () const;
    unsigned int max_size () const;
	bool ffull () const;
	bool bfull () const;
	bool empty () const;
    
  private:
    generic * m_data;
    unsigned int m_size;
	unsigned int m_max_size;
    unsigned int m_front;
    unsigned int m_back;
};

#include "block.hpp"
#endif
