#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 50

void nhap(float x[], float y[], int &n);
void bang_ty_hieu(float P[][MAX], float x[], float y[], int n);
void tinh_ty_hieu(float P[][MAX], float x[],  int n);
void xuat_ty_hieu(float P[][MAX], int n);
void tinh_gia_tri_gan_dung(float P[][MAX], float x[], int n, float c);

int main()
{
    int n;
    float c, x[MAX], y[MAX], P[MAX][MAX];

    cout << "Nhap n = ";
    cin >> n;

    nhap(x, y, n);

    bang_ty_hieu(P, x, y, n);

    tinh_ty_hieu(P, x, n);

    xuat_ty_hieu(P, n);

    cout << "Nhap gia tri can tinh gan dung: " << endl << "c = ";
    cin >> c;

    tinh_gia_tri_gan_dung(P, x, n, c);

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

void bang_ty_hieu(float P[][MAX], float x[], float y[], int n)
{
    for(int i = 0; i < n; i++)
    {
        P[i][0] = x[i];
        P[i][1] = y[i];
    }
}

void tinh_ty_hieu(float P[][MAX], float x[], int n)
{
    int k = 0, l = 1;
    for(int j = 0; j < n; j++)
    {
        k = j + 2;
        for(int t = l; t < n; t++)
        {
            P[t][k] = (P[t][k - 1] - P[t - 1][k - 1]) / (x[t] - x[t - l]);
        }
        l++;
    }
}

void xuat_ty_hieu(float P[][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n + 2; j++)
        {
            cout << setprecision(3) << P[i][j] << "  ";
        }
        cout << endl;
    }
}

void tinh_gia_tri_gan_dung(float P[][MAX], float x[], int n, float c)
{
    float tich, KQ = 0;
    for(int i = 0; i < n; i++)
    {
        tich = 1;
        for(int j = 0; i < i; j++)
        {
            tich = tich * (c - x[j]);
        }
        KQ = KQ + P[i][i + 1] * tich;
    }

    cout << "Ket Qua = " << KQ << endl;
}