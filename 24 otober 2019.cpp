#include <iostream>
using namespace std;

int main ()
{	
	int x, y, h, j, M, s, m=0, b, l;
	char q;
	do {
	cout << "MENU MAKANAN : ";
	cout << "\n1. Ayam Goreng";
	cout << "\n2. Cumi-Cumi Rebus";
	cout << "\n3. Timun Bakar";
	
	cout << "\nPilih : ";
	cin >> x;
		
		switch (x)
		{	case 1 :
				h = 15000;
				break;
			case 2 :
				h = 12000;
				break;
			case 3 :
				h = 5000;
				break;
			default :
				cout << "infut salah";
				cout << "\n\nKembali ke Menu? (y/n) : ";
				cin >> q;
		}		
			
	cout << "Beli berapa? : ";
	cin >> y;
	
		j = h*y;
	
	
	cout << "\nHarga Satuan : " << h;
	cout << "\nHarga : " << j; 
	
	cout << "\n\nKembali ke Menu? (y/n) : ";
	cin >> q;
	
	cout << endl << endl;
	} while (q=='y' || q=='Y');
	
	cout << "\n\nTotal Harga yang Harus Dibayar : " << M;
	cout << "\nBayar : ";
	cin >> b;
	
	s = b-M;
	
	
	
	return 0;
}
