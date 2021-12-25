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
        friend bool operator >= (PhanSo a, PhanSo b);
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

bool operator >= (PhanSo a, PhanSo b){
    if((float)(a.tu)/a.mau >= (float)(b.tu)/b.mau)
        return true;
    return false;
}

int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    PhanSo ps[n], max, min;
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
    for(int i = 0; i < n; i++){
        if(ps[i] >= max)
            max = ps[i];
    }
    min = ps[0];
    for(int i = 0; i < n; i++){
        if(min >= ps[i])
            min = ps[i];
    }
    cout << "Phan so lon nhat = ";
    max.in();
    cout << "Phan so be nhat = ";
    min.in();
    system("pause");
    return 0;
}