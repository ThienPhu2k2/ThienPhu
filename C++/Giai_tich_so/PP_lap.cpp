// Su dung pp lap tim nghiem gan dung   
 
#include <stdio.h>
#include <conio.h>
#include <math.h>
 
#define eps 0.01  // thay doi gioi han sai so o day
 
float tinh_ham(float x)
{
    // Thay ham so can tim o day:
    return (5 * pow(x, 3) + 3) / 20;
}
 
int main()
{
    float x, y;
    printf("\nNhap x: ");
    scanf("%f", &x);

    do {
        y = x;
        x = tinh_ham(x);
        printf("\n%.3f\t%.3f", x, y);
    }
    while (fabs(x - y) > eps);
     
    printf("\n\nNghiem gan dung cua pt la: %f", x);
    _getch();
}