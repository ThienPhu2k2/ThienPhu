#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int a[100], b[100], c[100], k[100];
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i <= n-1; i++){
        for(int j= i + 1; j <= n; j++){
            if(b[i] > b[j]) {
                swap(b[i], b[j]);
                swap(a[i], a[j]);
            }
        }
    }
    for(int i = 1; i<=n; i++) {
        k[i] = c[i];
        for(int j = 1; j <= i-1; j++) {
            if((b[j] <= a[i]) && (k[i] < (k[j] + c[i]))) k[i] = k[j] + c[i];
        }
    }
    system("pause");
    return 0;
}