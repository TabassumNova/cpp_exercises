#include <iostream>
#include <type_traits>
#include <vector>
#include <typeinfo>
#include <string>

// using std::cout;
// using std::endl;
// using std::vector;
using namespace std;

// 1. placeholder type specifiers

template<class T, class U>
auto add(T t, U u) { return t + u; }

int main()
{

  auto res = add(2,3.0);
  // string cars[1] = {"Volvo"};

  cout << res << " has type " << typeid(res).name() << endl;
  //static_assert(std::is_same<vector<int>::iterator ,decltype(it)>::value, "the type is wrong");


  return 0;
}
