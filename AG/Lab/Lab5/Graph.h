#include <string>
#include <iostream>
#include <vector>


struct Edge{
    int knoten1;
    int knoten2;
    Edge* next;
};

struct sll{
    Edge *head;
    sll(): head(nullptr){};
    void add_edge(int node1, int node2){
        Edge* newNode= new Edge;
        newNode->knoten1 = node1;
        newNode->knoten2 = node2;
        newNode->next = head;
        head = newNode;
    }
};

class Graph {
private:
    int n, m;
    sll adjList;
public:
    Graph(std::string filename);
    void  printGraph();
    void fleury();
    bool nextEdgeValid(int x, int y); ////x, y = knoten
    int countOddDegreeVertices();
    bool isEdgeVisited(int u, int y);
    void markEdgeVisited(int x, int y);
    void removeEdge(int x, int y);
};