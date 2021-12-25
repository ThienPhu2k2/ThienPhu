#include <iostream>

using namespace std;

class SV{
    protected:
        string lop;
        string name;
    public:
        virtual void nhap();
        virtual void hien_thi();
};

void SV::nhap(){
    fflush(stdin);
    cout << "Nhap lop hoc: ";
    getline(cin, lop);
    fflush(stdin);
    cout << "Nhap ho ten: ";
    getline(cin, name);
}

void SV::hien_thi(){
    cout << "Lop: " << lop << endl;
    cout << "Ho ten: " << name << endl;
}

class SVSP : public SV{
    private:
        string hoc_bong;
    public:
        void nhap();
        void hien_thi();
};

void SVSP::nhap(){
    SV::nhap();
    fflush(stdin);
    cout << "Nhap hoc bong: ";
    getline(cin, hoc_bong);
}

void SVSP::hien_thi(){
    SV::hien_thi();
    cout << "Hoc bong loai: " << hoc_bong << endl;
}

class SVTC : public SV{
    private:
        float hoc_phi;
    public:
        void nhap();
        void hien_thi();
};

void SVTC::nhap(){
    SV::nhap();
    cout << "Nhap hoc phi: ";
    cin >> hoc_phi;
}

void SVTC::hien_thi(){
    SV::hien_thi();
    cout << "Hoc phi: " << hoc_phi << endl;
}

int main()
{
    SV **sp, **tc;
    int n, m;
    cout << "So luong sinh vien su pham: "; cin >> n;
    sp = new SV*[n];
    cout << "So luong sinh vien tai chuc: "; cin >> m;
    tc = new SV*[m];
    for(int i = 0; i < n; i++){
        sp[i] = new SVSP;
        sp[i]->nhap();
    }
    for(int i = 0; i < m; i++){
        tc[i] = new SVTC;
        tc[i]->nhap();
    }
    for(int i = 0; i < n; i++){
        sp[i]->hien_thi();
    }
    for(int i = 0; i < m; i++){
        sp[i]->hien_thi();
    }

    system("pause");
    return 0;
}