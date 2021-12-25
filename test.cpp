#include <iostream>
#include <string>
#include <conio.h>
#include "test.h"

using namespace std;

template<typename T>

T tong(T a, T b){
    return a + b;
}

int main()
{
    int a = 3, b = 10;
    float c = 4.5, d = 6.1;
    cout << tong(a,b) << endl;
    cout << tong(c,d) << endl;
    _getch();
}