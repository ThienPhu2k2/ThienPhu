#include <iostream>

using namespace std;

class Person{
    private:
        string name;
        int age;
        string address;
    public:
        void Input_1();
        void Output_1();
        string getName();
};

class Student : public Person{
    private:
        string id;
        int score;
    public:
        void Input_2();
        void Output_2();
        void rank();
};

class Teacher : public Person{
    public:
        void Teach();
};

void Teacher::Teach()
{
    if(getName() == "dung")
    {
        cout << "Co " << getName() << "la CN lop CNTT K62" << endl;
    }
    else if(getName() == "minh")
    {
        cout << "Thay " << getName() << "la CN lop CNTT K60" << endl;
    }
    else if(getName() == "mien")
    {
        cout << "Co " << getName() << "la CN lop CNTT K61" << endl;
    }
}

void Student::rank()
{
    if(score >= 8)
    {
        cout << "Gioi" << endl;
    } 
    else if(score >= 7)
    {
        cout << "Kha" << endl;
    }
    else if(score >= 5)
    {
        cout << "Trung Binh" << endl;
    }
    else if(score >= 3)
    {
        cout << "Yeu" << endl;
    }
    else cout << "Kem" << endl;
}

void Student::Output_2()
{
    Output_1();
    cout << "Id: " << id << endl;
    cout << "Score: " << score << endl;
}

void Student::Input_2()
{
    Input_1();
    fflush(stdin);
    cout << "Enter id: ";
    getline(cin, id);
    cout << "Enter score: ";
    cin >> score;
}

string Person::getName()
{
    return name;
}

void Person::Output_1()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Address: " << address << endl;
}

void Person::Input_1()
{
    fflush(stdin);
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    fflush(stdin);
    cout << "Enter address: ";
    getline(cin, address);
}

int main()
{
    Student student;
    cout << "STUDENT: " << endl;
    student.Input_2();
    student.Output_2();
    student.rank();
    Teacher teacher;
    cout << "TEACHER: " << endl;
    teacher.Input_1();
    teacher.Output_1();
    teacher.Teach();
    system("pause");
    return 0;
}