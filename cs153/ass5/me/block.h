#ifndef BLOCK_H
#define BLOCK_H

#define BLOCK_SIZE 3

#include <iostream>
#include "exception.h"

template <class generic>
class Block
{
  public:
    Block ();
    //~Block () { }
	Block (Block &);
	Block & operator= (const Block &);
	void push_front (generic);
    void pop_front ();
    void push_back (generic);
    void pop_back ();
	generic & operator[] (unsigned int);
    generic & operator[] (unsigned int) const;
	void clear ();
	void display ();
    unsigned int size () const;
    unsigned int max_size () const;
    bool ffull() const { return m_front; }
	bool bfull() const { return m_back ==3; }
	bool empty () const;
    
  private:
    generic m_data[BLOCK_SIZE];
    unsigned int m_size;
    unsigned int m_front;
    unsigned int m_back;
};

#include "block.hpp"
#endif
