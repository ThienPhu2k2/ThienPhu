#include <bits/stdc++.h>

#define read(x, y) cin >> x >> y

using namespace std;

const int maxn = 1010, maxv = 1010;
int v[maxn], w[maxn];
int dp[maxv];

int main() {
    
    
    int N, V;
    read(N, V);
    for (int i = 1; i <= N; i++) {
        read(v[i], w[i]);
    } 

    for (int i = 1; i <= N; i++)
        for (int j = v[i]; j <= V; j++)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
         
    cout << dp[V] << endl;

    system("pause");
    return 0;
}