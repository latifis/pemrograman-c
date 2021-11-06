#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#define True 1
#define False 0
using namespace std;

typedef int typeinfo;
typedef string infostring;
typedef struct node *typeptr;
struct node{ //node queue (buat input)
	typeinfo noIdentitasPelanggan, tgl, thn, lamaMain;
	infostring nama, bln, jam;
	typeptr prev;
	typeptr next; 
};
typeptr awal,akhir;

typedef int typeinfo2;
typedef string infostring2;
typedef struct node2 *typeptr2;
struct node2{ //node stack (buat tampil dan hapus)
	typeinfo2 bayar, noIdentitasPelanggan, tgl, thn, lamaMain;
	infostring2 nama, bln, jam;
	typeptr2 prev;
	typeptr2 next; 
};
typeptr2 top, bottom;

string file;
int bantuu[2];
int cekBayar=0;
int queuekosong();
int stackkosong();
int convertString(string);
	
void pesan();
void bayar();
void cetakstackRiwayatBayar();
	
void buatqueue();
void enqueue(typeinfo IB, infostring IB2, typeinfo IB3, infostring IB4, typeinfo IB5, typeinfo IB6, infostring IB7);
void dequeue();
void cetakqueue();

void buatstack();
void push(typeinfo2 IB, infostring2 IB2, typeinfo2 IB3, infostring2 IB4, typeinfo2 IB5, typeinfo2 IB6, infostring2 IB7);
void cetakstack();

void import();
void importDataAntrian();
void importRiwayatPenyewaan();
void importRiwayatPembayaran();


int main (){
	
	int pilih;
	char keluar;
	buatqueue();
	buatstack();
	
	
	do
	{
		cout<<"=============================================\n";
		cout<<"||           BOOKING LAPANGAN FUTSAL       ||\n";
		cout<<"=============================================\n";
		
		cout << "\n	1. Pesan Tempat";
		cout << "\n	2. List Antrian";
		cout << "\n	3. Proses Penyewaan Selesai";
		cout << "\n	4. Bayar";
		cout << "\n	5. Riwayat Penyewaan";
		cout << "\n	6. Riwayat Pembayaran";
		cout << "\n	7. Save Data";
		cout << "\n	0. Exit";
		cout << "\n\n	Pilih : "; cin >> pilih; cout << endl;
		
		cout<<"=============================================\n\n";
		
		switch (pilih)
		{
			case 1:
				pesan();
				break;
			case 2:
				//cetak list antrian di dalam queue
				cetakqueue();
				break;
			case 3:
				//proses dequeue dan pindah ke riwayat / stack
				dequeue();
				cout << "  [ Penyewaan Pada Antrian Pertama Selesai ]\n\n";
				break;
			case 4:
				//proses pencarian dalam stack untuk bayar
				bayar();
				break;
			case 5:
				//cetak stack
				cetakstack();
				break;
			case 6:
				//cetak stack riwayat pembayaran
				cetakstackRiwayatBayar();
				break;
			case 7:
				//operasi file simpan data
				import();
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << "\t[ Tidak ada Dalam Menu ]\n\n";
		}
		cout << "Kembali ke Menu ? (y/n)"; cin >> keluar; 
		system("cls");
		
	} while (keluar=='Y' || keluar=='y');
	
}

void pesan(){// menginput data 
	typeinfo noIdentitasPelanggan, tgl, thn,lamaMain;
	infostring nama, bln, jam;
	char pilih;
	
	if(queuekosong()==1){
		buatqueue();
		}
		
	cout << "Masukkan ";
	cout << "\n\n Id		: "; cin >> noIdentitasPelanggan;
	cout << " Nama		: "; cin.ignore(); getline(cin,nama);
	cout << " Tanggal	 ";
	cout << "\n   -> tanggal	: "; cin >> tgl;
	cout << "   -> bulan	: "; cin >> bln;
	cout << "   -> tahun	: "; cin >> thn;
	cout << " Lama main	: "; cin >> lamaMain;
	cout << " Jam main	: "; cin.ignore(); getline(cin,jam);
	
	enqueue(noIdentitasPelanggan, nama, tgl, bln, thn, lamaMain, jam);
	
	cout << "\nInput Lagi ? (y/n) ";
	cin >> pilih;
	
	if(pilih=='Y' || pilih=='y')
	{
		pesan();
	}
}

void import(){
	int pilih;
	
	cout << "\nMenu Save Data";
	cout << "\n	1. Save Data Antrian";
	cout << "\n	2. Save Riwayat Penyewaan";
	cout << "\n	3. Save Riwayat Pembayaran";
	cout << "\n	0. Kembali ke Menu";
	cout << "\n\n	Pilih : "; cin >> pilih;
	
	switch (pilih)
	{
		case 1:
			importDataAntrian();
			break;
		case 2:
			importRiwayatPenyewaan();
			break;
		case 3:
			importRiwayatPembayaran();
			break;
		case 0:
			break;
		default:
			cout << "Tidak ada dalam Menu";
	}
	
}

void importDataAntrian(){ //Input Data Antrian		
	
	if (queuekosong()==true)     
	{
		cout << "\t[ Belom ada Antrian ]\n\n";
	}
	else
	{
		ofstream tulis;
		string namafile = "dataAntrian.txt";
		
		typeptr bantu;
		bantu = awal;
		
		tulis.open(namafile.c_str(), ios::app);
					
		do { 
			tulis << bantu->noIdentitasPelanggan << endl; 
			tulis << bantu->nama << endl;
			tulis << bantu->tgl << endl;
			tulis << bantu->bln << endl;
			tulis << bantu->thn << endl;	
			tulis << bantu->lamaMain << endl;	
			tulis << bantu->jam << endl;	
			bantu = bantu->next;
		} while(bantu != NULL);
		
		tulis.close();
		
		cout << "\t[ Import Data Antrian Berhasil ]\n\n";
	}	
}

void importRiwayatPenyewaan(){  //Input Riwayat Penyewaan
	
	if (stackkosong()==true)  
	{
		cout << "\t[ Belom ada Penyewaan yang Selesai ]\n\n";
	}
	else
	{
		ofstream tulis;
		string namafile = "dataRiwayatPenyewaan.txt";
		
		typeptr2 bantu;
		bantu = top;
		
		tulis.open(namafile.c_str(), ios::app);
					
		while(bantu!=NULL){
			tulis << bantu->noIdentitasPelanggan << endl; 
			tulis << bantu->nama << endl;
			tulis << bantu->tgl << endl;
			tulis << bantu->bln << endl;
			tulis << bantu->thn << endl;	
			tulis << bantu->lamaMain << endl;	
			tulis << bantu->jam << endl;	
			bantu = bantu->prev;
		};
		
		tulis.close();
		
		cout << "\t[ Import Riwayat Penyewaan Berhasil ]\n\n";
	}		
}

void importRiwayatPembayaran(){ //Input Riwayat Pembayaran
	
	bantuu[0]=1;
	
	if (stackkosong()==true)  
	{
		cout << "\t[ Belom ada Pembayaran yang Selesai ]\n\n";
	}
	else
	{
		ofstream tulis;
		string namafile = "dataRiwayatPembayaran.txt";
		
		typeptr2 bantu;
		bantu = top;
		
		tulis.open(namafile.c_str(), ios::app);
					
		while (bantu!=NULL){
			tulis << bantu->noIdentitasPelanggan << endl; 
			tulis << bantu->nama << endl;
			tulis << bantu->bayar << endl;
			bantu = bantu->prev;
		};
		
		tulis.close();
		
		cout << "\t[ Import Riwayat Pembayaran Berhasil ]\n\n";
	}		
}

int queuekosong(){ //mengecek queue kosong atau tidak
	if(awal == NULL)
		return(true);
	else
		return(false); 
}

int stackkosong(){ //mengecek stack kosong atau tidak 	
	if(top == NULL)
		return(true);
	else
		return(false); 
}

void buatqueue(){
	awal = NULL; 
	akhir = NULL; 
}

void buatstack(){
	bottom = NULL; 
	top = NULL;
}

void enqueue(typeinfo IB, infostring IB2, typeinfo IB3, infostring IB4, typeinfo IB5, typeinfo IB6, infostring IB7) //penyisipan queue dengan sisip belakang
{
	typeptr NB;
	NB = new node;
	NB->noIdentitasPelanggan = IB;
	NB->nama = IB2;
	NB->tgl = IB3;
	NB->bln = IB4;
	NB->thn = IB5;
	NB->lamaMain = IB6;
	NB->jam = IB7;
	
	NB->prev = NULL;
	NB->next = NULL;
	
	if (awal==NULL)
	{	
		awal=NB;
		akhir=NB;
	}
	else
	{ 
		akhir->next = NB;
		NB->prev = akhir;
	}
	akhir = NB;
}

void dequeue(){ //data pertama yang masuk queue akan di ubah ke stack, kemudian data queue tersebut di hapus
	
	typeptr hapus;
	
	if (queuekosong())
	{
		cout << "\t[ Belom ada Antrian ]\n\n";
	}
	else   //mengubah data queue menjadi stack
	{ 
		hapus = awal;
		push(hapus->noIdentitasPelanggan, hapus->nama, hapus->tgl, hapus->bln, hapus->thn, hapus->lamaMain, hapus->jam);
		awal = hapus->next;
		free(hapus); 
	}
	
}

void cetakqueue()
{
	if (queuekosong()==true)
	{
		cout << "\t[ Belom ada Antrian ]\n\n";
	}
	else
	{
		typeptr bantu;
		bantu = awal;
			
		cout<<"                =========================================================="<< endl;
		cout<<"                ||          LIST ANTREAN BOOKING LAPANGAN FUTSAL        ||"<< endl;
		cout<<"                =========================================================="<< endl;
		cout<< setw(12)<< "==============================================================================================="<< endl;
		cout<< setw(12)<< "No Pelanggan"<< setw(20)<< "Nama Pembooking"<< setw(25)<< "Tanggal"<< setw(20)<< "Lama Main" << setw(15)<< "Jam\n";
		
		do { 
			cout << setw(12) << "==============================================================================================="<< endl;
			cout << setw(12) << bantu->noIdentitasPelanggan;
			cout << setw(20) << bantu->nama;
			cout << setw(12) << bantu->tgl << setw(8) << bantu->bln << setw(5) << bantu->thn;
			cout << setw(20) << bantu->lamaMain;
			cout << setw(15) << bantu->jam;
			cout << endl;
			bantu = bantu->next;
		} while(bantu != NULL);
		cout<< setw(12)<< "==============================================================================================="<< endl;
	}	
}

void cetakstack(){ //mencetak data pembooking lapangan futsal
	
	if (stackkosong()==true)
	{
		cout << "\t[ Belom ada Proses yang Selesai ]\n\n";
	}
	else
	{
		typeptr2 bantu;
		bantu = top;
		
		cout<<"                =========================================================="<< endl;
		cout<<"                ||          LIST RIWAYAT BOOKING LAPANGAN FUTSAL        ||"<< endl;
		cout<<"                =========================================================="<< endl;
		cout<< setw(12)<< "==============================================================================================="<< endl;
		cout<< setw(12)<< "No Pelanggan"<< setw(20)<< "Nama Pembooking"<< setw(25)<< "Tanggal"<< setw(20)<< "Lama Main" << setw(15)<< "Jam\n";
		
		while (bantu!=NULL)
			{	
				cout << setw(12) << "==============================================================================================="<< endl;
				cout << setw(12) << bantu->noIdentitasPelanggan;
				cout << setw(20) << bantu->nama;
				cout << setw(12) << bantu->tgl << setw(8) << bantu->bln << setw(5) << bantu->thn;
				cout << setw(20) << bantu->lamaMain;
				cout << setw(15) << bantu->jam;
				cout << endl;
				bantu = bantu->prev;	
			}
		cout<< setw(12)<< "==============================================================================================="<< endl;
	
	}
}

void cetakstackRiwayatBayar(){ //mencetak data pembayaran
	
	if (stackkosong()==true || cekBayar==0)
	{
		cout << "\t[ Belom ada Proses Pembayaran ]\n";
		cout << " [ Lakukan Pembayaran Setelah Proses Selesai ]\n\n";
	}
	else
	{
		typeptr2 bantu;
		bantu = top;
		
		cout<<"         =========================================================="<< endl;
		cout<<"         ||          PEMBAYARAN PENYEWAAN LAPANGAN FUTSAL        ||"<< endl;
		cout<<"         =========================================================="<< endl;
		cout<< setw(12)<< "=============================================================================="<< endl;
		cout<< setw(12)<< "No Pelanggan"<< setw(20)<< "Nama Pembooking"<< setw(25)<< "Nominal Bayar\n";
		
		while (bantu!=NULL)
		{	
			cout << setw(12) << "==============================================================================="<< endl;
			cout << setw(12) << bantu->noIdentitasPelanggan;
			cout << setw(20) << bantu->nama;
			cout << setw(25) << bantu->bayar;
			cout << endl;
			bantu = bantu->prev;	
		}
		cout<< setw(12)<< "==============================================================================="<< endl;
	
	}
}

void push(typeinfo2 IB, infostring2 IB2, typeinfo2 IB3, infostring2 IB4, typeinfo2 IB5, typeinfo2 IB6, infostring2 IB7){ //penyisipan stack yang berasal dari queue
	typeptr2 NB;
	NB=new node2;
	
	NB->noIdentitasPelanggan = IB;
	NB->nama = IB2;
	NB->tgl = IB3;
	NB->bln = IB4;
	NB->thn = IB5;
	NB->lamaMain = IB6;
	NB->jam = IB7;
	
	NB->prev = NULL;
	NB->next = NULL;
	
	if (top==NULL)
	{	
		top = NB;
		bottom = NB;
	}
	else
	{ 
		top->next = NB;
		NB->prev = top;
	}
	top = NB;	
}

void bayar(){
	
	int idBayar;
	
	if (stackkosong()==true)
	{
		cout << "\t[ Belom ada Proses yang Selesai ]\n";
		cout << " [ Lakukan Pembayaran Setelah Proses Selesai ]\n\n";
	}
	else
	{
		cout << "\nMasukkan Id Pelanggan untuk melakukan pembayaran : "; cin >> idBayar;
		
		typeptr2 bantu;
		bantu = top;
				
		while (bantu!=NULL)
		{	
			if (idBayar==bantu->noIdentitasPelanggan)
			{
				cout << "Masukkan Nominal Bayar : "; cin >> bantu->bayar;
			}
			bantu = bantu->prev;	
		}
		cekBayar=1;	
	}
}


/*
 KELENGKAPAN MATERI 
 
	Materi Algo 1 :
		Percabangan (if)
		Perulangan (do-while, while)
		Fungsi (void, int)
		
	Materi Algo 2 :
		Struct dan Array (Struct node1, node2, Array 1D buat variabel bantu)
		Pencarian Data (Cari Id buat bayar)
		Pointer (dipakai pas buat stack dan queue dengan list)
		Operasi File (buat eksport dan import data)
		
	Struktur Data :
		Linked list (dipakai pas buat stack dan queue dengan list)
		Stack (buat mendata riwayat pembayaran, riwayat proses selesai, dan riwayat penyewaans)
		Queue (buat antrian penyewa)
 */
