#include <iostream>

using namespace std;

class MH {
    private:
        string tmh;
        int sl;
        float dg;
    public:
        MH();
        MH(string tenMH, int soluong, float dongia);
        MH(const MH &mh);
        ~MH();
        virtual void nhap();
        virtual void in();
        float tien();
};

MH::MH()
{
	tmh = "";
	sl = 0;
	dg = 0;
}

MH::MH(string tenMH, int soluong, float dongia)
{
    this->tmh = tenMH;
    this->sl = soluong;
    this->dg = dongia;
}

MH::MH(const MH &mh)
{
    this->tmh = mh.tmh;
    this->sl = mh.sl;
    this->dg = mh.dg;
}

MH::~MH()
{
}

void MH::nhap()
{
    fflush(stdin);
    cout << "Nhap ten mat hang: ";
    getline(cin, tmh);
    cout << "Nhap so luong: ";
    cin >> sl;
    cout << "Nhap don gia: ";
    cin >> dg;
}

void MH::in()
{
    cout << "Ten mat hang: " << tmh << endl;
    cout << "So luong = " << sl << endl;
    cout << "Don gia = " << dg << endl;
}

float MH::tien()
{
    return sl*dg;
}

class HD : public MH{
    private:
        string thd;
        int slmh;
        string dsmh;
        MH *mathang;
    public:
        HD();
        HD(string tenHD, int soluongMH, string danhsachMH);
        HD(const HD &hd);
        ~HD();
        void nhap();
        void in();
        float tongt();
        string getTHD();
};

HD::HD()
{
    thd = "";
    slmh = 0;
    dsmh = "";
}

HD::HD(string tenHD, int soluongMH, string danhsachMH)
{
    this->thd = tenHD;
    this->slmh = soluongMH;
    this->dsmh = danhsachMH;
}

HD::HD(const HD &hd)
{
    this->thd = hd.thd;
    this->slmh = hd.slmh;
    this->dsmh = hd.dsmh;
}

HD::~HD()
{
}

void HD::nhap()
{
    fflush(stdin);
    cout << "Nhap ten hoa don: ";
    getline(cin, thd);
    cout << "Nhap so luong mat hang: ";
    cin >> slmh;
    mathang = new MH[slmh];
    fflush(stdin);
    cout << "Nhap danh sach mat hang: ";
    getline(cin, dsmh);
    for(int i = 0; i < slmh; i++)
    {
        mathang[i].nhap();
    }
}

void HD::in()
{
    cout << "Ten hoa don: " << thd << endl;
    cout << "So luong mat hang: " << slmh << endl;
    cout << "Danh sach mat hang: " << dsmh << endl;
    for(int i = 0; i < slmh; i++)
    {
        mathang[i].in();
    }
    cout << "Tong tien hoa don = " << tongt() << endl;
}

float HD::tongt()
{
    float s = 0;
    for (int i = 0; i < slmh; i++)
    {
        s += mathang[i].tien();
    }
    return s;
}

string HD::getTHD()
{
    return thd;
}

void NhapDS_HoaDon(HD *hd, int &n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "===== Nhap mat hang thu "<<i+1<<"=====" << endl;
        hd[i].nhap();
    }
}

void XuatDS_HoaDon(HD *hd, int n)
{
    cout << endl << "======= Danh sach hoa don =======" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "===== Hoa don thu "<<i+1<<"=====" << endl;
        hd[i].in();
    }
}

void Max_tongt(HD *hd, int n)
{
    HD max;
    max = hd[0];
    for(int i = 0; i < n; i++)
    {
        if(max.tongt() < hd[i].tongt())
            max = hd[i];
    }
    cout << "Hoa don co tong tien lon nhat: " << endl;
    max.in();
}

void Search(HD *hd, int n)
{
    int count = 0;
    string search;
    fflush(stdin);
    cout << "Nhap ten hoa don can tim: ";
    getline(cin, search);
    for(int i = 0; i < n; i ++)
    {
        if(search == hd[i].getTHD())
        {
            cout << "===== Hoa don can tim: =====" << endl;
            hd[i].in();
            count++;
        }
    }
        if(count == 0) 
        {
            cout << "===== Khong tim thay hoa don nao ..... ";
        }
}

int main()
{
    HD *hoadon;
    int n;
    cout << "Nhap so luong danh sach hoa don: ";
    cin >> n;
    hoadon = new HD[n];
    NhapDS_HoaDon(hoadon, n);
    XuatDS_HoaDon(hoadon, n);
    Max_tongt(hoadon, n);
    Search(hoadon, n);
    system("pause");
}