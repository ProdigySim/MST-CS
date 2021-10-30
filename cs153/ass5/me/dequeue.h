#ifndef DEQUEUE_H
#define DEQUEUE_H

#include "block.h"
#include "exception.h"

template <class generic>
class Dequeue
{
  public:
    Dequeue ();
	Dequeue (Dequeue &);
    ~Dequeue ();
	void push_front (generic);
    void pop_front ();
    void push_back (generic);
    void pop_back ();
	void clear ();
	Dequeue & operator= (const Dequeue &);
	generic & operator[] (unsigned int);
    generic & operator[] (unsigned int) const;
    unsigned int size () const;
	bool empty() const;
    
  private:
    Block<generic> ** m_data;
    unsigned int m_size;
	unsigned int m_blocks;
	unsigned int m_block_size;
};

#include "dequeue.hpp"
#endif
