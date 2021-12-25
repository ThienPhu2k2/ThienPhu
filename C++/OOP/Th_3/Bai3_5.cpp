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
        virtual void nhap();
        virtual void hien_thi();
};

Media::Media(){
    name = "";
    salary = 0;
}

Media::Media(string name, float salary){
    this->name = name;
    this->salary = salary;
}

Media::~Media(){}

void Media::nhap(){
    fflush(stdin);
    cout << "Nhap ten: ";
    getline(cin, name);
    cout << "Nhap gia: ";
    cin >> salary;
}

void Media::hien_thi(){
    cout << "Ten: " << name << endl;
    cout << "Gia: " << salary << endl;
}

class Book : public Media{
    private:
        float number;
        string tac_gia;
    public:
        Book();
        ~Book();
        void nhap();
        void hien_thi();
};

Book::Book(){
    number = 1;
    tac_gia = "";
}

Book::~Book(){}

void Book::nhap(){
    Media::nhap();
    cout << "Nhap so trang sach: ";
    cin >> number;
    fflush(stdin);
    cout << "Nhap ten tac gia: ";
    getline(cin, tac_gia);
}

void Book::hien_thi(){
    Media::hien_thi();
    cout << "So trang: " << number << endl;
    cout << "Ten tac gia: " << tac_gia << endl;
}

class Video : public Media{
    private:
        float thoi_gian;
        float gia_ban;
    public:
        Video();
        ~Video();
        void nhap();
        void hien_thi();
};

Video::Video(){
    thoi_gian = 0;
    gia_ban = 0;
}

Video::~Video(){}

void Video::nhap(){
    Media::nhap();
    cout << "Nhap so thoi gian: ";
    cin >> thoi_gian;
    cout << "Nhap gia ban: ";
    cin >> gia_ban;
}

void Video::hien_thi(){
    Media::hien_thi();
    cout << "Thoi gian: " << thoi_gian << endl;
    cout << "Gia ban: " << gia_ban << endl;
}

int main()
{
    Media **book, **video;
    int n, m;
    cout << "So luong sach: "; cin >> n;
    book = new Media*[n];
    cout << "So luong video: "; cin >> m;
    video = new Media*[m];
    for(int i = 0; i < n; i++){
        book[i] = new Book;
        book[i]->nhap();
    }
    for(int i = 0; i < m; i++){
        video[i] = new Video;
        video[i]->nhap();
    }
    for(int i = 0; i < n; i++){
        book[i]->hien_thi();
    }
    for(int i = 0; i < n; i++){
        video[i]->hien_thi();
    }
    system("pause");
    return 0;
}