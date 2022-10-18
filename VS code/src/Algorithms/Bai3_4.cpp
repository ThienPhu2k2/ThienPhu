#include <bits/stdc++.h>

using namespace std;

void findMinRoute(vector<vector<int> > tsp) {
	int sum = 0;
	int counter = 0;
	int j = 0, i = 0;
	int min = INT_MAX;
	map<int, int> visitedRouteList;

	visitedRouteList[0] = 1;
	int route[tsp.size()];

	while (i < tsp.size() && j < tsp[i].size()) {

		if (counter >= tsp[i].size() - 1) {
			break;
		}

		if (j != i && (visitedRouteList[j] == 0)) {
			if (tsp[i][j] < min) {
				min = tsp[i][j];
				route[counter] = j + 1;
			}
		}
		j++;

		if (j == tsp[i].size()) {
			sum += min;
			min = INT_MAX;
			visitedRouteList[route[counter] - 1] = 1;
			j = 0;
			i = route[counter] - 1;
			counter++;
		}
	}

	i = route[counter - 1] - 1;

	for (j = 0; j < tsp.size(); j++) {

		if ((i != j) && tsp[i][j] < min) {
			min = tsp[i][j];
			route[counter] = j + 1;
		}
	}
	sum += min;

	cout << ("Minimum Cost is : ");
	cout << (sum);
}

int main() {

	vector<vector<int> > tsp = { { -1, 15, 12, 6, 4, 8, 11 },
								 { 15, -1, 6, 23, 5, 4, 1 },
								 { 12, 6, -1, 16, 13, 10, 2 },
								 { 6, 23, 16, -1, 26, 14, 9 },
                                 { 4, 5, 13, 26, -1, 24, 5 },
                                 { 8, 4, 10, 14, 24, -1, 7 },
                                 { 11, 1, 2, 9, 5, 7, -1 } };

	findMinRoute(tsp);

    system("pause");
    return 0;
}