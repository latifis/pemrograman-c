#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string nama[50], namapem;
string pass[50];
string user, kode;

int harga[10], banyak[10], x, y, total1, total2;
//int x, y, z, i, j, banyak[10], harga[10],kategori, total, total1=0, total2=0, bayar, bayar2; 
string menu[20], no; 

int pilih, kategori;

char pilih1, pilih2, pilih3, pilih4;

void buatakun();
void login();
void beli();
void belimakan();
void beliminum();
void akhir();

int main()
{
	for(int i=7; i<=50; i++){
			pass[i]="empty";
			nama[i]="empty";
			}
	
	do 
	{
		cout << "1. buat akun\n";
		cout << "2. login\n";
		cout << "3. beli\n";
		cout << "pilih : "; cin >> pilih;
	
		switch(pilih)
		{	
			case 1 :
				buatakun();
				break;
			case 2 :
				login();
				break;
			case 3 :
				beli ();
				void belimakan();
				void beliminum();
				break;
			default :
				cout << "Pilihan tidak ada dalam menu";
		}		
		cout << "\n\nKembali ke menu? (y/n)"; cin >> pilih1;
		system("cls");
		}while(pilih1=='y' || pilih1=='Y');
	
	akhir();
	
	return 0;
}

void buatakun(){
		
		int i=0;
		
		cout<<"\n||========================================||"<<endl;
		cout<<"||---------------DAFTAR AKUN--------------||"<<endl;
		cout<<"||========================================||"<<endl;
		
		cout << "\n Masukan Username: "; cin >> nama[i];
		cout << " Masukan Password: "; cin >> pass[i];
		i++;
		cout << endl << "Akun Telah Berhasil Dibuat\n";
	
}
void login(){
		
		cout<<"\n||======================================||"<<endl;
		cout<<"||-----------------LOGIN----------------||"<<endl;
		cout<<"||======================================||"<<endl;
		
		cout << "\n Username: "; cin >> user;
		cout << " Password: "; cin >> kode;
		
		for(int i=0; i<100; i++){
			if(nama[i]==user && pass[i]==kode)
				{
					cout << "\n Selamat, Login Anda Berhasil\n";
					break;
				}	
			else
				{	
					cout<< "\n LOGIN GAGAL\n\n";
					cout<<"Ingin Login Kembali? (y/n) : "; cin >> pilih2;
					if(pilih2=='y' || pilih2=='Y')
						login();
					else 
					{
						cout << "Kembali ke menu? (y/n)"; cin >> pilih3;
						if(pilih3=='y' || pilih3=='Y')
							main();
						else
						{	cout<<endl;
							cout<<"|======================================|"<<endl;
							cout<<"|\tTerima Kasih Sudah Berkunjug\t|"<<endl;
							cout<<"|\t    Semoga Memuaskan    \t"<<endl;
							cout<<"|======================================|"<<endl;		
						}
					}
					break;
				}
			
		}
}

void akhir(){
		
	cout<<endl;
	cout<<"|======================================|"<<endl;
	cout<<"|\tTerima Kasih Sudah Memesan\t|"<<endl;
	cout<<"|\t    Semoga Memuaskan    \t"<<endl;
	cout<<"|======================================|"<<endl;
	
}

void beli()
{
	int i, j;
	do
	{	
		cout<<"|*********************************|"<<endl;
		cout<<"|\t\t\tRESTORANKU\t\t\t|"<<endl;
		cout<<"|*********************************|"<<endl;
		cout<<"Nomor Pesanan\t: ";cin>>no;
		cout<<"Nama Pemesanan\t: ";cin>>namapem;


		cout<<"||==================================================||"<<endl;
		cout<<"||    KATEGORI    |          MENU      |    HARGA   ||"<<endl;
		cout<<"||==================================================||"<<endl;
		cout<<"||    |           | AG | Ayam Goreng   | Rp 16.000  ||"<<endl;
		cout<<"|| 1  |  Makanan  | AB | Ayam Bakar    | Rp 18.000  ||"<<endl;
		cout<<"||    |           | LG | Lele Goreng   | Rp 13.000  ||"<<endl;
		cout<<"||----------------| LB | Lele Bakar    | Rp 14.000  ||"<<endl;
		cout<<"|| 2  |  Minuman  | EJ | Es Jeruk      | Rp 3.000   ||"<<endl;
		cout<<"||    |           | ET | Es Teh        | Rp 3.000   ||"<<endl;
		cout<<"||==================================================||"<<endl;
			
		cout<<"Masukan Kategori Menu :"; cin>>kategori;
		cout<<endl;
			
			switch(kategori)
			{
				case 1 :
				{
					cout<<"Masukan Banyak Makanan : "; cin>>x;
					
						belimakan();
					
					cout<<"\nTotal harga makanan :"<<total1;
				}
				break;
				
				case 2 :
				{
					cout<<"Masukan Banyak Minuman : "; cin>>y;
					
						beliminum();
			
					cout<<"\nTotal harga minuman :"<<total2;
				}
				break;
				
				default : cout<<"Input Yang Anda Masukkan Salah"<<endl;
			}
				cout<<"\nIngin Kembali Ke Menu Utama? (y/n) : "; cin>>pilih4;
				cout<<endl;
		}	
		while(pilih4=='y' || pilih4=='Y');
		system("cls");
}

void belimakan()
{
	for(int i=0; i<x; i++)
	{
		cout << "\nMasukkan Menu Makanan ke-"<< i+1 <<"\t: ";
		cin >> menu[i];
		cout << "Masukkan banyak makanan\t\t: "; cin >> banyak[i];
		cin.ignore();
						
		if (menu[i]=="AG" ||menu[i]=="ag")
		{
			harga[i]=16000*banyak[i];
			cout<<"Harga =" << harga[i];
		}
		else if (menu[i]=="AB" || menu[i]=="ab")
		{
			harga[i]=18000*banyak[i];
			cout<<"Harga =" << harga[i];
		}
		else if (menu[i]=="LG" || menu[i]=="lg")
		{
			harga[i]=13000*banyak[i];
			cout<<"Harga =" << harga[i];
		}
		else if (menu[i]=="LB" || menu[i]=="lb")
		{
			harga[i]=14000*banyak[i];
			cout<<"Harga =" << harga[i];
		}
		else
		{
			cout << "Maaf, Menu Tidak Tersedia";
		}
		cout << endl;
		
		total1=total1+harga[i];
	}
}
void beliminum()
{
	for(int j=0; j<y; j++)
	{
		cout << "\nMasukkan Menu Minuman ke-"<< j+1 << "\t: "; 
		cin >> menu[j];
		cout << "Masukkan banyak minuman\t\t: "; cin >> banyak[j];
		cin.ignore();
		
		if (menu[j]=="EJ" || menu[j]=="ej")
		{
			harga[j]=3000*banyak[j];
			cout << "Harga =" << harga[j];
		}
		else if (menu[j]=="ET" ||menu[j]=="et")
		{
			harga[j]=3000*banyak[j];
			cout << "Harga =" << harga[j];
		}
		else
		{
			cout << "Maaf, Menu Tidak Tersedia";
		}
		cout << endl;
		
		total2=total2+harga[j];
	}
}
