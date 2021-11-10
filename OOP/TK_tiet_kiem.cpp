#include <iostream>

using namespace std;

class Tai_Khoan{
    private:
        float  m_fSoDu = 0;
    public:
        float baoSoDu() 
        {   
            return m_fSoDu; 
        }

        void napTien(float fSoTien) 
        {
            m_fSoDu += fSoTien;  
        }

        void rutTien(float fSoTien)  
        {
            if (fSoTien <= m_fSoDu)
            m_fSoDu -= fSoTien;
        }  
};

class Tai_Khoan_Tiet_Kiem : public Tai_Khoan{
    private:
        int ky_han_gui;
        float lai_suat;
        int so_thang_da_gui;
    public:
        void nap_tien(float so_tien);
        void rut_tien(float so_tien);
        void tang_sothangdagui(int so_thang);
        void sodu_hientai();
};

void Tai_Khoan_Tiet_Kiem::sodu_hientai()
{
    cout << "So du trong tai khoan: " << baoSoDu() << endl;
}

void Tai_Khoan_Tiet_Kiem::tang_sothangdagui(int so_thang)
{
    so_thang_da_gui += so_thang;
}

void Tai_Khoan_Tiet_Kiem::rut_tien(float so_tien)
{
    if(so_thang_da_gui == ky_han_gui)
    {
        rutTien(so_tien);
        cout << "Rut tien thanh cong" << endl;
    }
    else cout << "Chua den ky han gui ... " << endl;
}

void Tai_Khoan_Tiet_Kiem::nap_tien(float so_tien)
{
    napTien(so_tien);
    so_thang_da_gui = 0;
    cout << "Nap tien thanh cong" << endl;
}

int main()
{
    Tai_Khoan_Tiet_Kiem tk;
    tk.nap_tien(100);
    tk.rut_tien(100);
    system("pause");
    return 0;
}