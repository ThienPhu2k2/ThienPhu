#include <bits/stdc++.h>

#define MAXN 1007

using namespace std;

int volumn[MAXN], value[MAXN];

void bag(int n, int m) {
    int d[n + 1][m + 1];
    memset(d, 0, sizeof(d));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j < volumn[i]) {
                d[i][j] = d[i - 1][j];
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - volumn[i]] + value[i]);
            }
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++)
            cout << d[i][j] <<" ";
        cout << endl;
    }
    cout << d[n][m] << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> volumn[i] >> value[i];
    bag(n, m);

    system("pause");
    return 0;
}
