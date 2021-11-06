#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

typedef struct{
	string nik, nama, asal, goldar, jenkel;
	} data;
data wni[100];
data temp;

typedef struct{
	string akun, pass;
	} awal;
awal masuk[100];
awal tmp;

void inputdata();
void error();
void import(string file, int batas);
void tampildata();
void eksport(string file, int *tampil);

void caridata();
void caridataseq();
void carinikseq();
void carinamaseq();
void carigoldarseq();
void carijenkelseq();
void cariasalseq();

void caridatabin();
void caridatabin();
void carinikbin();
void carinamabin();
void carigoldarbin();
void carijenkelbin();
void cariasalbin();

void urutdata();

void urutdatabubble();
void urutbubblenik(string file);
void urutbubblenama(string file);
void urutbubblegoldar(string file);
void urutbubblejenkel(string file);
void urutbubbleasal(string file);

void urutdatasel();
void urutselnik(string file);
void urutselnama(string file);
void urutselgoldar(string file);
void urutseljenkel(string file);
void urutselasal(string file);

void urutdatains();
void urutinsnik(string file);
void urutinsnama(string file);
void urutinsgoldar(string file);
void urutinsjenkel(string file);
void urutinsasal(string file);

void urutdatashe();
void urutshenik(string file);
void urutshenama(string file);
void urutshegoldar(string file);
void urutshejenkel(string file);
void urutsheasal(string file);

void importurut(int batas);
void eksporturut(int *batas);
void ganti(int j);
void ganti2(int i, int j);
void ganti3(int a);
void tampilurut(int batas);

void home();
void login();
void daftar();
int homee=0;

main ()
{	
	if(homee==0)
	{
		home();
		homee++;
	}
	
	int pilih;
	string file;
	
	cout << "**==============================**==============================**";
	cout << "\n||				||				||";
	cout << "\n||	Latief Irfansyah	||	  NIM . 124190056	||";
	cout << "\n||				||				||";
	cout << "\n**==============================**==============================**";
	cout << "\n||								||";
	cout << "\n||			    K    T    P	 		        ||";
	cout << "\n||								||";
	cout << "\n**==============================================================**";
	cout << "\n||								||";
	cout << "\n||			1. Input Data		  	        ||";
	cout << "\n||			2. Tampilkan Data		        ||";
	cout << "\n||			3. Searching Data		        ||";
	cout << "\n||			4. Sorting Data		     	        ||";
	cout << "\n||			5. Keluar		  	        ||";
	cout << "\n||								||";
	cout << "\n**==============================================================**";
	cout << "\n\n  Pilih : "; cin >> pilih;
	cout << "\n\n**==============================================================**" << endl;
	system("cls");
	
	string aku = "aku makan";
	
	switch (pilih)
	{
		case 1 :
			inputdata();
			system("cls");
			main();
			break;
		case 2 :
			tampildata();
			system("cls");
			main();
			break;
		case 3 :
			caridata();
			system("cls");
			main();
			break;
		case 4 :
			urutdata();
			system("cls");
			main();
			break;
		case 5 :
			exit(0);
			break;
		default	:
			error();
			
	}
	

}

void home()
{
	for (int i = 0; i < 10; i++)
	{
		masuk[i].akun="0";
		masuk[i].pass="0";
	}
	
	
	int pilih;
	
	cout << "**================================================**" << endl;
	cout << "|| 						  ||" << endl;
	cout << "||		 H O M E    P A G E		  ||" << endl;
	cout << "|| 						  ||" << endl;
	cout << "**================================================**" << endl;
	cout << "|| 						  ||" << endl;
	cout << "||\t	   Selamat datang !!		  ||" << endl;
	cout << "||\t   Silahkan Login Terlebih Dahulu	  ||" << endl;
	cout << "|| 						  ||" << endl;
	cout << "||\t 	  Tidak Punya akun ??		  ||" << endl;
	cout << "||\t   Silahkan Daftar Terlebih Dahulu	  ||" << endl;
	cout << "|| 						  ||" << endl;
	cout << "||\t 	Tentukan Pilihan Anda		  ||" << endl;
	cout << "||\t  	     1. Login			  ||" << endl;
	cout << "||\t  	     2. Daftar			  ||" << endl;
	cout << "|| 						  ||" << endl;
	cout << "**================================================**" << endl << endl;
	cout << "\t  Pilih = "; cin >> pilih;
	system("cls");
	
	switch (pilih)
	{
		case 1 :
			login();
			break;
		case 2 :
			daftar();
			break;
		default:
			home();
	}
	
}

void login()
{
	cout << "**================================================**" << endl;
	cout << "|| 						  ||" << endl;
	cout << "||		L O G I N    P A G E		  ||" << endl;
	cout << "|| 						  ||" << endl;
	cout << "**================================================**" << endl << endl;
	cout << "\t Nama	: "; cin >> tmp.akun; cout << endl;
	cout << "\t Pass	: "; cin >> tmp.pass; cout << endl;
	
	ofstream tulis;
	string namafile="login.txt";
		
	tulis.open(namafile.c_str(), ios::app);	
	
	tulis.close();
	
	ifstream baca;
	int batas;
		
	baca.open(namafile);
		
		for(int i=0; true; i++)
		{
			getline(baca,masuk[i].akun);
			getline(baca,masuk[i].pass);

			if(baca.eof())
			{
				batas = i;
				break;
			}
		}
		
	baca.close();
	
	system("cls");
	
	for (int i = 0; i < batas; i++)
	{
		if(tmp.akun==masuk[i].akun && tmp.pass==masuk[i].pass)
		{
			homee=1;
		}
	}
	
	int tentu;
	
	if(homee==0)
	{
		cout << "\n\t Nama dan Password yang Anda Masukkan Salah!!";
		cout << "\n\n\t Masukkan Angka \"1\" untuk Kembali ke Menu Awal";
		cout << "\n\t Masukkan Angka \"2\" untuk Kembali ke Login Page";
		cout << "\n\t Masukkan Angka \"3\" untuk Kembali ke Daftar Page";
		cout << "\n\t Masukkan Angka Berapapun Selain 1,2,3 untuk Keluar";
		cout << "\n\n\t Tentukan : "; cin >> tentu;
		system("cls");
		
		switch (tentu)
		{
			case 1 :
				home();
				break;
			case 2 :
				login();
				break;
			case 3 :
				daftar();
				break;
			default:
				exit(0);
		}
		
	}
	system("cls");
}

void daftar()
{
	cout << "**================================================**" << endl;
	cout << "|| 						  ||" << endl;
	cout << "||		D A F T A R    P A G E		  ||" << endl;
	cout << "|| 						  ||" << endl;
	cout << "**================================================**" << endl << endl;
	cout << "\t Nama	: "; cin >> tmp.akun; cout << endl;
	cout << "\t Pass	: "; cin >> tmp.pass; cout << endl;
	system("cls");
	
	ofstream tulis;
	string namafile="login.txt";
		
	tulis.open(namafile.c_str(), ios::app);
	
		tulis << tmp.akun << endl; 
		tulis << tmp.pass << endl;	
	
	tulis.close();
	
	home();
}
	
void inputdata()
{
	int i=0, batas;
	char eksit;
	string file;
	
	cout << "**==============================================**";
	cout << "\n||		 INPUT DATA KTP			||";
	cout << "\n**==============================================**" << endl;
	cout << "\n  Masukan nama file : "; cin >> file;
	system("cls");
				
		do
		{
			cout << "**==============================================**";
			cout << "\n||		 INPUT DATA KTP			||";
			cout << "\n**==============================================**" << endl;
				
					cout << "\n\tNomor KTP\t: "; cin >> wni[i].nik;
					cin.ignore();
					cout << "\tNama\t\t: "; getline(cin, wni[i].nama);
					cout << "\tGolongan Darah\t: "; cin >> wni[i].goldar;
					cout << "\tJenKel(L/P)\t: "; cin >> wni[i].jenkel;
					cin.ignore();
					cout << "\tAsal Daerah\t: "; getline(cin, wni[i].asal);
					cout << "\n**==============================================**" << endl;
					cout << "\n\tTambah Data ? (y/n) : "; cin >> eksit;
					
					i++;
					
					system("cls");
				} while (eksit=='Y' || eksit=='y');
		
		batas = i;		
		import(file,batas);	
		
	
}

void import(string file, int batas)
{
		ofstream tulis;
		string namafile=file;
		
		tulis.open(namafile.c_str(), ios::app);
		for (int i=0; i<batas; i++){
			tulis << wni[i].nik << endl; 
			tulis << wni[i].nama << endl;
			tulis << wni[i].goldar << endl;
			tulis << wni[i].jenkel << endl;
			tulis << wni[i].asal << endl;	
		}
		tulis.close();	

		main();
}

void tampildata()
{
	string file;
	int tampil=0;
	
	cout << "Masukkan Nama File = "; cin >> file;
	system("cls");
	
	eksport(file, &tampil);
	cout << endl;
	cout << "\t\t\t\t\t\t\tTabel Data File " << "\"" << file << "\"" << endl << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	for (int i = 0; i < tampil; i++)
	{
		cout << "||\t" << wni[i].nik << "\t||\t" << wni[i].nama << "\t\t||\t" << wni[i].goldar << "\t||\t" << wni[i].jenkel << "\t||\t" << wni[i].asal << "\t\t||" << endl;
	}
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void eksport(string file, int *tampil)
{
		ifstream baca;
		string namafile=file;
		
		baca.open(namafile);
		
		for(int i=0; true; i++)
		{
			getline(baca,wni[i].nik);
			getline(baca,wni[i].nama);
			getline(baca,wni[i].goldar);
			getline(baca,wni[i].jenkel);
			getline(baca,wni[i].asal);
			if(baca.eof()){
				*tampil=i;
				break;
			}
		}
		baca.close();
}

void caridata()
{
	int pilih;
	
	cout << "**======================================**";
	cout << "\n||		 METODE CARI		||";
	cout << "\n**======================================**" << endl;
	cout << "||\t\t\t\t\t||";
	cout << "\n||\t  1. Sequential Search   \t||";
	cout << "\n||\t  2. Binary Search		||";
	cout << "\n||\t  3. Kembali ke Menu	\t||" << endl;
	cout << "||\t\t\t\t\t||";
	cout << "\n**======================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	system("cls");
	
	switch (pilih)
	{
		case 1 :
			caridataseq();
			system("cls");
			main();
			break;
		case 2 :
			caridatabin();
			system("cls");
			main();
			break;
		case 3 :
			system("cls");
			main();
			break;
		default	:
			error();
			
	}
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
	
}

void caridataseq()
{
	int pilih;
	
	cout << "**==============================================**";
	cout << "\n||		 SEQUENTIAL SEARCH		||";
	cout << "\n**==============================================**" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n||\t  1. Cari Berdasarkan NIK	   \t||";
	cout << "\n||\t  2. Cari Berdasarkan Nama		||";
	cout << "\n||\t  3. Cari Berdasarkan GolDar		||";
	cout << "\n||\t  4. Cari Berdasarkan Jenkel		||";
	cout << "\n||\t  5. Cari Berdasarkan Asal		||";
	cout << "\n||\t  6. Kembali ke Menu Cari		||";
	cout << "\n||\t  7. Kembali ke Menu			||" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n**==============================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	system("cls");
	
	switch (pilih)
	{
		case 1 :
			carinikseq();
			system("cls");
			caridataseq();
			break;
		case 2 :
			carinamaseq();
			system("cls");
			caridataseq();
			break;
		case 3 :
			carigoldarseq();
			system("cls");
			caridataseq();
			break;
		case 4 :
			carijenkelseq();
			system("cls");
			caridataseq();
			break;
		case 5 :
			cariasalseq();
			system("cls");
			caridataseq();
			break;
		case 6 :
			caridata();
			break;
		case 7 :
			main();
			break;
		default	:
			error();
			
	}
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void carinikseq()
{
	string file;
	int tampil=0;
	
	cout << "**==============================================**";
	cout << "\n||		 SEQUENTIAL SEARCH NIK		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	cout << "\tMasukkan NIK = "; cin >> temp.nik;
	system("cls");
	
	
	eksport(file, &tampil);
	
	cout << endl;
	cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan NIK " << "\"" << temp.nik << "\"" << endl << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	for (int i = 0; i < tampil; i++)
	{
		if (temp.nik==wni[i].nik)
		{
			cout << "||\t" << wni[i].nik << "\t||\t" << wni[i].nama << "\t\t||\t" << wni[i].goldar << "\t||\t" << wni[i].jenkel << "\t||\t" << wni[i].asal << "\t\t||" << endl;
		}
		
	}
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void carinamaseq()
{
	string file;
	int tampil=0;
	
	cout << "**==============================================**";
	cout << "\n||		 SEQUENTIAL SEARCH NAMA		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	cout << "\tMasukkan Nama = "; cin.ignore(); getline(cin, temp.nama);
	system("cls");
	
	eksport(file, &tampil);
	
	cout << endl;
	cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan Nama " << "\"" << temp.nama << "\"" << endl << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	for (int i = 0; i < tampil; i++)
	{
		if (temp.nama==wni[i].nama)
		{
			cout << "||\t" << wni[i].nik << "\t||\t" << wni[i].nama << "\t\t||\t" << wni[i].goldar << "\t||\t" << wni[i].jenkel << "\t||\t" << wni[i].asal << "\t\t||" << endl;
		}
		
	}
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void carigoldarseq()
{
	string file;
	int tampil=0;
	
	cout << "**==============================================**";
	cout << "\n||	    SEQUENTIAL SEARCH GOLDAR		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	cout << "\tMasukkan Goldar = "; cin >> temp.goldar;
	system("cls");
	
	eksport(file, &tampil);
	
	cout << endl;
	cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan Goldar " << "\"" << temp.goldar << "\"" << endl << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	for (int i = 0; i < tampil; i++)
	{
		if (temp.goldar==wni[i].goldar)
		{
			cout << "||\t" << wni[i].nik << "\t||\t" << wni[i].nama << "\t\t||\t" << wni[i].goldar << "\t||\t" << wni[i].jenkel << "\t||\t" << wni[i].asal << "\t\t||" << endl;
		}
		
	}
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void carijenkelseq()
{
	string file;
	int tampil=0;
	
	cout << "**==============================================**";
	cout << "\n||	   SEQUENTIAL SEARCH JENKEL		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	cout << "\tMasukkan Jenkel = "; cin >> temp.jenkel;
	system("cls");
	
	eksport(file, &tampil);
	
	cout << endl;
	cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan Jenkel " << "\"" << temp.jenkel << "\"" << endl << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	for (int i = 0; i < tampil; i++)
	{
		if (temp.jenkel==wni[i].jenkel)
		{
			cout << "||\t" << wni[i].nik << "\t||\t" << wni[i].nama << "\t\t||\t" << wni[i].goldar << "\t||\t" << wni[i].jenkel << "\t||\t" << wni[i].asal << "\t\t||" << endl;
		}
		
	}
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void cariasalseq()
{
	string file;
	int tampil=0;
	
	cout << "**==============================================**";
	cout << "\n||		 SEQUENTIAL SEARCH ASAL		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	cout << "\tMasukkan Asal = "; cin.ignore(); getline(cin, temp.asal);
	system("cls");
	
	eksport(file, &tampil);
	
	cout << endl;
	cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan Asal " << "\"" << temp.asal << "\"" << endl << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	for (int i = 0; i < tampil; i++)
	{
		if (temp.asal==wni[i].asal)
		{
			cout << "||\t" << wni[i].nik << "\t||\t" << wni[i].nama << "\t\t||\t" << wni[i].goldar << "\t||\t" << wni[i].jenkel << "\t||\t" << wni[i].asal << "\t\t||" << endl;
		}
	}
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void caridatabin()
{
	int pilih;
	
	cout << "**==============================================**";
	cout << "\n||		 BINARY SEARCH			||";
	cout << "\n**==============================================**" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n||\t  1. Cari Berdasarkan NIK	   \t||";
	cout << "\n||\t  2. Cari Berdasarkan Nama		||";
	cout << "\n||\t  3. Cari Berdasarkan GolDar		||";
	cout << "\n||\t  4. Cari Berdasarkan Jenkel		||";
	cout << "\n||\t  5. Cari Berdasarkan Asal		||";
	cout << "\n||\t  6. Kembali ke Menu Cari		||";
	cout << "\n||\t  7. Kembali ke Menu			||" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n**==============================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	system("cls");
	
	switch (pilih)
	{
		case 1 :
			carinikbin();
			system("cls");
			caridatabin();
			break;
		case 2 :
			carinamabin();
			system("cls");
			caridatabin();
			break;
		case 3 :
			carigoldarbin();
			system("cls");
			caridatabin();
			break;
		case 4 :
			carijenkelbin();
			system("cls");
			caridatabin();
			break;
		case 5 :
			cariasalbin();
			system("cls");
			caridatabin();
			break;
		case 6 :
			caridata();
			break;
		case 7 :
			main();
			break;
		default	:
			error();
			
	}
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void carinikbin()
{
	string file;
	int tampil=0, kiri, kanan, tengah, tanda;
	bool ketemu = false;
	
	cout << "**==============================================**";
	cout << "\n||		 BINARY SEARCH NIK		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	system("cls");
	
	eksport(file, &tampil);	
 
	for (int i=0; i<tampil; i++)
	{
		for(int j=0; j< tampil-i-1; j++)
		{
			if(wni[j].nik > wni[j+1].nik)
			{
				temp.nik = wni[j].nik;
				wni[j].nik = wni[j+1].nik;
				wni[j+1].nik = temp.nik;
			}
		}
	}
	
	cout << "\nData Telah Diurutkan" << "\n\nUntuk Melanjutkan Tekan Enter . . . ";
	getch();
	system("cls");

	cout << "\n Masukan NIK yang dicari : ";
	cin >> temp.nik;

	kiri=0;
	kanan=tampil-1;

	while(kiri<=kanan)
	{
		tengah=(kiri + kanan)/2;
		
		if(temp.nik == wni[tengah].nik)
		{
			ketemu=true;
			tanda = tengah;
			break;
		}
		else if (temp.nik < wni[tengah].nik)
		{
			kanan = tengah -1;
		}
		else
		{
			kiri = tengah +1;
		}
	}

	if (ketemu == true)
	{
		cout << "\n\tNIK ditemukan!!" << endl << endl;
		
		cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan NIK " << "\"" << temp.nik << "\"" << endl << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t" << wni[tanda].nik << "\t||\t" << wni[tanda].nama << "\t\t||\t" << wni[tanda].goldar << "\t||\t" << wni[tanda].jenkel << "\t||\t" << wni[tanda].asal << "\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	}
	else 
	{	
		cout<<"\n\tNIK tidak ditemukan!!" << endl;
	}
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void carinamabin()
{
	string file;
	int tampil=0, kiri, kanan, tengah, tanda;
	bool ketemu = false;
	
	cout << "**==============================================**";
	cout << "\n||		 BINARY SEARCH NAMA		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	system("cls");
	
	eksport(file, &tampil);	
 
	for (int i=0; i<tampil; i++)
	{
		for(int j=0; j< tampil-i-1; j++)
		{
			if(wni[j].nama > wni[j+1].nama)
			{
				temp.nama = wni[j].nama;
				wni[j].nama = wni[j+1].nama;
				wni[j+1].nama = temp.nama;
			}
		}
	}
	
	cout << "\nData Telah Diurutkan" << "\n\nUntuk Melanjutkan Tekan Enter . . . ";
	getch();
	system("cls");

	cout << "\n Masukan Nama yang dicari : ";
	cin.ignore(); getline(cin, temp.nama);

	kiri=0;
	kanan=tampil-1;

	while(kiri<=kanan)
	{
		tengah=(kiri + kanan)/2;
		
		if(temp.nama == wni[tengah].nama)
		{
			ketemu=true;
			tanda = tengah;
			break;
		}
		else if (temp.nama < wni[tengah].nama)
		{
			kanan = tengah -1;
		}
		else
		{
			kiri = tengah +1;
		}
	}

	if (ketemu == true)
	{
		cout << "\n\tNama ditemukan!!" << endl << endl;
		
		cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan Nama " << "\"" << temp.nama << "\"" << endl << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t" << wni[tanda].nik << "\t||\t" << wni[tanda].nama << "\t\t||\t" << wni[tanda].goldar << "\t||\t" << wni[tanda].jenkel << "\t||\t" << wni[tanda].asal << "\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	}
	else 
	{	
		cout<<"\n\tNama tidak ditemukan!!" << endl;
	}
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void carigoldarbin()
{
	string file;
	int tampil=0, kiri, kanan, tengah, tanda;
	bool ketemu = false;
	
	cout << "**==============================================**";
	cout << "\n||	    BINARY SEARCH GOLDAR		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	system("cls");
	
	eksport(file, &tampil);	
 
	for (int i=0; i<tampil; i++)
	{
		for(int j=0; j< tampil-i-1; j++)
		{
			if(wni[j].goldar > wni[j+1].goldar)
			{
				temp.goldar = wni[j].goldar;
				wni[j].goldar = wni[j+1].goldar;
				wni[j+1].goldar = temp.goldar;
			}
		}
	}
	
	cout << "\nData Telah Diurutkan" << "\n\nUntuk Melanjutkan Tekan Enter . . . ";
	getch();
	system("cls");

	cout << "\n Masukan Goldar yang dicari : ";
	cin >> temp.goldar;

	kiri=0;
	kanan=tampil-1;

	while(kiri<=kanan)
	{
		tengah=(kiri + kanan)/2;
		
		if(temp.goldar == wni[tengah].goldar)
		{
			ketemu=true;
			tanda = tengah;
			break;
		}
		else if (temp.goldar < wni[tengah].goldar)
		{
			kanan = tengah -1;
		}
		else
		{
			kiri = tengah +1;
		}
	}

	if (ketemu == true)
	{
		cout << "\n\tGoldar ditemukan!!" << endl << endl;
		
		cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan Goldar " << "\"" << temp.goldar << "\"" << endl << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t" << wni[tanda].nik << "\t||\t" << wni[tanda].nama << "\t\t||\t" << wni[tanda].goldar << "\t||\t" << wni[tanda].jenkel << "\t||\t" << wni[tanda].asal << "\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	}
	else 
	{	
		cout<<"\n\tGoldar tidak ditemukan!!" << endl;
	}
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void carijenkelbin()
{
	string file;
	int tampil=0, kiri, kanan, tengah, tanda;
	bool ketemu = false;
	
	cout << "**==============================================**";
	cout << "\n||   	    BINARY SEARCH JENKEL		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	system("cls");
	
	eksport(file, &tampil);	
 
	for (int i=0; i<tampil; i++)
	{
		for(int j=0; j< tampil-i-1; j++)
		{
			if(wni[j].jenkel > wni[j+1].jenkel)
			{
				temp.jenkel = wni[j].jenkel;
				wni[j].jenkel = wni[j+1].jenkel;
				wni[j+1].jenkel = temp.jenkel;
			}
		}
	}
	
	cout << "\nData Telah Diurutkan" << "\n\nUntuk Melanjutkan Tekan Enter . . . ";
	getch();
	system("cls");

	cout << "\n Masukan Jenkel yang dicari : ";
	cin >> temp.jenkel;

	kiri=0;
	kanan=tampil-1;

	while(kiri<=kanan)
	{
		tengah=(kiri + kanan)/2;
		
		if(temp.jenkel == wni[tengah].jenkel)
		{
			ketemu=true;
			tanda = tengah;
			break;
		}
		else if (temp.jenkel < wni[tengah].jenkel)
		{
			kanan = tengah -1;
		}
		else
		{
			kiri = tengah +1;
		}
	}

	if (ketemu == true)
	{
		cout << "\n\tJenkel ditemukan!!" << endl << endl;
		
		cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan Jenkel " << "\"" << temp.jenkel << "\"" << endl << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t" << wni[tanda].nik << "\t||\t" << wni[tanda].nama << "\t\t||\t" << wni[tanda].goldar << "\t||\t" << wni[tanda].jenkel << "\t||\t" << wni[tanda].asal << "\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	}
	else 
	{	
		cout<<"\n\tJenkel tidak ditemukan!!" << endl;
	}
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void cariasalbin()
{
	string file;
	int tampil=0, kiri, kanan, tengah, tanda;
	bool ketemu = false;
	
	cout << "**==============================================**";
	cout << "\n||		 BINARY SEARCH ASAL		||";
	cout << "\n**==============================================**" << endl << endl;
	cout << "\tMasukkan Nama File = "; cin >> file;
	cout << endl;
	system("cls");
	
	eksport(file, &tampil);	
 
	for (int i=0; i<tampil; i++)
	{
		for(int j=0; j< tampil-i-1; j++)
		{
			if(wni[j].asal > wni[j+1].asal)
			{
				temp.asal = wni[j].asal;
				wni[j].asal = wni[j+1].asal;
				wni[j+1].asal = temp.asal;
			}
		}
	}
	
	cout << "\nData Telah Diurutkan" << "\n\nUntuk Melanjutkan Tekan Enter . . . ";
	getch();
	system("cls");

	cout << "\n Masukan Asal yang dicari : ";
	cin.ignore(); getline(cin, temp.asal);

	kiri=0;
	kanan=tampil-1;

	while(kiri<=kanan)
	{
		tengah=(kiri + kanan)/2;
		
		if(temp.asal == wni[tengah].asal)
		{
			ketemu=true;
			tanda = tengah;
			break;
		}
		else if (temp.asal < wni[tengah].asal)
		{
			kanan = tengah -1;
		}
		else
		{
			kiri = tengah +1;
		}
	}

	if (ketemu == true)
	{
		cout << "\n\tAsal ditemukan!!" << endl << endl;
		
		cout << "\t\t\t\t\tTabel Data File " << "\"" << file << "\" dengan Asal " << "\"" << temp.asal << "\"" << endl << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
		cout << "||\t" << wni[tanda].nik << "\t||\t" << wni[tanda].nama << "\t\t||\t" << wni[tanda].goldar << "\t||\t" << wni[tanda].jenkel << "\t||\t" << wni[tanda].asal << "\t\t||" << endl;
		cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	}
	else 
	{	
		cout<<"\n\tAsal tidak ditemukan!!" << endl;
	}
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutdata()
{
	int pilih;
	
	cout << "**======================================**";
	cout << "\n||		 METODE URUT		||";
	cout << "\n**======================================**" << endl;
	cout << "||\t\t\t\t\t||";
	cout << "\n||\t  1. Bubble Sort   	\t||";
	cout << "\n||\t  2. Selection Sort		||";
	cout << "\n||\t  3. Insertion Sort		||";
	cout << "\n||\t  4. Shell Sort			||";
	cout << "\n||\t  5. Kembali ke Menu	\t||" << endl;
	cout << "||\t\t\t\t\t||";
	cout << "\n**======================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	system("cls");
	
	switch (pilih)
	{
		case 1 :
			urutdatabubble();
			system("cls");
			urutdata();
			break;
		case 2 :
			urutdatasel();
			system("cls");
			urutdata();
			break;
		case 3 :
			urutdatains();
			system("cls");
			urutdata();
			break;
		case 4 :
			urutdatashe();
			system("cls");
			urutdata();
			break;
		case 5 :
			system("cls");
			main();
			break;
		default	:
			error();
			
	}
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
	
}

void urutdatabubble()
{
	string file;
	int pilih;
	
	cout << "**==============================================**";
	cout << "\n||		 BUBBLE SORT			||";
	cout << "\n**==============================================**" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n||\t  1. Cari Berdasarkan NIK	   \t||";
	cout << "\n||\t  2. Cari Berdasarkan Nama		||";
	cout << "\n||\t  3. Cari Berdasarkan GolDar		||";
	cout << "\n||\t  4. Cari Berdasarkan Jenkel		||";
	cout << "\n||\t  5. Cari Berdasarkan Asal		||";
	cout << "\n||\t  6. Kembali ke Menu Urut		||";
	cout << "\n||\t  7. Kembali ke Menu			||" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n**==============================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	if (pilih<6)
	{
		cout << "\n\n  Masukkan Nama File : "; cin >> file;
	}
	system("cls");
	
	switch (pilih)
	{
		case 1 :						
			urutbubblenik(file);
			system("cls");
			urutdatabubble();
			break;
		case 2 :
			urutbubblenama(file);
			system("cls");
			urutdatabubble();
			break;
		case 3 :
			urutbubblegoldar(file);
			system("cls");
			urutdatabubble();
			break;
		case 4 :
			urutbubblejenkel(file);
			system("cls");
			urutdatabubble();
			break;
		case 5 :
			urutbubbleasal(file);
			system("cls");
			urutdatabubble();
			break;
		case 6 :
			urutdata();
			break;
		case 7 :
			main();
			break;
		default	:
			error();
			
	}
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutbubblenik(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int j = 0; j < batas-1; j++)
	{
		if(wni[j].nik > wni[j+1].nik)
		{
			ganti(j);
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutbubblenama(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int j = 0; j < batas-1; j++)
	{
		if(wni[j].nama > wni[j+1].nama)
		{
			ganti(j);
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutbubblegoldar(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int j = 0; j < batas-1; j++)
	{
		if(wni[j].goldar > wni[j+1].goldar)
		{
			ganti(j);
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutbubblejenkel(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int j = 0; j < batas-1; j++)
	{
		if(wni[j].jenkel > wni[j+1].jenkel)
		{
			ganti(j);
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutbubbleasal(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int j = 0; j < batas-1; j++)
	{
		if(wni[j].asal > wni[j+1].asal)
		{
			ganti(j);
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutdatasel()
{
	string file;
	int pilih;
	
	cout << "**==============================================**";
	cout << "\n||		 SELECTION SORT			||";
	cout << "\n**==============================================**" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n||\t  1. Cari Berdasarkan NIK	   \t||";
	cout << "\n||\t  2. Cari Berdasarkan Nama		||";
	cout << "\n||\t  3. Cari Berdasarkan GolDar		||";
	cout << "\n||\t  4. Cari Berdasarkan Jenkel		||";
	cout << "\n||\t  5. Cari Berdasarkan Asal		||";
	cout << "\n||\t  6. Kembali ke Menu Urut		||";
	cout << "\n||\t  7. Kembali ke Menu			||" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n**==============================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	if (pilih<6)
	{
		cout << "\n\n  Masukkan Nama File : "; cin >> file;
	}
	system("cls");
	
	switch (pilih)
	{
		case 1 :						
			urutselnik(file);
			system("cls");
			urutdatasel();
			break;
		case 2 :
			urutselnama(file);
			system("cls");
			urutdatasel();
			break;
		case 3 :
			urutselgoldar(file);
			system("cls");
			urutdatasel();
			break;
		case 4 :
			urutseljenkel(file);
			system("cls");
			urutdatasel();
			break;
		case 5 :
			urutselasal(file);
			system("cls");
			urutdatasel();
			break;
		case 6 :
			urutdata();
			break;
		case 7 :
			main();
			break;
		default	:
			error();
			
	}
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutselnik(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{
		for(int j = i+1; j < batas; j++)
		{
			if(wni[i].nik > wni[j].nik)
			{
				ganti2(i,j);
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutselnama(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{
		for(int j = i+1; j < batas; j++)
		{
			if(wni[i].nama > wni[j].nama)
			{
				ganti2(i,j);
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutselgoldar(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{
		for(int j = i+1; j < batas; j++)
		{
			if(wni[i].goldar > wni[j].goldar)
			{
				ganti2(i,j);
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutseljenkel(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{
		for(int j = i+1; j < batas; j++)
		{
			if(wni[i].jenkel > wni[j].jenkel)
			{
				ganti2(i,j);
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutselasal(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{
		for(int j = i+1; j < batas; j++)
		{
			if(wni[i].asal > wni[j].asal)
			{
				ganti2(i,j);
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutdatains()
{
	string file;
	int pilih;
	
	cout << "**==============================================**";
	cout << "\n||		 INSERTION SORT			||";
	cout << "\n**==============================================**" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n||\t  1. Cari Berdasarkan NIK	   \t||";
	cout << "\n||\t  2. Cari Berdasarkan Nama		||";
	cout << "\n||\t  3. Cari Berdasarkan GolDar		||";
	cout << "\n||\t  4. Cari Berdasarkan Jenkel		||";
	cout << "\n||\t  5. Cari Berdasarkan Asal		||";
	cout << "\n||\t  6. Kembali ke Menu Urut		||";
	cout << "\n||\t  7. Kembali ke Menu			||" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n**==============================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	if (pilih<6)
	{
		cout << "\n\n  Masukkan Nama File : "; cin >> file;
	}
	system("cls");
	
	switch (pilih)
	{
		case 1 :						
			urutinsnik(file);
			system("cls");
			urutdatains();
			break;
		case 2 :
			urutinsnama(file);
			system("cls");
			urutdatains();
			break;
		case 3 :
			urutinsgoldar(file);
			system("cls");
			urutdatains();
			break;
		case 4 :
			urutinsjenkel(file);
			system("cls");
			urutdatains();
			break;
		case 5 :
			urutinsasal(file);
			system("cls");
			urutdatains();
			break;
		case 6 :
			urutdata();
			break;
		case 7 :
			main();
			break;
		default	:
			error();
			
	}
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutinsnik(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{			
		temp.nik = wni[i].nik;
		temp.nama = wni[i].nama;
		temp.goldar = wni[i].goldar;
		temp.jenkel = wni[i].jenkel;
		temp.asal = wni[i].asal;
		
		int a = i-1;
							
		while (temp.nik < wni[a].nik && a >= 0)
		{
			ganti3(a);
		};									
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutinsnama(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{			
		temp.nik = wni[i].nik;
		temp.nama = wni[i].nama;
		temp.goldar = wni[i].goldar;
		temp.jenkel = wni[i].jenkel;
		temp.asal = wni[i].asal;
		
		int a = i-1;
							
		while (temp.nama < wni[a].nama && a >= 0)
		{
			ganti3(a);
		};									
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutinsgoldar(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{			
		temp.nik = wni[i].nik;
		temp.nama = wni[i].nama;
		temp.goldar = wni[i].goldar;
		temp.jenkel = wni[i].jenkel;
		temp.asal = wni[i].asal;
		
		int a = i-1;
							
		while (temp.goldar < wni[a].goldar && a >= 0)
		{
			ganti3(a);
		};									
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutinsjenkel(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{			
		temp.nik = wni[i].nik;
		temp.nama = wni[i].nama;
		temp.goldar = wni[i].goldar;
		temp.jenkel = wni[i].jenkel;
		temp.asal = wni[i].asal;
		
		int a = i-1;
							
		while (temp.jenkel < wni[a].jenkel && a >= 0)
		{
			ganti3(a);
		};									
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutinsasal(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for(int i = 0; i < batas; i++)
	{			
		temp.nik = wni[i].nik;
		temp.nama = wni[i].nama;
		temp.goldar = wni[i].goldar;
		temp.jenkel = wni[i].jenkel;
		temp.asal = wni[i].asal;
		
		int a = i-1;
							
		while (temp.asal < wni[a].asal && a >= 0)
		{
			ganti3(a);
		};									
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutdatashe()
{
	string file;
	int pilih;
	
	cout << "**==============================================**";
	cout << "\n||		 SHELL SORT			||";
	cout << "\n**==============================================**" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n||\t  1. Cari Berdasarkan NIK	   \t||";
	cout << "\n||\t  2. Cari Berdasarkan Nama		||";
	cout << "\n||\t  3. Cari Berdasarkan GolDar		||";
	cout << "\n||\t  4. Cari Berdasarkan Jenkel		||";
	cout << "\n||\t  5. Cari Berdasarkan Asal		||";
	cout << "\n||\t  6. Kembali ke Menu Urut		||";
	cout << "\n||\t  7. Kembali ke Menu			||" << endl;
	cout << "||\t\t\t\t\t\t||";
	cout << "\n**==============================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	if (pilih<6)
	{
		cout << "\n\n  Masukkan Nama File : "; cin >> file;
	}
	system("cls");
	
	switch (pilih)
	{
		case 1 :						
			urutshenik(file);
			system("cls");
			urutdatashe();
			break;
		case 2 :
			urutshenama(file);
			system("cls");
			urutdatashe();
			break;
		case 3 :
			urutshegoldar(file);
			system("cls");
			urutdatashe();
			break;
		case 4 :
			urutshejenkel(file);
			system("cls");
			urutdatashe();
			break;
		case 5 :
			urutsheasal(file);
			system("cls");
			urutdatashe();
			break;
		case 6 :
			urutdata();
			break;
		case 7 :
			main();
			break;
		default	:
			error();
			
	}
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutshenik(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for (int i = batas/2; i > 0; i=i/2)
	{
		for (int j = i; j < batas; j++)
		{
			for (int k = j-i; k >= 0; k=k-1)
			{
				if (wni[k+i].nik >= wni[k].nik)
				{
					break;
				}
				else
				{
					ganti(k);
				}
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutshenama(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for (int i = batas/2; i > 0; i=i/2)
	{
		for (int j = i; j < batas; j++)
		{
			for (int k = j-i; k >= 0; k=k-1)
			{
				if (wni[k+i].nama >= wni[k].nama)
				{
					break;
				}
				else
				{
					ganti(k);
				}
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutshegoldar(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for (int i = batas/2; i > 0; i=i/2)
	{
		for (int j = i; j < batas; j++)
		{
			for (int k = j-i; k >= 0; k=k-1)
			{
				if (wni[k+i].goldar >= wni[k].goldar)
				{
					break;
				}
				else
				{
					ganti(k);
				}
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutshejenkel(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for (int i = batas/2; i > 0; i=i/2)
	{
		for (int j = i; j < batas; j++)
		{
			for (int k = j-i; k >= 0; k=k-1)
			{
				if (wni[k+i].jenkel >= wni[k].jenkel)
				{
					break;
				}
				else
				{
					ganti(k);
				}
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void urutsheasal(string file)
{
	int batas;
	eksport(file, &batas);
	
	importurut(batas);
	eksporturut(&batas);
	
	for (int i = batas/2; i > 0; i=i/2)
	{
		for (int j = i; j < batas; j++)
		{
			for (int k = j-i; k >= 0; k=k-1)
			{
				if (wni[k+i].asal >= wni[k].asal)
				{
					break;
				}
				else
				{
					ganti(k);
				}
			}
		}
	}
	
	importurut(batas);
	eksporturut(&batas);
	
	tampilurut(batas);
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void tampilurut(int batas)
{
	cout << "\t\t\t\t\t\t\tTabel Data File " << endl << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	cout << "||\t\tNIK\t\t||\t\tNama\t\t||\tGoldar\t||\tJenkel\t||\t\t\tAsal\t\t||" << endl;
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
	
	for (int i = batas-1; i > 0; i--)
	{
		cout << "||\t" << wni[i].nik << "\t||\t" << wni[i].nama << "\t\t||\t" << wni[i].goldar << "\t||\t" << wni[i].jenkel << "\t||\t" << wni[i].asal << "\t\t||" << endl;
	}
	cout << "**==============================**==============================**==============**==============**==============================**" << endl;
}

void ganti(int j)
{
	temp.nik = wni[j].nik;
	wni[j].nik = wni[j+1].nik;
	wni[j+1].nik = temp.nik;
	
	temp.nama = wni[j].nama;
	wni[j].nama = wni[j+1].nama;
	wni[j+1].nama = temp.nama;
	
	temp.goldar = wni[j].goldar;
	wni[j].goldar = wni[j+1].goldar;
	wni[j+1].goldar = temp.goldar;
	
	temp.jenkel = wni[j].jenkel;
	wni[j].jenkel = wni[j+1].jenkel;
	wni[j+1].jenkel = temp.jenkel;
	
	temp.asal = wni[j].asal;
	wni[j].asal = wni[j+1].asal;
	wni[j+1].asal = temp.asal;
}

void ganti2(int i, int j)
{
	temp.nik = wni[i].nik;
	wni[i].nik = wni[j].nik;
	wni[j].nik = temp.nik;
	
	temp.nama = wni[i].nama;
	wni[i].nama = wni[j].nama;
	wni[j].nama = temp.nama;
	
	temp.goldar = wni[i].goldar;
	wni[i].goldar = wni[j].goldar;
	wni[j].goldar = temp.goldar;
	
	temp.jenkel = wni[i].jenkel;
	wni[i].jenkel = wni[j].jenkel;
	wni[j].jenkel = temp.jenkel;
	
	temp.asal = wni[i].asal;
	wni[i].asal = wni[j].asal;
	wni[j].asal = temp.asal;
}

void ganti3(int a)
{
	wni[a+1].nik = wni[a].nik;
	wni[a+1].nama = wni[a].nama;
	wni[a+1].goldar = wni[a].goldar;
	wni[a+1].jenkel = wni[a].jenkel;
	wni[a+1].asal = wni[a].asal;
	a = a-1;
	wni[a+1].nik = temp.nik;
	wni[a+1].nama = temp.nama;
	wni[a+1].goldar = temp.goldar;
	wni[a+1].jenkel = temp.jenkel;
	wni[a+1].asal = temp.asal;
}

void importurut(int batas)
{
		ofstream tulis;
		string namafile="urut.txt";
		
		tulis.open(namafile.c_str());
		for (int i=0; i<batas+1; i++){
			tulis << wni[i].nik << endl; 
			tulis << wni[i].nama << endl;
			tulis << wni[i].goldar << endl;
			tulis << wni[i].jenkel << endl;
			tulis << wni[i].asal << endl;	
		}
		tulis.close();	
}

void eksporturut(int *batas)
{		
		ifstream baca;
		string namafile="urut.txt";
		
		baca.open(namafile);
		
		for(int i=0; true; i++)
		{
			getline(baca,wni[i].nik);
			getline(baca,wni[i].nama);
			getline(baca,wni[i].goldar);
			getline(baca,wni[i].jenkel);
			getline(baca,wni[i].asal);
			if(baca.eof()){
				*batas=i;
				break;
			}
		}
		
		baca.close();
}

void error()
{
	cout << "**======================================================**" << endl;
	cout << "||\t\t\t[ERROR]\t\t\t\t||" << endl;
	cout << "**======================================================**" << endl;
	cout << "||\t\t\t\t\t\t\t||" << endl;
	cout << "||\t\tTidak ada dalam menu!!\t\t\t||" << endl;
	cout << "||\t  Untuk Kembali ke Menu Utama Tekan Enter\t||" << endl;
	cout << "||\t\t\t\t\t\t\t||" << endl;
	cout << "**======================================================**" << endl;
	getch();
	system("cls");
	main();
}
