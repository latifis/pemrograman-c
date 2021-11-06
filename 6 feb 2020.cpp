#include <iostream>
using namespace std;

int main ()
{
	//Deklarasi
	int jayam;
	int a, b, c;
	int jtelur[20];
	string nayam[20];
	string wtelur[20][20];
	
	//Deskripsi
	
	cout << "Masukkan Jumlah Ayam : "; cin >> jayam;
	
	for (int i=0; i<jayam; i++)
	{	
		cout << "\nMasukkan Nama Ayam : "; cin >> nayam[i];
		cout << "Masukkan Jumlah Telur " << nayam[i] << " : "; cin >> jtelur[i];
		
		a = jtelur[i];
		
		if (a>0)
		{
			cout << "Apa warna telur " << nayam[i] << " yang pertama? : "; cin >> wtelur[i][0];
		
			if (a>1)
			{
				for (int n=1; n<a; n++)
				{
					cout << "Apa warna telur " << nayam[i] << " yang ke-" << n+1 << "? : "; cin >> wtelur[i][n];
				}
			}
		}
		if (a==0)
		{	
			for (int n=1; n<a; n++)
			{
				cout << "Oke Deh"; 
				wtelur[i][n] = "tak ada";
			} 
		}	
	}
	
	cout << endl << endl;
	
	for (int k=0; k<jayam; k++)
	{
		cout << nayam[k] << " punya " << jtelur[k] << " telur. Warnanya "; 
		
		b = jtelur[k];
		
		if (b==0)
			cout << " ga ada, karena ga ada telurnya";
		else if (b==1)
			cout << wtelur[k][0];
		else if (b==2)
			cout << wtelur[k][0] << " dan " << wtelur[k][1];
		else
		{	
			for (int m=0; m<b-1; m++)
			{
				cout << wtelur[k][m] << ", ";
				c = m;
			}
			cout << "dan " << wtelur[k][c+1];
			
		}
		cout << endl;
		
	}
}
