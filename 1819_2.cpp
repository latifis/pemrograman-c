#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
	int bilangan;
	int x, y, z, sisa;
	
	cout << "bilangan(dalam mm) : "; cin >> bilangan;
	
	x = bilangan/1000000;
	y = (bilangan%1000000)/1000;
	z = (bilangan%1000)/10;
	
	sisa = bilangan%10;
	
	cout << "hasil konversi : " << x << " km, " << y << " m, " << z << " cm, " << sisa << " mm.";
	
}
