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
        friend Complex operator + (Complex a, Complex b);
        friend Complex operator - (Complex a, Complex b);
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

Complex operator + (Complex a, Complex b){
    return Complex(a.a + b.a, a.b + b.b);
}

Complex operator - (Complex a, Complex b){
    return Complex(a.a - b.a, a.b - b.b);
}

int main()
{
    Complex a, b;
    a.Nhap();
    cout << "So phuc da nhap: ";
    a.In();
    b.Nhap();
    cout << "So phuc da nhap: ";
    b.In();
    cout << endl;
    cout << "Tong 2 so phuc = ";
    (a + b).In();
    cout << "Hieu 2 so phuc = ";
    (a - b).In();

    system("pause");
    return 0;
}