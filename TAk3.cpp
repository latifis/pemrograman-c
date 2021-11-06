#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#define True 1;
#define False 0;
using namespace std;

void pesan();
void daftar();
void import (int id, string nama, int bayar, int hari, int bulan, int tahun);
void eksport();

typedef char typeinfo;
typedef struct typequeue *typeptr;
struct typequeue{typeinfo info;
typeptr next;
};
typeptr qdepan, qbelakang;

void buatqueue();
int queuekosong();
void enqueue(typeinfo *IB);
void dequeue();
void cetakqueue();
void eksport(string file, int *tampil)
void import(string file, int batas);

struct data_tgl{
	int hari[100], bln[100], thn[100];
};

struct data_penyewa{
	int noIdentitasPelanggan[100];
	string nama;
	struct data_tgl tgl;
	int bayar[100];
};

struct data_penyewa penyewa;
struct data_penyewa temp;
string file;

/*typedef struct typetamu *typeptrtamu;
struct typetamu{
    string nama;
    int jumlah_orang;
    string warna;
    typeptrtamu next;
};*/

int main (){
	
	int pilih;
	char keluar;
	buatqueue();
	
	
	do
	{
		cout << "Menu";
		cout << "\n1. Pesan Tempat";
		cout << "\n2. Daftar Booking";
		cout << "\n3. Bayar";
		cout << "\n4. Riwayat Selesai Booking";
		cout << "\n5. Riwayat Pembayaran";
		cout << "\n0. Exit";
		cout << "\nPilih : "; cin >> pilih;
		
		switch (pilih)
		{
			case 1:
				pesan();
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << "Tidak Ada dalam Menu";
		}
		cout << "Kembali ke Menu ? (y/n)"; cin >> keluar; 
		system("cls");
		
	} while (keluar=='Y' || keluar=='y');
	
}

void pesan(){
	cout << "Masukkan : ";
	cout << "\n\n Id : "; cin >> temp.noIdentitasPelanggan[0];
	cout << " Nama : "; cin >> temp.nama;
	cout << " Bayar : "; cin >> temp.bayar[0];
	cout << " Tanggal : ";
	cout << "\n\t hari	: "; cin >> temp.tgl.hari[0];
	cout << "\t bulan	: "; cin >> temp.tgl.bln[0];
	cout << "\t tahun	: "; cin >> temp.tgl.thn[0];
	
	import(temp.noIdentitasPelanggan[0], temp.nama, temp.bayar[0], temp.tgl.hari[0], temp.tgl.bln[0], temp.tgl.thn[0]);
}

void daftar(){
	
}

void import (int id, string nama, int bayar, int hari, int bulan, int tahun)
{
	ofstream tulis;
	string namafile = file;
	
	tulis.open(namafile.c_str(), ios::app);
	
	tulis << id << endl;
	tulis << nama << endl;
	tulis << bayar << endl;
	tulis << hari << endl;
	tulis << bulan << endl;
	tulis << tahun << endl;
	
	tulis.close();
}

void eksport(string file, int *tampil)
{
		ifstream baca;
		string namafile=file;
		
		baca.open(namafile);
		
		for(int i=0; true; i++)
		{
			getline(baca,wni[i].nik);
			getline(baca,wni[i].nama);
			getline(baca,wni[i].goldar);
			getline(baca,wni[i].jenkel);
			getline(baca,wni[i].asal);
			if(baca.eof()){
				*tampil=i;
				break;
			}
		}
		baca.close();
}

void import(string file, int batas)
{
		ofstream tulis;
		string namafile=file;
		
		tulis.open(namafile.c_str(), ios::app);
		for (int i=0; i<batas; i++){
			tulis << wni[i].nik << endl; 
			tulis << wni[i].nama << endl;
			tulis << wni[i].goldar << endl;
			tulis << wni[i].jenkel << endl;
			tulis << wni[i].asal << endl;	
		}
		tulis.close();	

		main();
}


void buatqueue()
{ 
	qdepan=(typequeue *) malloc(sizeof(typequeue));
	qdepan=NULL;
	qbelakang=qdepan;
}

int queuekosong()
{ 
	
}
void enqueue(typeinfo *IB)
{ 
	typeptr NB;
	NB=(typequeue *) malloc(sizeof(typequeue));
	NB->info=*IB;
	if (qdepan==NULL)
		qdepan=NB;
	else
		qbelakang->next=NB;
	qbelakang=NB;
	qbelakang->next=NULL;
}

void dequeue()
{
	typeptr hapus;
	if (queuekosong())
	{
	cout << "Queue masih kosong !";
	}
	else
	{ hapus=qdepan;
	qdepan=hapus->next;
	free(hapus); }
}
void cetakqueue()
{
	typeptr bantu;
	bantu=qdepan;
	do { 
		cout << " " << bantu->info;
		cout << " ";
		bantu=bantu->next;
	} while(bantu!=NULL);
}
// pindahan TA
void eksport(){
	int pilih;
	
	cout << "\nMenu Load Data";
	cout << "\n	1. Load Data Antrian";
	cout << "\n	2. Load Riwayat Penyewaan";
	cout << "\n	3. Load Riwayat Pembayaran";
	cout << "\n	0. Kembali ke Menu";
	cout << "\n\n	Pilih : "; cin >> pilih;
	
	switch (pilih)
	{
		case 1:
			cout << "gaa ada isi, gabisa jalan";//eksportDataAntrian();
			break;
		case 2:
			cout << "gaa ada isi, gabisa jalan";//eksportRiwayatPenyewaan();
			break;
		case 3:
			cout << "gaa ada isi, gabisa jalan";//eksportRiwayatPembayaran();
			break;
		case 0:
			break;
		default:
			cout << "Tidak ada dalam Menu";
	}
	
}
