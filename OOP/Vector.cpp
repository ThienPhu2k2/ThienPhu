#include <iostream>

using namespace std;

class Vector {
    private:
        int n;
        float *v;
    public:
        Vector();
        Vector(int new_n);
        Vector(const Vector &vt);
        ~Vector();
        void Input();
        void Output();
        void operator = (const Vector &vt);
        friend Vector operator + (Vector &vt1, Vector &vt2);

};

Vector operator + (Vector &vt1, Vector &vt2)
{
    Vector vt;
    vt = vt1;
    for(int i = 0; i < vt.n; i++)
    {
        vt.v[i] = vt1.v[i] + vt2.v[i];
    }
    return vt;
}

void Vector::operator = (const Vector &vt)
{
    n = vt.n;
    v = new float[n];
    for(int i = 0; i < n; i++)
    {
        v[i] = vt.v[i];
    }
}

void Vector::Output()
{
    for(int i = 0; i < n; i++)
    {
        cout << "v[" << i << "]: " << v[i] << endl;
    }
}

void Vector::Input()
{
    for(int i = 0; i < n; i++)
    {
        cout << "v thu [" << i << "]: ";
        cin >> v[i];
    }
}

Vector::~Vector()
{
    delete[] v;
}

Vector::Vector(const Vector &vt)
{
    n = vt.n;
    v = new float[n];
    for(int i = 0; i < n; i++)
    {
        v[i] = vt.v[i];
    }
}

Vector::Vector(int new_n)
{
    n = new_n;
    v = new float[n];
}

Vector::Vector()
{
	n = 0;
	v = new float[n];
}

int main()
{
    Vector vt1(5);
    cout << "**********" << endl << "Enter Vector: " << endl;
    vt1.Input();
    cout << endl;
    cout << "**********" << endl << "List Vector 1: " << endl;
    vt1.Output();
    Vector vt2(vt1);
    cout << "**********" << endl << "List Vector 2: " << endl;
    vt2.Output();
    Vector vt3(5);
    vt3 = vt1 + vt2;
    cout << "**********" << endl << "List Vector 3: " << endl;
    vt3.Output();
    system("pause");
    return 0;
}
