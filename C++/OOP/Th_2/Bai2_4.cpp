#include <iostream>

using namespace std;

class Media{
    protected:
        string name;
        float salary;
    public:
        Media();
        Media(string name, float salary);
        ~Media();
        void nhap();
        void hien_thi();
};

class Book : public Media{
    private:
        int so_trang;
        string tac_gia;
    public:
        Book();
        ~Book();
        void nhap();
        void hien_thi();
};

class Video : public Media{
    private:
        float thoi_gian;
        float gia;
    public:
        Video();
        ~Video();
        void nhap();
        void hien_thi();
};

Media::Media(){
    name = "";
    salary = 0;
}

Media::Media(string name, float salary){
    this->name = name;
    this->salary = salary;
}

Media::~Media() { }

void Media::nhap(){
    fflush(stdin);
    cout << "Nhap ten goi: ";
    getline(cin, name);
    cout << "Nhap gia ban: ";
    cin >> salary;
}

void Media::hien_thi(){
    cout << "Ten: " << name << endl;
    cout << "Gia ban: " << salary << endl;
}

Book::Book(){
    so_trang = 0;
    tac_gia = "";
}

Book::~Book() { }

void Book::nhap(){
    Media::nhap();
    cout << "Nhap so trang: ";
    cin >> so_trang;
    fflush(stdin);
    cout << "Nhap tac gia: ";
    getline(cin, tac_gia);
}

void Book::hien_thi(){
    Media::hien_thi();
    cout << "So trang: " << so_trang << endl;
    cout << "Tac gia: " << tac_gia << endl;
}

Video::Video(){
    thoi_gian = 0;
    gia = 0;
}

Video::~Video() { }

void Video::nhap(){
    Media::nhap();
    cout << "Nhap thoi gian: ";
    cin >> thoi_gian;
    cout << "Nhap gia ban: ";
    cin >> gia;
}

void Video::hien_thi(){
    Media::hien_thi();
    cout << "Thoi gian bo phim: " << thoi_gian << endl;
    cout << "Gia ban: " << gia << endl;
}

int main()
{
    int n, m;
    cout << "Nhap so luong doi tuong Book: "; cin >> n;
    cout << "Nhap so luong doi tuong Video: "; cin >> m;
    Book *book = new Book[n];
    Video *video = new Video[m];
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "\t**********" << endl;
        book[i].nhap();
    }
    for(int i = 0; i < m; i++){
        cout << "\t**********" << endl;
        video[i].nhap();
    }
    for(int i = 0; i < n; i++){
        cout << "\t**********" << endl;
        book[i].hien_thi();
    }
    for(int i = 0; i < n; i++){
        cout << "\t**********" << endl;
        video[i].hien_thi();
    }
    system("pause");
    return 0;
}