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
        friend int UCLN(int a, int b);
        friend PhanSo rut_gon(PhanSo &ps);
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

int UCLN(int a, int b){
    a = abs(a);
    b = abs(b);
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

PhanSo rut_gon(PhanSo &ps){
    int c = UCLN(ps.tu, ps.mau);
    ps.tu = ps.tu / c;
    ps.mau = ps.mau / c;
    return ps;
}

int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    PhanSo ps[n], sum;
    for(int i = 0; i < n; i++){
        cout << "Nhap ps["<<i<<"]: " << endl;
        ps[i].nhap();
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "ps["<<i<<"]: ";
        rut_gon(ps[i]);
        ps[i].in();
    }
    system("pause");
    return 0;
}
