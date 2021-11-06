#include <iostream>
using namespace std;

main()
{
	int angka[10]={5,4,8,1,10,19,2,5,6,10};
	int tampung;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (angka[j] > angka[i])
			{
				tampung = angka[j];
				angka[j] = angka[i];
				angka[i] = tampung;
			}
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		cout << angka[i] << " ";
	}
	
}

