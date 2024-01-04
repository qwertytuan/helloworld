#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class ve
{
public:
    string loaive;
    int so_luong_ve;
    int gia_ve;
    int tong_tien;
};
// tao class de luu tru thong tin nguoi dung
class nguoidung
{
public:
    string name;
    string pswd;
    string phone;
    string email;
    string cccd;
};
// tao 1 class de luu cac thong tin chuyen bay
class chuyenbay2
{
public:
    string MaMayBay2;
    string NoiDi2;
    string NoiDen2;
    string ThoiGianDi2;
    string ThoiGianDen2;
};

// ham hien thi menu
void HienThi_Menu()
{
    cout << "\n";
    cout << "\t\t\tChao Mung Den Voi He Thong Giu Cho va Dat Ve.\n";
    cout << "\t\tHay lua chon cac lua chon sau:\n";
    cout << "\t\tChon 1: Giu cho chuyen bay.\n";
    cout << "\t\tChon 2: Dat cho chuyen bay.\n";
    cout << "\t\tChon 3: Huy giu cho.\n";
    cout << "\t\tChon 4: Hien thi cac dat cho.\n";
    cout << "\t\tChon 5: Chinh sua tai khoan.\n";
    cout << "\t\tChon 6: Thoat.\n";
}

// ham tao file giu cho va ghi cac thong tin chuyen bay,nguoi dung ma nguoi dung da chon vao file temp1
void Giu_cho_chuyen_bay()
{
    ///////////////////

    cout << "\n\n";
    // tao object chuyen bay la f2
    class chuyenbay2 f2;
    string TimMaChuyenBay2;
    cout << "\n\n";
    // tao object nguoi dung la u
    class nguoidung u;
    string ten_nguoi_dung;
    // nguoi dung nhap vao ten
    cout << "Nhap ten nguoi dung:";
    cin >> ten_nguoi_dung;
    // nguoi dung nhap ma chuyen bay can giu cho
    cout << "Them Ma Chuyen Bay Muon Giu Cho: ";
    cin >> TimMaChuyenBay2;
    ///////////////
    // mo file LuuTruMayBay.txt
    ifstream infile;
    infile.open("LuuTruMayBay.txt");
    // neu khong mo duoc thi in ra
    if (!infile.is_open())
    {
        cout << "Không thể mở file input.txt\n";
    }

    // doc tung dong tu file va kiem tra xem co chua chuoi ma chuyen bay can tim hay không
    string line;
    while (getline(infile, line))
    {
        if (line.find(TimMaChuyenBay2) != string::npos) // Nếu tim thấy chuoi ma chuyen bay trong dong
        {
            // chuyen doi dong thanh 1 stream
            stringstream ss(line);
            // doc tung phan tu tu stream
            while (ss >> f2.MaMayBay2 >> f2.NoiDi2 >> f2.NoiDen2 >> f2.ThoiGianDi2 >> f2.ThoiGianDen2)
            {
                cout << "";
            }
        }
    }

    // dong file
    infile.close();

    ////////////////////////////////
    bool found1 = false;
    // mo file lua tru thong tin nguoi dung de doc
    ifstream fileuser("temp1.txt", ios::in);
    // kiem tra xem file da mo thanh cong chua
    if (fileuser.is_open())
    {
        // doc den khi den dong cuoi cua file
        while (fileuser >> u.name >> u.pswd >> u.cccd >> u.phone >> u.email && !found1)
        {
            // kiem tra ma may bay co trung hay khong
            if (ten_nguoi_dung == u.name)
            {
                // neu trung thi la true
                found1 = true;
                // hien thi la da tim thay
                cout << "Da tim thay thong tin nguoi dung.\n";
                cout << "Ho Ten: " << u.name << endl;
                cout << "CCCD: " << u.cccd << endl;
                cout << "So Dien Thoai: " << u.phone << endl;
                cout << "Email: " << u.email << endl;
                fileuser.close();
            }
        }
    }
    remove("temp1.txt");
    // mo file GiuCho de ghi
    ofstream file2("temp1.txt", ios::app);
    if (file2.is_open())
    {
        // ghi thong tin nguoi dung va chuyen bay vao file
        file2 << u.name << " "
              << u.pswd << " "
              << u.cccd << " "
              << u.phone << " "
              << u.email << " "
              << f2.MaMayBay2 << " "
              << f2.NoiDi2 << " "
              << f2.NoiDen2 << " "
              << f2.ThoiGianDi2 << " "
              << f2.ThoiGianDen2 << "\n";

        // dong file
        file2.close();

        // hien thi thanh cong
        cout << "Chuyen bay mang ma " << f2.MaMayBay2 << " giu cho thanh cong"
             << "\n";
    }
}

// ham dat cho
void Dat_Cho()
{
    // tao object chuyen bay la f2
    class chuyenbay2 f2;
    string ma_chuyen_bay_dat_cho;
    // tao object nguoi dung la u
    class nguoidung u;
    string ten_nguoi_dung;
    ifstream file("temp1.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file.is_open())
    {
        // hien thi thong tin
        cout << "\t\t\t"
             << " Danh sach giu cho:"
             << "\n\n";
        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\n";

        // doc den khi den dong cuoi cua file
        while (file >> u.name >> u.pswd >> u.cccd >> u.phone >> u.email >> f2.MaMayBay2 >> f2.NoiDi2 >> f2.NoiDen2 >> f2.ThoiGianDi2 >> f2.ThoiGianDen2)
        {
            // hien thi thong tin chuyen bay
            cout << "\n";
            cout << f2.MaMayBay2 << "\t\t"
                 << f2.NoiDi2 << "\t\t"
                 << f2.NoiDen2 << "\t\t"
                 << f2.ThoiGianDi2 << "\t\t"
                 << f2.ThoiGianDen2 << "\n";
            cout << "\n";
        }
    }
    // nhap ma chuyen bay
    cout << "Nhap Ma May Bay can dat: ";
    cin >> ma_chuyen_bay_dat_cho;

    // khai bao 1 co false
    bool found3 = false;

    // mo file temp1 de ghi
    ifstream file_in("temp1.txt", ios::in);

    // kiem tra xem file da mo hay chua
    if (file_in.is_open())
    {
        // mo file DatCho.txt de chinh sua
        ofstream file_out("DatCho.txt", ios::app);

        // kiem tra xem file da mo hay chua
        if (file_out.is_open())
        {
            // doc tat ca thong tin o file
            while (file_in >> u.name >> u.pswd >> u.cccd >> u.phone >> u.email >> f2.MaMayBay2 >> f2.NoiDi2 >> f2.NoiDen2 >> f2.ThoiGianDi2 >> f2.ThoiGianDen2 && !found3)
            {
                // kiem tra xem ma chuyen bay co trung voi ma chuyen bay can dat hay khong hay khong
                if (f2.MaMayBay2 == ma_chuyen_bay_dat_cho)
                {
                    // dat co thanh dung
                    found3 = true;

                    /////////////////////////////////////////
                    class ve ve1;
                    int a;
                    cout << "Thanh toan de hoan tat thu tuc dat cho \n";
                    cout << "Chon 1 de chap nhan.\n";
                    cout << "Chon 2 de thoat \n";
                    cout << "Vui long nhap lua chon cua ban: ";
                    cin >> a;
                    system("clear");
                    switch (a)
                    {
                    case 1:
                        int b;
                        cout << "\t\t Bang Chon loai ve:\n";
                        cout << "Chon 1 de mua ve hang pho thong: 600.000d/ve\n";
                        cout << "Chon 2 de mua ve hang thuong gia: 1.500.000/ve\n";
                        cout << "Vui long nhap lua chon cua ban: ";
                        cin >> b;
                        switch (b)
                        {
                        case 1:
                            ve1.loaive = "Pho Thong";
                            ve1.gia_ve = 600000;
                            do
                            {
                                cout << "So luong ve pho thong can dat(toi da 3 ve):";
                                cin >> ve1.so_luong_ve;
                                if (ve1.so_luong_ve < 0 || ve1.so_luong_ve > 3)
                                    cout << "Lua chon khong phu hop. Vui long chon lai\n";
                            } while (ve1.so_luong_ve < 0 || ve1.so_luong_ve > 3);
                            ve1.tong_tien = ve1.so_luong_ve * ve1.gia_ve;
                            break;

                        case 2:
                            ve1.loaive = "Thuong GIa";
                            ve1.gia_ve = 1500000;
                            do
                            {
                                cout << "So luong ve thuong gia can dat(toi da 2 ve):";
                                cin >> ve1.so_luong_ve;
                                if (ve1.so_luong_ve < 0 || ve1.so_luong_ve > 2)
                                    cout << "Lua chon khong phu hop. Vui long chon lai\n";
                            } while ((ve1.so_luong_ve) < 0 || ve1.so_luong_ve > 2);
                            ve1.tong_tien = ve1.so_luong_ve * ve1.gia_ve;
                            break;
                        }
                    case 2:
                    break;
                    default:
                        break;
                    }
                    /////////////////////////////////////////////////////////
                    // ghi tat ca thong tin vao file dat cho
                    file_out << u.name << " "
                             << u.pswd << " "
                             << u.cccd << " "
                             << u.phone << " "
                             << u.email << " "
                             << f2.MaMayBay2 << " "
                             << f2.NoiDi2 << " "
                             << f2.NoiDen2 << " "
                             << f2.ThoiGianDi2 << " "
                             << f2.ThoiGianDen2 << " "
                             << ve1.loaive << " "
                             << ve1.gia_ve << " "
                             << ve1.so_luong_ve << " "
                             << ve1.tong_tien << "\n";

                    // hien thi da dat thanh cong
                    cout << "Da dat cho thanh cong.\n";
                    cout << "Ma Chuyen Bay: " << f2.MaMayBay2 << "\n";
                    cout << "Noi Di: " << f2.NoiDi2 << "\n";
                    cout << "Noi Den: " << f2.NoiDen2 << "\n";
                    cout << "Thoi Gian Di: " << f2.ThoiGianDi2 << "\n";
                    cout << "Thoi Gian Den: " << f2.ThoiGianDen2 << "\n";
                }
            }

            // dong ca 2 file
            file_in.close();
            file_out.close();

            // kiem tra xem co co sai hay khong
            if (!found3)
            {
                // hien thi loi
                cout << "Khong tim thay giu cho.\n";
            }
        }
        else
        {
            // hien thi loi dong file
            cout << "Loi.Khong mo duoc file2.\n";
            file_in.close();
        }
    }

    else
    {
        // hien thi loi
        cout << "Loi.\n";
    }
   
}

// ham de huy giu cho
void Huy_Dat_Cho()
{
    // tao object chuyen bay la f2
    class chuyenbay2 f2;
    string Ma_Chuyen_bay_Bi_Huy;
    // tao object nguoi dung de giu cho
    class nguoidung u;
    //
    cout << "Nhap Ma chuyen bay de huy: ";
    cin >> Ma_Chuyen_bay_Bi_Huy;

    // tao co false
    bool found = false;

    // mo file temp1 de ghi
    ifstream file_in("temp1.txt", ios::in);

    // kiem tra xem file da mo hay chua
    if (file_in.is_open())
    {
        // mo 1 file de placeholder
        ofstream file_out("temp.txt", ios::out);

        // kiem tra xem file da mo hay chua
        if (file_out.is_open())
        {
            // doc tat ca thong tin trong file
            while (file_in >> u.name >> u.pswd >> u.cccd >> u.phone >> u.email >> f2.MaMayBay2 >> f2.NoiDi2 >> f2.NoiDen2 >> f2.ThoiGianDi2 >> f2.ThoiGianDen2)
            {
                // kiem tra xem ma chuyen bay co trung vs ma chuyen bay bi huy hay khong
                if (f2.MaMayBay2 == Ma_Chuyen_bay_Bi_Huy)
                {
                    // dat co thanh true
                    found = true;
                }
                else
                {
                    // ghi tat ca thong tin vao file dat cho
                    file_out << f2.MaMayBay2 << " "
                             << f2.NoiDi2 << " "
                             << f2.NoiDen2 << " "
                             << f2.ThoiGianDi2 << " "
                             << f2.ThoiGianDen2 << "\n";
                }
            }

            // dong file
            file_in.close();
            file_out.close();

            if (found)
            {

                remove("temp1.txt");
                rename("temp.txt", "temp1.txt");

                cout << "Huy giu cho thanh cong.\n";
            }
            else
            {

                cout << "Khong tim thay giu cho.\n";
                remove("temp.txt");
            }
        }
        else
        {

            cout << "Loi.Khong mo duoc file2.\n";
            file_in.close();
        }
    }
    else
    {

        cout << "Loi.\n";
    }
}

// ham goi chinh
void giu_cho_mua_ve()
{

    int LuaChon;

    do
    {
        HienThi_Menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> LuaChon;
        switch (LuaChon)
        {
        // neu Lua chon cua nguoi dung la 1 thi chuyen den ham giu cho
        case 1:
            Giu_cho_chuyen_bay();
            break;
        case 2:
            // neu Lua chon cua nguoi dung la 2 thi chuyen den ham dat cho
            Dat_Cho();
            break;
        // neu Lua chon cua nguoi dung la 3 thi chuyen den ham huy giu cho
        case 3:
            Huy_Dat_Cho();
            break;
        // neu Lua chon cua nguoi dung la 4 thi thoat
        case 4:
            remove("temp1.txt");
            break;
        default:
            cout << "Loi.Vui long thu lai.\n";
        }
    } while (LuaChon != 4);
}

void MuaVe()

{
    class ve ve1;
    int a;
    cout << "Thanh toan de hoan tat thu tuc dat cho \n";
    cout << "Chon 1 de chap nhan.\n";
    cout << "Chon 2 de thoat \n";
    cout << "Vui long nhap lua chon cua ban: ";
    cin >> a;
    switch (a)
    {
    case 1:
        int b;
        cout << "\t\t Bang Chon loai ve:\n";
        cout << "Chon 1 de mua ve hang pho thong: 600.000d/ve\n";
        cout << "Chon 2 de mua ve hang thuong gia: 1.500.000/ve\n";
        switch (b)
        {
        case 1:

            ve1.loaive = "Pho-Thong";
            ve1.gia_ve = 600000;
            do
            {
                cout << "So luong ve pho thong can dat(toi da 3 ve):";
                cin >> ve1.so_luong_ve;
                if (ve1.so_luong_ve < 0 || ve1.so_luong_ve > 3)
                    cout << "Lua chon khong phu hop. Vui long chon lai\n";
            } while ((ve1.so_luong_ve) < 0 || ve1.so_luong_ve > 3);
            ve1.tong_tien = ve1.so_luong_ve * ve1.gia_ve;

        case 2:
            ve1.loaive = "Thuong-Gia";
            ve1.gia_ve = 1500000;
            do
            {
                cout << "So luong ve thuong gia can dat(toi da 2 ve):";
                cin >> ve1.so_luong_ve;
                if (ve1.so_luong_ve < 0 || ve1.so_luong_ve > 2)
                    cout << "Lua chon khong phu hop. Vui long chon lai";
            } while ((ve1.so_luong_ve) < 0 || ve1.so_luong_ve > 2);
            ve1.tong_tien = ve1.so_luong_ve * ve1.gia_ve;
        }

    case 2:
        giu_cho_mua_ve();
    }
}

void HienThiDatCho()
{
    string cccd;
    class nguoidung u;
    class ve ve1;
    class chuyenbay2 f2;
    cout << "Nhap cccd de tim kiem chuyen bay da dat:";
    cin >> cccd;
    bool found = false;
    ifstream file_in("DatCho.txt");

    // kiem tra xem file da mo hay chua
    if (file_in.is_open())
    {

        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\tLoai Ve\tGia Ve\tSo Luong Ve\tTong Tien\n";
        // doc tat ca thong tin o file
        while (file_in >> u.name >> u.pswd >> u.cccd >> u.phone >> u.email >> f2.MaMayBay2 >> f2.NoiDi2 >> f2.NoiDen2 >> f2.ThoiGianDi2 >> f2.ThoiGianDen2 >> ve1.loaive >> ve1.gia_ve >> ve1.so_luong_ve >> ve1.tong_tien && !found)
        {
            if (cccd == u.cccd)
            {
                found = true;
                cout << "\n";
                cout << f2.MaMayBay2 << "\t\t"
                     << f2.NoiDi2 << "\t\t"
                     << f2.NoiDen2 << "\t\t"
                     << f2.ThoiGianDi2 << "\t\t"
                     << f2.ThoiGianDen2 << "\t"
                     << ve1.loaive << "\t"
                     << ve1.gia_ve << "\t"
                     << ve1.so_luong_ve << " "
                     << ve1.tong_tien << " ";
                cout << "\n";
                cout << "Thong Tin Nguoi Dat Ve";
                cout << "Ho ten\t\tCCCD\t\t\tSo Dien Thoai\t\t\tEmail\n";
                cout << u.name << "\t" << u.cccd << "\t\t" << u.phone << "\t\t" << u.email << endl;
            }
        }
        if (!found)
            cout << "Khong tim thay dat cho\n";
    }
    file_in.close();
}