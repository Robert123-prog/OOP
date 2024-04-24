//
// Created by user on 30-Mar-24.
//

#include "DSM.h"
#include <stdexcept>

//constructor 1
DSM::DSM(int elementCount) {
    adjacencyMatrix.resize(elementCount,  std::vector<float> (elementCount, 0.0));
}

//constructor 2
DSM::DSM(std::vector<std::string> elementNames) : elementNames(elementNames){
    int elementCount = elementNames.size();
    adjacencyMatrix.resize(elementCount, std::vector<float>(elementCount, 0.0));
}

//destructor
DSM::~DSM() {

}

//copy constructor
DSM::DSM(const DSM &other) : elementNames(other.elementNames), adjacencyMatrix(other.adjacencyMatrix) {}


//return size of DSM
int DSM::size() const {
    return adjacencyMatrix.size();
}

//returns name of elem at given index
std::string DSM::getName(int index) const {
    if (index < 0 || index >= elementNames.size()){
        throw std::runtime_error("Element not found");
    }

    return elementNames[index];
}

//sets elem at given index
void DSM::setElement(int index, std::string name) {
    if (index < 0){
        throw std::runtime_error("Invalid index");
    }

    if (index >= elementNames.size()){
        elementNames.resize(index + 1);
    }

    elementNames[index] = name;
}

//adds links between from elem to to elem
void DSM::addLink(std::string fromElement, std::string toElement, float weight) {
    int fromIndex = -1, toIndex = -1;

    for (int i = 0; i < elementNames.size(); ++i){
        //check if current elem position matches fromElement and toElement position

        if (elementNames[i] == fromElement){
            fromIndex = i;
        }

        if (elementNames[i] == toElement){
            toIndex = i;
        }
    }

    if (fromIndex == -1 || toIndex == -1){
        throw std::runtime_error("Element not found");
    }

    adjacencyMatrix[fromIndex][toIndex] = weight;
}

//deletes links between from elem and to elem
void DSM::deleteLink(std::string fromElement, std::string toElement) {
    addLink(fromElement, toElement, 0.0);
}

//checks if from elem and to elem are linked
bool DSM::haveLink(std::string fromElement, std::string toElement) const {
    int fromIndex, toIndex = -1;

    for (auto i = 0; i < elementNames.size(); ++i){
        if (elementNames[i] == fromElement){
            fromIndex = i;
        }

        if (elementNames[i] == toElement){
            toIndex = i;
        }
    }

    if (fromIndex == -1 || toIndex == -1){
        throw std::runtime_error("Element not found");
    }

    return adjacencyMatrix[fromIndex][toIndex] != 0.0;
}

//returns link weight between from elem and to elem
float DSM::linkWeight(std::string fromElement, std::string toElement) const {
    int fromIndex, toIndex = -1;

    for (auto i = 0; i < elementNames.size(); ++i){
        if (elementNames[i] == fromElement){
            fromIndex = i;
        }

        if (elementNames[i] == toElement){
            toIndex = i;
        }
    }

    if (fromIndex == -1 || toIndex == -1){
        throw std::runtime_error("Element not found");
    }

    return adjacencyMatrix[fromIndex][toIndex];
}

//counts all from links of given elem
int DSM::countToLinks(std::string elementName) const {
    int idx = -1;

    // Find the index of the specified element
    for (int i = 0; i < elementNames.size(); i++) {
        if (elementNames[i] == elementName) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        throw std::runtime_error("Element not found");
    }

    int count = 0;

    // Iterate over the rows of the adj matrix
    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        // Check if there is a link from the current element to the specified element
        if (adjacencyMatrix[i][idx] != 0.0) {
            count++;
        }
    }

    return count;
}

//counts all to links of given elem
int DSM::countFromLinks(std::string elementName) const {
    int idx = -1;

    // Find the index of the specified element
    for (int i = 0; i < elementNames.size(); i++) {
        if (elementNames[i] == elementName) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        throw std::runtime_error("Element not found");
    }

    int count = 0;

    // Iterate over the columns of the adjacency matrix
    for (int i = 0; i < adjacencyMatrix[idx].size(); i++) {
        // Check if there is a link from the specified element to the current element
        if (adjacencyMatrix[idx][i] != 0.0) {
            count++;
        }
    }

    return count;
}



//counts all links in the matrix
int DSM::countAllLinks() const {
    int count = 0;

    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        for (int j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != 0.0) {
                // Increment the count for each non-zero element
                count++;
            }
        }
    }

    return count;
}



