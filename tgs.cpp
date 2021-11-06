#include <iostream>
using namespace std;

int main ()
{
		int a, b, x, y;
		
		cout << "input baris = "; cin >> a;
		cout << "input kolom = "; cin >> b;
		
		int abc[a][b];
		
		for (int i=0; i<a; i++)
		{
			for (int j=0; j<b; j++)
			{
				cout << "abc[" << i << "][" << j << "] = ";
				cin >> abc[i][j];
			}
			cout << endl;
		}
		
		cout << "sebelum ditranspose" << endl;
		for (int i=0; i<a; i++)
		{
			for (int j=0; j<b; j++)
			{
				cout << abc[i][j] << "\t";
			}
			cout << endl;
		}
	
		x=b;
		y=a;
	
		cout << "sesudah ditranspose" << endl;
		for (int i=0; i<x; i++)
		{
			for (int j=0; j<y; j++)
			{
				cout << abc[j][i] << "\t";
			}
			cout << endl;
		}
}
