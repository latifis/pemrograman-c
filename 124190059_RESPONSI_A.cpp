#include <iostream>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#define max 50
#define True 1
#define False 0

using namespace std;

//Queue
typedef string typeinfo;
typedef struct typequeue *typeptr;
struct datatamu{
	typeinfo nama;
	int jumlah;
};
struct typequeue{
	datatamu data;
	typeptr next;
};
typeptr depan, belakang;
typequeue a;
int stoktamu = 5;

void buatqueue();
int queuekosong();
void enqueue(datatamu IB);
void dequeue();
void cetakqueue();

//Souvenir
struct Souvenir{
	char warna[10];
	int urutan;
};

Souvenir stockSouvenir[13], readySouvenir[4];

int topStockSouvenir = 0;
int topReadySouvenir = 0;

void init();
void bacaStockSouvenir();
void pushReadySouvenir();
int readySouvenirFull();
int readySouvenirEmpty();
int stockSouvenirEmpty();
void bacaReadySouvenir();

int main(){
	
	int pilih, pilih2 = 0;
	init();
	
	do{
		system("cls");
		cout<<"==========================================\n";
		cout<<"Sisa orang yang boleh masuk	: "<< stoktamu;
		cout<<"\nTumpukan Souvenir 		: " << topReadySouvenir;
		cout<<"\n==========================================\n";
		cout<<"Menu :\n 1. Masuk\n 2. Tamu yang masuk\n 3. Antrian\n 4. Tamu keluar\n 5. Souvenir\n 0. Exit\n";
		cout<<"Pilih : "; cin>>pilih;  cin.ignore(); 
	
		switch (pilih){
			case 1:
				cout<<endl;
				if (topReadySouvenir > 0){
					cout<<"Nama yang diundang : "; getline(cin,a.data.nama);
					cout<<"Jumlah orang yang datang : "; cin>>a.data.jumlah; 
					enqueue(a.data);
					system("pause");
				}
				else{
					cout << "Isi Souvenir" << endl;
				}
				stoktamu -= a.data.jumlah;
				cout<<endl;
				break;
			case 2:
				cout<<endl;
				cetakqueue();
				cout<<endl;
				system ("pause");
				break;
			case 3:
				cout<<endl;
				cout<<"Fitur menyusul";
				break;
			case 4:
				cout<<endl;
				break;
			case 5: 
				cout<<endl;
				cout << "Souvenir dimeja :\n";
				bacaReadySouvenir();
				cout << "\n============\n";
				cout << "1. Push\n0. Kembali\nPilih : ";
				cin >> pilih2;
				
				if(pilih2 == 1){
					pushReadySouvenir();
				}
				
				system("pause");
				break;
			case 0:
				exit(0);
				break;
		}
	} while (pilih != 0);
}

//QUEUE
void buatqueue(){
	depan=(typequeue *) malloc(sizeof(typequeue));
	depan=NULL;
	belakang=depan;
}

void cetakqueue(){
	typeptr bantu;
	bantu=depan;
	do{
		cout << "Nama Undangan : " << bantu->data.nama;
		cout << "\nJumlah Anggota :" << bantu->data.jumlah;
		bantu=bantu->next;
	}while(bantu!=NULL);
}

int queuekosong(){
	if(depan==NULL)	
		return(true);
	else
		return(false);
}

void enqueue(datatamu IB){
	typeptr NB;
	NB=(typequeue *) malloc(sizeof(typequeue));
	NB->data=IB;
	if (depan==NULL)
		depan=NB;
	else{
		belakang->next=NB;
		belakang=NB;
		belakang->next=NULL;
	}
}

void dequeue(){
	typeptr hapus;
	if (queuekosong()){
		cout << "Queue masih kosong !";
	}
	else{
		hapus=depan;
		depan=hapus->next;
		free(hapus);
	}
}

//SOUVENIR
void init(){
	topStockSouvenir = 12;
	for (int i = 1; i <= 12; i+=3){
		strcpy(stockSouvenir[i].warna, "Merah");
		strcpy(stockSouvenir[i+1].warna, "Kuning");
		strcpy(stockSouvenir[i+2].warna, "Hijau");
	}
	
	pushReadySouvenir();
	pushReadySouvenir();
	pushReadySouvenir();
}

void bacaStockSouvenir(){
	int i = topStockSouvenir;
	
	if(stockSouvenirEmpty()){
		cout << "Stock souvenir habis";
		return;
	}
	else {
		while(i > 0){
			cout << stockSouvenir[i].warna << endl;
			i--;
		}	
	}
}

int readySouvenirFull(){
	if(topReadySouvenir == 3){
		return(True);
	}
	else {
		return(False);
	}
}

int readySouvenirEmpty(){
	if(topReadySouvenir == 0){
		return(True);
	}	
	else {
		return(False);
	}
}

int stockSouvenirEmpty(){
	if(topStockSouvenir == 0){
		return(True);
	}	
	else {
		return(False);
	}
}

void pushReadySouvenir(){
	if(readySouvenirFull()){
		cout << "Souvenir dimeja sudah penuh";
		return;
	}
	else if(stockSouvenirEmpty()){
		cout << "Stock souvenir habis";
		return;
	}
	else {
		topReadySouvenir++;
		strcpy(readySouvenir[topReadySouvenir].warna, stockSouvenir[topStockSouvenir].warna);
		topStockSouvenir--;
		
		readySouvenir[0].urutan = topReadySouvenir;
		stockSouvenir[0].urutan = topStockSouvenir;
		
		cout << "\nPush berhasil";
	}
}

void bacaReadySouvenir(){
	int i = topReadySouvenir;
	
	if(readySouvenirEmpty()){
		cout << "Souvenir dimeja habis, push dulu";
		return;
	}
	else {
		while(i > 0){
			cout << readySouvenir[i].warna << endl;
			i--;
		}	
	}
}
