#include <iostream>
#include <string.h>
using namespace std;

char kalimat[100];

void proses ();

int main ()
{
	for(int i;i<=100;i++)
	{
		kalimat[i]=1;
	}
	
	cout << "input kalimat= ";
	cin >> kalimat;
	
	proses();
	
	return 0;
}

void peoses()
{
	int n = strlen(kalimat);
	cout << "output kalimat : ";
	
	do
	{
		strcmp(kalimat[i],' ');
		int a=0;
		
		for(int i=n-1; i>=a; i--)
		{
			cout << kalimat[i];
			a=i+1;
		}
		
		cout << " ";
		i++;
	}while(kalimat=='');
}
