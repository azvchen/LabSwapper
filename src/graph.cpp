// Austin Chen (azc2rc) 5/9/2016
// graph.cpp

#include "graph.h"

#include <string>
#include <vector>
#include <list>
#include "edge.h"
#include <iostream>
using namespace std;

graph::graph() {
  graph(1);
}

graph::graph(int nvs) {
  numVertices = nvs;
  // names = vector<string>(nvs);
  adjList = vector< list<edge> >(nvs);
  for(int i = 0; i < numVertices; i++)
    adjList[i] = list<edge>();
}

void graph::addVertex(string name) {
  names.push_back(name);
}

void graph::addEdge(int c, int v, int w) {
  edge e(v, w, c);
  adjList[v].push_back(e);
}

void graph::addEdge(int c, string v, string w) {
  addEdge(c, index(v), index(w));
}

int graph::getEdge(int v, int w) const {
  for(list<edge>::const_iterator it = adjList[v].begin(); it != adjList[v].end(); it++)
    if(it->finish == w)
      return it->capacity;
  return 0;
}

int graph::getEdge(string v, string w) const {
  return getEdge(index(v), index(w));
}

void graph::incrementEdge(int i, int v, int w) {
  for(list<edge>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++)
    if(it->finish == w) {
      it->capacity += i;
      return;
    }
  addEdge(i, v, w);
}

void graph::incrementEdge(int i, string v, string w) {
  incrementEdge(i, index(v), index(w));
}

void graph::zeroAllEdges() {
  for(int i = 0; i < numVertices; i++)
    adjList[i] = list<edge>();
}

int graph::size() const {
  return numVertices;
}

void graph::printAsList() const {
  for(int i = 0; i < numVertices; i++) {
    cout << names[i] << ":";
    for(list<edge>::const_iterator it = adjList[i].begin(); it != adjList[i].end(); it++) {
      cout << " (" << names[it->finish] << ", " << it->capacity << ")";
    }
    cout << endl;
  }
}

int graph::index(string name) const {
  for(int i = 0; i < numVertices; i++)
    if(names[i] == name)
      return i;
  return -1;
}
