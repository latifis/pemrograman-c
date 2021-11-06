#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int x,pilih;
	char y;
	
	cout << "========== Input Data ==========" << endl;
	cout << "\nMasukkan jumlah data : "; cin >> x;
	
	struct mahasiswa{
		string nama;
		int nim;
		char kelas;
	};
	struct mahasiswa mhs[x];
	struct mahasiswa temp[x];
	
	cout << "\nMasukkan data : " << endl;
	
	for (int i = 0; i < x; i++)
	{
		cin.ignore();
		cout << "Nama 	: "; getline(cin,mhs[i].nama);
		cout << "NIM 	: "; cin >> mhs[i].nim;
		cout << "Kelas 	: "; cin >> mhs[i].kelas;
		cout << endl;
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
			case 1:
				for (int i = 0; i < x-1; i++)
				{
					for (int j = 0; j < x-1; j++)
					{
						if (mhs[j].nim>mhs[j+1].nim)
						{
							temp[j].nama = mhs[j].nama;
							mhs[j].nama = mhs[j+1].nama;
							mhs[j+1].nama = temp[j].nama;
							
							temp[j].nim = mhs[j].nim;
							mhs[j].nim = mhs[j+1].nim;
							mhs[j+1].nim = temp[j].nim;
							
							temp[j].kelas = mhs[j].kelas;
							mhs[j].kelas = mhs[j+1].kelas;
							mhs[j+1].kelas = temp[j].kelas;
						}
					}
				}
				cout << "Data setelah diurutkan : " << endl;
				for (int i = 0; i < x; i++)
				{
					cout << "\nData ke-" << i+1 << " : ";
					cout << "\n\tNama 	: " << mhs[i].nama;
					cout << "\n\tNIM 	: " << mhs[i].nim;
					cout << "\n\tKelas 	: " << mhs[i].kelas;
					cout << endl;
				}
				break;
				
			case 2:
				int i,j;
				for (i = 0; i < x; i++)
				{
					for (j = i+1; j < x; j++)
					{
						if (mhs[i].nama>mhs[j].nama)
						{
							temp[i].nama = mhs[i].nama;
							mhs[i].nama = mhs[j].nama;
							mhs[j].nama = temp[i].nama;
							
							temp[i].nim = mhs[i].nim;
							mhs[i].nim = mhs[j].nim;
							mhs[j].nim = temp[i].nim;
							
							temp[i].kelas = mhs[i].kelas;
							mhs[i].kelas = mhs[j].kelas;
							mhs[j].kelas = temp[i].kelas;
						}
					}
					
				}
				cout<<"Data setelah diurutkan : "<<endl;
				for (int i = 0; i < x; i++)
				{
					cout << "\nData ke-" << i+1 << " : ";
					cout << "\n\tNama 	: " << mhs[i].nama;
					cout << "\n\tNIM	: " << mhs[i].nim;
					cout << "\n\tKelas	: " << mhs[i].kelas;
					cout << endl;
				}
				break;
				
			case 3: {
				int kiri,kanan,tengah,nim;
				bool found = false;
			
				for (int i = 0; i < x; i++)
				{
					temp[i].nama = mhs[i].nama;
					temp[i].nim = mhs[i].nim;
					temp[i].kelas = mhs[i].kelas;
					int j = i-1;
					while (temp[i].nim < mhs[j].nim && j>=0)
					{
						mhs[j+1].nim = mhs[j].nim;
						mhs[j+1].nama = mhs[j].nama;
						mhs[j+1].kelas = mhs[j].kelas;
						j = j-1;
						mhs[j+1].nim = temp[i].nim;
						mhs[j+1].nama = temp[i].nama;
						mhs[j+1].kelas = temp[i].kelas;
					}
				}
				cout << "NIM Diurutkan : ";
				for (int i = 0; i < x; i++)
				{
					cout << mhs[i].nim << " ";
				}
				cout << endl << endl;
				cout << "Input NIM : "; cin>>nim;
				kiri = 0;
				kanan = x-1;
				
				while (kiri<=kanan)
				{
					tengah = (kiri+kanan)/2;
					if (nim == mhs[tengah].nim)
					{
						found = true;
						break;
					}
					else if (nim < mhs[tengah].nim)
					{
						kanan = tengah-1;
					}
					else
					{
						kiri = tengah+1;
					}
				}
				if (found == true)
				{
					cout << "NIM Ditemukan.";
					cout << "\nNama	: " << mhs[tengah].nama;
					cout << "\nNIM	: " << mhs[tengah].nim;
					cout << "\nKelas	: " << mhs[tengah].kelas << endl;
				}
				else
				{
					cout<<"NIM tidak ditemukan."<<endl;
				}
			}
				break;
				
			case 4:
				exit(0);
				break;
				
			default:
				cout << "Tidak ada dalam menu!!";
		}
		cout<<endl;
		cout << "\nMau kembali ke menu ? (y/n) : "; cin>>y;
		
		system("cls");
		
	}while(y=='y' || y=='Y');
}
