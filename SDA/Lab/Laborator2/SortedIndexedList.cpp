#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
	//TODO - Implementation
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}

int SortedIndexedList::size() const {
	//TODO - Implementation
	return currentSize;
}

bool SortedIndexedList::isEmpty() const {
	//TODO - Implementation
	return currentSize == 0;
}

TComp SortedIndexedList::getElement(int i) const{
	//TODO - Implementation
	return NULL_TCOMP;
}

TComp SortedIndexedList::remove(int i) {
	//TODO - Implementation
	return NULL_TCOMP;
}

int SortedIndexedList::search(TComp e) const {
	//TODO - Implementation
	return 0;
}

void SortedIndexedList::add(TComp e) {
	//TODO - Implementation
}

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
	//TODO - Implementation
}
