// Austin Chen (azc2rc) 5/2/2016
// maxFlowFinder.cpp

#include "maxFlowFinder.h"

#include "graph.h"

maxFlowFinder::maxFlowFinder(const graph &g) {
  this->g = g;
}

graph maxFlowFinder::fordFulkerson() {
  graph flow = g;
  flow.zeroAllEdges();

  while(addFlow(0, -1, flow) > 0);
  
  return flow;
}

int maxFlowFinder::addFlow(int v, int minResid, graph &flow) {
  if(v == g.size() - 1) {
    return minResid;
  }
  for(int w = 0; w < g.size(); w++) {
    int resid = residual(v, w, g, flow);
    int newMinResid;
    if(resid > 0) { // there is possibly a flow going through w
      if(minResid == -1 || resid < minResid) // minResid may not have been set yet
        newMinResid = resid;
      else
        newMinResid = minResid;
      
      newMinResid = addFlow(w, newMinResid, flow);
      if(newMinResid > 0) {
        flow.incrementEdge(newMinResid, v, w);
        flow.incrementEdge(-1 * newMinResid, w, v);
        return newMinResid;
      }
    }
  }
  return 0;
}

int maxFlowFinder::residual(int v, int w, const graph &g, const graph &h) {
  return g.getEdge(v, w) - h.getEdge(v, w);
}
