

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
void importurut(int batas);
void eksporturut(int *tampil);


main ()
{	
	int pilih;
	string file;
	
	cout << "**=================================**";
	cout << "\n||  Latief Irfansyah || 124190056  ||";
	cout << "\n**=================================**";
	cout << "\n||	    K    T    P	 	   ||";
	cout << "\n**=================================**";
	cout << "\n||  1. Input Data		   ||";
	cout << "\n||  2. Tampilkan Data		   ||";
	cout << "\n||  3. Searching Data		   ||";
	cout << "\n||  4. Sorting Data		   ||";
	cout << "\n||  5. Keluar			   ||";
	cout << "\n**=================================**";
	cout << "\n\n  Pilih : ";cin >> pilih;
	cout << "\n**=================================**" << endl;
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
	cout << "\n||\t  1. Bubble Sort   \t||";
	cout << "\n||\t  2. Selection Sort		||";
	cout << "\n||\t  3. Insertion Sort		||";
	cout << "\n||\t  4. Shell Sort		||";
	cout << "\n||\t  5. Quick Sort		||";
	cout << "\n||\t  6. Kembali ke Menu	\t||" << endl;
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
			caridatabin();
			system("cls");
			main();
			break;
		case 4 :
			caridatabin();
			system("cls");
			main();
			break;
		case 5 :
			caridatabin();
			system("cls");
			main();
			break;
		case 6 :
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
	int pilih;
	cout << "**======================================**";
	cout << "\n||		 BUBBLE SORT		||";
	cout << "\n**======================================**" << endl;
	
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
	system("cls");
}

void importurut(int batas)
{
		ofstream tulis;
		string namafile="urut.txt";
		
		tulis.open(namafile.c_str());
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

void eksporturut(int *tampil)
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
				*tampil=i;
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
