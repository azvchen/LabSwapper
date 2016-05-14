// Austin Chen (azc2rc) 5/9/2016
// graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <list>
#include "edge.h"
using namespace std;

class graph {
 public:
  graph();
  graph(int nvs);
  // graph(const graph &g);
  // ~graph();

  void addVertex(string name);
  void addEdge(int c, int v, int w);
  void addEdge(int c, string v, string w);
  int getEdge(int v, int w) const;
  int getEdge(string v, string w) const;
  void incrementEdge(int i, int v, int w);
  void incrementEdge(int i, string v, string w);

  void zeroAllEdges();

  int size() const;

  void printAsList() const;
  // void printAsMatrix();

 private:
  int index(string name) const;

  int numVertices;
  vector<string> names;
  vector< list<edge> > adjList;
};

#endif
