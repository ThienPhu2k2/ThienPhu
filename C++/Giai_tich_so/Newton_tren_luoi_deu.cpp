#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
#define MAX 50

void nhap(float x[], float y[], int &n);
void bang_sai_phan_huu_han(float y[], float p[][MAX], int n);
void xuat_bang(float p[][MAX], int n);
float giai_thua(int t);

int main()
{
    int n;
    float c, x[MAX], y[MAX], p[MAX][MAX], h, u;
    cout << "Nhap n = ";
    cin >> n;
    cout << "Nhap gia tri can tinh gan dung = ";
    cin >> c;

    nhap(x, y, n);

    bang_sai_phan_huu_han(y, p, n);

    xuat_bang(p, n);

    h = abs(x[0] - x[1]);
    u = (c - x[0])/h;



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
        cin >> y[i];
    }
}

void bang_sai_phan_huu_han(float y[], float p[][MAX], int n)
{
    int k, l = 1;

    for(int i = 0; i < n; i++)
    {
        p[i][0] = y[i];
    }

    for(int i = 0; i < n; i++)
    {
        k = n;
        for(int t = 0; t < k--; t++)
        {
            p[t][l] = p[t + 1][i] - p[t][i];
        }
        l++;
    }
}

void xuat_bang(float p[][MAX], int n)
{
    int k = n + 1;
    for(int i = 0; i < n; i++)
    {
        k--;
        for(int j = 0; j < k; j++)
        {
            cout << setprecision(3) << p[i][j] << "  ";
        }
        cout << endl;
    }
}

float giai_thua(int n)
{
    if(n <= 1) return 1;
    return n * giai_thua(n - 1);
}