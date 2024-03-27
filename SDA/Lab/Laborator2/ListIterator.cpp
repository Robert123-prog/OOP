#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	//TODO - Implementation
    first();
}

void ListIterator::first(){
	//TODO - Implementation
    current = list.head;
}

void ListIterator::next(){
	//TODO - Implementation
    current = current->next;
}

bool ListIterator::valid() const{
	//TODO - Implementation
	if (current != nullptr){
        return true;
    }
    else{
        return false;
    }
}

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
	if (!valid()){
        throw std::runtime_error("Invalid position");
    }
    else{
        return current->info;
    }
}


