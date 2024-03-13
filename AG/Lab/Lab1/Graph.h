class Graph {
private:

    int n;
    int m;
    int matrix[100][100];
    
public:

    Graph();

    void addEdge(int x, int y);

    bool isEdge(int x, int y);

    void printGraph();

    void printList();

    int maxFromList();

    int minFromList();

    void addEdgeMatrix(int x, int y);

    int maxFromMatrix();

    int minFromMatrix();

};