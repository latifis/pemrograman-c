#include <iostream>
#include <string.h>
using namespace std;

main(){
	char kata[100], cari;
	bool found=false;
	
	cout << "Kata yang ingin diinput : "; cin.getline(kata, sizeof(kata));
	int n=strlen(kata);
	cout << "Cari huruf	: "; cin >> cari;
	
	for (int i = 0; i < n; i++)
	{
		if (kata[i] == cari)
		{
			found=true;
			break;
		}
	}
	
	if (found)
	{
		cout<<"Array ditemukan pada index ";
		for (int i = 0; i < n; i++)
		{
			if (kata[i]==cari)
			{
				cout << i << " ";
			}
		}
	}
	else {
		cout << cari << " tidak ditemukan :)";
	}	
}
