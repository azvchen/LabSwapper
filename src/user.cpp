// Austin Chen, 2/17/2016

#include "user.h"

#include <string>
using namespace std;

user::user(string n, int c) {
  name = n;
  current = c;
  for(int i = 0; i < NUM_SECTIONS; i++)
    requests[i] = false;
}

user::user(const user & u) {
  name = u.name;
  current = u.current;
  for(int i = 0; i < NUM_SECTIONS; i++)
    requests[i] = u.requests[i];
}

const string user::SECTIONS[6] = {"101", "102", "103",
				  "104", "105", "106"};
