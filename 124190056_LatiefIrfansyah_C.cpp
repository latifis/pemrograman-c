#include <iostream>
using namespace std;

int main(){

	//DEKLARASI
	
	int a;
	string p,u;
	float k, b, c, d, e, f, g;
	
	
	//DESKRIPSI
	
	cout << "========== MENU ==========";
	cout << "\n1. Login";
	cout << "\n2. Rata-Rata Nilai";
	cout << "\n\nInput Pilihan = ";
	cin >> a;
	cout << endl;
	
	cout << "==========================";
	
	switch (a)
	{
		case 1 :
			cout << "\nMasukkan Username = ";
			cin >> u;
			cout << "Masukkan Password = ";
			cin >> p;
			
			if (u=="latipip" && p=="entahapa")
				cout << "Login Sukses!";
			else
				cout << "Login Gagal!";			
			break;
			
		case 2 :
			cout << "\nNilai";
			cout << "\n\nMatematika	= "; cin >> b;
			cout << "Biologi		= "; cin >> c;
			cout << "Fisika		= "; cin >> d;
			cout << "Kimia		= "; cin >> e;
			cout << "B. Indo		= "; cin >> f;
			cout << "B. Inggris	= "; cin >> g;
			
			k = (b+c+d+e+f+g)/6;
			
			cout << "\nRata-Rata Nilai adalah " << k << endl;
			
			if (k>=80)
				cout << "Anda Lulus !";
			else
				cout << "Anda Tidak Lulus !";
			break;
			
		default:
			cout << "\nTidak Ada dalam Menu";	
		
	}
		return 0;	
			
	
}
