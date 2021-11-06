#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	string huruf;
	
	cout << "Masukkan yang mau diurutkan : "; getline(cin, huruf);
	
	int pnj = huruf.length();
	
	for (int i = 0; i < pnj; i++)
	{
		for (int j = 0; j < pnj; j++)
		{
			if(huruf[i]<huruf[j])
			{
				char x = huruf[i];
				huruf[i] = huruf[j];
				huruf[j] = x;
			}
		}
		
	}
	cout << huruf;
	return 0;
}
