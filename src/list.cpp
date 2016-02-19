// Austin Chen, 2/17/2016

#include "list.h"

#include "user.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

list::list() {
  users = vector<user>();
}

bool list::addUser(string name, int current) {
  if(hasUser(name))
    return false;
  users.push_back(user(name, current));
  return true;
}

bool list::removeUser(string name) {
  vector<user>::iterator it = getUser(name);
  if(it == users.end())
    return false;
  users.erase(it);
  return true;
}

bool list::hasUser(string name) {
  return getUser(name) != users.end();
}

int list::currentSection(string name) {
  return getUser(name)->current;
}

// adds section to user's requests
// return true if change was made, false otherwise
bool list::addSection(string name, int section) {
  vector<user>::iterator u = getUser(name);
  if(u->current == section || u->requests[section] == true)
    return false;
  u->requests[section] = true;
  return true;
}

// removes section from user's requests
// return true if change was made, false otherwise
bool list::removeSection(string name, int section) {
  vector<user>::iterator u = getUser(name);
  if(u->current == section || u->requests[section] == false)
    return false;
  u->requests[section] = false;
  return true;
}

bool list::requestsSection(string name, int section) {
  return getUser(name)->requests[section];
}

void list::printUser(string name) {
  user u = *(getUser(name));
  cout << u.name << " (" << user::SECTIONS[u.current] << "): ";
  for(int i = 0; i < user::NUM_SECTIONS; i++) {
    if(u.requests[i])
      cout << user::SECTIONS[i] << " ";
  }
  cout << endl;
}

void list::printUsers() {
  cout << "Users: " << endl;
  int i = 1;
  for(vector<user>::iterator u = users.begin(); u != users.end(); u++) {
    cout << i << ": ";
    printUser(u->name);
    i++;
  }
}

void list::printSwaps() {
  cout << "Swaps: " << endl;
  int i = 1;
  for(vector<user>::iterator u = users.begin(); u != users.end(); u++) {
    for(vector<user>::iterator v = u; v != users.end(); v++) {
      if(v->requests[u->current] && u->requests[v->current]) {
	cout << i << ": " << u->name << " " << user::SECTIONS[u->current] <<
	  " <-> " << user::SECTIONS[v->current] << " " << v->name << endl;
	i++;
      }
    }
  }
}

void list::saveToFile(string filename) {
  ofstream savefile;
  savefile.open(filename);
  savefile << user::NUM_SECTIONS << endl;

  for(vector<user>::iterator u = users.begin(); u != users.end(); u++) {
    savefile << u->name << " " <<  u->current;
    for(int i = 0; i < user::NUM_SECTIONS; i++) {
      if(u->requests[i])
	savefile << " " << i;
    }
    savefile << endl;
  }

  savefile.close();
}

vector<user>::iterator list::getUser(string name) {
  for(vector<user>::iterator it = users.begin(); it != users.end(); it++) {
    if(it->name == name) {
      return it;
    }
  }
  return users.end();
}
