#include <iostream>
#include <malloc.h>
using namespace std;

int main (){
	int N=6, b, c, *x, *y, **a;
	x = (int *)malloc(sizeof(int));
	c = N;
	
	y = &c;
	*x = *y;
	*y = c+2;
	a = &y;
	b = *y;
	y = x;
	*x = **a+3;
	
	cout << "Nilai b\t\t= " << b << endl;
	cout << "Nilai c\t\t= " << c << endl;
	cout << "Nilai *x\t= " << *x << endl;
	cout << "Nilai *y\t= " << *y << endl;
	cout << "Nilai **a\t= " << **a << endl;
	}
