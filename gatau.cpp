#include <iostream>
#include <string.h>
using namespace std;

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

		cout << "\nMasukkan pilihan : ";cin>>pilih;
		
		switch (pilih)
		{
			case 1: 
				cout << "masukkan nama :"; cin >> kata;
	int n=strlen(kata);
	
	for (int i=n-1; i>=0; i--)
	{
		cout << kata[i];    
	}
				break;
			case 2: 
				cout << "masukkan banyak baris: "; cin >> x;
	cout << "masukkan kolom :"; cin >> y;
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
				break;
			case 3: 
					cout << "masukkan banyak baris: "; cin >> x;
	cout << "masukkan kolom :"; cin >> y;
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
				break;
			default: 
				cout<<"\nSalah input";
				break;
		}
	
	cout << "\nUlang tidak(y/n) : "; cin >> a;
	cout << endl << endl;
		
	}while (a=='Y' || a=='y');	
}
