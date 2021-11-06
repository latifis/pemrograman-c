#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
using namespace std;

string nama[50];
string pass[50];
string user,kode,nam,vc;
string pilih,menu,lagi;
string sepatu[50]={"JORDAN AJ 33 SE PF Grey","JORDAN AJ 2 RETRO Black","JORDAN AJ 7 RETRO PE Ray Allen","JORDAN AJ 9 RETRO Blue","JORDAN DNA LX Dark","JORDAN AJ 8 RETRO","JORDAN WMNS AJ 1 MID Military Olive"};

int men1,beli;
int harga[50]={2900000,2700000,2800000,2800000,1800000,2500000,2000000};
int size[8]={40,41,42,43,44,45,46};
int ukuran;
int total,total2,kembalian,bayar,diskon;

char men0;

void listsepatu ();
void listsize ();
void login();
void buatakun();
void detailpembelian();
void pembayaran();

int main(){
			
			for(int i=7; i<=50; i++){
			pass[i]="empty";
			nama[i]="empty";
			sepatu[i]="empty";
			harga[i]=0;
			}

do{
	cout <<
			" ++ ======  MENU UTAMA  ======= ++\n"
			" ||				||\n"
			" ||	 1. Buat Akun	        ||\n"
			" ||      2. Login	        ||\n"
			" ||	 3. Buat Pesanan        ||\n"
			" ||				||\n"
			" ++ =========================== ++\n\n\n"
			
			" Pilihan: "; cin >> men1;
			cin.ignore();
			

switch(men1){
	case 1:
		buatakun();
		break;
	case 2:
		login();
		break;
	case 3 :
		cout << "Berikut List Sepatu yang Tersedia	: \n";
		listsepatu();
		break;
	default:
		cout << " Input Tidak Ada Dalam Menu\n";
	}

	cout << "\nKembali ke Menu Utama?(y/n) "; cin>>men0;
	cout << "\n\n\n\n";
	system("cls");
}while(men0=='y'||men0=='Y');
	
	return 0;
}
void buatakun(){
		int i=0;
		cout << "\n\n\n ====  Menu Buat Akun  ====\n\n";
		cout << " Masukan Username: "; getline(cin,nama[i]);
		
		cout << " Masukan Password: "; getline(cin,pass[i]);
		i++;
		cout << endl << "Akun Telah Berhasil Dibuat\n\n";
}
void login(){
		int acak;
		string voucher[5]={"ABC534","LOL556","GOB777","LUC666","LUV123"};
		srand(time(0));
		
		cout << "\n\n\n ====  Menu Login  ====\n\n";
		cout << "\n Masukan Username: "; getline(cin,user);
		cout << " Masukan Password: "; getline(cin,kode);
		
		for(int i=0; i<100; i++){
			if(nama[i]==user && pass[i]==kode)
				{
					cout << "\n Login Berhasil\n\n";
					acak = rand() % 5;
					/*cout << " Selamat untuk kamu mendapatkan voucher diskon :"
							"\n\n ++\t\t\t\t\t\t++"
							"\n ++\t\t\t\t\t\t++";
					cout << "\n ||\t\t\t[" << voucher[acak] << "]\t\t\t \n\n" << endl;
					cout << "\n ||\t\t\t\t\t\t||"
							"\n ++\t\t\t\t\t\t++";*/
							
					cout << " Selamat untuk kamu mendapatkan voucher diskon. \n Kode voucher :"
							"\n\n \t ++=============++"
							"\n \t ||\t\t||";
					cout << "\n \t ||   [" << voucher[acak] << "]  ||";
					cout << "\n \t ||\t\t||"
							"\n \t ++=============++" << endl;
					break;
				}
			else
				{	
					cout<< "\n Belum Punya Akun ?? Silahkan mendaftar di Menu Buat Akun\n";
					break;
				}
		}	
}
void listsepatu(){
		do
		{
			for(int i=0; i<=50; i++){
			if(sepatu[i]== "empty" ) break;
			cout << i+1 <<". "<< sepatu[i]; 
			cout <<"\n   Harga		: Rp "<< harga[i] << endl;
			listsize();
			cout << endl;
		}
		
		cout << "   Pilih sepatu	: "; cin >> beli;
		cout << "   Pilih size	: "; cin >> ukuran;
		
		detailpembelian ();
		
		if (ukuran>=40 && ukuran<=46)
			total=total+harga[beli-1];
		else
			total=0;
		
		cout << endl;
		cout << "Beli lagi? (ya/tidak) "; cin >> lagi;
		} while (lagi=="ya");
		system("cls");
		cout << endl;
		cout << "P E M B A Y A R A N\n";
		cout << "Total		: Rp " << total << endl;
		cout << "\n*jika anda tidak memiliki kode voucher tolong ketik 0";
		cout << "\nMASUKAN KODE VOUCHER	: "; cin >> vc;
		if (vc=="ABC534" || vc=="LOL556" || vc=="GOB777" || vc=="LUC666" || vc=="LUV123"){
			cout << "Selamat anda mendapatkan diskon 5%";
			diskon=total*0.05;
		}
		else
			diskon=0;
			
		cout << endl;
		
		if (ukuran>=40 && ukuran<=46)
			total2=total-diskon;
		else
			total2=0;
		
		cout << "\nTotal		: Rp " << total2;
		pembayaran();
}
void listsize(){
	cout << "   Size tersedia	: ";	
	for(int i=0; i<7; i++){
		cout << size[i];
		if(i<6)
			cout << ",";
		else
			cout << endl;
	}
}
void detailpembelian(){
		cout << "\n Detail pembelian";
		
		for(int i=0; i<=7; i++){
			if ((beli-1)==i){
				
				cout << endl << endl;
				cout << "\t" << sepatu[i] << endl; 
				cout <<"\n   Harga		: Rp "<< harga[i] << endl;
				
				if (ukuran>=40 && ukuran<=46)
					cout <<"\n   Size			: "<< ukuran << endl;
				else
						cout <<"\n   Size			: Size tidak tersedia" << endl;
				}	
			else if ((beli-1)>=7){
				cout << endl << endl;
				cout << "\t INPUT SALAH" << endl; 
				cout <<"\n   Harga		: -" << endl;
				cout <<"\n   Size			: -" << endl;
				break;
			}
		}
}
void pembayaran(){
		cout << "\nBayar		: Rp "; cin >> bayar;
		kembalian=bayar-total2;
		if (kembalian==0)
			cout << "Uang anda pas!";
		else if (bayar-total2>0)
			cout << "Kembalian: Rp " << kembalian;
		else
			cout << "Uang anda kurang!";
			
		total=0; total2=0;
}
