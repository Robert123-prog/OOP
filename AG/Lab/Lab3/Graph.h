#include <string>
#include <iostream>
#include <vector>


class Graph {
private:

    int n;
    int m;
    int matrix[100][100];
    std::vector<bool> visited;

public:

    Graph(std::string filename);

    void addEdge(int x, int y);

    void BFS(int x);

    bool connected();

    bool isBinaryTree(int x);

    void printInorder();

    bool isEdge(int x, int y);

    void printGraph();

    void printList();

    int maxFromList();

    int minFromList();

    void addEdgeMatrix(int x, int y);

    int maxFromMatrix();

    int minFromMatrix();

    std::vector<std::vector<int>>power(int n);

    bool isConnected();

    std::vector<std::vector<int>>sumOfPowers(int n);

};