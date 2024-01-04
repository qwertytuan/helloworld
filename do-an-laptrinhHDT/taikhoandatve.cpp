#include<iostream>
#include<fstream>
#include<string.h>
#include"giucho-muave.hpp"
#include"nguoidung.hpp"
using namespace std;

	
int main()
{
	remove("temp1.txt");
    int c;
    cout<<"Chao mung den voi trang dat ve"<<"\n";
	cout<<"Cac chuyen bay hien co:"<<"\n";
	HienThiThongTinChuyenBay();
    cout<<"Vui long dang ky hoac dang nhap de tiep tuc su dung dich vu."<<"\n";
    cout<<"Chon 1 de dang nhap."<<endl;
    cout<<"Chon 2 de dang ky."<<endl;
	cout<<"Chon 3 tim kiem cac chuyen bay."<<endl;
    cout<<"Nhap lua chon cua ban:";
    cin>>c;
	
    switch(c)
	{
		case 1 :
			DangNhap();
			main();
			break;
		case 2 :
			DangKy();
			break;
		case 3:
		TimKiemChuyenBay();
			break;
		default:
		    cout<<"\t\t\t Vui long chon cac tuy chon da cung cap tren \n"<<endl;
			main();
			 	
	 } 
	 
}
