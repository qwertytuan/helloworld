#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ve5
{
public:
    string loaive;
    int so_luong_ve;
    int gia_ve;
    int tong_tien;
};
class nguoidatcho
{
public:
    string name;
    string pswd;
    string cccd;
    string phone;
    string email;
};

class ChuyenBay
{
public:
    string MaMayBay;
    string NoiDi;
    string NoiDen;
    string ThoiGianDi;
    string ThoiGianDen;
};

// ham hien thi menu
void HienThiMenu()
{
    cout << ("====== He Thong Quan Ly Dat Ve May Bay ======\n");
    cout << ("1. Nhap thong tin chuyen bay\n");
    cout << ("2. Hien thi thong tin cac chuyen bay\n");
    cout << ("3. Tim kiem thong tin cac chuyen bay\n");
    cout << ("4. Sua thong tin cac chuyen bay\n");
    cout << ("5. Hien Thi Tat Ca Dat cho. \n");
    cout << ("6. Thoat. \n");
    cout << ("======================================\n");
    cout << ("Nhap lua chon cua ban: ");
}

// ham nhap du lieu vao LuuTruMayBay.txt
void ThemChuyenBay()
{
    // tao 1 strct la f,viet cho ngan gon
    ChuyenBay f;

   
    cout << "Them Ma Chuyen Bay: ";
    cin >> f.MaMayBay;
    cout << "Them Noi Di: ";
    cin >> f.NoiDi;
    cout << "Them Noi Den: ";
    cin >> f.NoiDen;
    cout << "Them thoi gian di: ";
    cin >> f.ThoiGianDi;
    cout << "Them thoi gian den: ";
    cin >> f.ThoiGianDen;

    // Mo file
    ofstream file("LuuTruMayBay.txt", ios::app);

    // kiem tra file co mo duoc ko
    if (file.is_open())
    {
        // viet cac chi tiet ve chuyen bay vao LuuTruMayBay.txt
        file << f.MaMayBay << " "
             << f.NoiDi << " "
             << f.NoiDen << " "
             << f.ThoiGianDi << " "
             << f.ThoiGianDen << "\n";

        // dong file txt
        file.close();

        // hien thi them thanh cong
        cout << "Them chi tiet chuyen bay thanh cong.\n";
    }
    else
    {
        // hien thi loi
        cout << "Loi. Khong The Mo File.\n";
    }
}

// ham hien thi thong tin chuyen bay, doc tu LuuTruMayBay.txt
void HienThiThongTinChuyenBay()
{
    
    ChuyenBay f;

    // mo file LuuTruMayBay.txt de ghi
    ifstream file("LuuTruMayBay.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file.is_open())
    {
        // hien thi thong tin
        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\n";

        // doc den khi den dong cuoi cua file
        while (file >>
               f.MaMayBay >>
               f.NoiDi >>
               f.NoiDen >>
               f.ThoiGianDi >>
               f.ThoiGianDen)
        {
            // hien thi thong tin chuyen bay
            cout << "\n";
            cout << f.MaMayBay << "\t\t"
                 << f.NoiDi << "\t\t"
                 << f.NoiDen << "\t\t"
                 << f.ThoiGianDi << "\t\t"
                 << f.ThoiGianDen << "\n";
            cout << "\n";
        }

        // dong file
        file.close();
    }
    else
    {
        // hien thi loi
        cout << "Loi. Khong The Mo File.\n";
    }
}

// ham tim kiem thong tin chuyen bay tu file LuuTruMayBay.txt
void TimMaChuyenBay()
{
    // 
    ChuyenBay f;

    // khai bao 1 bien lua ma may bay
    string TimMaChuyenBay;

    // nguoi dung nhap vao ma may bay
    cout << "Them Ma Chuyen Bay Muon Tim: ";
    cin >> TimMaChuyenBay;

    // khai bao 1 cai co de xem co tim thay hay khong
    bool found = false;

    // mo file LuuTruMayBay.txt de ghi
    ifstream file("LuuTruMayBay.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file.is_open())
    {
        // doc den khi den dong cuoi cua file or the class ChuyenBay is found
        while (file >>
                   f.MaMayBay >>
                   f.NoiDi >>
                   f.NoiDen >>
                   f.ThoiGianDi >>
                   f.ThoiGianDen &&
               !found)
        {
            // kiem tra ma may bay co trung hay khong
            if (f.MaMayBay == TimMaChuyenBay)
            {
                // neu trung thi la true
                found = true;

                // hien thi la da tim thay
                cout << "Da tim thay.\n";
                cout << "Ma may bay: " << f.MaMayBay << "\n";
                cout << "NoiDi: " << f.NoiDi << "\n";
                cout << "NoiDen: " << f.NoiDen << "\n";
                cout << "thoi gian di: " << f.ThoiGianDi << "\n";
                cout << "thoi gian den: " << f.ThoiGianDen << "\n";
            }
        }

        // dong file
        file.close();

        // kiem tra xem co tim duoc khong
        if (!found)
        {
            // hien thi ko tim thay
            cout << "Khong tim thay chuyen bay.\n";
        }
    }
    else
    {
        // hien thi loi
        cout << "Loi. Khong The Mo File.\n";
    }
}

// ham de chinh sua chi tiet chuyen bay
void ChinhSuaChiTiet()
{
    
    ChuyenBay f;

    // khai bao ham de chua ma may bay can chinh sua
    string ChinhSuaMaMayBay;

    // Prompt the user to Them Ma Chuyen Bay to be edited
    cout << "Nhap ma may bay can chinh sua: ";
    cin >> ChinhSuaMaMayBay;

    // khai bao de xem ma may bay co ton tai hay khong
    bool found = false;

    // mo file LuuTruMayBay.txt de ghi
    ifstream file_in("LuuTruMayBay.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file_in.is_open())
    {
        // mo 1 file temp tam thoi
        ofstream file_out("temp.txt", ios::out);

        // kiem tra xem file da mo thanh cong chua
        if (file_out.is_open())
        {
            // doc chi tiet chuyen bay den dong cuoi
            while (file_in >>
                   f.MaMayBay >>
                   f.NoiDi >>
                   f.NoiDen >>
                   f.ThoiGianDi >>
                   f.ThoiGianDen)
            {
                // kiem tra xem ma may bay co trung voi ma may bay can duoc sua
                if (f.MaMayBay == ChinhSuaMaMayBay)
                {
                    // neu dung thi cho la true
                    found = true;

                    // ghi cac chi tiet moi vao
                    cout << "Them Noi Di Moi: ";
                    cin >> f.NoiDi;
                    cout << "Them Noi Den Moi: ";
                    cin >> f.NoiDen;
                    cout << "Them thoi gian Di Moi: ";
                    cin >> f.ThoiGianDi;
                    cout << "Them thoi gian Den Moi: ";
                    cin >> f.ThoiGianDen;
                }

                // ghi lai vao file
                file_out << f.MaMayBay << " "
                         << f.NoiDi << " "
                         << f.NoiDen << " "
                         << f.ThoiGianDi << " "
                         << f.ThoiGianDen << "\n";
            }

            // dong ca 2 file temp va LuuTruMayBay.txt
            file_in.close();
            file_out.close();

            // kiem tra xem co true khong
            if (found)
            {
                // thay ten cua file temp = LuuTruMayBay.txt va xoa file cu di
                remove("LuuTruMayBay.txt");
                rename("temp.txt", "LuuTruMayBay.txt");

                // hien thi da thanh cong
                cout << "Chi tiet chuyen bay da sua thanh cong.\n";
            }
            else
            {
                // hien thi loi va xoa file temp
                cout << "Khong tim thay chuyen bay.\n";
                remove("temp.txt");
            }
        }
        else
        {
            // hien thi loi and close the input file
            cout << "Loi.Khong the mo file output.\n";
            file_in.close();
        }
    }
    else
    {
        // hien thi loi
        cout << "Loi.Khong the mo file input.\n";
    }
}

void HienThiTatCaDatCho()
{
    bool found = false;
    nguoidatcho u;
    ChuyenBay f2;
    ve5 v5;
    ifstream file_in("DatCho.txt");

    // kiem tra xem file da mo hay chua
    if (file_in.is_open())
    {

        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\tLoai Ve       Gia Ve\tSo Ve\tTong Tien\n";
        // doc tat ca thong tin o file
        while (file_in >>
                   u.name >>
                   u.pswd >>
                   u.cccd >>
                   u.phone >>
                   u.email >>
                   f2.MaMayBay >>
                   f2.NoiDi >>
                   f2.NoiDen >>
                   f2.ThoiGianDi >>
                   f2.ThoiGianDen >>
                   v5.loaive >>
                   v5.gia_ve >>
                   v5.so_luong_ve >>
                   v5.tong_tien &&
               !found)
        {

            found = true;
            cout << "\n";
            cout << f2.MaMayBay << "\t\t"
                 << f2.NoiDi << "\t\t"
                 << f2.NoiDen << "\t\t"
                 << f2.ThoiGianDi << "\t\t"
                 << f2.ThoiGianDen << "\t"
                 << v5.loaive << "    "
                 << v5.gia_ve << "\t  "
                 << v5.so_luong_ve << "\t "
                 << v5.tong_tien << " ";
            cout << "\n\n\n";
            cout << "Thong Tin Nguoi Dat Ve: " << endl;
            cout << "Ho ten\t\tCCCD\t\t\tSo Dien Thoai\t\t\tEmail\n";
            cout << u.name
                 << "\t"
                 << u.cccd
                 << "\t\t"
                 << u.phone
                 << "\t\t"
                 << u.email << endl;
        }
        if (!found)
            cout << "Khong tim thay dat cho\n";
    }
    file_in.close();
}

// ham chinh cua chuong trinh
void ham_admin() {
    // khai bao bien lua chon cua nguoi dung
    int choice;

    // hien thi menu va nhap lua chon
    do {
        HienThiMenu();
        
        cin >> choice;

        // doi case dua theo lua chon ma nguoi dung nhap
        switch (choice) {
            case 1:
                ThemChuyenBay();
                break;
            case 2:
                HienThiThongTinChuyenBay();
                break;
            case 3:
                TimMaChuyenBay();
                break;
            case 4:
                ChinhSuaChiTiet();
                break;
            case 5:
                HienThiTatCaDatCho();
                break;
            case 6:
                cout << "Cam on da dung dich vu cua chung toi.\n";
                break;
            default:
                cout << "Lua chon khong phu hop.Vui long thu lai\n";
            }
    } while (choice != 6);
}