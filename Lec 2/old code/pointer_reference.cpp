#include <iostream>

using std::cout;
using std::endl;

#define LOG(x) std::cout<< x << std::endl;

void increment(int* value)
{
    (*value)++;
}

void increment(int& value)
{
    value++;
}


int main()
{
/*
    int a = 5;
    int& r = a;
    LOG(a);

    r = 2;
    LOG(a)
    LOG(&a)
    LOG(&r)
    LOG(*&r)
    increment(&a);
    LOG(a);
    increment(a);
    LOG(a);
*/

    int i = 1, j = 2;
    int*pi = &i, *pj = &j;
    LOG(pi);
    LOG(pj);
    pi = pj;
    LOG(*pi);
    LOG(*pj);
    LOG(pi);
    LOG(pj);
    pi++;
    LOG(pi);

/*
    int i = 1, j = 2;
    int &ri = i, &rj = j;
    LOG(ri);
    LOG(rj);
    ri = rj;
    LOG(i);
    LOG(j);
    */

    return 0;
}
