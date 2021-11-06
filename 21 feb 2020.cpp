#include <iostream>
#include <math.h>
using namespace std;

int tambahan(int x, int y, int b, int h);
int pengurangan(int x, int y, int b, int h);
float pecahan(int j, float h, float x, float y);

main () {
	int pilih, awal, akhir, beda, jumlah;
	float hasil=0;
	
	cout << "Menu\n";
	cout << "1. Tambah2an atau Kurang2an\n";
	cout << "2. Perkalian\n";
	cout << "Pilih : "; cin >> pilih;
	cout << endl;
	
	switch (pilih) {
		case 1 : {
			cout << "Nilai awal	: "; cin >> awal;
			cout << "Nilai akhir	: "; cin >> akhir;
			cout << "Beda	: "; cin >> beda;
			
			if (awal < akhir) {
				cout << tambahan(awal, akhir, beda, hasil);
		}
			else if (awal > akhir) {
				hasil = awal;
				cout << pengurangan(awal, akhir, beda, hasil);
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

int tambahan(int x, int y, int b, int h) {
	cout << x;
	if ((x == y) || (x+b > y)) {
		cout << " = ";
		return h+x;
	} 
	else {
		cout << " + ";
		return h = x+tambahan(x+b, y, b, h);
	}
	
}

int pengurangan(int x, int y, int b, int h) {
	cout << x;
	if ((h != x) || (x == b)) {
			h = h-x;
	}
	if ((x == y) || (x-b < y)) {
		cout << " = ";
		return h;
	}
	else {
		cout << " - ";
		return pengurangan(x-b, y, b, h);
	}
}

float pecahan (int j, float h, float x, float y) {
	cout << x << "/" << y;
	if (j == 1) {
		cout << " = ";
		return h + (x/y);
	}
	else {
		cout << " + ";
		return h = (x/y)+pecahan(j-1, h, x*2, y*3);
	}
}
