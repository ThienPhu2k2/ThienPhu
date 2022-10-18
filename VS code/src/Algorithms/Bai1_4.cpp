#include <bits/stdc++.h>

using namespace std;

int main() {
    long n;
    cin >> n;

    long a[n];
    for(int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    int k;
    cout << "nhap k so dau: ";
    cin >> k;

    for(int i = 0; i < k; i++) {
        swap(a[i], a[n - 1 - i]);
    }

    for(int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "]: " << a[i] << endl;
    }
    system("pause");
    return 0;
}