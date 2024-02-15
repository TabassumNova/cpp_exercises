#include <iostream>

using std::cout;
using std::endl;

#define LOG(x) std::cout<< x << std::endl;


int& getvalue()
{
    int value = 10;
    int* p = &value;
    //LOG(p);
    return value;
}
/*
void setvalue(int& val)
{
    cout<< "Check: int val "<<val << endl;
}

void setvalue(const int& val)
{
    cout<< "Check: const int& val "<<val << endl;
}

void setvalue(int&& val)
{
    cout<< "Check: int&& val "<<val << endl;
}
*/
void setvalue(int* val)
{
    cout<< "Check: int* val "<<val << endl;
}

int main()
{
    //int i = getvalue();
    //getvalue() = 5;

    int x = 10;
    int* y;
    //setvalue(10);
    //setvalue(x);
    setvalue(y);




}
