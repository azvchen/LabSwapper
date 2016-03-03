// Austin Chen, 3/2/2016

#ifndef SWAPPER_H
#define SWAPPER_H

#include "user.h"
#include "list.h"

class swapper {
 public:
  swapper(list l);

  void makeSwaps();
  void printSwaps();

  static bool swappable(const user& a, const user& b);
  
 private:
  void makeSwap(int u, int v_init);
  
  list l;
  vector<int> swaps;
};

#endif
