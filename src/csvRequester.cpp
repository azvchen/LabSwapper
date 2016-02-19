// Austin Chen, 2/18/2016

#include "user.h"
#include "list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int parseSection(string id) {
  for(int i = 0; i < user::NUM_SECTIONS; i++)
    if(user::SECTIONS[i] == id)
      return i;
  cout << "Invalid section name." << endl;
  exit(-1);
  //return -1;
}

void parseUser(list& l, string str) {
  int pos = str.find("\"");
  while(pos != string::npos) {
    str.erase(pos, 1);
    pos = str.find("\"");
  }
  
  istringstream ss(str);
  ss.ignore(50, ',');
  char *name = new char[10];
  ss.getline(name, 10, ',');
  char *scurrent = new char[10];
  ss.getline(scurrent, 10, ',');
  l.addUser(name, parseSection(scurrent));

  char *srequest = new char[10];
  while(ss.good()) {
    ss.getline(srequest, 10, ';');
    l.addSection(name, parseSection(srequest));
  }

  delete name;
  delete scurrent;
  delete srequest;
}

int main(int argc, char **argv) {
  if(argc == 1) {
    cout << "Command line argument: csv file of swap requests." << endl;
    return 1;
  }
  
  list l;
  ifstream csvfile(argv[1]);
  csvfile.ignore(500, '\n');
  char *buffer = new char[500];
  while(csvfile.good()) {
    csvfile.getline(buffer, 500);
    string line = string(buffer);
    parseUser(l, line);
  }
  csvfile.close();
  delete buffer;

  l.printSwaps();
  l.printUsers();
  
  return 0;
}
