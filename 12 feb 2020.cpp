#include <iostream>
#include <string.h>
using namespace std;

struct varlaen{
	int a, b;
	}var;

struct data_mahasiswa{
	string nmhs[100][100];
	float bmhs[100][100], tmhs[100][100];
	}mhs;

struct kelas{
	int jkls, jmhs[100];
	string nkls[100];
	data_mahasiswa mhs;
	varlaen var;
	}kls;

int main ()
{
	cout << "Masukkan jumlah kelas : "; cin >> kls.jkls;
	
	cout << endl;
	
	if(kls.jkls<1)
		cout << "[error]gabisa mendata, kalo kelas ga ada" << endl;
	
	for (int i=0; i<kls.jkls; i++)
	{
		cout << "\tMasukkan nama kelas : "; cin >> kls.nkls[i];
		cout << "\tMasukkkan jumlah mahasiswa kelas " << kls.nkls[i] << " : "; cin >> kls.jmhs[i];
		
		kls.var.b=kls.jmhs[i];
		
		if (kls.var.b<1)
			cout << "\t[error]gabisa data, kalo mahasiswa saja tidak ada" << endl;
	}
	
	cout << endl;
	
	for (int i=0; i<kls.jkls; i++)
	{
		kls.var.a=kls.jmhs[i];
		for (int j=0; j<kls.var.a; j++)
		{
			cout << "\t\tMasukkan nama mahasiswa " << j+1 << " kelas " << kls.nkls[i] << " : " ; cin >> kls.mhs.nmhs[i][j];
			cout << "\t\tMasukkan berat mahasiswa " << j+1 << " kelas " << kls.nkls[i] << " : " ; cin >> kls.mhs.bmhs[i][j];
			cout << "\t\tMasukkan tinggi mahasiswa " << j+1 << " kelas " << kls.nkls[i] << " : " ; cin >> kls.mhs.tmhs[i][j];
			cout << endl;
		}
	}
	
	cout << endl;
	
	for (int i=0; i<kls.jkls; i++)
	{
		cout << "Kelas : " << kls.nkls[i] << endl;
		kls.var.a=kls.jmhs[i];
		if (kls.var.a<1)
			cout << "\n\t[error]ga ada data" << endl;
		for (int j=0; j<kls.var.a; j++)
		{
			cout << "\n\tNAMA : " << kls.mhs.nmhs[i][j];
			cout << "\n\tBERAT : " << kls.mhs.bmhs[i][j];
			cout << "\n\tTINGGI : " << kls.mhs.tmhs[i][j] << endl;
		}
		cout << endl;
	}
}
