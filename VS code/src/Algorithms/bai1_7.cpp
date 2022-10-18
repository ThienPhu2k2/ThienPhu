#include <bits/stdc++.h>

using namespace std;

void deleteElement(int arr[], int &n, int key) {
    for(int i = key; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void sameElement(int arr[], int &n) {
    for(int i = 0; i < n + 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                deleteElement(arr, n, j);
                i--;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "]: ";
        cin >> arr[i];
    }

    sameElement(arr, n);

    for(int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "]: " << arr[i] << endl;
    }

    system("pause");
    return 0;
}