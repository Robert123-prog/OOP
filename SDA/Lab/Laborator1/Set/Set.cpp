#include "Set.h"
#include "SetIterator.h"
#include <cmath>

Set::Set() {
	//TODO - Implementation
    capacity = 10;
    bitarray = new bool[capacity];
}


bool Set::add(TElem elem) {
	//TODO - Implementation
    if (!search(elem)){
        if (elem < min){

            for (int i = min;i < capacity - 1;i++){
                bitarray[i + 1] = bitarray[i];
            }

            min = elem;
        }
    }
	return false;
}


bool Set::remove(TElem elem) {
	//TODO - Implementation
    bitarray[elem] = 0;
	return false;
}

bool Set::search(TElem elem) const {
	//TODO - Implementation
    if (bitarray[elem] == 1){
        return true;
    }
	return false;
}


int Set::size() const {
	//TODO - Implementation
    return capacity;
	return 0;
}


bool Set::isEmpty() const {
	//TODO - Implementation
	return false;
}


Set::~Set() {
	//TODO - Implementation
    delete[] bitarray;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


