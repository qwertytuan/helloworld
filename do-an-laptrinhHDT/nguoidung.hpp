#include<iostream>
#include<fstream>
#include<string.h>
#include"ham-admin.hpp"
#include"filephutro.hpp"
using namespace std;
class ve2
{
public:
    string loaive2;
    int so_luong_ve2;
    int gia_ve2;
    int tong_tien2;
};
class phiennguoidung
{
 public:
 string name;
 string pswd;
 string cccd;
 string phone;
 string email;
};
class chuyenbay3
{
public:
    string MaMayBay3;
    string NoiDi3;
    string NoiDen3;
    string ThoiGianDi3;
    string ThoiGianDen3;
};
void DangNhap();
void DangKy();
void ChinhSuaProfile();
void TimKiemChuyenBay();


void DangNhap()
    {
		ofstream file_out("temp1.txt", ios::app);
		class phiennguoidung u2;
		class ve2 ve2;
		class chuyenbay3 f3;
    	int count;
    	string userId, password, Id, pass,cccd,sdt,email2;
    	system("clear");
    	cout<<"\t\t\t Vui long nhap ten tai khoan va mat khau: "<<endl;
    	cout<<"\t\t\t Ten tai khoan : ";
    	cin>>userId;
    	cout<<"\t\t\t Mat khau :" ;
	    echo(false);
        cin>>password;
        echo(true);
    	ifstream input("LuuTruNguoiDung.txt");
    	
    	while(input>>Id>>pass>>cccd>>sdt>>email2)
    	{
			// neu userId ta nhap trung voi Id da luu trong LuuTruNguoiDung.txt thi cho bien count=1
    		if(userId==Id && password==pass)
    		{
    			count=1;
    			system("clear");
			}
	
		}
		input.close();
		// neu count=1 thi ta xac nhan da dang nhap thanh cong
		if(count==1)

{
			cout<<userId<<"\n Dang nhap cua ban thanh cong! \n Cam on vi da dang nhap! \n"; 
			//////////////////////////////////////////////////
			 bool found1 = false;
    // mo file lua tru thong tin nguoi dung de doc
    ifstream fileuser("LuuTruNguoiDung.txt", ios::in);
     // kiem tra xem file da mo thanh cong chua
     if (fileuser.is_open()) {
         // doc den khi den dong cuoi cua file 
         while (fileuser>>u2.name>>u2.pswd>>u2.cccd>>u2.phone>>u2.email && !found1) {
             // kiem tra ma may bay co trung hay khong
             if ( userId==u2.name)
			  {
                 // neu trung thi la true
                 found1 = true;
				 // viet vao 1 file tam temp1 de tao 1 phien dang nhap cho tung nguoi dung
				 if( file_out.is_open())
				 {
				 file_out<<u2.name<<" "<<u2.pswd<<" "<<u2.cccd<<" "<<u2.phone<<" "<<u2.email<<endl;
				 file_out.close();
				 }
             }
     }
		}
///////////////////////////////////

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
			HienThiThongTinChuyenBay();
                Giu_cho_chuyen_bay();
                break;
            case 2:
            // neu Lua chon cua nguoi dung la 2 thi chuyen den ham dat cho
                Dat_Cho();
                break;
            // neu Lua chon cua nguoi dung la 3 thi chuyen den ham huy giu cho
            case 3: 
			HienThiThongTinChuyenBay;
                Huy_Dat_Cho();
                break;
			case 4:
			HienThiDatCho();
            break;
            // neu Lua chon cua nguoi dung la 4 thi thoat 
            case 5:
            ChinhSuaProfile();
            break;
            case 6:
            break;
            default:         
			 cout << "Loi.Vui long thu lai.\n";
        
	    }

    } while (LuaChon != 7);

}

		// neu count khac 1 thi quay lai menu
		else
		{
			cout<<"\n Loi dang nhap! \n Vui long kiem tra ten dang nhap va mat khau! \n";
		}
	}
	// ham DangKy() doc dau vao cua nguoi dung va luu vào file LuuTruNguoiDung.txt de ham DangNhap() dung
void DangKy()
	{
		string ruserId, rpassword, rId, rpass, rcccd,rsodienthoai,remail;
		string checktentk,cpswd,Ccccd,csodienthoai,cemail;
		system("clear");
		cout<<"\t\t\t Nhap ten nguoi dung : ";
		cin>>ruserId;
		cout<<"\t\t\t Nhap mat khau : ";
		cin>>rpassword;
		cout<<"\t\t\t Nhap can cuoc cong dan : ";
		cin>>rcccd;
		cout<<"\t\t\t Nhap so dien thoai :";
		cin>>rsodienthoai;
		cout<<"\t\t\t Nhap email :";
		cin>>remail;
		bool checkttk=false;
		ifstream checktk("LuuTruNguoiDung.txt");
		while(checktk>>checktentk>>cpswd>>Ccccd>>csodienthoai>>cemail && !checkttk)
    	{
			// neu userId ta nhap trung voi Id da luu trong LuuTruNguoiDung.txt thi cho bien count=1
    		if(ruserId==checktentk)
    		{
    			checkttk=true;
				cout<<"Ten tai khoan da bi trung. Vui long thu lai\n";
			    DangKy();
			}
		
	
		}
		if(!checkttk)
		{
		//nhap du lieu cua nguoi dung vao file txt 
		ofstream f1("LuuTruNguoiDung.txt", ios::app);
		f1<<ruserId<<' '<<rpassword<<' '<<rcccd<<' '<<rsodienthoai<<' '<<remail<<endl;
		system("clear");
		cout<<"\n\t\t\t  Dang ky cua ban thanh cong! \n";
		DangNhap();
		}
	}

void ChinhSuaProfile()
{ 
class nguoidung u3;
string tencanchinhsua;
string checkT,cHpswd,CHcccd,cHsodienthoai,cHemail;
 ifstream filechinhsuatk("temp1.txt");
 filechinhsuatk>>tencanchinhsua>>u3.pswd>>u3.cccd>>u3.phone>>u3.email;
 filechinhsuatk.close();
    // khai bao de xem ma may bay co ton tai hay khong
    bool found = false;

    // mo file LuuTruNguoiDung.txt de ghi
    ifstream file_in("LuuTruNguoiDung.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file_in.is_open()) 
    {
        // mo 1 file temp tam thoi
        ofstream file_out("temp.txt", ios::out);

        // kiem tra xem file da mo thanh cong chua
        if (file_out.is_open()) {
            // doc chi tiet 
            while (file_in >>u3.name>>u3.pswd>>u3.cccd>>u3.phone>>u3.email) 
            {
                // kiem tra xem ma may bay co trung voi ma may bay can duoc sua
                if ( tencanchinhsua == u3.name) {
                    // neu dung thi cho la true
                    found = true;

                    // ghi cac chi tiet moi vao
                    cout << "Nhap ten tai khoan moi: \n";
                    cin >> u3.name;
                    /////////

                    bool checkttk=false;
		ifstream check("LuuTruNguoiDung.txt");
		while(check>>checkT>>cHpswd>>CHcccd>>cHsodienthoai>>cHemail && !checkttk)
    	{
			// neu userId ta nhap trung voi Id da luu trong LuuTruNguoiDung.txt thi cho bien count=1
    		if(u3.name==checkT)
    		{
    			checkttk=true;
				cout<<"Ten tai khoan da bi trung. Vui long thu lai\n";
			    HienThi_Menu();
			}
		
	
		}
		if(!checkttk)
		{
                    /////////

                    cout << "Nhap mat khau moi: \n";
                    cin >> u3.pswd;
                    cout << "Nhap cccd moi: \n";
                    cin >> u3.cccd;
                    cout << "Nhap so dien thoai moi: \n";
                    cin >>u3.phone;
                    cout<<"Nhap email moi: \n";
                    cin>>u3.email;
        }
                }

                // ghi lai vao file
                file_out << u3.name << " "
                         << u3.pswd << " "
                         << u3.cccd << " "
                         << u3.phone << " "
                         <<u3.email << "\n";
            }

            // dong ca 2 file temp va LuuTruNguoiDung.txt
            file_in.close();
            file_out.close();

            // kiem tra xem co true khong
            if (found) {
                // thay ten cua file temp = LuuTruNguoiDung.txt va xoa file cu di
                remove("LuuTruNguoiDung.txt");
                rename("temp.txt", "LuuTruNguoiDung.txt");

                // hien thi da thanh cong
                cout << "Tai khoan da sua thanh cong.\n";
            }
            else {
                // hien thi loi va xoa file temp
                cout << "Khong tim thay tai khoan.\n";
                remove("temp.txt");
            }
        }
        else {
            // hien thi loi and close the input file
            cout << "Loi.Khong the mo file output.\n";
            file_in.close();
        }
    }

    else {
        // hien thi loi
        cout << "Loi.Khong the mo file input.\n";
    }

}

void TimKiemChuyenBay()
{
    int chon;
    class chuyenbay3 f4;
    string noixuatphat,noiden;
    system("clear");
    cout<<"Chon 1: Tim kiem theo noi xuat phat.\n";
    cout<<"Chon 2: Tim kiem theo noi den.\n";
    cout<<"Nhap lua chon cua ban:";
    cin>>chon;
    switch (chon)
    {
    case 1:
    {
    cout<<"Nhap noi xuat phat: ";
    cin>>noixuatphat;
    

    // mo file LuuTruMayBay.txt de ghi
    ifstream file("LuuTruMayBay.txt", ios::in);

     // kiem tra xem file da mo thanh cong chua
     if (file.is_open()) {
        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\n";
         // doc den khi den dong cuoi cua file 
         while (file >> f4.MaMayBay3 >> f4.NoiDi3 >> f4.NoiDen3 >> f4.ThoiGianDi3 >> f4.ThoiGianDen3 ) {
             // kiem tra ma may bay co trung hay khong
             if (f4.NoiDi3 == noixuatphat) 
             {
                 // hien thi la da tim thay
                  cout<<"\n";
            cout << f4.MaMayBay3 <<"\t\t"
                 << f4.NoiDi3 <<"\t\t"
                 << f4.NoiDen3 <<"\t\t"
                 << f4.ThoiGianDi3 <<"\t\t"
                 << f4.ThoiGianDen3 <<"\n";
                 cout<<"\n";
             }
             // neu trung thi la true
             
         }

         // dong file
         file.close();

         // kiem tra xem co tim duoc khong
         /*if (!founda) {
             // hien thi ko tim thay
             cout << "Khong tim thay chuyen bay.\n";
         }
         */
     }
     else {
         // hien thi loi
         cout << "Loi. Khong The Mo File.\n";
     }
     break;
    }

case 2:
{
    cout<<"Nhap noi den: ";
    cin>>noiden;
    // mo file LuuTruMayBay.txt de ghi
    ifstream filef("LuuTruMayBay.txt", ios::in);

     // kiem tra xem file da mo thanh cong chua
     if (filef.is_open()) {
        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\n";
         // doc den khi den dong cuoi cua file 
         while (filef >> f4.MaMayBay3 >> f4.NoiDi3 >> f4.NoiDen3 >> f4.ThoiGianDi3 >> f4.ThoiGianDen3 ) {
             // kiem tra ma may bay co trung hay khong
             if (f4.NoiDen3 == noiden) {
                 // hien thi la da tim thay
                  cout<<"\n";
            cout << f4.MaMayBay3 <<"\t\t"
                 << f4.NoiDi3 <<"\t\t"
                 << f4.NoiDen3 <<"\t\t"
                 << f4.ThoiGianDi3 <<"\t\t"
                 << f4.ThoiGianDen3 <<"\n";
                 cout<<"\n";
             }
             // neu trung thi la true
            
         }

         // dong file
         filef.close();

         // kiem tra xem co tim duoc khong
        /* if (!foundf) {
             // hien thi ko tim thay
             cout << "Khong tim thay chuyen bay.\n";
         }
         */
     }
     else {
         // hien thi loi
         cout << "Loi. Khong The Mo File.\n";
     }
     break;
}
     default:
     break;
    }
    
}