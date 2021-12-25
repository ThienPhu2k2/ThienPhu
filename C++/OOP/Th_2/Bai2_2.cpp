#include <iostream>

using namespace std;

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

class Person{
    protected:
        string name;
        string address;
        int phone;
    public:
        Person();
        ~Person();
        void nhap();
        void hien_thi();
};

class Officer : public Mydate, public Person{
    private:
        float salary;
    public:
        Officer();
        ~Officer();
        void nhap();
        void hien_thi();
};

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

Person::Person(){
    name = "";
    address = "";
    phone = 0;
}

Person::~Person() { }

void Person::nhap(){
    fflush(stdin);
    cout << "Nhap ten: ";
    getline(cin, name);
    fflush(stdin);
    cout << "Nhap dia chi: ";
    getline(cin, address);
    cout << "Nhap so dien thoai: ";
    cin >> phone;
}

void Person::hien_thi(){
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
}

Officer::Officer(){
    salary = 0;
}

Officer::~Officer() { }

void Officer::nhap(){
    Person::nhap();
    Mydate::nhap();
    cout << "Nhap luong: ";
    cin >> salary;
}

void Officer::hien_thi(){
    Mydate::hien_thi();
    Person::hien_thi();
    cout << "Luong: " << salary << endl;
}

int main()
{
    Officer *officer = new Officer[4];
    for(int i = 0; i < 4; i++){
        cout << "\t***********" << endl;
        officer[i].nhap();
    }
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            if(officer[i] > officer[j]){
                Officer temp = officer[i];
                officer[i] = officer[j];
                officer[j] = temp;
            }
        }
    }
    for(int i = 0; i < 4; i++){
        cout << "\t***********" << endl;
        officer[i].hien_thi();
    }
    delete[] officer;
    system("pause");
    return 0;
}