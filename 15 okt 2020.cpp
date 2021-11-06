#include <iostream>
using namespace std;

int x[10] = {2,3,4,5,6,7,8,9,10,11};
void cari(int *xcari);

int main(){
	int xcari;
	
	cout << "Cari Angka Berapa : "; cin >> xcari;
	cari(&xcari);
	}

void cari(int *xcari){
	
	int a, b;
	
	for (int i = 0; i < 10; i++)
	{
		if (x[i]==*xcari)
		{
			a=x[i];
			b=i;
		}
	}
	
	cout << "\n\tYang dicari : " << a << endl << "\tKetemu di array ke-" << b;
	
	}
