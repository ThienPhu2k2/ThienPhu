#include<iostream>
#include<math.h>
using namespace std;


class phanso {
    private:
	    int tu, mau;
    public:
	    PhanSo();
        ~PhanSo();
        void nhap();
        void in();
	    phanso operator =(phanso ps);
	    int operator >(phanso ps);
};



PhanSo::PhanSo(){
    tu = 0;
    mau = 1;
}

PhanSo::~PhanSo(){ }

void PhanSo::nhap(){
    cout << "Nhap tu so: ";
    cin >> tu;
    cout << "Nhap mau so: ";
    cin >> mau;
}

void PhanSo::in(){
    cout <<tu<<"/"<<mau << endl;
}

phanso phanso::operator =(phanso ps) {
	ps.tu = gettu();
	ps.mau = getmau();
	return ps;
}


int phanso::operator > (phanso ps) {
	if ((float(tu) / mau) > (float(ps.tu) / ps.mau)) {
		return 1;
	}
	else return 0;
}


void nhap_ds(int n, phanso a[]) {
	for (int i = 0; i < n; i++) {
		cout << "Phan so thu " << i + 1 << endl;
		cin >> a[i];
	}
}

void xuat_ds(int n, phanso a[]) {
	for (int i = 0; i < n; i++) {
		cout << "Phan so thu " << i + 1 << endl;
		cout << a[i];
	}
}


template<class T> T max(T *arr, int n){
	T maxV = arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>maxV){
			maxV=arr[i];
		}
	}
	return maxV;
}

void sothuc(){
	float b[100];
	int m;
	cout<<"Nhap mang so thuc"<<endl;
	cout<<"So phan tu: ";
	cin>>m;
	for(int i=0;i<m;i++){
		cout<<"b["<<i<<"]: ";
		cin>>b[i];
	}
	cout<<"Max: "<<max(b,m);
}

int main() {
	phanso a[100];
	int n;
	cout << "Nhap mang phan so" << endl;
	cout << "Nhap so phan tu: ";
	cin >> n;
	nhap_ds(n, a);
	xuat_ds(n,a);
	max(a,n);
	// sothuc();

    system("pause");
    return 0;

}