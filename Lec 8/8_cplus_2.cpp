Module interface Unit:
// math1.cppm 
export module math1; 

export int add(int fir, int sec);

Main program:
// main.cpp 

import math1;
 
int main(){ 
  add(2000, 20); 
}


Module Implementation Unit:
// math1.cpp
module math1; 

int add(int fir, int sec){ 
  return fir + sec; 
}