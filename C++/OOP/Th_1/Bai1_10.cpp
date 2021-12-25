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
        bool kiem_tra(Vector a);
        Vector operator = (const Vector &vt);
        friend Vector operator + (Vector a, Vector b);
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

bool Vector::kiem_tra(Vector a){
    if(n == a.n)
        return true;
    return false;
}

Vector Vector::operator = (const Vector &vt){
    n = vt.n;
    v = new float[n];
    for(int i = 0; i < n; i++){
        v[i] = vt.v[i];
    }
    return *this;
}

Vector operator + (Vector a, Vector b){
    Vector vt = a;
    for(int i = 0; i < vt.n; i++){
        vt.v[i] = a.v[i] + b.v[i];
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
    cout << "Nhap vector b: " << endl;
    b.nhap();
    b.hien_thi();
    cout << endl;
    cout << "Tong 2 vector:";
    if(a.kiem_tra(b)){
        (a + b).hien_thi();
    }
    else cout << "vector a, b khong cong duoc voi nhau";
    system("pause");
    return 0;
}