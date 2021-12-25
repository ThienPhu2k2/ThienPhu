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
        friend bool operator > (Mydate a, Mydate b);
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

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    Mydate a[n];
    for(int i = 0; i < n; i++){
        cout << endl << "Mydate "<<i<<" : ";
        a[i].nhap();
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "My date "<<i<<" : ";
        a[i].in();
    }
    cout << endl;
    cout << "Sau sap xep: " << endl;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                Mydate temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << "My date "<<i<<" : ";
        a[i].in();
    }

    system("pause");
    return 0;
}