#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <stdexcept>

SortedIndexedList::SortedIndexedList(Relation r) {

    head = nullptr;
    tail = nullptr;
    currentSize = 0;
    relation = r;
}

//// O(1)
int SortedIndexedList::size() const {

	return currentSize;
}

//// O(1)
bool SortedIndexedList::isEmpty() const {

	return currentSize == 0;
}

////tetha(1) if pos = 1
////tetha(n) if pos = currentSize
TComp SortedIndexedList::getElement(int pos) const{

	if (pos < 0 || pos >= currentSize){
        throw std::runtime_error("Invalid position");
    }

//    int idx = 0;
    Node *current = head;

    while (pos > 0){
        current = current->next;
        pos--;
    }

    return current->info;

}

////tetha(1) if remove first
////tetha(n) else
////O(n) average
TComp SortedIndexedList::remove(int pos) {

	if (pos < 0 || isEmpty() || pos >= currentSize){
        throw std::runtime_error("Invalid Position");
    }

    Node *current = head;
    TComp element;

    if (pos == 0){
        head = head->next;
        if (head != nullptr){
            head->prev = nullptr;
        }
        element = current->info;
        delete current;
        currentSize--;

        if (isEmpty()) {
            tail = nullptr; // Update tail if list becomes empty
        }
        return element;
    }

//    int idx = 0;
    while (pos > 0){
        current = current->next;
        pos--;
    }

    if (current == nullptr){
        throw std::runtime_error("Invalid position");
    }

    if (current->prev != nullptr){
        current->prev->next = current->next;
    } else{
        head = current->next;
    }

    if (current->next != nullptr){
        current->next->prev = current->prev;
    } else{
        tail = current->prev;
    }
    element = current->info;
    delete current;
    currentSize--;
    return element;

}

////tetha(1) if elem to find is first in the list
////tetha(n) else
////O(n) average
int SortedIndexedList::search(TComp e) const {


    Node* current = head;
    int idx = 0;
    while (current != nullptr) {
        if (current->info == e) {
            return idx;
        }
        current = current->next;
        idx++;
    }
    return -1;
//
//    if (isEmpty()) {
//        return -1; // Return -1 if the list is empty
//    }
//
//    int st = 0;
//    int dr = currentSize - 1;
//
//    while (st <= dr) {
//        int mid = (st + dr) / 2;
//        TComp midElement = getElement(mid);
//
//        if (e > midElement) {
//            st = mid + 1;
//        } else if (e < midElement) {
//            dr = mid - 1;
//        } else {
//            return mid; // Return the index of found element
//        }
//    }
//
//    return -1; // Return -1 if elem not found
}

////tetha(1) best case = list is empty or elem to be inserted at the beginning
////tetha(n) worst case = list must be traversed
////O(n) average
void SortedIndexedList::add(TComp e) {


    Node *newNode = new Node;
    newNode->info = e;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // If the list is empty, or if new elem should be inserted at the beginning
    if (isEmpty() || relation(e, head->info)) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        // If the list was empty => update tail
        if (tail == nullptr) {
            tail = newNode;
        }
    } else {
        // Traverse list to find correct position to insert new node
        Node *current = head;
        while (current->next != nullptr && relation(current->next->info, e)) {
            current = current->next;
        }
        // Insert new node after the current node
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode; // Update tail if inserting at the end
        }
        current->next = newNode;
    }

    currentSize++; // Increment the size of the list

}

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}

//destructor
////O(n)
SortedIndexedList::~SortedIndexedList() {


    Node *current = head;

    while (current != nullptr){
        Node *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}
