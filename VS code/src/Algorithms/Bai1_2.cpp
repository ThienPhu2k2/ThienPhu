#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p = 1, t = 1;
    float s = 1;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        p *= 2*(i + 1);
        t *= 2*i + 3;
        s = s + (float)p/t;
    }

    cout << "S = " << s << endl;

    system("pause");
    return 0;
}