#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
    idx = 0;
}


void SetIterator::first() {
	//TODO - Implementation
    idx = 0;
}


void SetIterator::next() {
	//TODO - Implementation
    idx += 1;
}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
    if (valid()){
        return set.bitarray[idx];
    }
	return NULL_TELEM;
}

bool SetIterator::valid() const {
	//TODO - Implementation
    return idx >= 0 && idx <= set.max;
}



