#include <iostream>
#include <typeinfo>

using namespace std;


class MyClass {
public:
  // Reference member, has to be Initialized in Member Initializer List
  int &i;
  int b;
  // Non static const member, must be Initialized in Member Initializer List
  const int k;

  // Constructor’s parameter name b is same as class data member
  // Other way is to use this->b to refer to data member
  MyClass(int a, int b, int c) : i(a), b(b), k(c) {
    // Without Member Initializer
    // this->b = b;
    cout << "private"<< endl;

  }
};

class MyClass2 : public MyClass {
public:
  int p;
  int q;
  MyClass2(int x, int y, int z, int l, int m) : MyClass(x, y, z), p(l), q(m), count(0) {}
private:
  size_t count;
};

int main() {
  int x = 10;
  int y = 20;
  int z = 30;
  MyClass obj(x, y, z);

  int l = 40;
  int m = 50;
  MyClass2 obj2(x, y, z, l, m);

  return 0;
}