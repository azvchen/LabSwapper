// Austin Chen, 2/17/2016

#ifndef LIST_H
#define LIST_H

#include "user.h"
#include <string>
#include <vector>
using namespace std;

class list {
 public:
  list();

  bool addUser(string name, int current);
  bool removeUser(string name);
  bool hasUser(string name);

  int currentSection(string name);
  bool addSection(string name, int section);
  bool removeSection(string name, int section);
  bool requestsSection(string name, int section);
  
  void printUser(string name);
  void printUsers();

  void printSwaps();

  void saveToFile(string filename);

 private:
  vector<user> users;

  vector<user>::iterator getUser(string name);

  friend class swapper;
};

#endif
