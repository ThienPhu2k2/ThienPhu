    
            // ********* TINH DA HINH ********

#include <iostream>
#include <vector>

using namespace std;

class Giang_vien {
    protected:
        string Ma_so;
        string Ho_ten;
        int tuoi;
        float luong;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual void Tinh_luong() = 0;
        float getLuong();
};

void Giang_vien::Nhap()
{
    fflush(stdin);
    cout << "Nhap Ma so: ";
    cin >> Ma_so;
    fflush(stdin);
    cout << "Nhap Ho ten: ";
    getline(cin, Ho_ten);
    cout << "Nhap Tuoi: ";
    cin >> tuoi;
}

void Giang_vien::Xuat()
{
    cout << "Ma so: " << Ma_so << endl;
    cout << "Ho ten: " << Ho_ten << endl;
    cout << "Tuoi: " << tuoi << endl;
}

float Giang_vien::getLuong()
{
    return luong;
}

class Giang_vien_co_huu:public Giang_vien {
    private:
        float He_so_luong;
        float Tham_nien;
    public:
        void Nhap();
        void Xuat();
        void Tinh_luong();
};

void Giang_vien_co_huu::Nhap()
{
    Giang_vien::Nhap();
    cout << "Nhap He so luong: ";
    cin >> He_so_luong;
    cout << "Nhap Tham nien: ";
    cin >> Tham_nien;
}

void Giang_vien_co_huu::Xuat()
{
    Giang_vien::Xuat();
    cout << "He so luong: " << He_so_luong << endl;
    cout << "Tham nien: " << Tham_nien << endl;
    this->Tinh_luong();
    cout << "Luong: " << luong << endl;
}

void Giang_vien_co_huu::Tinh_luong()
{
    luong = He_so_luong*1600 + Tham_nien*500;
}

class Giang_vien_thinh_giang:public Giang_vien {
    private:
        int So_tiet;
        float Don_gia;
    public:
        void Nhap();
        void Xuat();
        void Tinh_luong();
};

void Giang_vien_thinh_giang::Nhap()
{
    Giang_vien::Nhap();
    cout << "Nhap So tiet: ";
    cin >> So_tiet;
    cout << "Nhap Don gia: ";
    cin >> Don_gia;
}

void Giang_vien_thinh_giang::Xuat()
{
    Giang_vien::Xuat();
    cout << "So tiet: " << So_tiet << endl;
    cout << "Don gia: " << Don_gia << endl;
    this->Tinh_luong();
    cout << "Luong: " << luong << endl;
}

void Giang_vien_thinh_giang::Tinh_luong()
{
    luong = So_tiet*Don_gia;
}

class Quan_ly_giang_vien {
    private:
        vector<Giang_vien *> giangvien;
    public:
        void NhapDS();
        void XuatDS();
        void XapSep();
        void Max_luong();
        void Tong_luong();
};

void Quan_ly_giang_vien::NhapDS()
{
    Giang_vien *gv;
    cout << "Nhap so luong Giang Vien Co Huu: ";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        gv = new Giang_vien_co_huu;
        gv->Nhap();
        giangvien.push_back(gv);
        cout << endl;
    }
    cout << "Nhap so luong Giang Vien Thinh Giang: ";
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        gv = new Giang_vien_thinh_giang;
        gv->Nhap();
        giangvien.push_back(gv);
        cout << endl;
    }
}

void Quan_ly_giang_vien::XuatDS()
{
    cout << "***** Thong tin giang vien *****" << endl;
    for(int i = 0; i < giangvien.size(); i++)
    {
        giangvien.at(i)->Xuat();
        cout << endl;
    }
}

void Quan_ly_giang_vien::XapSep()
{
    for(int i = 0; i < giangvien.size() - 1; i++)
    {
        for(int j = i + 1; j < giangvien.size(); j++)
        {
            if(giangvien.at(i)->getLuong() > giangvien.at(j)->getLuong())
            {
                Giang_vien *temp = giangvien.at(i);
                giangvien.at(i) = giangvien.at(j);
                giangvien.at(j) = temp;
            }
        }
    }
    XuatDS();
}

void Quan_ly_giang_vien::Max_luong()
{
    Giang_vien *max;
    max = giangvien.at(0);
    for(int i = 0; i < giangvien.size(); i++)
    {
        if(max->getLuong() < giangvien.at(i)->getLuong())
        {
            max = giangvien.at(i);
        }
    }
    max->Xuat();
}

void Quan_ly_giang_vien::Tong_luong()
{
    float tong = 0;
    for(int i = 0; i < giangvien.size(); i++)
    {
        tong += giangvien.at(i)->getLuong();
    }
    cout << endl <<  "Tong so luong cua giang vien = " << tong << endl;
}

int main()
{
    Quan_ly_giang_vien a;
    a.NhapDS();
    a.XuatDS();
    cout << "Danh sach giang vien tang dan theo so luong:" << endl;
    a.XapSep();
    cout << "Giang vien co so luong cao nhat: " << endl;
    a.Max_luong();
    a.Tong_luong();
    system("pause");
    return 0;
}

