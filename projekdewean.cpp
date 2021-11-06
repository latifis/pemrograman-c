#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

struct warganegaraindonesia{
		int nik;
		string nama, asal;
		char goldar, jenkel;
	};
struct warganegaraindonesia wni[100];
struct warganegaraindonesia temp;
string file;

void import (int nik, string nama, char goldar, char jenkel, string asal)
{
	ofstream tulis;
	string namafile = file;
	
	tulis.open(namafile.c_str(), ios::app);
	
	tulis << nik << endl;
	tulis << nama << endl;
	tulis << goldar << endl;
	tulis << jenkel << endl;
	tulis << asal << endl;
	
	tulis.close();
}

void eksport()
{	
	int i=0;
	ifstream baca;
	string namafile = file;
	string baris;
	int baris2;
	char baris3;
	
	baca.open(namafile.c_str());
	
	while (!baca.eof(){
		
		baris2 << baca;
		wni[i].nik=baris2;
		
		getline(baca, baris);
		wni[i].nama=baris;
		
		baris3 << baca;
		wni[i].goldar=baris3;
		
		baris3 << baca;
		wni[i].jenkel=baris3;
		
		getline(baca, baris);
		wni[i].asal=baris;	
		
		i++;
    	};
	
	/*for (int i = 0; i < 100; i++)
	{
		//getw(baca, wni[i].nik);
		getline(baca, wni[i].nama);
		//getchar(baca, wni[i].goldar);
		//getchar(baca, wni[i].jenkel);
		getline(baca, wni[i].asal);
		
		if (baca.eof())
		{
			break;
		}
		
		cout << i;
	}*/
	
	
	baca.close();
}

int main()
{
	int pilih;
	char eksit;
	ofstream tulis;
	ifstream baca;
	
	
	
	//cout << endl << endl << endl;
	for (int i = 0; i < true; i++)
	{
		wni[i].nik=0;
	}
	
	
	while (true)
	{
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
		
		switch (pilih)
		{
			case 1 :
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
				
					int i;
					cout << "\n\tNomor KTP\t: "; cin >> wni[i].nik;
					cin.ignore();
					cout << "\tNama\t\t: "; getline(cin, wni[i].nama);
					cout << "\tGolongan Darah\t: "; cin >> wni[i].goldar;
					cout << "\tJenKel(L/P)\t: "; cin >> wni[i].jenkel;
					cin.ignore();
					cout << "\tAsal Daerah\t: "; getline(cin, wni[i].asal);
					cout << "\n**==============================================**" << endl;
					cout << "\n\tTambah Data ? (y/n) : "; cin >> eksit;
					
					import(wni[i].nik, wni[i].nama, wni[i].goldar, wni[i].jenkel, wni[i].asal);
					
					i++;
					system("cls");
				} while (eksit=='Y' || eksit=='y');
				
				break;
				
			case 2 :
				cout << "**==============================================**";
				cout << "\n||	       	 DATA KTP			||";
				cout << "\n**==============================================**" << endl;
				cout << "\n  Masukan nama file : "; cin >> file;
				cout << endl;
				
				eksport();
				
				
					cout << "\n\tNIK	: " << wni[0].nik;
					cout << "\n\tNama	: " << wni[0].nama;
					cout << "\n\tGoldar	: " << wni[0].goldar;
					cout << "\n\tJenkel	: " << wni[0].jenkel;
					cout << "\n\tAsal	: " << wni[0].asal;
				
				//for (int i = 0; i < true; i++)
				//{
				//	if (wni[i].nik!=0)
				//	{
				//		cout << "\n\tNIK	: " << wni[i].nik;
				//		cout << "\n\tNama	: " << wni[i].nama;
				//		cout << "\n\tGoldar	: " << wni[i].goldar;
				//		cout << "\n\tJenkel	: " << wni[i].jenkel;
				//		cout << "\n\tAsal	: " << wni[i].asal;
				//	}
					
				//}
				system("cls");
				break;
				
			case 3 :
				cout << "";
				break;
			
			case 4 :
				cout << "";
				break;
				
			case 5 :
				exit(0);
				break;
				
			default:
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
				cout << "\n\n  Pilih : ";
				cout << "\n\n**=================================**";	
				cout << "\n||	Tidak Ada dalam Menu !!	   ||";
				cout << "\n**=================================**" << endl << endl;
				system("pause");
				system("cls");
				
		}
	}
	
	
}
