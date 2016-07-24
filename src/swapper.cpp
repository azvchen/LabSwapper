// Austin Chen (azc2rc) 4/28/2016
// swapper.cpp

#include "student.h"
#include "graph.h"
#include "maxFlowFinder.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>

#include <fstream>
#include <sstream>

using namespace std;

string sections[6] = {"101", "102", "103", "104", "105", "106"};
int numSections = 6;

vector<student> makeStudentsFromFile(string filename);
graph makeGraphFromStudents(const vector<student> &students);
int *findOptimalSwaps(const graph &g, int numStudents);
void printSwaps(int *swaps, const vector<student> &students);

int indexOfSection(string s);

int main(int argc, char **argv) {
  if(argc != 2) {
    cout << "Command line parameter: name of csv file." << endl;
    return 1;
  }
  string filename(argv[1]);

  vector<student> students = makeStudentsFromFile(filename);
  graph g = makeGraphFromStudents(students);
  g.printAsList();
  // graph nodes: S, then students, then labs, then T
  
  int *swaps = findOptimalSwaps(g, students.size());
  printSwaps(swaps, students);

  delete[] swaps;
  
  /*
  graph flow = fordFulkerson(g);
  flow.printAsList();

  vector<student> randomStuds;
  for(int seed = 2; seed < 20; seed++) {
    string n;
    n += seed + 63;
    student stud = student::randomStudent(n, numSections, seed);
    stud.print();
    randomStuds.push_back(stud);
  }
  graph randomG = makeGraphFromStudents(randomStuds);
  graph randomFlow = fordFulkerson(randomG);
  randomFlow.printAsList();
  */
}

vector<student> makeStudentsFromFile(string filename) {
  vector<student> students;
  
  // determine number of students
  int numStudents = -1; // account for filler first line
  ifstream file(filename.c_str());
  while(file.good()) {
    file.ignore(256, '\n');
    numStudents++;
  }
  file.close();

  // make list of students
  file.open(filename.c_str());
  file.ignore(256, '\n'); // ignore filler first line
  char *name_buffer = new char[16];
  char *curr_buffer = new char[16];
  char *rqst_buffer = new char[128];
  char *sect_buffer = new char[16];
  
  for(int i = 0; i < numStudents; i++) {
    file.ignore(32, ','); // ignore timestamp
    file.getline(name_buffer, 16, ',');
    string name(name_buffer);
    
    file.getline(curr_buffer, 16, ',');
    string curr(curr_buffer);
    int current = indexOfSection(curr);

    student stud = student(name, current, numSections);
    for(int s = 0; s < numSections; s++)
      stud.requests[s] = false;

    file.getline(rqst_buffer, 128);
    string rqst(rqst_buffer);
    if(rqst_buffer[0] == '"') {
      if(rqst[rqst.size() - 1] == '\r') // remove \r from rqst
	rqst = rqst.substr(0, rqst.size() - 1);
      istringstream iss(rqst.substr(1, rqst.size() - 2)); // remove " from rqst
      while(iss.good()) {
	iss.getline(sect_buffer, 16, ',');
	string sect(sect_buffer);
	stud.requests[indexOfSection(sect)] = true;
	iss.get();
      }
    } else
      stud.requests[indexOfSection(rqst.substr(0, rqst.size() - 1))] = true;

    students.push_back(stud);
  }
  delete[] name_buffer;
  delete[] curr_buffer;
  delete[] rqst_buffer;
  delete[] sect_buffer;

  // comment lines
  for(int i = 0; i < numStudents; i++)
    students[i].print();

  return students;
}

graph makeGraphFromStudents(const vector<student> &students) {
  // initialize graph
  int numStudents = students.size();
  graph g(1 + numStudents + numSections + 1);
  g.addVertex("_source_");
  for(int i = 0; i < numStudents; i++)
    g.addVertex(students[i].name);
  for(int i = 0; i < numSections; i++)
    g.addVertex(sections[i]);
  g.addVertex("_sink_");

  // add edges
  int *labEdges = new int[numSections];
  for(int i = 0; i < numSections; i++)
    labEdges[i] = 0;
  
  for(int i = 0; i < numStudents; i++) {
    student s = students[i];
    
    g.addEdge(1, "_source_", s.name);
    g.addEdge(-1, s.name, "_source_");
    
    for(int r = 0; r < numSections; r++) {
      if(s.requests[r]) {
        g.addEdge(1, s.name, sections[r]);
        g.addEdge(-1, sections[r], s.name);
      }
    }

    labEdges[s.current]++;
  }

  for(int i = 0; i < numSections; i++) {
    g.addEdge(labEdges[i], sections[i], "_sink_");
    g.addEdge(-1 * labEdges[i], "_sink_", sections[i]);
  }

  for(int i = 0; i < numStudents; i++) {
    int c = students[i].current;
    g.addEdge(1, students[i].name, sections[c]);
    g.addEdge(-1, students[i].name, sections[c]);
  }
  
  return g;
}

int *findOptimalSwaps(const graph &g, int numStudents) {
  maxFlowFinder mff(g);
  graph maxFlow = mff.fordFulkerson();
  maxFlow.printAsList();
  int *swaps = new int[numStudents];

  for(int stud = 0; stud < numStudents; stud++) {
    swaps[stud] = -1; // default value, no swap found
    for(int sect = 0; sect < numSections; sect++) {
      if(maxFlow.getEdge(1 + stud, 1 + numStudents + sect) == 1) {
        swaps[stud] = sect;
        break;
      }
    }
  }

  return swaps;
}

int indexOfSection(string s) {
  for(int i = 0; i < numSections; i++)
    if(sections[i] == s)
      return i;
  return -1;
}

void printSwaps(int *swaps, const vector<student> &students) {
  for(int i = 0; i < students.size(); i++) {
    student stud = students[i];
    cout << stud.name << ":\t" << stud.current << " -> ";
    if(swaps[i] == -1)
      cout << "none";
    else
      cout << swaps[i];
    cout << endl;
  }
}
