#include <iostream>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#define max 50
#define True 1
#define False 0
using namespace std;

void masuk();

typedef int typeinfo;
typedef string typeinfo2;
typedef struct typequeue *typeptr;
struct typequeue{
	typeinfo infojumlah;
	typeinfo2 infonama, infowarna;
	typeptr next;
};
typeptr qdepan, qbelakang;

struct Souvenir{
	char warna[10];
	int urutan;
};
Souvenir stockSouvenir[13], readySouvenir[4];

void buatqueue();
int queuekosong();
void enqueue(typeinfo2 IB, typeinfo IB2, typeinfo2 IB3);
void dequeue();
void cetakqueue();

void cetakstack();
void buatstack();	
void push(int IB);
void pop();
int stackkosong();
int stackpenuh();

int kapOrang=5, kapSouv=3;
int top=0, stack[max];

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
	
	int pilih;
	char keluar;
	buatqueue();
	//buatqueue2();
	buatstack();
	
	do
	{
		cout << "\n===============================";
		cout << "\nSisa orang yang boleh masuk = " << kapOrang; 
		cout << "\nTumpukan souvernir = " << kapSouv;
		cout << "\n===============================";
		cout << "\n\nMenu :";
		cout << "\n1. Masuk";
		cout << "\n2. Tamu yang Masuk";
		cout << "\n3. Antrian";
		cout << "\n4. Tamu Keluar";
		cout << "\n5. Souvernir";
		cout << "\n0. Keluar";
		
		cout << "\nPilih : "; cin >> pilih;
		
		switch (pilih)
		{
			case 1:
				masuk();
				main();
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				int menuSouvenir;
				cout << "Souvenir dimeja\n";
				bacaReadySouvenir();
				cout << "\n============\n";
				cout << "1. Push\n0. Kembali\nPilih : ";
				cin >> menuSouvenir;
				
				if(menuSouvenir == 1){
					pushReadySouvenir();
				}
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << "Tidak Ada dalam Menu";
		}
		cout << "Keluar dari Sistem ? (y/n)"; cin >> keluar; 
		
	} while (keluar=='Y' || keluar=='y');
	
}

void masuk(){
	string nama, warna="hijau";
	int jumlah;
	cout << "\nNama yang diundang : "; cin >> nama;
	cout << "Jumlah orang yang datang (max 2) : "; cin >> jumlah;
	
	enqueue(nama,jumlah,warna);
	kapOrang = kapOrang-jumlah;
	cout << kapOrang;
	cetakqueue();
}

//================ Void-void Queue orang di dalem

void buatqueue(){ 
	qdepan=(typequeue *) malloc(sizeof(typequeue));
	qdepan=NULL;
	qbelakang=qdepan;
}
int queuekosong(){ 
	if(qdepan==NULL)
		return(True);
	else
		return(False);
}
void enqueue(typeinfo2 IB, typeinfo IB2, typeinfo2 IB3){ 
	typeptr NB;
	NB=(typequeue *) malloc(sizeof(typequeue));  //iki
	NB->infonama=IB;
	NB->infojumlah=IB2;
	NB->infowarna=IB3;
	if (qdepan==NULL)
		qdepan=NB;
	else
		qbelakang->next=NB;
	qbelakang=NB;
	qbelakang->next=NULL;
}
void dequeue(){
	typeptr hapus;
	if (queuekosong())
	{
		cout << "Queue masih kosong !";
	}
	else
	{ 
		hapus=qdepan;
		qdepan=hapus->next;
		free(hapus); 
	}
}
void cetakqueue()
{
	typeptr bantu;
	bantu=qdepan;
	do { 
		cout << " " << bantu->infonama;
		cout << " " << bantu->infojumlah;
		cout << " " << bantu->infowarna;
		cout << " ";
		bantu=bantu->next;
	} while(bantu!=NULL);
}

//================ Void-void Queue orang di luar



//====================== Void-void stack
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

//================ Void-void stack

void cetakstack(){ 
	int i=1;
	while (i<=top)
	{ 
		cout << stack[i] << endl;
		i++; 
	}
}

void buatstack() { 
	stack[top]=0; }
	int stackkosong()
	{ 
		if(top==0)
			return(True);
		else
			return(False); 
	}
	int stackpenuh()
	{ 
		if(top==max)
			return(True);
		else
			return(False); 
	}
	
void push(int IB){ 
	if (stackpenuh())
		cout << "stack overflow\n";
	else
	{
		top++;
		stack[top]=IB;
		stack[0]=top; 
	} 
}

void pop(){ 
	int IP;
	if (stackkosong())
		cout << "stack underflow\n";
	else
	{
		IP=stack[top];
		top--;
		stack[0]=top; 
	} 
}
