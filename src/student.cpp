// Austin Chen (azc2rc) 4/28/2016
// student.cpp

#include "student.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

student::student(string n, int c, int s) {
  name = n;
  current = c;
  sections = s;
  requests = new bool[s];
}

student::student(const student &s) {
  name = s.name;
  current = s.current;
  sections = s.sections;
  requests = new bool[sections];
  for(int i = 0; i < sections; i++)
    requests[i] = s.requests[i];
}

student::~student() {
  delete[] requests;
}

void student::print() {
  cout << name << " (" << current << "):";
  for(int i = 0; i < sections; i++)
    if(requests[i])
      cout << " " << i;
  cout << endl;
}

student student::randomStudent(string n, int s, int seed) {
  srand((seed == -1) ? time(NULL) : seed);
  for(int i = 0; i < 5; i++)
    rand();
  
  int current = rand() % s;
  bool *requests = new bool[s];
  
  int r = rand() % 100;
  int numRequests;
  if(r < 50)
    numRequests = 1;
  else if(r < 80)
    numRequests = 2;
  else if(r < 95)
    numRequests = 3;
  else
    numRequests = 4;
  if(numRequests >= s)
    numRequests = s - 1;
  for(int i = 0; i < s; i++) {
    if(rand() % (s - i) < numRequests) {
      requests[i] = true;
      numRequests--;
    } else
      requests[i] = false;
  }
  
  student stud(n, current, s);
  stud.requests = requests;
  return stud;
}
