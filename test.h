#include <iostream>

using namespace std;

template<typename T>

void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

float giai_thua(float n)
{
    if(n <= 1) 
        return 1;
    return n * giai_thua(n - 1);
}