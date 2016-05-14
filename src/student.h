// Austin Chen (azc2rc) 4/28/2016
// student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class student {
 public:
  student(string n, int c, int s);
  student(const student &s);
  ~student();

  void print();
  static student randomStudent(string n, int s, int seed);
  
  string name;
  int current;
  int sections;
  bool *requests;
};

#endif
