#include <iostream>
#include <initializer_list>
#include<utility>
using namespace std;

int foo(int i)
{
    return i++;
}

int main()
{
    int i = 1;
    i = foo(i);
    cout << i <<endl;
    return 0;

}

