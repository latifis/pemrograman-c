#include <iostream>
#include <windows.h>
using namespace std;

int jfilm;
int fil;
int tahun[50];

string kode[50];
char ulang;

string judul[50];
string genre[50];

int main ()
{
	cout << "\tRENTAL FILM" << endl;
	
	do
	{
		cout << "\nMasukkan Jumlah Film : "; cin >> jfilm;
		cout << endl;
	
		for (int i=0; i<jfilm; i++)
		{
			cout << "Film ke-" << fil+1;
			cout << "\nKode Film\t: "; cin >> kode[fil];
			cout << "Judul Film\t: "; cin >> judul[fil];
			cout << "Tahun Rilis\t: "; cin >> tahun[fil];
			fil++;
			cout << endl;
		}
	
		cout << "\nData yang diinput :";
		cout << "\n===================================================================================";
		cout << "\n\tNo\t|\tKode\t|\tGenre\t|\tJudul\t|\tTahun Rilis\t";
	
		for (int i=0; i<fil; i++)
		{
			if (kode[i]=="a%")
				genre[i] = "Action";
			else if (kode[i]=="r%")
				genre[i] = "Romance";
			else if (kode[i]=="c%")
				genre[i] = "Comedy";
			else 
				genre[i] = "Unknown";
		
			cout << "\n===================================================================================";
			cout << "\n\t" << i+1 << "\t|\t" << kode[i] << "\t|\t" << genre[i] << "\t|\t" << judul[i] << "\t|\t" << tahun[i] << "\t";
		}
		
		cout << "\n===================================================================================";
	
		cout << "\n\nTambah Film (y/n)"; cin >> ulang;
		system("cls");
	
	}while(ulang=='y' || ulang=='Y');
	

}
