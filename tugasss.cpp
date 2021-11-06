#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int pilih, a, b, p, q, m, n, x;
	char cbl;
	

	do{
		cout <<
		
		"1. Perkalian"<<
		"\n2. Perpangkatan"<<
		"\n3. Kotak Bolong"<<
		"\n4. Segitiga"<<
		"\nPilih: "; 
		cin >> pilih;
		
		
		switch (pilih){
			case 1:
			
			cout << "x : "; 
			cin >> a;
			cout << "y : "; 
			cin >> b;
			
			for (int i = 1; i <= b; i++)
			{
				cout << a;
				if (i==b)
				cout << " = ";
				else 
				cout << " + ";
			}
			cout << a*b;
			
				break;
				
			case 2:
			
			cout << "x : "; 
			cin >> p;
			cout << "y : "; 
			cin >> q;
			
			for (int i = 1; i <= q; i++){
				cout << p;
				if (i==q)
					cout << " = ";
				else
				cout << " x ";
			}
				cout << pow(p,q);
				
				break;
				
			case 3:
			
			cout << "Panjang sisi : "; 
			cin>>m;
			cout << "Lebar sisi : "; 
			cin>>n;
			
			for (int i = 1; i <= m; i++){
				if (i==1 || i==m){
				for (int j = 1; j <= n; j++){
						cout << " *";
					}
				}		
				else 
					for (int j = 1; j <= n; j++){
						if(j==1||j==n)
						cout << " *";
						else
						cout << "  ";
						}
						cout << endl;
			}
			break;
			
			case 4:
				cout << "masukkan batas : ";
				cin >> x;
				 
					for (int i=1; i<=x; i++)
					{
						for (int j=1; j<=i; j++)
						{
							cout << i*j << " ";
				
						}
	
					cout << endl;
					}
				break;
			
			default:
				cout << "Input Salah";
				cout << endl;
			}	
					
	cout << "\n\nCoba lagi? (y/n)"; 
	cin >> cbl;
	cout << endl;
				
	} while (cbl=='y'|| cbl=='Y');
	
	return 0;
}

