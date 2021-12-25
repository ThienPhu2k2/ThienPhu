#include <iostream>

using namespace std;

class SV{
    protected:
        string lop;
        string ho_ten;
    public:
        SV();
        ~SV();
        void nhap();
        void hien_thi();
};

class SVSP : public SV{
    protected:
        float dtb;
        string hoc_bong;
    public:
        SVSP();
        ~SVSP();
        void nhap();
        void hien_thi();
};

class SVCN : public SVSP{
    private:
        float hoc_phi;
    public:
        SVCN();
        ~SVCN();
        void nhap();
        void hien_thi();
};

SV::SV(){
    lop = "";
    ho_ten = "";
}

SV::~SV() { }

void SV::nhap(){
    fflush(stdin);
    cout << "Nhap lop: ";
    getline(cin, lop);
    fflush(stdin);
    cout << "Nhap ho ten: ";
    getline(cin, ho_ten);
}

void SV::hien_thi(){
    cout << "Lop: " << lop << endl;
    cout << "Ten: " << ho_ten << endl;
}

SVSP::SVSP(){
    dtb = 0;
    hoc_bong = "";
}

SVSP::~SVSP() { }

void SVSP::nhap(){
    SV::nhap();
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
    fflush(stdin);
    cout << "Nhap loai hoc bong: ";
    getline(cin, hoc_bong);
}

void SVSP::hien_thi(){
    SV::hien_thi();
    cout << "Diem trung binh: " << dtb << endl;
    cout << "Hoc bong loai: " << hoc_bong << endl;
}

SVCN::SVCN(){
    hoc_phi = 0;
}

SVCN::~SVCN() { }

void SVCN::nhap(){
    SVSP::nhap();
    cout << "Nhap hoc phi: "; 
    cin >> hoc_phi;
}

void SVCN::hien_thi(){
    SVSP::hien_thi();
    cout << "Hoc phi: " << hoc_phi << endl;
}

int main()
{
    SVCN *svcn = new SVCN[3];
    for(int i = 0; i < 3; i ++){
        cout << "\t**********" << endl;
        svcn[i].nhap();
    }
    for(int i = 0; i < 3; i ++){
        cout << "\t**********" << endl;
        svcn[i].hien_thi();
    }
    delete[] SVCN;
    system("pause");
    return 0;
}