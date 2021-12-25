#include <iostream>

using namespace std;

class Mydate{
    private:
        int ngay;
        int thang;
        int nam;
    public:
        Mydate();
        Mydate(int ngay, int thang, int nam);
        Mydate(const Mydate &m);
        ~Mydate();
        void nhap();
        void in();
        friend bool operator >= (Mydate a, Mydate b);
};

Mydate::Mydate(){
    ngay = 1;
    thang = 1;
    nam = 1;
}

Mydate::Mydate(int ngay, int thang, int nam){
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

Mydate::Mydate(const Mydate &m){
    ngay = m.ngay;
    thang = m.thang;
    nam = m.nam;
}

Mydate::~Mydate() { }

void Mydate::nhap(){
    cout << endl << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
}

void Mydate::in(){
    cout << ngay<<"-"<<thang<<"-"<<nam<< endl;
}

bool operator >= (Mydate a, Mydate b){
    if(a.nam > b.nam)
        return true;
    else if(a.nam == b.nam){
        if(a.thang > b.thang)
            return true;
        else if(a.thang == b.thang){
            if(a.ngay > b.ngay)
                return true;
            else if(a.ngay == b.ngay)
                return true;
        }
    }
    return false;
}

int main()
{
    Mydate a[5], max;
    for(int i = 0; i < 5; i++){
        cout << endl << "Mydate "<<i<<" : ";
        a[i].nhap();
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << "My date "<<i<<" : ";
        a[i].in();
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        if(a[i] >= max){
            max = a[i];
        }
    }
    cout << "Ngay lon nhat: ";
    max.in();

    system("pause");
    return 0;
}