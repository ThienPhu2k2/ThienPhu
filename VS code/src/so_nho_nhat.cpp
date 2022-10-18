#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, k, m, count, temp;
    cin >> t;
    while (t > 0) {
        cin >> n;
        cin >> k;

        for(long i = pow(10, n-1); i < pow(10, n); i++) {
            m = i;
            count = 0;

            for(int j = 0; j < n; j++) {
                temp = m % 10;
                m /= 10;
                count += temp;
            }

            if(count == k) {
                cout << i << endl;
                break;
            }
        }

        if(count != k) {
            cout << -1 << endl;
        }
        --t;
    }

    system("pause");
    return 0;
}
