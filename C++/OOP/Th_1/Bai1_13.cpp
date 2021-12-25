#include <iostream>
using namespace std;
class Student{
    private:
        string ten;
        float hoc_ky1, hoc_ky2;
        float GPA;
    public:
        Student();
        void nhap();
        void in();
        bool operator > (Student a);
}; 

Student::Student (){
    ten = "";
    hoc_ky1 = 0;
    hoc_ky2 = 0;
    GPA = 0;
}

void Student::nhap(){
    fflush(stdin);
    cout << "Nhap ho ten: ";
    getline(cin,ten);
    cout << "Nhap diem ky 1: ";
    cin >> hoc_ky1;
    cout << "Nhap diem ky 2: ";
    cin >> hoc_ky2;
    GPA = (hoc_ky1 + hoc_ky2 * 2) / 3;
}

void Student::in(){
    cout <<"Name: "<<ten<<" || Semester 1: "<<hoc_ky1<<" || Semester 2: "<<hoc_ky2<<" || Average: "<<GPA<<endl;
}

bool Student:: operator > (Student a){
    return GPA>a.GPA;
}

void nhap(Student a[], int n){
    for(int i = 0; i < n; i++){
        cout << endl << "Nhap student " << i+1 << endl ;
        a[i].nhap() ;
    } 
}

void in(Student a[], int n){
    for(int i = 0; i < n; i++){
        cout << endl << "Student " << i+1 << ": " ;
        a[i].in();
    }
}

void sort(Student a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if (a[j] > a[i]){
                swap(a[i], a[j]);
            }
        }
    }
}
int main()
{
    Student sv1;
    Student sv2;
    cout << "Student 1: " << endl;
    sv1.nhap(); 
    cout << "Student 2: " << endl;
    sv2.nhap();
    sv1.in();
    sv2.in();
    Student s[5];
    nhap(s,5);
    in(s,5);
    cout << endl <<"sau sap xep: " << endl;
    sort(s,5);
    in(s,5);
    return 0;
}