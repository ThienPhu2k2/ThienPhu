#include <iostream>

using namespace std;

class MatHang{
    protected:
        string name;
    public:
        virtual void nhap();
        virtual void hien_thi();
};

void MatHang::nhap(){
    fflush(stdin);
    cout << "Nhap ten mat hang: ";
    getline(cin, name);
}

void MatHang::hien_thi(){
    cout << "Ten mat hang: " << name << endl;
}

class MayTinh : public MatHang{
    private:
        int speed;
    public:
        void nhap();
        void hien_thi();
};

void MayTinh::nhap(){
    MatHang::nhap();
    cout << "Nhap speed: ";
    cin >> speed;
}

void MayTinh::hien_thi(){
    MatHang::hien_thi();
    cout << "Speed: " << speed << endl;
}

class MayIn : public MatHang{
    private:
        int Dpi;
    public:
        void nhap();
        void hien_thi();
};

void MayIn::nhap(){
    MatHang::nhap();
    cout << "Nhap Dpi: ";
    cin >> Dpi;
}

void MayIn::hien_thi(){
    MatHang::hien_thi();
    cout << "Dpi: " << Dpi << endl;
}

int main()
{
    MatHang **mt, **mi;
    int n, m;
    cout << "Nhap so luong may tinh: "; cin >> n;
    mt = new MatHang*[n];
    cout << "Nhap so luong may in: "; cin >> m;
    mi = new MatHang*[m];
    for(int i = 0; i < n; i++){
        mt[i] = new MayTinh;
        mt[i]->nhap();
    }
    for(int i = 0; i < m; i++){
        mi[i] = new MayIn;
        mi[i]->nhap();
    }
    for(int i = 0; i < n; i++){
        mt[i]->hien_thi();
    }
    for(int i = 0; i < m; i++){
        mi[i]->hien_thi();
    }
    
    system("pause");
    return 0;
}