#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	string nama;
	string dosen;
	string nama_kul[100];
	string kode_kul[100];
	
	char univ, fakul, prodi;
	char nim[9];
	char nhuruf[100];
	
	int nakhir1;	
	int jmat;
	int sks[100];
	int nakhir[100];
	int tnilai, tsks;
	
	cout << "Input Data KRS =====";
	cout << "\nNama \t\t\t: "; getline(cin,nama);
	cout << "NIM \t\t\t: "; cin >> nim; cin.ignore();
	cout << "Dosen Wali \t\t: "; getline(cin,dosen);
	cout << "Jumlah Mata Kuliah \t: "; cin >> jmat;
	cout << endl;
	
	for (int i; i<jmat; i++)
	{
		cout << "Matkul ke-" << i+1;
		cout << "\nKode Matkul : "; cin >> kode_kul[i];
		cout << "Nama Matkul : "; cin >> nama_kul[i];
		cout << "SKS : "; cin >> sks[i];
		cout << "Nilai Akhir : "; cin >> nakhir[i];
	}
	
	univ=nim[0];
	fakul=nim[1];
	prodi=nim[2];
	
	cout << endl << endl;
	
	if(univ=='1')
	{
		cout << "UPN \"Veteran\" Yogyakarta" << endl;
		
		if(fakul=='2')
			cout << "Fakultas Teknik Industri";
		else 
			cout << "Fakultas lain";
		
		cout << endl;
		
		if(fakul=='1')
			cout << "Teknik Kimia D3";
		else if(fakul=='2')
			cout << "Teknik Industri";
		else if(fakul=='3')
			cout << "Teknik Informatika";
		else if(fakul=='4')
			cout << "Sistem Informasi";
			
		cout << endl;
		
		cout << "Nim \t: " << nim << endl;
		cout << "Nama \t: " << nama << endl;
		cout << "Angkatan \t: " << "20" << nim[3] << nim[4];
		cout << endl << endl;
		
		cout << "\t\t\t\t KARTU HASIL STUDI";
		cout << "\n==================================================================================";
		cout << "\nNo | Kode MK |\t\tMata Kuliah\t| SKS | Nilai Angka | Nilai Huruf | Total ";
		cout << "\n==================================================================================";
		
	
		
		for(int i; i<jmat; i++)
		{
			nakhir1=nakhir[i];
			if(nakhir1>=81 && nakhir1<=100)
				nhuruf[i]='A';
			else if(nakhir1>=61 && nakhir1<=80)
				nhuruf[i]='B';
			else if(nakhir1>=41 && nakhir1<=60)
				nhuruf[i]='C';
			else if(nakhir1>=21 && nakhir1<=40)
				nhuruf[i]='D';
			else if(nakhir1>=0 && nakhir1<=20)
				nhuruf[i]='E';
		}
		
		for(int i; i<jmat; i++)
		{	
			cout << "\n " << i+1 << " |\t" << kode_kul[i] << "  |\t\t" << nama_kul[i] << "\t\t|  " << sks[i] << "  |\t\t" << nakhir[i] << "  |\t\t" << nhuruf[i] << " | " << "Total";
		}
		cout << "\n==================================================================================";
		cout << endl << endl;
		
		
		cout << "Total SKS \t: " << tsks;
		cout << "\nTotal Nilai \t: " << tnilai;
		cout << "\nIP \t: ";
		
		
	}	
		
	else 
		cout << "Bukan anak UPN VY";
	

}
