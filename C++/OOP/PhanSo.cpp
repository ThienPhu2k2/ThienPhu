#include <iostream>

using namespace std;

// -------------------------------------- CÁCH BÌNH THƯỜNG ------------------------------------------------------
/*class PhanSo {
    private:
        int tu;
        int mau;
    public:
        void Nhap();
        void Xuat();
        PhanSo Tong(PhanSo p);
        void Tru(PhanSo p);
        float Nhan(PhanSo p);
        PhanSo Chia(PhanSo p);
        int getTu();
        int getMau();
};

void SoSanh(PhanSo p, PhanSo q) {
    if((float)p.getTu()/p.getMau() > q.getTu()/q.getMau()) {
        cout << "ps1 > ps2" << endl;
    } else if((float)p.getTu()/p.getMau() < q.getTu()/q.getMau()) {
        cout << "ps1 < ps2" << endl;
    } else cout << "ps1 = ps2" << endl;
}

int PhanSo::getTu() {
    return tu;
}

int PhanSo::getMau() {
    return mau;
}

PhanSo PhanSo::Tong(PhanSo p) {
    PhanSo s;
    s.tu = tu*p.mau + mau*p.tu;
    s.mau = mau*p.mau;
    return s;
}

void PhanSo::Tru(PhanSo p) {
    cout << tu*p.mau - mau*p.tu << "/" << mau*p.mau << endl;
}

float PhanSo::Nhan(PhanSo p) {
    return (float)(tu*p.tu / mau*p.mau);
}

void PhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}

void PhanSo::Xuat() {
    cout << "\t" << tu << "/" << mau << endl;
}

int main() {
    PhanSo ps1, ps2;
    ps1.Nhap();
    ps1.Xuat();
    ps2.Nhap();
    ps2.Xuat();
    SoSanh(ps1, ps2);
    cout << "Tong = ";
    (ps1.Tong(ps2)).Xuat();
    cout << "Tru = ";
    ps1.Tru(ps2);
    cout << "Tich = " << ps1.Nhan(ps2) << endl;
    system("pause");
    return 0;
}*/

//-------------------------------------------- NẠP CHỒNG TOÁN TỬ ------------------------------------------------------
class PhanSo {
    private:
        int tu, mau;
    public:
        friend istream& operator >> (istream &is, PhanSo &ps);
        friend ostream& operator << (ostream &os, const PhanSo &ps);
        friend PhanSo operator + (PhanSo a, PhanSo b);
        friend PhanSo operator - (PhanSo a, PhanSo b);
        friend PhanSo operator * (PhanSo a, PhanSo b);
        friend PhanSo operator / (PhanSo a, PhanSo b);
        friend PhanSo operator += (PhanSo a, PhanSo b);
};

PhanSo operator += (PhanSo a, PhanSo b) {
    PhanSo t;
    t.tu = b.tu*a.mau + a.tu*b.mau;
    t.mau = b.mau * a.mau;
    return t;
}

PhanSo operator / (PhanSo a, PhanSo b) {
    PhanSo t;
    t.tu = a.tu * b.mau;
    t.mau = a.mau * b.tu;
    return t;
}

PhanSo operator * (PhanSo a, PhanSo b) {
    PhanSo t;
    t.tu = a.tu * b.tu;
    t.mau = a.mau * b.mau;
    return t;
}

PhanSo operator - (PhanSo a, PhanSo b) {
    PhanSo t;
    t.tu = a.tu*b.mau - b.tu*a.mau;
    t.mau = a.mau * b.mau;
    return t;
}

PhanSo operator + (PhanSo a, PhanSo b) {
    PhanSo t;
    t.tu = a.tu*b.mau + b.tu*a.mau;
    t.mau = a.mau * b.mau;
    return t;
}

ostream& operator << (ostream &os, const PhanSo &ps) {
    os << "\t" << ps.tu << "/" << ps.mau << endl;
    return os;
}

istream& operator >> (istream &is, PhanSo &ps) {
    cout << "Nhap tu = ";
    is >> ps.tu;
    cout << "Nhap mau = ";
    is >> ps.mau;
    return is;
}

int main() {
    PhanSo ps1, ps2, ps3;
    cout << "Nhap phan so: " << endl;
    cin >> ps1;
    cin >> ps2;
    cout << "Phan so da nhap: " << endl;
    cout << ps1;
    cout << ps2;
    /*ps3 = ps1 + ps2;
    cout << "Tong = ";
    cout << ps3;
    ps3 = ps1 - ps2;
    cout << "Hieu = ";
    cout << ps3;
    ps3 = ps1 * ps2;
    cout << "Tich = ";
    cout << ps3;
    ps3 = ps1 / ps2;
    cout << "Chia = ";
    cout << ps3;*/
    ps3 = ps1 + ps2;
    cout << ps3;
    system("pause");
    return 0;
}