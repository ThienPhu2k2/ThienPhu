#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void SelectionSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++){
        int minv = a[i], pMin = i;
        for(int j = i + 1; j < n; j++){
            if(minv > a[j]){
                minv = a[j];
                pMin = j;
            }
        }
        if(i != pMin){
            swap(a[i], a[pMin]);
        }
    }
}

void InsertionSort(int a[], int n)
{
    for(int i = 1; i < n; i++){
        int x = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > x){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void QuickSort(int a[], int left, int right)
{
    int x = a[(left + right)/2];
    int i = left, j = right;
    do{
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while(i < j);
    if(left < j){
        QuickSort(a, left, j);
    }
    if(right > i){
        QuickSort(a, i, right);
    }
}

int linearSearch(int a[], int n, int key)
{
    for(int i = 0; i < n; i++){
        if(a[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int a[], int n, int key)
{
    int left = 0, right = n - 1, mid;
    while(left <= right){
        mid = (left + right)/2;
        if(a[mid] == key)
            return mid;
        if(a[mid] < key)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}

// Ho ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay sinh: 12/05/2002
// Email: 6151071083@st.utc2.edu.vn
int main()
{
    int a[10] = {25, 55, 45, 40, 5, 10, 90, 85, 35, 12};
    cout << linearSearch(a, 10, 12) << endl;
    BubbleSort(a, 10);
    InsertionSort(a, 10);
    SelectionSort(a, 10);
    QuickSort(a, 0, 9);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << binarySearch(a, 10, 5) << endl;

    system("pause");
    return 0;
}