#include "Graph.h"

#include<iostream>
#include <vector>
#include<fstream>

using namespace std;

int main(){

    Graph g("data.in");
//    cout<<g.isEdge(0,1)<<endl;
    g.printGraph();

    vector<vector<int>> res = g.power(2);

    cout << "Result: " << endl;

    for (auto i: res){
        for (auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }


//      g.printList();
//      cout << "Max: " << g.maxFromList() << endl;
//      cout << "Min: " << g.minFromList() << endl;
//      cout << "Max Matrix: " << g.maxFromMatrix() << endl;
//      cout << "Min Matrix: " << g.minFromMatrix();

}