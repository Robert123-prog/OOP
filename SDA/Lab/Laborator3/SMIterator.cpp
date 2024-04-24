#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <iostream>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	//TODO - Implementation
    current = map.head;
}

void SMIterator::first(){
	//TODO - Implementation
    current = map.head;
}

void SMIterator::next(){
	//TODO - Implementation
    current = map.array[current].next;
}

bool SMIterator::valid() const{
	//TODO - Implementation
	if (current >= map.capacity - 1 || current <= -1 || current == map.firstEmpty || map.isEmpty()){
        return false;
    }
    return true;
}

TElem SMIterator::getCurrent() const{
	//TODO - Implementation
	if (!valid()){
        throw std::runtime_error("Invalid Position!");
    }
    return map.array[current].info;
}


