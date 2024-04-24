#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;


SortedMap::SortedMap(Relation r) {
	//TODO - Implementation
    relation = r;
    capacity = 1;
    array = new Node[capacity];
    head = -1;
    tail = -1;
    currentSize = 0;
    firstEmpty = 0;


}

TValue SortedMap::add(TKey k, TValue v) {
	//TODO - Implementation

    //If arr is empty
    if (head == -1){
        currentSize++;
        head = firstEmpty;
        tail = firstEmpty;
        array[firstEmpty] =  Node{make_pair(k, v), -1, -1};
        firstEmpty++;
        resizeUp();
        return NULL_TVALUE;

    }

    if (currentSize == capacity - 1){
        resizeUp();
    }

    if (!relation(array[head].info.first, k)){

            Node newNode{make_pair(k, v), head, -1};;
            array[firstEmpty] = newNode; ////TODO TO BE CHECKED
            array[head].prev = firstEmpty;
            head = firstEmpty;

            for (int i = 0; i < capacity;i++){
                if (search(array[i].info.first) == NULL_TVALUE){
                    firstEmpty = i;
                    return NULL_TVALUE;
                }
            }


    }

    if (!relation(array[tail].info.first, k)){
        Node newNode{make_pair(k, v), -1, tail};
        array[firstEmpty] = newNode;
        array[tail].prev = firstEmpty;
        tail = firstEmpty;

        for (int i = 0;i < capacity;i++){
            if (search(array[i].info.first) == NULL_TVALUE){
                firstEmpty = i;
                return NULL_TVALUE;
            }
        }
    }
////TODO adauga cazul cheie existanta in toate!!!!!!!!!!!!!
////TODO DE TERMINAT PLM

    if (relation(array[head].info.first, k) && relation(array[tail].info.first, k)){
        Node newNode{make_pair(k, v), -1, -1};
        array[firstEmpty] = newNode;

        auto current = 0;
        while (current != -1 && relation(k, array[current].info.first)){
            current++;
        }

        ////current = firstEmpty
        array[current]



    }


}

TValue SortedMap::search(TKey k) const {
	//TODO - Implementation
    if (isEmpty())
        return NULL_TVALUE;
    int current = head;
    while (current != -1) { // iterate trough nodes
        if (array[current].info.first == k) // compare keys
            return array[current].info.second;
        current = array[current].next; // go to next node
    }
    return NULL_TVALUE; // key is not in array

}


TValue SortedMap::remove(TKey k) {
	//TODO - Implementation
	return NULL_TVALUE;
}

int SortedMap::size() const {
	//TODO - Implementation
	return currentSize;
}

bool SortedMap::isEmpty() const {
	//TODO - Implementation
	return currentSize == 0;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

void SortedMap::resizeUp() {
    capacity *= 2;

    Node *newArray = new Node[capacity];

    for (int i = 0;i < currentSize;i++){
        newArray[i] = array[i];
    }

    for (int i = currentSize;i < capacity;i++){
        newArray[i] = Node{make_pair(NULL_TVALUE, NULL_TVALUE), -1, -1};
    }

    delete[] array;
    array = newArray;

}

void SortedMap::resizeDown() {
    capacity = capacity / 2;

    Node *newArray = new Node[capacity];

    for (int i = 0;i < currentSize;i++){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;

}

SortedMap::~SortedMap() {
	//TODO - Implementation
    delete[] array;
}
