#include <iostream>

using namespace std;

class MyAttr{
    protected:
        int so_hieu;
    public:
        MyAttr();
        ~MyAttr();
        void nhap();
        void hien_thi();
};

class Mydate{
    protected:
        int ngay;
        int thang;
        int nam;
    public:
        Mydate();
        ~Mydate();
        void nhap();
        void hien_thi();
        friend bool operator > (Mydate a, Mydate b);
};

class Myfile : public MyAttr, public Mydate{
    private:
        char filename[225];
        int filesize;
    public:
        Myfile();
        ~Myfile();
        void nhap();
        void hien_thi();
};

MyAttr::MyAttr(){
    so_hieu = 0;
}

MyAttr::~MyAttr() { }

void MyAttr::nhap(){
    cout << "Nhap so hieu: ";
    cin >> so_hieu;
}

void MyAttr::hien_thi(){
    cout << "So hieu thuoc tinh tep: " << so_hieu << endl;
}

Mydate::Mydate(){
    ngay = 1;
    thang = 1;
    nam = 1;
}

Mydate::~Mydate() { }

void Mydate::nhap(){
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
}

void Mydate::hien_thi(){
    cout << ngay<<"-"<<thang<<"-"<<nam<< endl;
}

bool operator > (Mydate a, Mydate b){
    if(a.nam > b.nam)
        return true;
    else if(a.nam == b.nam){
        if(a.thang > b.thang)
            return true;
        else if(a.thang == b.thang){
            if(a.ngay > b.ngay)
                return true;
        }
    }
    return false;
}

Myfile::Myfile(){
    filesize = 0;
}

Myfile::~Myfile() { }

void Myfile::nhap(){
    MyAttr::nhap();
    Mydate::nhap();
    cout << "Nhap file name: ";
    cin >> filename;
    cout << "Nhap file size: ";
    cin >> filesize;
}

void Myfile::hien_thi(){
    cout << "File name: " << filename << endl;
    cout << "File size: " << filesize << endl;
    Mydate::hien_thi();
    MyAttr::hien_thi();
}

int main()
{
    Myfile *myfile = new Myfile[4];
    for(int i = 0; i < 4; i++){
        cout << "\t**********" << endl;
        myfile[i].nhap();
    }
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            if(myfile[i] > myfile[j]){
                Myfile temp = myfile[i];
                myfile[i] = myfile[j];
                myfile[j] = temp;
            }
        }
    }
    for(int i = 0; i < 4; i++){
        cout << "\t**********" << endl;
        myfile[i].hien_thi();
    }
    delete[] myfile;
    system("pause");
    return 0;
}