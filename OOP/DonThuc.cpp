#include <iostream>

using namespace std;

class DonThuc {
    private:
        float heso, bac;
    public:
        void Nhap();
        void Xuat();
        float gia_tri_tai_x(float x);
        void sosanh(DonThuc t);
        DonThuc Cong(DonThuc t);
        DonThuc Tru(DonThuc t);
        DonThuc Nhan(DonThuc t);
        DonThuc Chia(DonThuc t);
        float getHeSo();
        float getBac();
        DonThuc daoham();
        DonThuc nguyenham();
};

float DonThuc::getHeSo() {
    return heso;
}

float DonThuc::getBac() {
    return bac;
}

DonThuc DonThuc::nguyenham() {
    DonThuc s;
    s.heso = heso / bac;
    s.bac = bac + 1;
    return s;
}

DonThuc DonThuc::daoham() {
    DonThuc s;
    s.heso = heso * bac;
    s.bac = bac - 1;
    return s;
}

DonThuc DonThuc::Chia(DonThuc t) {
    DonThuc s;
    s.heso = heso / t.heso;
    s.bac = bac - t.bac;
    return s;
}

DonThuc DonThuc::Nhan(DonThuc t) {
    DonThuc s;
    s.heso = heso * t.heso;
    s.bac = bac + t.bac;
    return s;
}

DonThuc DonThuc::Tru(DonThuc t) {
    DonThuc s;
   if(bac != t.bac) {
        cout << "khong cung bac .... " << endl;
        s.heso = 0;
        s.bac = 0;
    } else {
        s.heso = heso - t.heso;
        s.bac = bac;
    }
    return s;
}

DonThuc DonThuc::Cong(DonThuc t) {
    DonThuc s;
    if(bac != t.bac) {
        cout << "khong cung bac .... " << endl;
        s.heso = 0;
        s.bac = 0;
    } else {
        s.heso = heso + t.heso;
        s.bac = bac;
    }
    return s;
}

float DonThuc::gia_tri_tai_x(float x) {
    float y = 1;
    for(int i = 0; i < bac; i++)
        y = y * x;
    return (heso * y);
}

void DonThuc::sosanh(DonThuc t) {
    if(bac > t.bac) {
        cout << "don thuc 1 > don thuc 2" << endl;
    } else if ( bac < t.bac) {
        cout << "don thuc 1 < don thuc 2" << endl;
    } else {
        if(heso > t.heso) {
            cout << "don thuc 1 > don thuc 2" << endl;
        } else if(heso < t.heso) {
            cout << "don thuc 1 < don thuc 2" << endl;
        } else cout << "don thuc 1 = don thuc 2" << endl;
    }
}

void DonThuc::Nhap() {
    cout << "nhap he so: ";
    cin >> heso;
    cout << "nhap bac: ";
    cin >> bac;
}

void DonThuc::Xuat() {
    cout << "\t" << heso << "x^" << bac << endl;  
}

int main() {
    DonThuc dt1, dt2;
    float x;
    dt1.Nhap();
    dt1.Xuat();
    cout << endl;
    cout << "sau khi dao ham = ";
    (dt1.daoham()).Xuat();
    cout << "sau khi nguyen ham = ";
    (dt1.nguyenham()).Xuat();
    dt2.Nhap();
    dt2.Xuat();
    cout << "sau khi dao ham = ";
    (dt2.daoham()).Xuat();
    cout << "sau khi nguyen ham = ";
    (dt2.nguyenham()).Xuat();
    cout << "nhap x = ";
    cin >> x;
    cout << " gia tri tai x = " << dt1.gia_tri_tai_x(x) << endl;
    cout << " gia tri tai x = " << dt2.gia_tri_tai_x(x) << endl;
    dt1.sosanh(dt2);
    cout << "Tong don thuc = ";
    (dt1.Cong(dt2)).Xuat();
    cout << "Hieu don thuc = ";
    (dt1.Tru(dt2)).Xuat();
    cout << "Tich don thuc = ";
    (dt1.Nhan(dt2)).Xuat();
    cout << "Thuong don thuc = ";
    (dt1.Chia(dt2)).Xuat();
    system("pause");
    return 0;
}