#include <iostream>
#include <string>

using namespace std;

class Printer{
	private:
		string name;
		int soluong;
	public:
		void nhapkho(int q);
		void xuatkho(int q);
};

void Printer::nhapkho(int q){
	cout << "Kho "<<q<<": "<<endl;
	cout << "Nhap ten: " << endl;
	getline(cin, name);
	cout << "nhap so luong: " << endl;
	cin >> soluong;
}

void Printer::xuatkho(int q){
	cout << "Kho "<<q<<": " << endl;
	cout << "Ten: " << name << endl;
	cout << "So luong: " << soluong << endl;
}

class Laser : public Printer{
	private:
		float DPI;
	public:
		void nhapkho(int q);
		void xuatkho(int q);	
};

void Laser::nhapkho(int q){
	Printer::nhapkho(q);
	cout << "Nhap DPI: " << endl;
	cin >> DPI;
	cin.ignore();
}

void Laser::xuatkho(int q){
	Printer::xuatkho(q);
	cout << "DPI: " << DPI << endl;
}

class ColorPrinter : public Printer{
	private:
		string color;
	public:
		void nhapkho(int q);
		void xuatkho(int q);
};

void ColorPrinter::nhapkho(int q){
	Printer::nhapkho(q);
	cout << "Nhap mau: " << endl;
	cin.ignore();
	getline(cin, color);
}

void ColorPrinter::xuatkho(int q){
	Printer::xuatkho(q);
	cout << "The printer's color is: " << color << endl;
}

class ColorLaser : public Laser, ColorPrinter{
	public:
		void nhapkho(int q);
		void xuatkho(int q);
};

void ColorLaser::nhapkho(int q){
	Laser::nhapkho(q);
	ColorPrinter::nhapkho(q);
}

void ColorLaser::xuatkho(int q){
	Laser::xuatkho(q);
	ColorPrinter::xuatkho(q);
}

int main()
{
	ColorLaser *a = new ColorLaser[3];
	for(int i=0; i<3; i++){
		a[i].nhapkho(i+1);
    }
	for(int i=0; i<3; i++){
		a[i].xuatkho(i+1);
    }
    system("pause");
    return 0;
}