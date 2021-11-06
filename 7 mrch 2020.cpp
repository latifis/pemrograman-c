#include <iostream>
using namespace std;

int main ()
{
	int a, b=1, banyak, nilai[100];
	string nama[100], nim[100];
	
	cout << "Masukkan  banyak data : "; cin >> banyak; 
	cout << endl;
	
	for (int i = 0; i < banyak; i++)
	{
		cin.ignore();
		cout << i+1;
		cout << "\nNama\t\t\t : "; getline(cin, nama[i]);
		cout << "NIM\t\t\t : "; cin >> nim[i];
		cout << "Nilai\t\t\t : "; cin >> nilai[i];
		cout << endl;
	}
	
	a=nilai[0];
	
	for (int i = 0; i < banyak; i++)
	{
		if (a<nilai[i])
			a=nilai[i];	
	}
	
	cout << "\n\n\nNilai tertinggi adalah : " << endl;
	
	for (int i = 0; i < banyak; i++)
	{
		if (nilai[i]==a)
		{
			cout << b;
			cout << "\nNama\t\t\t : " << nama[i];
			cout << "\nNIM\t\t\t : " << nim[i];
			cout << "\nNilai\t\t\t : " << nilai[i];
			b++;
		}
		cout << endl;	
	}
	


}
