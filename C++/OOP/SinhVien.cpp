#include <iostream>
#define MAX 50

using namespace std;

class SinhVien {
    private:
        string MSV;
        string hoten;
        int namsinh;
        string lop;
        float DTB;
    public:
        static int stt;
        static int so_thu_tu();
        friend istream& operator >> (istream &is, SinhVien &sv);
        friend ostream& operator << (ostream &os, const SinhVien &sv);
        friend bool operator > (SinhVien a, SinhVien b);
        friend bool operator < (SinhVien a, SinhVien b);
        float getDTB();
};

int SinhVien::stt = 0;

int SinhVien::so_thu_tu()
{
    stt++;
    return stt;
}

void ThongKe(SinhVien s[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i].getDTB() <= 1) {
            count++;
        }
    }
    cout << "CO " << count <<" SINH VIEN BI CANH CAO HOC TAP." << endl;
}

float SinhVien::getDTB() {
    return DTB;
}

void SXNS(SinhVien s[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            if(s[i] > s[j] == true) {
               SinhVien t = s[i];
                s[i] = s[j];
                s[j] = t; 
            }
        }
    }
}

void SXDTB(SinhVien s[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] < s[j] == true) {
                SinhVien t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
}

bool operator > (SinhVien a, SinhVien b) {
    if(a.namsinh > b.namsinh) {
        return true;
    } else return false;
}

bool operator < (SinhVien a, SinhVien b) {
    if(a.DTB < b.DTB) {
        return true;
    } else return false;
}

ostream& operator << (ostream &os, const SinhVien &sv) {
    cout << "MSV: ";
    os << sv.MSV << endl;
    cout << "Ho ten: ";
    os << sv.hoten << endl;
    cout << "Nam sinh: ";
    os << sv.namsinh << endl;
    cout << "Lop: ";
    os << sv.lop << endl;
    cout << "DTB = ";
    os << sv.DTB << endl;
    return os;
}

istream& operator >> (istream &is, SinhVien &sv) {
    sv.stt = sv.stt++;
    cout << "Sinh vien thu: " << sv.stt << endl;
    cout << "Nhap MSV: ";
    getline(is, sv.MSV);
    fflush(stdin);
    cout << "Nhap Ho ten: ";
    getline(is, sv.hoten);
    cout << "Nhap Nam sinh: ";
    is >> sv.namsinh;
    fflush(stdin);
    cout << "Nhap Lop: ";
    getline(is, sv.lop);
    cout << "Nhap Diem trung binh = ";
    is >> sv.DTB;
    return is;
}

void XuatDS(SinhVien s[], int n){
    for(int i = 0; i < n; i++) {
        cout << s[i];
    }
}

void NhapDS(SinhVien s[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Sinh Vien thu" << SinhVien::so_thu_tu() << endl;
        fflush(stdin);
        cin >> s[i];
    }
}

int main() {
    SinhVien sv[MAX];
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    NhapDS(sv, n);
    cout << endl << "**********" << endl;
    cout << "Danh sach sinh vien: " << endl;
    XuatDS(sv, n);
    SXDTB(sv, n);
    cout << "********SAU SAP XEP: " << endl;
    XuatDS(sv, n);
    SXNS(sv, n);
    cout << "********SAU SAP XEP: " << endl;
    XuatDS(sv, n);
    cout << "********SV bi canh cao hoc tap: " << endl;
    ThongKe(sv, n);
    system("pause");
    return 0;
}