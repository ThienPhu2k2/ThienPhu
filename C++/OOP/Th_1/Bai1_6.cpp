#include <iostream>
#include <cmath>

using namespace std;

class PhanSo {
    private:
        int tu, mau;
    public:
        PhanSo();
        ~PhanSo();
        void nhap();
        void in();
        friend bool operator > (PhanSo a, PhanSo b);
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

bool operator > (PhanSo a, PhanSo b){
    if((float)(a.tu)/a.mau > (float)(b.tu)/b.mau)
        return true;
    return false;
}

int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    PhanSo ps[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap ps["<<i<<"]: " << endl;
        ps[i].nhap();
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "ps["<<i<<"]: ";
        ps[i].in();
    }
    cout << endl;
    cout << "Sau sap xep: " << endl;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ps[i] > ps[j]){
                PhanSo temp = ps[j];
                ps[j] = ps[i];
                ps[i] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << "ps["<<i<<"]: ";
        ps[i].in();
    }
    system("pause");
    return 0;
}