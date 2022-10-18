#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p = 1;
    float s = 0, t = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        t = t + i;
        p = p*i;
        s = s + t/p;
    }
    cout << "S = " << s << endl;

    system("pause");
    return 0;
}