#include <iostream>

using namespace std;

class Complex{
    private:
        float a;
        float b;
    public:
        Complex();
        Complex(float a, float b);
        Complex(const Complex &c);
        ~Complex();
        void Nhap();
        void In();
        Complex operator = (const Complex &c);
        friend Complex operator + (Complex a, Complex b);
};

Complex::Complex(){
    a = 0;
    b = 0;
}

Complex::Complex(float a, float b){
    this->a = a;
    this->b = b;
}

Complex::Complex(const Complex &c){
    a = c.a;
    b = c.b;
}

Complex::~Complex() { }

void Complex::Nhap(){
    cout << endl << "Nhap so thuc a: ";
    cin >> a;
    cout << "Nhap so ao b: ";
    cin >> b;
}

void Complex::In(){
    cout <<a<<"+"<<b<<"i" << endl;
}

Complex Complex::operator = (const Complex &c){
    a = c.a;
    b = c.b;
    return *this;
}

Complex operator + (Complex a, Complex b){
    return Complex(a.a + b.a, a.b + b.b);
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    Complex a[n], sum;
    cout << endl << "Nhap cac phan tu: ";
    for(int i = 0; i < n; i++){
        a[i].Nhap();
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "So phuc thu "<<i<<" : ";
        a[i].In();
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        sum = sum + a[i];
    }
    cout << "Tong day so phuc = ";
    sum.In();

    system("pause");
    return 0;
}