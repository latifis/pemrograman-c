#include<iostream>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#define max 50
#define True 1
#define False 0

using namespace std;

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
	int menu;
	int menuSouvenir = 0;
	
	init();
	do{
		system("cls");
		cout << "===============================\n";
		cout << "Sisa orang yang boleh masuk = \n";
		cout << "Tumpukan souvenir = " << topReadySouvenir << endl;
		cout << "=================================\n";
		cout << "Menu:\n1. Masuk\n2. Tamu yang Masuk\n3. Antrian\n4. Tamu Keluar\n5. Souvenir\n0. Exit\nPilih : ";
		cin >> menu;
		cout << "\n\n";
		
		switch(menu){
			case 1:
				cout << menu;
				break;
			case 2:
				cout << menu;
				break;
			case 3:
				cout << menu;
				break;
			case 4:
				cout << menu;
				break;
			case 5:
				
				cout << "Souvenir dimeja\n";
				bacaReadySouvenir();
				cout << "\n============\n";
				cout << "1. Push\n0. Kembali\nPilih : ";
				cin >> menuSouvenir;
				
				if(menuSouvenir == 1){
					pushReadySouvenir();
				}
				
				system("pause");
				break;
			case 0:
				cout << menu;
				break;
		}
		
	} while(menu != 0);
}

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
