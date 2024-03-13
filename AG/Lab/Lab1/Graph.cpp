#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> adjList;

Graph::Graph(){

    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        addEdgeMatrix(x,y);
    }



//      ifstream fin("data.in");
//      fin >> n >> m;
//
//      adjList.resize(m);
//
//      int x, y;
//
//      for (int i = 0;i < m;i++){
//          fin >> x >> y;
//          addEdge(x, y);
//      }





}

void Graph::addEdge(int x, int y){
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

void Graph::addEdgeMatrix(int x, int y) {
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}

bool Graph::isEdge(int x, int y){
    return matrix[x][y] == 1;
}

void Graph::printGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void Graph::printList() {
    for (int i = 0;i < m;i++){
        cout << i << ": ";

        for (int j = 0; j < adjList[i].size(); j++){
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int Graph::maxFromList() {
    int globCnt = 0, locCnt = 0;
    for (int i = 0;i < adjList.size();i++){
        for (int j = 0;j < adjList[i].size(); j++){
            locCnt ++;
        }
        if (locCnt >= globCnt){
            globCnt = locCnt;
            locCnt = 0;
        };
    }

    return globCnt;
}

int Graph::minFromList() {
    int globCnt = INT_MAX, locCnt = 0;

    for (int i = 0;i < adjList.size();i++){
        for (int j = 0;j < adjList[i].size();j++){
            locCnt ++;
        }

        if (locCnt <= globCnt){
            globCnt = locCnt;
            locCnt = 0;
        }
    }

    return globCnt;
}

int Graph::maxFromMatrix() {
    int globSum = INT_MIN, locSum;

    for (int i = 0;i < n; i++){
        locSum = 0;

        for (int j = 0;j < n;j++){
            locSum += matrix[i][j];
        }

        if (locSum > globSum){
            globSum = locSum;
        }
    }

    return globSum;
}

int Graph::minFromMatrix() {
    int globSum = INT_MAX, locSum;

    for (int i = 0;i < n;i++){
        locSum = 0;

        for (int j = 0;j < n;j++){
            locSum += matrix[i][j];
        }

        if (locSum < globSum){
            globSum = locSum;
        }
    }

    return globSum;
}




