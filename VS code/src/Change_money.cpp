#include <bits/stdc++.h>

using namespace std; 


int main()
{
     string str;
     cin >> str;
     char arr[100];
     size_t length;
     length = str.copy(arr, str.size());
     arr[length] = '\0';
     cout << arr << endl;
     for(int i = length-1; i > 0; i =- 3){
          int count = 0;
          for(int j = i; j > 0; j--){
               arr[j + 1] = arr[j];
               count++;
               if(j != length && count == 3){
                    arr[j] = ',';
                    break;
               }
          }
     }
     length++;
     arr[length] = '\0';
     cout << arr << endl;
     system("pause");
     return 0;
}