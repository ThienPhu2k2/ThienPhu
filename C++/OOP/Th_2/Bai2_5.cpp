#include <iostream> 

using namespace std;

class MyAddress{
    protected:
        string tinh;
        string huyen;
    public:
        MyAddress();
        ~MyAddress();
        void nhap();
        void hien_thi();
};

class Person : public MyAddress{
    protected:
        string name;
        int phone;
    public:
        Person();
        ~Person();
        void nhap();
        void hien_thi();
};

class Officer : public Person{
    protected: 
        float salary;
    public:
        Officer();
        ~Officer();
        void nhap();
        void hien_thi();
        friend bool operator > (Officer a, Officer b); 
};

MyAddress::MyAddress(){
    tinh = "";
    huyen = "";
}

MyAddress::~MyAddress() { }

void MyAddress::nhap(){
    fflush(stdin);
    cout << "Nhap Tinh: ";
    getline(cin, tinh);
    fflush(stdin);
    cout << "Nhap Huyen: ";
    getline(cin, huyen);
}

void MyAddress::hien_thi(){
    cout << "Tinh: " << tinh << endl;
    cout << "Huyen: " << huyen << endl;
}

Person::Person(){
    name = "";
    phone = 0;
}

Person::~Person() { }

void Person::nhap(){
    MyAddress::nhap();
    fflush(stdin);
    cout << "Nhap ten: ";
    getline(cin, name);
    cout << "Nhap so dien thoai: ";
    cin >> phone;
}

void Person::hien_thi(){
    MyAddress::hien_thi();
    cout << "Ten: " << name << endl;
    cout << "So dien thoai: " << phone << endl;
}

Officer::Officer(){
    salary = 0;
}

Officer::~Officer() { }

void Officer::nhap(){
    Person::nhap();
    cout << "Nhap luong: ";
    cin >> salary;
}

void Officer::hien_thi(){
    Person::hien_thi();
    cout << "Luong: " << salary << endl;
}

bool operator > (Officer a, Officer b){
    if(a.salary > b.salary)
        return true;
    else 
        return false;
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
    system("pause");
    return 0;
}