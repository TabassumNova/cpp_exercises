#include <iostream>

using std::cout;
using std::endl;
using std::move;

//#define LOG(x) std::cout<< x << std::endl;
using namespace std;



template<class T>
void swap(T& a, T& b)
    {
    T tmp(move(a));
    a = move(b);
    b = move(tmp);
    }

int main()
{
    int x = 3;
    int y = 5;

    int &&rr = x*3;

    cout<<(&x)<<endl;
    cout<<(&y)<<endl;
    cout<<(&rr)<<endl;
    cout<<(rr)<<endl;

    //swap(x,y);

    //LOG(x);
    //LOG(y);
}
