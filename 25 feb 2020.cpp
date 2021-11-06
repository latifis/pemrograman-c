#include <iostream>
#include <math.h>
using namespace std;

int tambah(int awal, int akhir, int beda, int hasil);
int kurang(int awal, int akhir, int beda, int hasil);
float pecahan(int jumlah, float hasil, float atas, float bawah);

main () {
	int pilih, awal, akhir, beda, jumlah;
	float hasil=0;
	
	cout << "============Menu============";
	cout << "\n1. Tambah2an atau Kurang2an";
	cout << "\n2. Perkalian";
	cout << "\nPilih : "; cin >> pilih;
	cout << endl;
	
	switch (pilih) 
	{
		case 1 : {
			
			cout << "Nilai awal	: "; cin >> awal;
			cout << "Nilai akhir	: "; cin >> akhir;
			cout << "Beda	: "; cin >> beda;
			
			if (awal < akhir) 
			{
				cout << tambah(awal, akhir, beda, hasil);
			}
			else if (awal > akhir) 
			{
				hasil = awal;
				cout << kurang(awal, akhir, beda, hasil);
			}
			break;			
	}
		
		case 2 : {
			cout << "jumlah : "; cin >> jumlah;
			cout << pecahan (jumlah, hasil, 2, 3);
			break;
		}
	}
}

int tambah(int awal, int akhir, int beda, int hasil) {
	cout << awal;
	if ((awal == akhir) || (awal+beda > akhir)) {
		cout << " = ";
		return hasil+awal;
	} 
	else {
		cout << " + ";
		return hasil = awal+tambah(awal+beda, akhir, beda, hasil);
	}
	
}

int kurang(int awal, int akhir, int beda, int hasil) {
	cout << awal;
	if ((hasil != awal) || (awal == beda)) {
			hasil = hasil-awal;
	}
	if ((awal == akhir) || (awal-beda < akhir)) {
		cout << " = ";
		return hasil;
	}
	else {
		cout << " - ";
		return kurang(awal-beda, akhir, beda, hasil);
	}
}

float pecahan (int jumlah, float hasil, float atas, float bawah) {
	cout << atas << "/" << bawah;
	if (jumlah == 1) {
		cout << " = ";
		return hasil + (atas/bawah);
	}
	else {
		cout << " + ";
		return hasil = (atas/bawah)+pecahan(jumlah-1, hasil, atas*2, bawah*3);
	}
}
