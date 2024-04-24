#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> adjList;

Graph::Graph(string filename){

      ifstream fin("data.in");
      fin >> n >> m;

      adjList.resize(n + 1);

      int x, y;

      for (int i = 0;i < m;i++){
          fin >> x >> y;
          adjList[x].push_back(y);
          adjList[y].push_back(x);
      }

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
    for (int i = 0; i < adjList.size() - 1; i++) {
        cout << i << " : ";

        for (auto j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

}

void Graph :: BFS(int x){
    int queue[n]; // retine nodurile care urmeaza sa fie vizitate
    int st = 0, dr = 0, index = 0; // start , end of queue, current idx
    visited[x] = true;
    queue[dr++] = x;
    while(st!=dr) //while queue not empty -> pops first node, marks neighbors as visited and pushes them on the queue if not visited before

    {
        int currentNode = queue[st++];
        for(int i = 0; i< adjList[currentNode].size(); i++)
        {
            int neighbor = adjList[currentNode][i];
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                queue[dr++] = neighbor;
            }

        }
    }
}

bool Graph::connected() {

    visited.assign(n, false);
    int numberComponents = 0;
    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
            //verif daca graf este conex facand BFS din fiecare nod nevizitat
        {
            BFS(i);
            numberComponents++;
        }
    }
    //daca exista o singura comp conexa ret true
    if(numberComponents == 1)
        return true;

    return false;
}

bool Graph::isBinaryTree(int x) {
    visited.assign(n, false);
    vector<int> parent(n, -1); // arr ca sa retine parintele fiecarui nod
    vector<int> queue; // queue pentru trecerea prin BFS

    queue.push_back(x);
    visited[x] = true;

    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.erase(queue.begin());

        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push_back(neighbor);
                parent[neighbor] = currentNode; // update neighbor of parent
            } else {
                // daca parintele e vizitat si nu vecinul => ciclu
                if (parent[currentNode] != neighbor) {
                    return false;
                }
            }
        }
    }

    // verif graf conex
    if (!connected()) {
        return false;
    }

    //  verif daca exista exact un nod fara parinte
    int rootCount = 0;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == -1) {
            rootCount++;
        }
    }
    if (rootCount != 1) {
        return false;
    }

    // verif daca fiecare nod are 0, 1 sau 2 copii
    for (int i = 0; i < n; ++i) {
        if (adjList[i].size() > 2) {
            return false;
        }
    }

    return true;
}

void Graph::printInorder() {

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> inorder;

    int currentNode = 0;
    visited[currentNode] = true;
    vector<int> stack(1, currentNode);

    while (!stack.empty()) {
        int nextNode = -1;

        // cauta urmatorul vecin care nu a fost parcurs
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                nextNode = neighbor;
                break;
            }
        }

        if (nextNode != -1) {
            // mergi la urmatorul vecin neparcurs
            visited[nextNode] = true;
            parent[nextNode] = currentNode;
            stack.push_back(nextNode);
            currentNode = nextNode;
        } else {
            // daca au fost parcursi toti vecinii, backtracking inapoi
            inorder.push_back(currentNode);
            stack.pop_back();
            if (!stack.empty()) {
                currentNode = stack.back();
            }
        }
    }

    //returneaza in order
    cout << "In-Order Traversal: ";
    for (int node : inorder) {
        cout << node << " ";
    }
    cout << endl;
}




//void Graph::printList() {
//    for (int i = 0;i < m;i++){
//        cout << i << ": ";
//
//        for (int j = 0; j < adjList[i].size(); j++){
//            cout << adjList[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

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




