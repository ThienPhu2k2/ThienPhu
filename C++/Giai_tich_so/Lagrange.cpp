#include <iostream>

using namespace std;
#define MAX 50

void nhap(float x[], float y[], int &n);
void tinh(float x[], float y[], int n, float c);

int main()
{
    int n;
    float c, x[MAX], y[MAX];
    
    cout << "Nhap n = ";
    cin >> n;

    cout << "Nhap so can tinh = ";
    cin >> c;

    nhap(x, y, n);

    tinh(x, y, n, c);

    system("pause");
    return 0;
}

void nhap(float x[], float y[], int &n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "x["<<i<<"] = ";
        cin >> x[i];
        cout << "y["<<i<<"] = ";
        cin >>y[i];
    }
}

void tinh(float x[], float y[], int n, float c)
{
    float G, P = 0;
    for(int i = 0; i < n; i++)
    {
        G = 1;
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                G = G * ( (c - x[j]) / (x[i] - x[j]) );
            }
        }
        P = P + y[i] * G;
    }
    cout << "Phep tinh gan dung = " << P << endl;
}