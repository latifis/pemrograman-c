#include <iostream>
using namespace std;

int main ()
{
	int x, prima=0;

		cout << "masukkan angka :"; cin >> x;
		for (int i = 1; 1<=x; i++)
		{
			if (x%1==0)
			{
				prima++;
			}
		}
		
		if  (prima==2)
		{
			cout << "prima";
		}
		else 
		{
			cout << "bukan bilangan prima";
		}
	
	return 0;
}
