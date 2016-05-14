// Austin Chen (azc2rc) 5/2/2016
// maxFlowFinder.h

#ifndef MAXFLOWFINDER_H
#define MAXFLOWFINDER_H

#include "graph.h"

class maxFlowFinder {
 public:
  maxFlowFinder(const graph &g);
  
  graph fordFulkerson();
  
 private:
  int addFlow(int v, int minResid, graph &flow);
  static int residual(int v, int w, const graph &g, const graph &h);
  
  graph g;
};

#endif
