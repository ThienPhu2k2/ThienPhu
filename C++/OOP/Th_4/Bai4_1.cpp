#include <iostream>

using namespace std;

template<typename T>

T max(T str[], int n){
    T max = str[0];
    for(int i = 0; i < n; i++){
        if(str[i] > max){
            max = str[i];
        }
    }
    return max;
}

int main()
{
    string a[3];
    for(int i = 0; i < 3; i++){
        cout << "Nhap chuoi "<<i+1<<": ";
        cin >> a[i];
    }
    cout << max(a, 3) << endl;
    system("pause");
    return 0;
}