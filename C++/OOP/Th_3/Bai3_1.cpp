#include <iostream>

using namespace std;

#define pi 3.14

class Shape{
    public:
        virtual float dien_tich() = 0;
        virtual void nhap() = 0;
        virtual void hien_thi() = 0;
};

class Circle : public Shape{
    private:
        float ban_kinh;
    public:
        Circle();
        ~Circle();
        void nhap();
        void hien_thi();
        float dien_tich();
};

Circle::Circle(){
    ban_kinh = 1;
}

Circle::~Circle(){}

void Circle::nhap(){
    cout << "Nhap ban kinh: ";
    cin >> ban_kinh;
}

void Circle::hien_thi(){
    float dientich = dien_tich();
    cout << "Dien tich hinh tron: " << dientich << endl;
}

float Circle::dien_tich(){
    return (ban_kinh*ban_kinh)*pi;
}

class Rectangle : public Shape{
    private:
        float lenght;
        float width;
    public:
        Rectangle();
        ~Rectangle();
        void nhap();
        void hien_thi();
        float dien_tich();
};

Rectangle::Rectangle(){
    lenght = 1;
    width = 1;
}

Rectangle::~Rectangle(){}

void Rectangle::nhap(){
    cout << "Nhap chieu cao: ";
    cin >> lenght;
    cout << "Nhap chieu dai: ";
    cin >> width;
}

void Rectangle::hien_thi(){
    float dientich = dien_tich();
    cout << "Dien tich hinh chu nhat: " << dientich << endl;
}

float Rectangle::dien_tich(){
    return lenght*width;
}

int main()
{
    Shape **cir, **rec;
    int n, m;
    cout << "So luong hinh tron: "; cin >> n;
    cir = new Shape*[n];
    cout << "So luong hinh chu nhat: "; cin >> m;
    rec = new Shape*[m];
    for(int i = 0; i < n; i++){
        cir[i] = new Circle;
        cir[i]->nhap();
    }
    for(int i = 0; i < m; i++){
        rec[i] = new Rectangle;
        rec[i]->nhap();
    }
    for(int i = 0; i < n; i++){
        cir[i]->hien_thi();
    }
    for(int i = 0; i < m; i++){
        rec[i]->hien_thi();
    }

    system("pause");
    return 0;
}