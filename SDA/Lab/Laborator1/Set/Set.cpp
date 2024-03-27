#include "Set.h"
#include "SetIterator.h"
#include <cmath>

Set::Set() {
    this->capacity = 0;
    this->length = 0;
    this->bitArray = nullptr;
    this->min = 0;
}


////Explanation why relative positions:
////  using relative positions-> direct indexing into the array based on the elem value.
////  ex: if min is 100 and elem is 105,
////  the elem can be accessed at bitArray[105 - 100], which is bitArray[5]


////tetha(1) if no resize is needed
////tetha(n), if resize is needed, where n = newArrSize
////tetha(1), amortized complexity, as the worst case(resize, elem doesnt fit the arr) cant occur right after another one


bool Set::add(TElem elem) {

   //case : arr doesnt exist
   if (capacity == 0){
       capacity = 1;
       length = 1;
       min = elem;
       bitArray = new bool[capacity];

       //add elem to the single element arr
       bitArray[0] = true;
       return true;
   }



   //elem can be added in the arr, without resize

   if (elem >= min && elem < min + capacity){

       //check if elem already in arr
       if (bitArray[elem - min]){
           return false;
       }

       else {
           bitArray[elem - min] = true;
       }
   }

   //case: elem < min

   else if (elem < min){
       //by how many positions to the right must the old array be moved
       int positionsToMoveBy = min - elem;

       int newArrSize = capacity + positionsToMoveBy;
       bool* newArr = new bool[newArrSize];

       //add elem
       newArr[0] = true;


       //elems before previous min and current min need to be cleared
       for (int i = 1; i < positionsToMoveBy; i++){
           newArr[i] = false;
       }

       //copy elems of original array into the new array, but with positions shifted according to positionsToMoveBy
       for (int i = 0;i < capacity;i++){
           newArr[i + positionsToMoveBy] = bitArray[i];
       }
       delete[] bitArray;

       bitArray = newArr;
       capacity = newArrSize;
       min = elem;


   }

   //case: elem > max

   else {
        int max = min + capacity - 1;
        int newArrCapacity = capacity + (elem - max);
        bool* newArr = new bool[newArrCapacity];

        //copy elems of old arr into new arr

        for (int i = 0;i < capacity;i++){
            newArr[i] = bitArray[i];
        }

        //elems after capacity of old arr cleared

        for (int i = capacity;i < newArrCapacity - 1;i++){
            newArr[i] = false;
        }

        //add the elem
        newArr[newArrCapacity - 1] = true;

        delete[] bitArray;
       bitArray = newArr;
       capacity = newArrCapacity;
   }

    length++;
    return true;



}


////tetha(1), if the removed elem doesnt lead to a sparse array or the elem does not exist
////tetha(n), where n = capacity, if the resize operation is needed; as the first or last capacity/2 elements are copied into the new array
bool Set::remove(TElem elem) {
    if (!search(elem))
        return false;

    //remove elem from arr + update length
    bitArray[elem - min] = false;
    length--;

    //case 1: Elem removed was the minimum

    if (elem == min) {

        //idx of first true elem in the set
        int idxOfFirstElem = 0;

        while (idxOfFirstElem < capacity && bitArray[idxOfFirstElem] == 0) {
            idxOfFirstElem++;
        }

        //If first half of arr is empty => resize

        if (idxOfFirstElem >= capacity / 2) {

            int newMin = min + idxOfFirstElem;
            int newArrCapacity = capacity - idxOfFirstElem;
            bool *newArr = new bool[newArrCapacity];


            //copy old arr into new one
            //resize is done accordingly: the add method uses relative positions to the min
            //so the remove must do the resizing in case elem < min accordingly
            for (int i = idxOfFirstElem; i < capacity; i++) {
                newArr[i - idxOfFirstElem] = bitArray[i];
            }
            delete[] bitArray;

            bitArray = newArr;
            capacity = newArrCapacity;
            min = newMin;

        }


    }

    //case 2: Elem removed was the max
    //min + capacity - 1 = max elem

    else if (elem == min + capacity - 1){
        //idx of last true elem in the set
        int idxLastElem = capacity - 1;

        while (idxLastElem > 0 && bitArray[idxLastElem] == 0){
            idxLastElem--;
        }

        //If second half of arr is empty => resize

        if (idxLastElem <= capacity / 2) {

           int newArrCapacity = idxLastElem + 1;
           bool* newArr = new bool[newArrCapacity];

           for (int i = 0;i < newArrCapacity;i++){
               newArr[i] = bitArray[i];
           }
           delete[] bitArray;

           bitArray = newArr;
           capacity = newArrCapacity;

        }

    }

    return true;
}

////tetha(1)
bool Set::search(TElem elem) const {

    //if elem not in arr => false
    if (elem < min || elem >= min + capacity)
        return false;
    else
        return bitArray[elem - min];

}

////tetha(1)
int Set::size() const {
    return length;
}

////tetha(1)
bool Set::isEmpty() const {
    return length == 0;
}

////O(n)
Set::~Set() {
    delete[] bitArray;
}


SetIterator Set::iterator() const {
    return SetIterator(*this);
}


