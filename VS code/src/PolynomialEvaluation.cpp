
//  DO PHUC TAP CUA THUAT TOAN LA O(no^2)
//  SO PHEP SO SANH: 2
//  SO PHEP GAN: 9

#include <bits/stdc++.h>

using namespace std; 

int horner(int a[], int n, int x)
{
    float p = 0.0;
    for(int i = n; i > 0; i--)
    {
        int power = 1;
        for(int j = 1; j < i; j++)
        {
            power *= x;
        }
        p = p + a[i] * power;
    }
    return p;
}

//      IMPROVEMENT
// DO PHUC TAP CUA THUAT TOAN LA O(N)
// SO PHEP SO SANH: 1
// SO PHEP GAN: 3

int HORNER(int A[], int N, int X)
{
    int P = A[0];
    for (int i = 1; i < N; i++)
        P = P * X + A[i];
 
    return P;
} 

int main()
{
    int a[] = {2, -6, 2, -1};
    int x = 3;
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Value of anomial is " << horner(a, n, x) << endl;
    system("pause");
    return 0;
}

