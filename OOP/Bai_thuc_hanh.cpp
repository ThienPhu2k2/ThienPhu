// TAO CLASS A VA DE B KE THUA A VA HAM TAO

#include <iostream>

using namespace std;

class A {
    private:
        int x;
        int y;
    public:
        A();
        A(int x, int y);
        A(const A &a);
        ~A();
        friend istream& operator >> (istream &is, A &a);
        friend ostream& operator << (ostream &os, const A &a);
        friend bool operator > (A a, A c);
        friend A operator + (A a, A c);
};

A::A() { }

A::A(int x, int y)
{
    this->x = x;
    this->y = y;
}

A::A(const A &a)
{
    x = a.x;
    y = a.y;
}

A::~A() { }

istream& operator >> (istream &is, A &a)
{
    cout << "Enter x: ";
    is >> a.x;
    cout << "Enter y: ";
    is >> a.y;
    return is;
}

ostream& operator << (ostream &os, const A &a)
{
    cout << "X = ";
    os << a.x << endl;
    cout << "Y = ";
    os << a.y << endl;
    return os;
}

bool operator > (A a, A c)
{
    return a.x > c.x ? true : false;
}

A operator + (A a, A c)
{
    return A(a.x + c.x, a.y + c.y);
}

class B : public A {
    private:
        int z;
    public:
        B();
        B(int x, int y, int z);
        B(const B &b);
        ~B();
        friend istream& operator >> (istream &is, B &b);
        friend ostream& operator << (ostream &os, B &b);
        friend bool operator > (B b, B d);
        friend B operator + (B b, B d);
};

B::B():A() {}

B::B(int x, int y, int z):A(x, y)
{
    this->z = z;
}

B::B(const B &b)
{
    *this = b;
}

B::~B() {}

istream& operator >> (istream &is, B &b)
{
    A *a = static_cast<A *>(&b);
    is >> *a;
    cout << "Enter z: ";
    is >> b.z;
    return is;
}

ostream& operator << (ostream &os, B &b)
{
    A *a = static_cast<A *>(&b);
    os << *a;
    cout << "Z = ";
    os << b.z << endl;
    return os;
}

bool operator > (B b, B d)
{
    A *a1 = static_cast<A *>(&b);
    A *a2 = static_cast<A *>(&d);
    if(*a1 > *a2 && b.z > d.z)
        return true;
    return false;
}

B operator + (B b, B d)
{
    B t;
    A *a1 = static_cast<A *>(&b);
    A *a2 = static_cast<A *>(&d);
    A *t1 = static_cast<A *>(&t);
    *t1 = *a1 + *a2;
    t.z = b.z + d.z;
    return t;
}

int main()
{
    B b1, b2(4, 5, 6), b3;
    cin >> b1;
    b3 = b1 + b2;
    cout << b1;
    cout << b2;
    cout << b3;
    if(b1 > b2)
    {
        cout << "Lon hon" << endl;
    }
    else
    {
        cout << "Nho hon" << endl;
    }
    system("pause");
    return 0;
}