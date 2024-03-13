#include "Graph.h"

#include<iostream>
#include<fstream>

using namespace std;

int main(){

    Graph g;
//    cout<<g.isEdge(0,1)<<endl;
//    g.printGraph();

//      g.printList();
//      cout << "Max: " << g.maxFromList() << endl;
//      cout << "Min: " << g.minFromList() << endl;
      cout << "Max Matrix: " << g.maxFromMatrix() << endl;
      cout << "Min Matrix: " << g.minFromMatrix();

}