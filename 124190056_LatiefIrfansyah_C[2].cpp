#include <iostream>
#include <windows.h>
using namespace std;

int jfilm;
int jfilm0;
int jfilm1;
int tahun[50];

char kode[50];
char ulang;

string judul[50];
string genre[50];

int main ()
{
	cout << "RENTAL FILM";
	cout << "\nMasukkan Jumlah Film : "; cin >> jfilm;
	cout << endl;
	
	for (int i=0; i<jfilm; i++)
	{
		cout << "Film ke-" << i+1;
		cout << "\nKode Film\t: "; cin >> kode[i];
		cout << "Judul Film\t: "; cin >> judul[i];
		cout << "Tahun Rilis\t: "; cin >> tahun[i];
		cout << endl;
	}
	
	cout << "\nData yang diinput :";
	cout << "\n===================================================================================";
	cout << "\n\tNo\t|\tKode\t|\tGenre\t|\tJudul\t|\tTahun Rilis\t";
	
	
	
	for (int i=0; i<jfilm; i++)
	{
		if (kode[i]=='a')
			genre[i] = "Action";
		else if (kode[i]=='r')
			genre[i] = "Romance";
		else if (kode[i]=='c')
			genre[i] = "Comedy";
		else 
			genre[i] = "Unknown";
		
		cout << "\n===================================================================================";
		cout << "\n\t" << i+1 << "\t|\t" << kode[i] << "\t|\t" << genre[i] << "\t|\t" << judul[i] << "\t|\t" << tahun[i] << "\t";
	}
	cout << "\n===================================================================================";
	
	

	cout << "\n\nTambah Film (y/n)"; cin >> ulang;
	do
	{
		if(ulang=='y' || ulang=='Y')
		{	
			cout << "Berapa data film tambahan?? : "; cin >> jfilm0;
			
			
			
			for (int i=jfilm; i<jfilm0+jfilm; i++)
			{
				cout << "Film ke-" << i+1;
				cout << "\nKode Film\t: "; cin >> kode[i];
				cout << "Judul Film\t: "; cin >> judul[i];
				cout << "Tahun Rilis\t: "; cin >> tahun[i];
				jfilm0++;
				cout << endl;	
			}
		
			cout << "\nData yang diinput :";
			cout << "\n===================================================================================";
			cout << "\n\tNo\t|\tKode\t|\tGenre\t|\tJudul\t|\tTahun Rilis\t";
	
	
			for (int i=0; i<(jfilm+jfilm0); i++)
			{
				if (kode[i]=='a')
					genre[i] = "Action";
				else if (kode[i]=='r')
					genre[i] = "Romance";
				else if (kode[i]=='c')
					genre[i] = "Comedy";
				else 
					genre[i] = "Unknown";
			
				cout << "\n===================================================================================";
				cout << "\n\t" << i+1 << "\t|\t" << kode[i] << "\t|\t" << genre[i] << "\t|\t" << judul[i] << "\t|\t" << tahun[i] << "\t";
			}
			cout << "\n===================================================================================";
	
			}
			cout << "\n\nTambah Film (y/n)"; cin >> ulang;
			system("cls");
			
		
			
	}while(ulang=='y' || ulang=='Y');
	

}
