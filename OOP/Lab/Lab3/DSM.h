//
// Created by user on 30-Mar-24.
//

#ifndef LAB3_DSM_H
#define LAB3_DSM_H

#include <vector>
#include <string>


class DSM {
private:
    std::vector<std::string> elementNames;
    std::vector<std::vector<float>> adjacencyMatrix;


public:
    DSM(int elementCount);

    DSM(std::vector<std::string> elementNames);

    ~DSM(); //destructor
    DSM(const DSM &other); //copy constructor

    int size() const;

    std::string getName(int index) const;

    void setElement(int index, std::string name);

    void addLink(std::string fromElement, std::string toElement, float weight);

    void deleteLink(std::string fromElement, std::string toElement);


    bool haveLink(std::string fromElement, std::string toElement) const;

    float linkWeight(std::string fromElement, std::string toElement) const;

    int countToLinks(std::string elementName) const;

    int countFromLinks(std::string elementName) const;

    int countAllLinks() const;

};


#endif //LAB3_DSM_H
