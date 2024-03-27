#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> adjList;

Graph::Graph(string filename){

    ifstream f;
    f.open("data.in");
    f >> n;
    adjList.resize(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for (int j = 0;j < n;j++) {


            f >> adjList[i][j];

        }
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
//    adjList[x].push_back(y);
//    adjList[y].push_back(x);


}

void Graph::addEdgeMatrix(int x, int y) {
//    matrix[x][y] = 1;
//    matrix[y][x] = 1;


    adjList[x][y] = 1;
    adjList[y][x] = 1;

}

bool Graph::isEdge(int x, int y){
    return matrix[x][y] == 1;
}

void Graph::printGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

}

vector<vector<int>> Graph::power(int n) {
    vector<vector<int>> res = adjList;


    for (int i = 1; i < n; i++) {
        vector<vector<int>> newRes = res;


        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int sum = 0;
                for (int l = 0; l < n; l++) {
                    sum += res[j][l] * adjList[l][k];
                }
                newRes[j][k] = sum;
            }
        }


        res = newRes;
    }

    return res;

}

std::vector<std::vector<int>> Graph::sumOfPowers(int n) {
    vector<vector<int>> res = adjList;

    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }


    for (int i = 1; i < n; i++) {
        vector<vector<int>> newRes = res;


        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int sum = 0;
                for (int l = 0; l < n; l++) {
                    sum += res[j][l] * adjList[l][k];
                }

            }
        }


        for (int j = 0;j < n;j++){
            for (int k = 0;k < n;k++){
                res[j][k] += newRes[j][k];
            }
        }

    }

    return res;


}

bool Graph::isConnected() {
    std::vector<std::vector<int>> sumOfPows;

    for (int i = 0;i < n;i++){
        sumOfPows = adjList.
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




