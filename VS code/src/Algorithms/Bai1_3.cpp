#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, p = 1;
    float s = 0;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        p *= i;
        t = 2*i - 1;
        s += (float)t/p;
    }

    cout << "S = " << s << endl;

    system("pause");
    return 0;
}