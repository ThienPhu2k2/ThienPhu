#include <bits/stdc++.h>

using namespace std;
 
typedef struct {
    int s, f;
}T;
 
void sapXep(T a[], int left, int right) {
    int i, j;
    T x, y;
    i = left; j = right;
    x = a[(left + right)/2];

    do {
        while(x.f > a[i].f && i < right) i++;
        while(a[j].f > x.f && j > left) j--;
            if(i <= j) {
                y = a[i];
                a[i] = a[j];
                a[j] = y;
                i++;
                j--;
            }
    }
    while (i <= j);

    if (left < j){
        sapXep(a, left, j);
    } 
    if (i < right) {
        sapXep(a, i, right);
    }
}
 
 
 
int main() {
    int n; cin >> n;
    T *S = new T[n + 5];

    for(int i = 1; i <= n; i++) cin >> S[i].s >> S[i].f;

    sapXep(S, 1, n);
    int x = S[1].s;
    int d = 0;
    for(int i = 1;i <= n; i++) {
        if(x <= S[i].s) {
            d++;
            x = S[i].f;
        }
    }

    cout << "So phong co the hop: " << d << endl;
    system("pause");
    return 0;
}