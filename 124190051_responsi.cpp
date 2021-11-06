#include <iostream>
#include <string.h>
#include <malloc.h>
#define max 50
#define true 1
#define false 0
using namespace std;
//queue=================================================================
typedef string typeinfo;
typedef struct typequeue *typeptr;
struct dataTamu{
	typeinfo nama;
	int jumlah;
};
struct typequeue{
	dataTamu data;
	typeptr next;
};
typeptr qdepan, qbelakang;
typequeue info;

void buatqueue();
int queuekosong();
void enqueue(dataTamu IB);
void dequeue();
void cetakqueue();
//======================================================================

//souvenir==============================================================
struct Souvenir{
	char warna[10];
	int urutan;
};

Souvenir stock[13], ready[4];

int topStock = 0;
int topReady = 0;


void awal();
void bacaStock();
void pushSouvenir();
int souvenirFull();
int souvenirKosong();
int stockKosong();
void bacaReady();
//======================================================================

int main()
{
	int pilih;
	
	do
	{
		cout << "=====================================\n";
		cout << "Sisa orang yang boleh masuk = " << endl;
		cout << "Tumpukan souvenir = " << endl;
		cout << "=====================================\n";
		cout << "Menu	:\n";
		cout << "1. Masuk\n2. Tamu yang masuk\n3. Antrian\n4. Tamu keluar\n5. Souvenir\n6. Exit\n";
		cout << "Pilih	: "; cin >> pilih;
		switch (pilih)
		{
			case 1:
				cout << "Nama yang diundang	: "; cin.ignore(); getline(cin,info.data.nama);
				cout << "Jumlah orang yang datang	: "; cin >> info.data.jumlah;
				enqueue(info.data);
				break;
			case 2:
				cetakqueue();
				break;
			case 6:
				exit(0);
				break;
		}
	} while (pilih <= 6);
	

}
//Void QUEUE------------------------------------------------------------
void buatqueue(){
	qdepan=(typequeue *) malloc(sizeof(typequeue));
	qdepan=NULL;
	qbelakang=qdepan;
}

void cetakqueue(){
	typeptr bantu;
	bantu=qdepan;
	do{
		cout << " " << bantu->data.nama;
		cout << " ";
		bantu=bantu->next;
	}while(bantu!=NULL);
}

int queuekosong(){
	if(qdepan==NULL)	
		return(true);
	else
		return(false);
}

void enqueue(dataTamu IB){
	typeptr NB;
	NB=(typequeue *) malloc(sizeof(typequeue));
	NB->data=IB;
	if (qdepan==NULL)
		qdepan=NB;
	else{
		qbelakang->next=NB;
		qbelakang=NB;
		qbelakang->next=NULL;
	}
}

void dequeue(){
	typeptr hapus;
	if (queuekosong()){
		cout << "Queue masih kosong !";
	}
	else{
		hapus=qdepan;
		qdepan=hapus->next;
		free(hapus);
	}
}
//----------------------------------------------------------------------

//Void souveir----------------------------------------------------------
void awal(){
	topStock = 12;
	for (int i = 1; i <= 12; i+=3){
		strcpy(stock[i].warna, "Merah");
		strcpy(stock[i+1].warna, "Kuning");
		strcpy(stock[i+2].warna, "Hijau");
	}
	
	pushSouvenir();
	pushSouvenir();
	pushSouvenir();
}

void pushSouvenir(){
	if(souvenirFull()){
		cout << "Souvenir dimeja sudah penuh";
		return;
	}
	else if(souvenirKosong()){
		cout << "Stock souvenir habis";
		return;
	}
	else {
		topReady++;
		strcpy(ready[topReady].warna, stock[topStock].warna);
		topStock--;
		
		ready[0].urutan = topReady;
		stock[0].urutan = topStock;
		
		cout << "\nPush berhasil";
	}
}

int souvenirFull(){
	if(topReady == 3){
		return(true);
	}
	else {
		return(false);
	}
}

int souvenirKosong(){
	if(topReady == 0){
		return(true);
	}	
	else {
		return(false);
	}
}

int stockKosong(){
	if(topStock == 0){
		return(true);
	}	
	else {
		return(false);
	}
}

void bacaStock(){
	int i = topStock;
	
	if(stockKosong()){
		cout << "Stock souvenir habis";
		return;
	}
	else {
		while(i > 0){
			cout << stock[i].warna << endl;
			i--;
		}	
	}
}

void bacaReady(){
	int i = topReady;
	
	if(souvenirKosong()){
		cout << "Souvenir dimeja habis, push dulu";
		return;
	}
	else {
		while(i > 0){
			cout << ready[i].warna << endl;
			i--;
		}	
	}
}
