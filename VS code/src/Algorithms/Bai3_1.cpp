#include <bits/stdc++.h>

using namespace std;

#define n 4

void bai1(int m[][n], int s) {
	vector<int> a;
	for (int i = 0; i < n; i++)
		if (i != s)
			a.push_back(i);
	int min_path = INT_MAX;
	do {

		int curr_weight = 0;
		int k = s;
		for (int i = 0; i < a.size(); i++) {
			curr_weight += m[k][a[i]];
			k = a[i];
		}
		curr_weight += m[k][s];
		min_path = min(min_path, curr_weight);
		cout << m[k][s] << "\t";

	} while (next_permutation(a.begin(), a.end()));
}

int main() {
	int m[][n] = { { 0, 10, 15, 20 },
					{ 15, 0, 25, 35 },
					{ 25, 35, 0, 30 },
					{ 10, 20, 25, 0 } };
	int s = 0;
	bai1(m, s);

    system("pause");
	return 0;
}