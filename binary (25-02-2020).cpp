#include <iostream>
using namespace std;

main()
{
	//binary//
	
	int x[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int i, nilaicari, j, k;
	bool found;
	
	cout << "Nilai yang dicari	= "; cin >> nilaicari;
	
	found=false;
	i=0;
	j=10;
	
	while (!found && i <= j)
	{
		k = (i+j)/2;
		if (nilaicari == x[k])
			found=true;
		else
			{
				if (nilaicari < x[k])
				{
					j = k-1; //i tetap
				}
				else
				{
					i = k+1; //j teteap
				}
			}
	}
	
	if (found)
	{
		cout << nilaicari << " ditemukan dalam array pada index ke-" << k << endl;
	}
	else
	{
		cout << "Tidak ada " << nilaicari << " dalam array" << endl;
	}
}

