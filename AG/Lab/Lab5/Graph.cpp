#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<Edge> adjList;

Graph::Graph(string filename) {

    ifstream fin(filename);
    fin >> n >> m;
    int n1, n2;
    for (int i = 0; i < m; i++) {
        fin >> n1 >> n2;
        adjList.add_edge(n1, n2);
        adjList.add_edge(n2, n1);
    }


}

void Graph::printGraph() {
    for (Edge* current = adjList.head; current != nullptr; current = current->next) {
        cout << current->knoten1 << " " << current->knoten2 << endl;
    }
}


void Graph::fleury() {
    int oddDegreeVertices = countOddDegreeVertices();

    // only if there are 0 or 2 odd deg vertices
    if (oddDegreeVertices == 0 || oddDegreeVertices == 2) {
        // start from a vertex with odd degree or if all degrees are even -> any vertex
        int startVertex = adjList.head->knoten1;
        int currentVertex = startVertex;

        while (adjList.head != nullptr) {
            Edge *edge = adjList.head;

            int nextVertex;
            if (edge->knoten1 == currentVertex) {
                nextVertex = edge->knoten2;
            } else {
                nextVertex = edge->knoten1;
            }

            // if next edge is valid => print it + mark as visited
            if (nextEdgeValid(currentVertex, nextVertex)) {
                cout << currentVertex << " " << nextVertex << endl;
                markEdgeVisited(currentVertex, nextVertex);
                currentVertex = nextVertex;
            } else {
                // if next edge not valid =>  remove from adjacency list
                removeEdge(currentVertex, nextVertex);
            }
        }
    }
    //else eulerscher kantenzug existiert nicht
    else {
        std::cout << "keinen eulerscher kantenzug" << std::endl;
    }
}

void Graph::removeEdge(int x, int y) {
    Edge* prev = nullptr;
    Edge* current = adjList.head;


    // iterate through sll to find edge to remove
    while (current != nullptr) {
        if ((current->knoten1 == x && current->knoten2 == y) || (current->knoten1 == y && current->knoten2 == x)) {
            // if edge is found => remove from list
            if (prev == nullptr) {
                // if edge to remove == head
                adjList.head = current->next;
            } else {
                // if edge to remove != head
                prev->next = current->next;
            }
            delete current;
            return;
        }
        // next edge
        prev = current;
        current = current->next;
    }
}

bool Graph::nextEdgeValid(int x, int y) {
    int degree = 0;
    for (Edge* edge = adjList.head; edge != nullptr; edge = edge->next) {
        if ((edge->knoten1 == x && edge->knoten2 == y) || (edge->knoten1 == y && edge->knoten2 == x)) {
            degree++;
        }
    }
    return degree == 1 && !isEdgeVisited(x, y);
}

int Graph::countOddDegreeVertices() {
    sll vertices;
    for (Edge* edge = adjList.head; edge != nullptr; edge = edge->next) {
        vertices.add_edge(edge->knoten1, 0);
        vertices.add_edge(edge->knoten2, 0);
    }
    int oddDegreeVertices = 0;
    for (Edge* edge = adjList.head; edge != nullptr; edge = edge->next) {
        vertices.add_edge(edge->knoten1, vertices.head->knoten2 + 1);
        vertices.add_edge(edge->knoten2, vertices.head->knoten2 + 1);
    }
    for (Edge* vertex = vertices.head; vertex != nullptr; vertex = vertex->next) {
        if (vertex->knoten2 % 2 != 0) {
            oddDegreeVertices++;
        }
    }
    return oddDegreeVertices;
}

bool Graph::isEdgeVisited(int x, int y) {
    for (Edge* edge = adjList.head; edge != nullptr; edge = edge->next) {
        if ((edge->knoten1 == x && edge->knoten2 == y) || (edge->knoten1 == y && edge->knoten2 == x)) {
            return true;
        }

    }
    return false;
}

void Graph::markEdgeVisited(int x, int y) {
    for (Edge* edge = adjList.head; edge != nullptr; edge = edge->next) {
        if ((edge->knoten1 == x && edge->knoten2 == y) || (edge->knoten1 == y && edge->knoten2 == x)) {
            adjList.head = edge->next;
            delete edge;
            return;
        }
    }
}










