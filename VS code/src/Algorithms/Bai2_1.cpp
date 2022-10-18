#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;

    vector<int> l(n);
    int result = 1;
    for (int i=0; i<n; i++) {
        l[i] = 0;
        for (int j=i-1; j>=0; j--) {
            if (a[i] > a[j]) {
                l[i] = max(l[i], l[j]);
            }
        }
        l[i] += 1;
        result = max(result, l[i]);
    }

    cout << "Day con dai nhat = " << result << endl;
    system("pause");
    return 0;
}