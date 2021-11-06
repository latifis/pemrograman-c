#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;
typedef struct { long NIM;
					  char Nama[25];
					  char KodeMK[5];
					  int SKS;
					  char Indeks;
					} DataMhs;
FILE *ArsipMhs;
void RekamDataMahasiswa();
void CetakDaftarMhs();

int main()
{
  int pilih;
  do
  {
	 system("cls");
	 cout << "\nMENU";
	 cout << "\n1. Rekam Data Mhs";
	 cout << "\n2. Cetak Data Mhs";
	 cout << "\n3. Keluar";
	 cout << "\npilih = "; cin>>pilih;
	 switch (pilih)
	 {
		case 1 : system("cls");
					cout << "\nREKAM DATA MAHASISWA\n";
					RekamDataMahasiswa();
					break;
		case 2 : system("cls");
					CetakDaftarMhs();
					break;
		case 3 : system("cls");
					cout << "\nGOOD BYE.....";
	 }
  }
  while (pilih!=3);
}

void RekamDataMahasiswa()
{
  DataMhs Mhs;
  char namafile[20],jawaban;
  int sudah_benar;

  cout <<"file = "; cin>>namafile;fflush(stdin);
  if ((ArsipMhs = fopen(namafile,"w"))==NULL)
  {
	 cout<<"file tidak dapat diciptakan!";
	 exit(1);
  }
  do
  {
	 cout << "\nNIM : "; cin>>Mhs.NIM;
	 cout << "Nama : "; cin>>Mhs.Nama;
	 cout << "Kode MK : "; cin>>Mhs.KodeMK;
	 cout << "SKS : "; cin>>Mhs.SKS;
	 cout << "Nilai : "; cin>>Mhs.Indeks;
	 fwrite(&Mhs,sizeof(Mhs),1,ArsipMhs);

	 cout << "\nMau merekam data lagi [Y/T]?";
	 do {
		 jawaban = getchar(); fflush(stdin);
		 sudah_benar = ((jawaban=='Y')||(jawaban=='y')
			 ||(jawaban=='T')||(jawaban=='t'));
	 } while (!sudah_benar);

  }while (jawaban == 'y'|| jawaban=='Y');

  fclose(ArsipMhs);
}

void CetakDaftarMhs()
{
  int no;
  DataMhs Mhs;
  char namafile[20];
  cout <<"file = "; cin>>namafile;
  if ((ArsipMhs = fopen(namafile,"r"))==NULL)
  {
	 cout << "File tidak dapat dibuka\n";
	 exit(1);
  }

  cout << "DAFTAR MAHASISWA\n";
  cout << "---------------------------------------------\n";
  cout << "No. NIM    Nama   Mata Kuliah    SKS    Nilai\n";
  cout << "---------------------------------------------\n";
  no = 0;
  while (fread(&Mhs,sizeof(Mhs),1,ArsipMhs)==1)
  {
	  no++;
	  cout<<no<<setw(7)<<Mhs.NIM<<setw(7)<<Mhs.Nama<<setw(7)<<Mhs.KodeMK << setw(13) << Mhs.SKS << setw(9) << Mhs.Indeks << endl;
  }
  cout << "---------------------------------------------\n";

  fclose(ArsipMhs);
  getche();
}

