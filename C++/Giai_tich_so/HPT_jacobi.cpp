#include <stdio.h>
#include <conio.h>
#include <math.h>
typedef float matran[50][50];
typedef float mang[50];

//phuongphap Jacobi

void nhap(int &n, matran &a, mang &b)
{
    printf("\nNhap cap n = ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            float t;
            printf("a[%d][%d]=", i, j);
            scanf("%f", &t);
            a[i][j] = t;
        }
        printf("b[%d]=", i);
        scanf("%f", &b[i]);
    }
}

void xu_ly(int &n, matran &a, mang &b)
{
    int k, j = 0, c = 1;
    float x[50][50] = {}, t, sub;
    printf("nhap so lan lap=");
    scanf("%d", &k);
    while(j < k)
    {
        for(int i = 1; i <= n; i++)
        {
            sub = 0;
            t = 0;
            for(int j = 1; j <= n; j++)
            {
                if(i != j)
                {
                    sub = sub - (a[i][j] * x[j][c]);
                }
            }
                t = 1/a[i][i]*(b[i] + sub);
                x[i][c + 1] = t;
        }
        c++;
        j++;
    }
    printf("gia tri sau moi lan lap: \n");
    for(int i = 1; i <= k; i++)
    {
        printf("x[%d]", i);
        for(int j = 1; j <= k + 1; j++)
        {
            printf("\t%.3f", x[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    matran a;
    mang b;
    int n;
    nhap(n, a, b);
    xu_ly(n, a, b);
    getch();
    return 1;
}
