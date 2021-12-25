#include <iostream>

using namespace std;

class Vector{
    private:
        int n;
        float *v;
    public:
        Vector(int new_n);
        Vector(const Vector &vt);
        ~Vector();
        void nhap();
        void hien_thi();
        Vector operator = (const Vector &vt);
        friend Vector operator * (float k, Vector a);
};

Vector::Vector(int new_n){
    n = new_n;
    v = new float[n];
}

Vector::Vector(const Vector &vt){
    n = vt.n;
    v = new float[n];
    for(int i = 0; i < n; i++){
        v[i] = vt.v[i];
    }
}

Vector::~Vector(){
    delete[] v;
}

void Vector::nhap(){
    for(int i = 0; i < n; i++){
        cout << "vector["<<i<<"]: ";
        cin >> v[i];
    }
}

void Vector::hien_thi(){
    for(int i = 0; i < n; i++){
        cout << endl << "v["<<i<<"]: ";
        cout << v[i];
    }
    cout << endl;
}

Vector Vector::operator = (const Vector &vt){
    n = vt.n;
    v = new float[n];
    for(int i = 0; i < n; i++){
        v[i] = vt.v[i];
    }
    return *this;
}

Vector operator * (float k, Vector a){
    Vector vt = a;
    for(int i = 0; i < vt.n; i++){
        vt.v[i] = a.v[i] * k;
    }
    return vt;
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu vector: ";
    cin >> n;
    Vector a(n), b(n);
    cout << "Nhap vector a: " << endl;
    a.nhap();
    a.hien_thi();
    cout << endl;
    float k;
    cout << "Nhap k: ";
    cin >> k;
    cout << "Tich cua k va vector a: ";
    (k * a).hien_thi();
    system("pause");
    return 0;
}