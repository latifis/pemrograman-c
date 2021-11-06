#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct datapasien {
	string nama;
	int nomorUrut;
	string penyakit;
	int lamaInap;
	int bayar;
	}pasien[10];

void input();
void import();
void eksport();
void caridata();
void pembayaran();
void error();

int main(){
	
	int pilih;
	eksport();
	
	cout << "============ RS. Harapan Hidup ============";
	cout << "\n\n\t1. Input Data Pasien Inap";
	cout << "\n\t2. Cari Data Pasien Inap";
	cout << "\n\t3. Pembayaran Inap";
	cout << "\n\t4. Keluar";
	cout << "\n\n\tPilih : "; cin >> pilih;
	
	system("cls");
	
	switch (pilih)
	{
		case 1 :
			input();
			import();
			main();
			break;			
		case 2 :
			eksport();
			caridata();
			main();
			break;
		case 3 :
			eksport();
			pembayaran();
			import();
			main();
			break;
		case 4 :
			exit(0);
		default:
			error();		
	}		
}

void input(){
	
	int jml;
	
	cout << "Jumlah Pasien yang Akan Dimasukkan Datanya(max 10) : "; cin >> jml;
	
	for (int i = 0; i < jml; i++)
	{
		cout << "\nMasukkan Data Pasien ke-" << i+1;
		cin.ignore();
		cout << "\n\tNama\t\t: "; getline(cin, pasien[i].nama);
		cout << "\tNomor Urut\t: "; cin >> pasien[i].nomorUrut;
		cin.ignore();
		cout << "\tPenyakit\t: "; getline(cin, pasien[i].penyakit);
		cout << "\tLama Inap\t: "; cin >> pasien[i].lamaInap;
	}
	
	cout << "\n\nData telah berhasil di input, tekan enter untuk kembali ke Menu";
	getch();
	system("cls");
}

void import()
{
	ofstream tulis;
	string namafile="file.txt";
		
	tulis.open(namafile.c_str());
	for (int i = 0; i < 10; i++)
	{
		tulis << pasien[i].nama << endl; 
		tulis << pasien[i].nomorUrut << endl;
		tulis << pasien[i].penyakit << endl;
		tulis << pasien[i].lamaInap << endl;
		tulis << pasien[i].bayar << endl;	
	}
	tulis.close();	

}

void eksport()
{
	ifstream baca;
	string namafile="file.txt";
		
	baca.open(namafile);
		
	for(int i = 0 ; i < 5; i++)
	{
		getline(baca,pasien[i].nama);
		baca >> pasien[i].nomorUrut;
		baca.ignore();
		getline(baca,pasien[i].penyakit);
		baca >> pasien[i].lamaInap;
		baca >> pasien[i].bayar;
	}
	baca.close();
}

void caridata(){
	
	string namaPenyakit;
	char keluar;
	int ketemu=0;
	
	cin.ignore();
	cout << "Masukkan Nama Penyakit : "; getline(cin, namaPenyakit);
	
	for (int i = 0; i < 10; i++)
	{
		if (pasien[i].penyakit==namaPenyakit)
		{
			cout << "\n\tNama\t\t: " << pasien[i].nama;
			cout << "\n\tNomor Urut\t: " << pasien[i].nomorUrut;
			cout << "\n\tPenyakit\t: " << pasien[i].penyakit;
			cout << "\n\tLama Inap\t: " << pasien[i].lamaInap;
			ketemu = 1;
		}
	}
	if (ketemu==0)
	{
		cout << "\n\tData Tidak Ditemukan";
	}
	
	cout << "\n\nKembali ke menu? (y/n)"; cin >> keluar;
	system("cls");
	
	if (keluar=='y' || keluar=='Y')
	{
		main();
	}	
	else if(keluar=='n' || keluar=='N')
	{
		caridata();
	}
	else
	{
		error();
	}	
}

void pembayaran(){
	
	string namaPasien;
	char keluar;
	int ketemu=0;
	
	cin.ignore();
	cout << "Masukkan Nama Pasien : "; getline(cin, namaPasien);
	
	for (int i = 0; i < 10; i++)
	{
		if (pasien[i].nama==namaPasien)
		{
			cout << "\n\tNama\t\t: " << pasien[i].nama;
			cout << "\n\tNomor Urut\t: " << pasien[i].nomorUrut;
			cout << "\n\tPenyakit\t: " << pasien[i].penyakit;
			cout << "\n\tLama Inap\t: " << pasien[i].lamaInap;
			pasien[i].bayar = 500000*pasien[i].lamaInap;
			cout << "\n\tLama Inap\t: " << pasien[i].bayar;
			ketemu = 1; 
		}
	}
	
	if (ketemu==0)
	{
		cout << "\n\tData Tidak Ditemukan";
	}
	
	cout << "\n\nKembali ke menu? (y/n)"; cin >> keluar;
	system("cls");
	
	if (keluar=='y' || keluar=='Y')
	{
		main();
	}	
	else if(keluar=='n' || keluar=='N')
	{
		caridata();
	}
	else
	{
		error();
	}
}

void error()
{
	cout << "Tidak ada dalam menu!!" << endl;
	cout << "Untuk Kembali ke Menu Utama Tekan Enter" << endl;
	getch();
	system("cls");
	main();
}
