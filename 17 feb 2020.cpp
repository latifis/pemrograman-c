#include <iostream>
using namespace std;

struct data_mka{
	int jmka[100], nilai[100][100];
	char kmka[100][100], kelas[100][100], nilaihuruf[100][100];
	string nmka[100][100];
	}data;

struct data_mahasiswa{
	int jmhs, nim[100];
	string nama[100];
	data_mka data;
	}mhs;

int main()
{
	int a, b;
	
	cout << "Banyaknya Mahasiswa : "; cin >> mhs.jmhs;
	
	cout << endl;
	
	for (int i=0; i<mhs.jmhs; i++)
	{
		cout << "Mhs[" << i << "].NoMhs\t  : "; cin >> mhs.nim[i];
		cout << "Mhs[" << i << "].Nama\t  : "; cin >> mhs.nama[i];
		cout << "Mhs[" << i << "].BanyakMKA  : "; cin >> mhs.data.jmka[i];
		
			a=mhs.data.jmka[i];
		
			for (int j=0; j<a; j++)
			{
				cout << "  Mhs[" << i << "].MKA[" << j << "].KodeMKA\t  : "; cin >> mhs.data.kmka[i][j];
				cout << "  Mhs[" << i << "].MKA[" << j << "].NamaMKA\t  : "; cin >> mhs.data.nmka[i][j];
				cout << "  Mhs[" << i << "].MKA[" << j << "].Kelas\t  : "; cin >> mhs.data.kelas[i][j];
				cout << "  Mhs[" << i << "].MKA[" << j << "].NilaiUTS  : "; cin >> mhs.data.nilai[i][j];
				
				b=mhs.data.nilai[i][j];
				
				if (b<100 && b>=75)
					mhs.data.nilaihuruf[i][j]='A';
				else if (b<75 && b>=60)
					mhs.data.nilaihuruf[i][j]='B';
				else if (b<60 && b>=40)
					mhs.data.nilaihuruf[i][j]='C';
				else if (b<40 && b>=20)
					mhs.data.nilaihuruf[i][j]='D';
				else if (b<20 && b>=0)
					mhs.data.nilaihuruf[i][j]='E';
			}
		cout << endl;
	}
	
	cout << endl << endl << "Data yang Input : " << endl;
	for (int i=0; i<mhs.jmhs; i++)
	{
		cout << "\nNoMhs\t: " << mhs.nim[i];
		cout << "\nNama\t: " << mhs.nama[i] << endl << endl;
		
			a=mhs.data.jmka[i];
		
			cout << " KodeMKA    Kelas    NilaiUTS    NilaiHuruf     NamaMKA" << endl;
		
			for (int j=0; j<a; j++)
			{
				cout << "    " << mhs.data.kmka[i][j] << "          " << mhs.data.kelas[i][j] << "          " << mhs.data.nilai[i][j] << "          " << mhs.data.nilaihuruf[i][j] << "          " << mhs.data.nmka[i][j] << endl;
			}
		cout << endl;
	}
}
