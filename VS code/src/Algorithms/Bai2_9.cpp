#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n, t = 0, f[10001], d[10001];
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
	   	cin >> a[i];
	   	t = t + a[i];
	   }
	t = t/2;

	for (int i=1;i<=t;i++) {
		f[i] = INT_MAX;
	   for (int j = 1; j <= n; j++)
	      if (i >= a[j] && j > f[i - a[j]]) {
	      	f[i] = j;
	      	break;
		  }
	}

    system("pause");
    return 0;
}