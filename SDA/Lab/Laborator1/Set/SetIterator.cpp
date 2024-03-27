#include "SetIterator.h"
#include "Set.h"
#include <stdexcept>



SetIterator::SetIterator(const Set& m) : set(m)
{

    //first called to find first elem in arr
    first();
}

////tetha(1) if the first elem of the set is true
////tetha(capacity) if there are no true values is the arr, or the only true values are at the end
void SetIterator::first() {
    idx = 0;

    while (valid() && set.bitArray[idx] == 0){
        idx++;
    }


}

////tetha(1) best case: if next elem is true
////tetha(capacity) worst case: if there are no true values is the arr, or the only true values are at the end
void SetIterator::next() {

    if (!valid()) {
        //exception necessary to be thrown, so test doesn`t fail
        throw std::runtime_error("Iterator is at the end");
    }

    idx++;

    while (valid()){

        //when an elem is found => break
        if (set.bitArray[idx]){
            break;
        }
        idx++;
    }
}

////tetha(1)
TElem SetIterator::getCurrent()
{
    if (!valid()){
        //exception necessary to be thrown, so test doesn`t fail
        throw std::runtime_error("Current value is false");
    }
    return idx + set.min;
}

////tetha(1)
bool SetIterator::valid() const {

    if (this->idx >= 0 && this->idx < set.capacity){
        return true;
    }
    else {
        return false;
    }
}

////throws exception if elem is not true
////calcutates elem to remove based on relative position to min (like add and remove function from set)
////O(1)

void SetIterator::deleteCurrent() {
    if(!valid()){
        throw std::runtime_error("The iterator is not on a valid position!");
    }

    TElem elemToRemove = idx - set.min;
    set.bitArray[elemToRemove] = false;
    next();

}



