#include <iostream>

using namespace std;

int pow(int a, int n)
{
    if(n == 1) {
        return a;
    } else {
        int temp = pow(a, n/2);
        if(n % 2 == 0)
            return temp * temp;
        else
            return temp * temp * a;
    }
}

int main() {
    int a = 4, b = 3;
    cout << pow(a, b) << endl;

    system("pause");
    return 0;
}