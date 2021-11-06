#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

typedef struct{
	string nama, range;
	int nim, nh, nk, np, nr, na;
	} data;
data mhs[5];
data temp;

void inputdata();
void ambildata();
void input5data();
void urut();
void import();
void eksport(string file);

void outputdata();
void hasildata();
void proseshasildata();

void hasilakhir();
void searchingdata();

void rekursif();
void prekursif(int bil, int mod);

void pointer();

void error();

int main(){
	int pilih;
	
	cout << "**==============================**==============================**";
	cout << "\n||				||				||";
	cout << "\n||	Latief Irfansyah	||	  NIM . 124190056	||";
	cout << "\n||				||				||";
	cout << "\n**==============================**==============================**";
	cout << "\n||								||";
	cout << "\n||		         R E S P O N S I		        ||";
	cout << "\n||								||";
	cout << "\n**==============================================================**";
	cout << "\n||								||";
	cout << "\n||			1. Input Data		  	        ||";
	cout << "\n||			2. Output Data			        ||";
	cout << "\n||			3. Hasil Data			        ||";
	cout << "\n||			4. Hasil Akhir dibawah C+     	        ||";
	cout << "\n||			5. Searching Data		        ||";
	cout << "\n||			6. Rekursif			        ||";
	cout << "\n||			7. Pointer			        ||";
	cout << "\n||			8. Keluar		  	        ||";
	cout << "\n||								||";
	cout << "\n**==============================================================**";
	cout << "\n\n  Pilih : "; cin >> pilih;
	cout << "\n\n**==============================================================**" << endl;
	system("cls");
	
	switch (pilih)
	{
		case 1 :
			inputdata();
			system("cls");
			main();
			break;
		case 2 :
			outputdata();
			system("cls");
			main();
			break;
		case 3 :
			hasildata();
			system("cls");
			main();
			break;
		case 4 :
			hasilakhir();
			system("cls");
			main();
			break;
		case 5 :
			searchingdata();
			system("cls");
			main();
			break;
		case 6 :
			rekursif();
			system("cls");
			main();
			break;
		case 7 :
			pointer();
			system("cls");
			main();
			break;
		case 8 :
			exit(0);
			break;
		default	:
			error();
			
	}
}

void inputdata()
{
	int pilih;
	
	cout << "Pilih metode : ";
	cout << "\n1. ambil dari file";
	cout << "\n2. input (min5 dan max 5)";
	cout << "\n3. kembali ke menu";
	cout << "\n\nPilih : "; cin >> pilih;
	
	switch (pilih)
	{
		case 1 :
			ambildata();
			system("cls");
			main();
			break;
		case 2 :
			input5data();
			system("cls");
			main();
			break;
		case 3 :
			main();
			break;
		default	:
			error();
	}
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void ambildata()
{
	string file;
	
	cout << "Masukkan nama file : "; cin >> file;
	
	eksport(file);
	urut();
	import();
}

void input5data()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\n	Nim		: "; cin >> mhs[i].nim;
		cin.ignore();
		cout << "	Nama		: "; getline(cin, mhs[i].nama);
		cout << "	Nilai harian	: "; cin >> mhs[i].nh;
		cout << "	Nilai kuis	: "; cin >> mhs[i].nk;
		cout << "	Nilai project	: "; cin >> mhs[i].np;
		cout << "	Nilai Responsi	: "; cin >> mhs[i].nr;
	}
	urut();
	import();
}

void urut()
{
	for(int j = 0; j < 5-1; j++)
	{
		if(mhs[j].nim > mhs[j+1].nim)
		{
			temp.nim = mhs[j].nim;
			mhs[j].nim = mhs[j+1].nim;
			mhs[j+1].nim = temp.nim;
			
			temp.nama = mhs[j].nama;
			mhs[j].nama = mhs[j+1].nama;
			mhs[j+1].nama = temp.nama;
			
			temp.nh = mhs[j].nh;
			mhs[j].nh = mhs[j+1].nh;
			mhs[j+1].nh = temp.nh;
			
			temp.nk = mhs[j].nk;
			mhs[j].nk = mhs[j+1].nk;
			mhs[j+1].nk = temp.nk;
			
			temp.np = mhs[j].np;
			mhs[j].np = mhs[j+1].np;
			mhs[j+1].np = temp.np;
			
			temp.nr = mhs[j].nr;
			mhs[j].nr = mhs[j+1].nr;
			mhs[j+1].nr = temp.nr;
		}
	}
	
	import();
}

void import()
{
	ofstream tulis;
	string namafile="file1.txt";
		
	tulis.open(namafile.c_str());
	for (int i = 0; i < 5; i++)
	{
		tulis << mhs[i].nim << endl; 
		tulis << mhs[i].nama << endl;
		tulis << mhs[i].nh << endl;
		tulis << mhs[i].nk << endl;
		tulis << mhs[i].np << endl;
		tulis << mhs[i].nr << endl;	
	}
	tulis.close();	

}

void eksport(string file)
{
	ifstream baca;
	string namafile=file;
		
	baca.open(namafile);
		
	for(int i = 0 ; i < 5; i++)
	{
		baca >> mhs[i].nim;
		baca.ignore();
		getline(baca,mhs[i].nama);
		baca >> mhs[i].nh;
		baca >> mhs[i].nk;
		baca >> mhs[i].np;
		baca >> mhs[i].nr;
	}
	baca.close();
}

void outputdata()
{
	ifstream baca;
	string namafile="file1.txt";
		
	baca.open(namafile);
		
	for(int i = 0 ; i < 5; i++)
	{
		baca >> mhs[i].nim;
		baca.ignore();
		getline(baca,mhs[i].nama);
		baca >> mhs[i].nh;
		baca >> mhs[i].nk;
		baca >> mhs[i].np;
		baca >> mhs[i].nr;
	}
	baca.close();
	
	cout << endl;
	cout << "\t\t\t\t\t\t\tTabel Data File " << endl << endl;
	cout << "**==============**==============**==============================**======================================================================**" << endl;
	cout << "||\tNo\t||\tNIM\t||\t\tNama\t\t||\t\t\t\tNilai\t\t\t\t\t||" << endl;
	cout << "||\t\t||\t\t||\t\t\t\t||\tHarian\t||\tKuis\t||\tProject\t||\tResponsi\t||" << endl;
	cout << "**==============**==============**==============================**======================================================================**" << endl;
	
	for (int i = 0; i < 5; i++)
	{
		cout << "||\t" << i+1 << "\t||\t" << mhs[i].nim << "\t||\t\t" << mhs[i].nama << "\t\t||\t" << mhs[i].nh << "\t||\t" << mhs[i].nk << "\t||\t" << mhs[i].np << "\t||\t   " << mhs[i].nr <<  "\t\t||" << endl;
	}
	cout << "**==============**==============**==============================**======================================================================**" << endl;
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void hasildata()
{
	proseshasildata();
	int a=0;
	
	cout << endl;
	cout << "\t\t\t\t\t\t\tTabel Data File " << endl << endl;
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	cout << "||\tNo\t||\tNIM\t||\t\tNama\t\t||\t\t\t\tNilai\t\t\t\t\t||\tNilai Akhir\t||\tRange\t||" << endl;
	cout << "||\t\t||\t\t||\t\t\t\t||\tHarian\t||\tKuis\t||\tProject\t||\tResponsi\t||\t\t\t||\t\t||" << endl;
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	
	for (int i = 0; i < 5; i++)
	{
		cout << "||\t" << a << "\t||\t" << mhs[i].nim << "\t||\t\t" << mhs[i].nama << "\t\t||\t" << mhs[i].nh << "\t||\t" << mhs[i].nk << "\t||\t" << mhs[i].np << "\t||\t   " << mhs[i].nr <<  "\t\t||\t   " << mhs[i].na << "\t\t||\t" << mhs[i].range << "\t||" << endl;
		a++;
	}
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	
	ofstream tulis;
	string namafile="file2.txt";
		
	tulis.open(namafile.c_str());
	for (int i = 0; i < 5; i++)
	{
		tulis << mhs[i].nim << endl; 
		tulis << mhs[i].nama << endl;
		tulis << mhs[i].nh << endl;
		tulis << mhs[i].nk << endl;
		tulis << mhs[i].np << endl;
		tulis << mhs[i].nr << endl;
		tulis << mhs[i].na << endl;
		tulis << mhs[i].range << endl;
	}
	tulis.close();
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void proseshasildata()
{
	for (int i = 0; i < 5; i++)
	{
		mhs[i].na= mhs[i].nh*0.2 + mhs[i].nk*0.2 + mhs[i].np*0.4 + mhs[i].nr*0.2;
		
		if(mhs[i].na>=80 && mhs[i].na<=100)
		{
			mhs[i].range="A";
		}
		else if(mhs[i].na>=75 && mhs[i].na<=79)
		{
			mhs[i].range="B+";
		}
		else if(mhs[i].na>=65 && mhs[i].na<=74)
		{
			mhs[i].range="B";
		}
		else if(mhs[i].na>=60 && mhs[i].na<=64)
		{
			mhs[i].range="C+";
		}
		else if(mhs[i].na>=50 && mhs[i].na<=59)
		{
			mhs[i].range="C";
		}
		else if(mhs[i].na>=21 && mhs[i].na<=49)
		{
			mhs[i].range="D";
		}
		else if(mhs[i].na>=0 && mhs[i].na<=20)
		{
			mhs[i].range="E";
		}
	}
	
}

void hasilakhir()
{
	cout << endl;
	cout << "\t\t\t\t\t\t\tTabel Data File " << endl << endl;
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	cout << "||\tNo\t||\tNIM\t||\t\tNama\t\t||\t\t\t\tNilai\t\t\t\t\t||\tNilai Akhir\t||\tRange\t||" << endl;
	cout << "||\t\t||\t\t||\t\t\t\t||\tHarian\t||\tKuis\t||\tProject\t||\tResponsi\t||\t\t\t||\t\t||" << endl;
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	
	for (int i = 0; i < 5; i++)
	{
		if (mhs[i].range=="C" || mhs[i].range=="D" || mhs[i].range=="E") 
		{
			cout << "||\t" << i+1 << "\t||\t" << mhs[i].nim << "\t||\t\t" << mhs[i].nama << "\t\t||\t" << mhs[i].nh << "\t||\t" << mhs[i].nk << "\t||\t" << mhs[i].np << "\t||\t   " << mhs[i].nr <<  "\t\t||\t   " << mhs[i].na << "\t\t||\t" << mhs[i].range << "\t||" << endl;
		}
		
	}
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void searchingdata()
{
	cout << "Nama yang dicari : "; cin.ignore(); getline(cin, temp.nama);

	cout << endl;
	cout << "\t\t\t\t\t\t\tTabel Data File " << endl << endl;
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	cout << "||\tNo\t||\tNIM\t||\t\tNama\t\t||\t\t\t\tNilai\t\t\t\t\t||\tNilai Akhir\t||\tRange\t||" << endl;
	cout << "||\t\t||\t\t||\t\t\t\t||\tHarian\t||\tKuis\t||\tProject\t||\tResponsi\t||\t\t\t||\t\t||" << endl;
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	
	for (int i = 0; i < 5; i++)
	{
		if (temp.nama==mhs[i].nama)
		{
			cout << "||\t" << i+1 << "\t||\t" << mhs[i].nim << "\t||\t\t" << mhs[i].nama << "\t\t||\t" << mhs[i].nh << "\t||\t" << mhs[i].nk << "\t||\t" << mhs[i].np << "\t||\t   " << mhs[i].nr <<  "\t\t||\t   " << mhs[i].na << "\t\t||\t" << mhs[i].range << "\t||" << endl;
		}
		
	}
	cout << "**==============**==============**==============================**======================================================================**======================**==============**" << endl;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void rekursif()
{
	int bil, mod, hakhir;
	
	cout << "Bilangan\t: "; cin >> bil;
	cout << "Mod\t: "; cin >> mod;
	
	hakhir = bil%mod;
	
	prekursif(bil, mod);
	
	cout << endl << "hasil akhir	: "<< hakhir;
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void prekursif(int bil, int mod)
{
	int hasil= bil%mod;
	cout << endl;
	cout << bil << " mod " << mod << " = " <<  hasil << endl;
	prekursif(bil/mod, mod-1);
}

void pointer()
{
	string kalimat;
	int jumlah;
	char huruf;
	int *phuruf;
	
	cout << "Masukkan kalimat	:"; cin.ignore(); getline(cin, kalimat);
	cout << "Sembunyikan huruf	: "; cin >> huruf; 
	
	*phuruf = huruf;
	
	jumlah=kalimat.length();
	
	for (int i = 0; i < jumlah; i++)
	{
		if(kalimat[i]==*phuruf)
		{
			kalimat[i]='*';
		}
	}
	
	for (int i = 0; i < jumlah; i++)
	{
		cout << kalimat[i];
	}
	
	
	cout << endl << "\tTekan Enter Untuk Kembali ke Menu . . . ";
	getch();
}

void error()
{
	cout << "**======================================================**" << endl;
	cout << "||\t\t\t[ERROR]\t\t\t\t||" << endl;
	cout << "**======================================================**" << endl;
	cout << "||\t\t\t\t\t\t\t||" << endl;
	cout << "||\t\tTidak ada dalam menu!!\t\t\t||" << endl;
	cout << "||\t  Untuk Kembali ke Menu Utama Tekan Enter\t||" << endl;
	cout << "||\t\t\t\t\t\t\t||" << endl;
	cout << "**======================================================**" << endl;
	getch();
	system("cls");
	main();
}
