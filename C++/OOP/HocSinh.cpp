#include <iostream>

using namespace std;

class hoc_sinh {
    private:
        string ho_ten;
        float diem_toan;
        float diem_van;
    public:
        hoc_sinh();
        hoc_sinh(string hoten, float diemtoan, float diemvan);
        hoc_sinh(string hoten);
        hoc_sinh(const hoc_sinh &hs);
        ~hoc_sinh();
        friend istream& operator >> (istream &is, hoc_sinh &hs);
        friend ostream& operator << (ostream &os, const hoc_sinh &hs);
        friend bool operator > (hoc_sinh a, hoc_sinh b);
        friend bool operator < (hoc_sinh a, hoc_sinh b);
        friend bool operator >= (hoc_sinh a, hoc_sinh b);
        friend bool operator <= (hoc_sinh a, hoc_sinh b);
        friend bool operator == (hoc_sinh a, hoc_sinh b);
        void operator = (const hoc_sinh &hs);
        void Nhap();
        void Xuat();
        string getHo_Ten();
        float getDiem_Toan();
        float getDiem_Van();
        void setHo_Ten(string ho_ten);
        void setDiem_Toan(float diem_toan);
        void setDiem_Van(float diem_van);
        float GPA();
        void XepLoai();
};

void hoc_sinh::operator = (const hoc_sinh &hs)
{
    ho_ten = hs.ho_ten;
    diem_toan = hs.diem_toan;
    diem_van = hs.diem_van;                               
}

bool operator <= (hoc_sinh a, hoc_sinh b)
{
    if(a.GPA() <= b.GPA())
    {
        return true;
    } else return false;
}

bool operator >= (hoc_sinh a, hoc_sinh b)
{
    if(a.GPA() >= b.GPA())
    {
        return true;
    } else return false;
}

bool operator < (hoc_sinh a, hoc_sinh b)
{
    if(a.GPA() < b.GPA())
    {
        return true;
    } else return false;
}

bool operator > (hoc_sinh a, hoc_sinh b)
{
    if(a.GPA() > b.GPA())
    {
        return true;
    } else return false;
}

ostream& operator << (ostream &os, const hoc_sinh &hs)
{
    cout << "Ho ten hs: ";
    os << hs.ho_ten << endl;
    cout << "Diem toan = ";
    os << hs.diem_toan << endl;
    cout << "Diem van = ";
    os << hs.diem_van << endl;
    return os;
}

istream& operator >> (istream &is, hoc_sinh &hs)
{
    fflush(stdin);
    cout << "Nhap ho ten: ";
    getline(is, hs.ho_ten);
    cout << "Nhap diem toan: ";
    is >> hs.diem_toan;
    cout << "Nhap diem van: ";
    is >> hs.diem_van;
    return is;
}

hoc_sinh::~hoc_sinh()
{

}

hoc_sinh::hoc_sinh(const hoc_sinh &hs)
{
    ho_ten = hs.ho_ten;
    diem_toan = hs.diem_toan;
    diem_van = hs.diem_van;
}

hoc_sinh::hoc_sinh(string hoten)
{
    ho_ten = hoten;
    diem_van = 0;
    diem_toan = 0;
}

hoc_sinh::hoc_sinh(string hoten, float diemtoan, float diemvan)
{
    ho_ten = hoten;
    diem_toan = diemtoan;
    diem_van = diemvan;
}

hoc_sinh::hoc_sinh() 
{
    ho_ten = "tran thien phu";
    diem_toan = 8;
    diem_van = 8;
}

void hoc_sinh::XepLoai() {
    if(GPA() >= 8) {
        cout << "Xep loai: Gioi" << endl;
    } else if(GPA() >= 7) {
        cout << "Xep loai: Kha" << endl;
    } else if(GPA() >= 5) {
        cout << "Xep loai: Kha" << endl;
    } else {
        cout << "Xep loai: Yeu" << endl;
    }
}

float hoc_sinh::GPA() {
    float gpa;
    gpa = (diem_toan + diem_van) / 2;
    return gpa;
}

void hoc_sinh::setDiem_Van(float diem_van) {
    this->diem_van = diem_van;
}

void hoc_sinh::setDiem_Toan(float diem_toan) {
    this->diem_toan = diem_toan;
}

void hoc_sinh::setHo_Ten(string ho_ten) {
    this->ho_ten = ho_ten;
}

float hoc_sinh::getDiem_Van() {
    return diem_van;
}

float hoc_sinh::getDiem_Toan() {
    return diem_toan;
}

string hoc_sinh::getHo_Ten() {
    return ho_ten;
}

void hoc_sinh::Xuat() {
    cout << "Hoc Sinh: " << endl;
    cout << "Ho Ten: " << ho_ten << endl;
    cout << "Diem Toan = " << diem_toan << endl;
    cout << "Diem Van = " << diem_van << endl;
}

void hoc_sinh::Nhap() {
    cout << "Nhap ho ten: "; getline(cin, ho_ten);
    cout << "Nhap diem toan = "; cin >> diem_toan;
    cout << "Nhap diem van = "; cin >> diem_van;
}

int main() {
    hoc_sinh hs1, hs2("dung"), hs3, hs4(hs2);
    hs3 = hs1;
    cout << hs4;
    cout << hs3;
    cout << hs2;
    cout << hs1;
    /*hs1.Nhap();
    hs1.Xuat();
    cout << "Diem trung binh = " << hs1.GPA() << endl;
    hs1.XepLoai();
    hs2.setHo_Ten("tra thien phu");
    hs2.setDiem_Toan(8.5);
    hs2.setDiem_Van(6.5);
    hs2.Xuat();
    cout << "Diem trung binh = " << hs2.GPA() << endl;
    hs2.XepLoai();*/
    system("pause");
    return 0;
}