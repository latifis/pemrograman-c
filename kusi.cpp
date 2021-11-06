#include <iostream>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#define true 1
#define false 0
using namespace std;

typedef string typeinfo;
typedef struct typenode *typeptr;
struct data_pendonor{
	typeinfo nama, goldar, status;
	int umur;
};

struct typenode{
	data_pendonor data;
	typeptr next;
}identitas;

typeptr awal,akhir;
void buatlistbaru();
void sisipnode(data_pendonor db);
void hapusnode(typeinfo hnama);
void bacamaju();
int listkosong();

int main()
{
	int pilih, banyak;
	cout << "\tUnit Pelayanan Tranfusi Darah\n\n";
	cout << "=============================================\n";
	cout << "Daftar Menu :\n";
	cout << " 1. Input Data Pendonor\n 2. Lihat Data Pendonor\n 3. Cek Kandidat Pendonor\n 4. Hapus Data Pendonor\n 5. Keluar\n";
	cout << "=============================================\n";
	cout << "Pilih	: "; cin >> pilih;
	system("cls");
	
	switch (pilih)
	{
		case 1:
			cout << "\tInput Data Pendonor\n";
			cout << "=============================================\n";
			cout << "Banyak data yang diinput : "; cin >> banyak;
			for (int i = 0; i < banyak; i++)
			{
				cout << " Data Ke-" << i+1 << endl;
				cout << " Nama Pendonor	 : "; cin.ignore(); getline(cin,identitas.data.nama);
				cout << " Umur		 : "; cin >> identitas.data.umur;
				cout << " Golongan Darah	: "; cin >> identitas.data.goldar;
				if (identitas.data.umur >= 17 && identitas.data.umur <= 60)
				{
					identitas.data.status = "Bisa Donor";
				}
				else
				{
					identitas.data.status = "Tidak Bisa Donor";
				}
				cout << " Status	: " << identitas.data.status;
				sisipnode(identitas.data);
			}
			break;
		default:
			cout << "Pilihan Anda Tidak Ada.... Silahkan Kembali Ke Menu Utama\n\n";
	}
}
	
int listkosong(){
	if(awal==NULL)
		return(true);
	else
		return(false);
}

void buatlistbaru(){
	typeptr list;
	list=NULL;
	awal=list;
	akhir=list;
}

void sisipnode(data_pendonor db){
	typeptr NB;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->data = db;
	NB->next = NULL;
	if (listkosong()){
		awal = NB;
		akhir = NB;
	}
	else{
		NB->next = awal;
		awal = NB;
	}
}
