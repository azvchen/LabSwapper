// Austin Chen, 2/17/2016

#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class user {
 public:
  user(string n, int c);
  user(const user & u);
  
  static const int NUM_SECTIONS = 6;
  static const string SECTIONS[6];
  
 private:
  string name;
  int current;
  bool requests[6];

  friend class list;
};

#endif
