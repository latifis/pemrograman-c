#include <iostream>
using namespace std;

main(){
	int banyak, cari;
	bool found=false;
	
	cout<<"Banyak data yang ingin di input : "; cin>>banyak;
	
	int angka[banyak];
	int x = sizeof(angka)/sizeof(angka[0]);
	
	for (int i = 0; i < x; i++)
	{
		cout<<"angka "<<i<<" = "; cin>>angka[i];
	}
	
	cout<<"\nCari angka : "; cin>>cari;
	
	//untuk nyari tau angka yang kita cari ada apa enggak
	for (int i = 0; i < x; i++)
	{
		if (angka[i]==cari)
		{
			found=true;
			break;
		}
	}
	
	if (found)
	{
		cout<<"Array ditemukan pada index ";
		for (int i = 0; i < x; i++)
		{
			if (angka[i]==cari)
			{
				cout<<i<<" ";
			}
		}
	}
	else {
		cout<<"Angka "<<cari<<" tidak ditemukan :)";
	}
	
}
