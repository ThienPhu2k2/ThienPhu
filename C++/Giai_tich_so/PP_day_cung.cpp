// Su dung phuong phap day cung tinh nghiem gan dung
 
#include <stdio.h>
#include <conio.h>
#include <math.h>
 
#define eps 0.02  // thay doi gioi han sai so o day 
 
float f(float x)
{
        // Thay doi ham so o day:
    return 5 * (x * x * x) - x * x - x - 1;
}
 
int main()
{
    float x, a, b;
    printf("\n Nhap khoang nghiem a, b: \n");
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
     
    x = a - (b - a) * f(a) / (f(b) - f(a));

    if (f(x) * f(a) < 0) {
        do {
            b = x;
            x = a - ((b - a) * f(a) / (f(b) - f(a)));
            printf("\n%f\t%f\t%f\t%f", a, b, x, f(x));
        }
        while (fabs(x - b) > eps);
    }
     
    else {
        do {
            a = x;
            x = a - ((b - a) * f(a) / (f(b) - f(a)));
            printf("\n%f\t%f\t%f\t%f", a, b, x, f(x));
        }
        while (fabs(x - a) > eps);
    }
     
    printf("\nNghiem cua phuong trinh x = %f ", x);
    _getch();
}