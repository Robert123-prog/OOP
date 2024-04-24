#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {

    first();
}

////O(1)
void ListIterator::first(){

    current = list.head;
}

////O(1)
void ListIterator::next(){

    if (valid()) {
        current = current->next;
    }
    else {
        throw std::runtime_error("Invalid position");
    }
}

////O(1)
bool ListIterator::valid() const{

    if (current != nullptr){
        return true;
    }  else {
        return false;
    }
}


////O(1)
bool ListIterator::modifyCurrent(TComp elem) {
    if (!valid() || list.isEmpty()){
        return false;
    }

//    if (!list.relation(current->info, elem)){
//
//    }

    if (current == list.head){
        if (current->next != nullptr && !list.relation(elem, current->next->info)){
            return false;
        }
        current->info = elem;
        return true;
    }

    if (current == list.tail){
        if (current->prev != nullptr && !list.relation(current->prev->info, elem)){
            return false;
        }
        current->info = elem;
        return true;
    }

    if (current->prev != nullptr && !list.relation(current->prev->info, elem)){
        return false;
    }

    if (current->next != nullptr && !list.relation(elem, current->next->info)) {
        return false;
    }

    current->info = elem;
    return true;
}

////O(1)
TComp ListIterator::getCurrent() const{

	if (!valid()){
        throw std::runtime_error("Invalid position");
    }else{
        return current->info;
    }

}


