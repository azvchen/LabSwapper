// Austin Chen, 3/2/2016

#include "swapper.h"

#include "user.h"
#include "list.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

swapper::swapper(list l) {
  this->l = l;
  swaps = vector<int>(l.users.size());
  for(int i = 0; i < swaps.size(); i++)
    swaps[i] = -1;
}

void swapper::makeSwaps() {
  for(int u = l.users.size() - 1; u >= 0; u--)
    makeSwap(u, 0);
}

// Precondition: swaps[u] == -1
void swapper::makeSwap(int u, int v_init) {
  if(swaps[u] != -1) {
    return;
    //cout << "makeSwap went wrong" << endl;
    //exit(0);
  }
  user snd = l.users[u];
  for(int v = v_init; v < u; v++) {
    user fst = l.users[v];
    if(swappable(fst, snd)) {
      if(swaps[v] == -1) {
	swaps[u] = v;
	swaps[v] = u;
	break;
      } else {
	int w = swaps[v];
	if(w > u) {
	  swaps[v] = u;
	  swaps[u] = v;
	  swaps[w] = -1;
	  makeSwap(w, v + 1);
	  break;
	}
      }
    }
  }
}

void swapper::printSwaps() {
  cout << "Swaps:" << endl;
  for(int u = 0; u < swaps.size(); u++) {
    int v = swaps[u];
    if(v != -1 && u < v) {
      cout << l.users[u].name << " " << user::SECTIONS[l.users[u].current] << " <-> "
	   << user::SECTIONS[l.users[v].current] << " " << l.users[v].name << endl;
    }
  }
}

bool swapper::swappable(const user& a, const user& b) {
  return a.requests[b.current] && b.requests[a.current];
}
