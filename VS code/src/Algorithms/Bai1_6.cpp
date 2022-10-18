#include <bits/stdc++.h>

using namespace std;

long int dem(int n){
	int count = 0;
	int sqr;

	 for(int i = 1; i <= n; i++){
	 	sqr = sqrt(i);
	 	if(sqr * sqr == i){
	 		count++;
		 }
	 }

	 return count;
}

int main(){
    int n = 10000000;
    cout << "\nCac so chinh phuong: " << dem(n) << endl;
    system("pause");
    return 0;
}