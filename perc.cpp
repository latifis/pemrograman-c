#include <iostream>
using namespace std;

int main(){
	
	
	//DEKLARASI
	int pilih, beli, sisa;
	float Ayam, Cumi, Timun, total, bayar, Ayam2, Cumi2, Timun2;
	char x;
	
	
	//DESKRIPSI
	do {
		cout << "MENU MAKANAN";
		cout << "\n1. Ayam Goreng";
		cout << "\n2. Cumi-Cumi Rebus";
		cout << "\n3. Timun Bakar";
		cout << "\nPilih : ";
		cin >> pilih;
		
		switch (pilih)
		{
			case 1: 
				cout << "Beli Berapa :";
				cin >> beli;
				cout << "Harga Satuan = 15000\n";
				cout << "Harga = " << 15000*beli;
				Ayam2 = 15000*beli;
				Ayam = Ayam+Ayam2;
				break;
			case 2: 
				cout << "Beli Berapa :";
				cin >> beli;
				cout << "Harga Satuan = 12000\n";
				cout << "Harga = " << 12000*beli;
				Cumi2 = 12000*beli;
				Cumi = Cumi+Cumi2;
				break;
			case 3: 
				cout << "Beli Berapa :";
				cin >> beli;
				cout << "Harga Satuan = 5000\n";
				cout << "Harga = " << 5000*beli;
				Timun2 = 5000*beli;
				Timun = Timun+Timun2;
				break;
			default:
				cout << "\nInput salah";
		}
		
	cout << "\n\nKembali ke menu?? (y/n)";
	cin >> x;
	cout << endl;
		
	total = Ayam+Cumi+Timun;	
		
	}while(x=='y'||x=='Y');
	
	cout << "Total Harga Dibayar = "<<total<<endl;
	cout << "Bayar = ";
	cin >> bayar;
	
	sisa = bayar-total;
	
	if (bayar>total)
		cout << "\nKembalian Anda : " << sisa;
	else if (bayar==total)
		cout << "\nUang Anda Pas";
	else if (bayar<total)
		cout << "\nUang Anda Kurang";
	
	
	return 0;
}
