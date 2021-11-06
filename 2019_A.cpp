#include <iostream>
#include <string.h>
using namespace std;

int main (){
	
	int angka;
	int temp;
	
	cout << "Banyak Angka : "; cin >> angka;
	
	int test[angka];
	int simpan[100];
	
	for (int i = 0; i < angka; i++)
	{
		cout << "Angka ke-" << i+1 << " : "; cin >> test[i];
	}
	
	cout << "\nHasil" << endl;
	
	for (int i = 0; i < angka; i++)
	{
		temp=0;
		cout << "\nBilangan ke-" << i+1;
		for (int j = 0; j < test[i]+1; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (test[i]%k==0 && k%2==0 && k!=0 && k!=1)
				{
					simpan[temp]=k;
					temp++;
				}
			}			
		}
		if (temp!=0)
			{
				cout << " : ADA\n";
				cout << "\tBilangan Pembagi : "; 
				for (int j = 0; j < temp; j++)
				{
					cout << simpan[j];
				}
				cout << endl;
			}
			else
			{
				cout << " : TIDAK ADA \n";
			}
	}
	
}
