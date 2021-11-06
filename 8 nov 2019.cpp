#include <iostream>
#include <string.h>
using namespace std;

void baliknama();
void tranpose();
void balikmatriks();
int pilih;
char kata[10], a;
int x, y;
	
int main(){
	
	do 
	{
		cout << "Menu Utama";
		cout << "\n1. Balik Kata";
		cout << "\n2. Transpose Matrik";
		cout << "\n3. Balik Angka Matriks" << endl;

		cout << "\nPilih : ";cin>>pilih;
		
		switch (pilih)
		{
			case 1: 
				baliknama();
				break;
			case 2: 
				tranpose();
				break;
			case 3: 
				balikmatriks();
				break;
			default: 
				cout<<"\nSalah input";
				break;
		}
	
	cout << "\n\nKembali ke Menu(y/n) : "; cin >> a;
	cout << endl << endl;
		
	}while (a=='Y' || a=='y');
	
	cout << "\nTerima Kasih";	
}


void baliknama()
{
	cout << "Masukkan Kata : "; cin >> kata;
	int n=strlen(kata);
	
	for (int i=n-1; i>=0; i--)
	{
		cout << kata[i];    
	}
}


void tranpose()
{	
	cout << "masukkan Jumlah Baris : "; cin >> x;
	cout << "masukkan Jumlah Kolom : "; cin >> y;
	int angka[x][y];
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << "angka [" << i << "] [" << j << "] : ";
			cin >> angka[i][j];
		}
		
		cout << endl;
	}
	
	cout << endl;
	cout << "sebelum transpose :\n";
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << angka[i][j] << " ";
		}
		cout << endl;
	}
				
	cout  << "seseudah transpose :\n";

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << angka[j][i] << " ";
		}
		cout << endl;
	}
}


void balikmatriks()
{
	cout << "masukkan Jumlah Baris : "; cin >> x;
	cout << "masukkan Jumlah Kolom : "; cin >> y;
	int angka [x][y];
				
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << "angka [" << i << "] [" << j <<  "] : ";
			cin >> angka[i][j];
		}
		cout << endl;
	}
				
	cout << endl;
	cout << "sebelum dibalik :\n";
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << angka[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "seseudah dibalik :\n";
	
	x--;
	y--;
	
	for (int i = x; i >= 0; i--)
	{
		for (int j = y; j >= 0; j--)
		{
			cout << angka[i][j] << " ";
		}
		cout << endl;
	}
}


