#ifndef SNODE_H
#define SNODE_H

template <class generic>
struct Snode
{
    Snode<generic> * forward;
    generic data;
};

#endif
