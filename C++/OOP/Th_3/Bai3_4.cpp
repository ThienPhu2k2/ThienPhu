#include <iostream>

using namespace std;

class Printer{
    protected:
        string name;
    public:
        virtual void nhap();
        virtual void hien_thi();
        friend bool operator > (Printer a, Printer b);
};

void Printer::nhap(){
    fflush(stdin);
    cout << "Nhap ten may in: ";
    getline(cin, name);
}

void Printer::hien_thi(){
    cout << "Ten may in: " << name << endl;
}

bool operator > (Printer a, Printer b){
    if(a.name > b.name)
        return true;
    else 
        return false;
}

class Laser : public Printer{
    protected:
        int Dpi;
    public:
        void nhap();
        void hien_thi();
};

void Laser::nhap(){
    Printer::nhap();
    cout << "Nhap Dpi: ";
    cin >> Dpi;
}

void Laser::hien_thi(){
    Printer::hien_thi();
    cout << "Dpi: " << Dpi << endl;
}

class ColorLaser : public Laser{
    private:
        string color;
    public:
        void nhap();
        void hien_thi();
};

void ColorLaser::nhap(){
    Laser::nhap();
    fflush(stdin);
    cout << "Nhap color: ";
    getline(cin, color);
}

void ColorLaser::hien_thi(){
    Laser::hien_thi();
    cout << "Color: " << color << endl;
}

int main()
{
    Printer **laser, **colorlaser;
    int n, m;
    cout << "So luong may laser: "; cin >> n;
    laser = new Printer*[n];
    cout << "So luong may colorlaser: "; cin >> m;
    colorlaser = new Printer*[m];
    for(int i = 0; i < n; i++){
        laser[i] = new Laser;
        laser[i]->nhap();
    }
    for(int i = 0; i < m; i++){
        colorlaser[i] = new ColorLaser;
        colorlaser[i]->nhap();
    }
    Printer *temp = new Laser;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(laser[i] > laser[j]){
                temp = laser[i];
                laser[i] = laser[j];
                laser[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        laser[i]->hien_thi();
    }
    temp = new ColorLaser;
    for(int i = 0; i < m - 1; i++){
        for(int j = i + 1; j < m; j++){
            if(colorlaser[i] > colorlaser[j]){
                temp = colorlaser[i];
                colorlaser[i] = colorlaser[j];
                colorlaser[j] = temp;
            }
        }
    }
    for(int i = 0; i < m; i++){
        colorlaser[i]->hien_thi();
    }
    
    system("pause");
    return 0;
}