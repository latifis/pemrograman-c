#include <iostream>
using namespace std;

main()
{
	//non sentinel tidak urut//
	
	int x[10]={20, 50, 10, 30, 90, 60, 70, 80, 40, 100};
	bool found=false;
	int i, cari;
	
	cout << "Nilai yang dicari	= "; cin >> cari;
	
	i=0;
	while ((i < 10) && (!found))
	{
		if (x[i] == cari)
		{
			found = true;
		}
		else
			i++;
	}
	if(found)
		cout << cari << " ditemukan pada indek array ke-" << i << endl;
	else
		cout << cari << " tidak ada dalam array tersebut" << endl;
	
}

