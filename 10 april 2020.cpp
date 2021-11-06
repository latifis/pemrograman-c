#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

int main () 
{
	int pilih, n, angka[12], kiri, kanan, tengah, key, nim[100];
	char menu;
	string nama[100], kelas[100], temp;
	bool ketemu = false;
	
	cout << "========== Input Data ==========" << endl;
	cout << "\nMasukkan jumlah data : "; cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nMasukkan data " << "ke-" << i+1 << " : ";
		cin.ignore();
		cout << "\n\tNama	: "; getline(cin, nama[i]);
		cout << "\tNIM	: "; cin >> nim[i];
		cout << "\tKelas	: "; cin >> kelas[i];
	}
	
	system("cls");
	
	do
	{
		cout << "==================== Menu ====================" << endl;
		cout << "Silahkan Pilih Menu" << endl;
		cout << "1. Sorting Berdasarkan NIM\n";
		cout << "2. Sorting Berdasarkan Nama\n";
		cout << "3. Searcing data Berdasarkan NIM dengan Binery\n";
		cout << "4. Exit\n";
		cout << "Pilih : "; cin>> pilih;
		cout << endl;
		
		switch (pilih)
		{
			case 1 :
				
				for(int i = 0; i < n-1; i++)
				{
					for(int j = 0; j < n-1; j++)
					{
						if(nim[j]>nim[j+1])
						{
							temp = nama[j];
							nama[j] = nama[j+1];
							nama[j+1] = temp;
							
							int teemp = nim[j];
							nim[j] = nim[j+1];
							nim[j+1] = teemp;
							
							temp = kelas[j];
							kelas[j] = kelas[j+1];
							kelas[j+1] = temp;
						}
					}
				}				
				
				for (int i = 0; i < n; i++)
				{
					cout << "\nData ke-" << i+1 << " : ";
					cout << "\n\tNama	: " << nama[i];
					cout << "\n\tNIM	: " << nim[i];
					cout << "\n\tKelas	: " << kelas[i];
				}
				
				
				break;
				
			case 2 :
				
				for(int i = 0; i < n; i++)
				{
					for(int j = i+1; j < n; j++)
					{												
						if(nama[i]>nama[j])
						{
							temp = nama[j];
							nama[j] = nama[j+1];
							nama[j+1] = temp;
							
							int teemp = nim[j];
							nim[j] = nim[j+1];
							nim[j+1] = teemp;
							
							temp = kelas[j];
							kelas[j] = kelas[j+1];
							kelas[j+1] = temp;
						}
					}
				}
				
				for (int i = 0; i < n; i++)
				{
					cout << "\nData ke-" << i+1 << " : ";
					cout << "\n\tNama	: " << nama[i];
					cout << "\n\tNIM	: " << nim[i];
					cout << "\n\tKelas	: " << kelas[i];
				}
				
				break;
				
			case 3 :

				 cout << "Masukan jumlah data : "; cin>>n;
				 
				
				 for (int i=0; i<n; i++)
				 {
					for(int j=0; j< n-i-1; j++)
					{
						if(angka [j] > angka [j+1])
						{
							cout << "belom";
						}
					}
				 }
				
				 cout << "Data yang telah diurutkan adalah : ";
				
				 for(int i=0; i<n; i++)
				 {
					cout<<angka[i]<<" ";
				 }
				
				 cout << "\n Masukan angka yang dicari : ";
				 cin >> key;

				 kiri=0;
				 kanan=n-1;

				while(kiri <= kanan)
				{
					tengah = (kiri + kanan)/2;
					if(key==angka[tengah])
					{
						ketemu = true;
						break;
					}
					
					else if (key < angka [tengah])
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
					cout << "Angka ditemukan!";
					cout << "Nama";
				}
				else 
				{
					cout << "Angka tidak ditemukan";
				}
				  
			case 4 :
				exit(0);
				break;
					
			default:
				cout << "Tidak ada dalam menu!!";
				
		}
		cout << "\n\nMau kembali ke menu ? (y/n) : "; cin >> menu;
		system("cls");
	} while (menu=='y' || menu=='Y');
}
