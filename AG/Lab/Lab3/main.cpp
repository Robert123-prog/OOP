#include <iostream>
#include "Graph.h"
#include <cassert>


int main() {
    Graph g("data.in");
    g.printGraph();
    std::cout << std::endl;
    bool a = g.isBinaryTree(0);
    std::cout << a << std::endl;

   g.printInorder();
}
