#include <iostream>
#include <conio.h>
#define max 5
#define True 1
#define False 0
using namespace std;

//struct tamu

typedef struct typenode *typeptr;
struct tamu{
	string nama; int jml;};

struct typequeue{//deklarasi struct queue
	int belakang; tamu t[max]; 
};
string warna[9]={"merah","kuning","hijau""merah","kuning","hijau""merah","kuning","hijau"};

//pendeklarasian struct
struct STACK
{
      int top;
      string data[10];
};
float dta;

/*struct yang telah dibuat (STACK) dijadikan suatu Tipe data, dimana disebut tipe data abstrak*/
struct STACK stackbaru;
struct typequeue queue;

void makequeue();
int queuenull();
int queuefull();
void enqueue(string nama, int jml);
void masuk();
void daftartamu();
void antrian();
void tamukeluar();
void menusouvenir();
void push(float dta);
void print();
void pop();

int sisa=max, jmlsouvenir=3, pilih;
bool menu=true;

//fungsi boolean untuk mengetahui apakah stack kosong
bool isempty()
{
      if(stackbaru.top == -1)
            return true;
      else
            return false;
}

int main() {
	do{
		system("cls");
		cout<<"=================================="<<endl;
		cout<<"Sisa orang yang boleh masuk = "<<sisa<<endl;
		cout<<"Tumpukan souvenir = ";
		cout<<stackbaru.top;
		cout<<endl;
		cout<<"=================================="<<endl;
		cout<<"Menu :\n1. Masuk\n2. Tamu yang Masuk\n3. Antrian\n4. Tamu Keluar\n5. Souvenir\n0. Exit\n";
		cout<<"Pilih : ";cin>>pilih;
		switch(pilih) {
			case 1:
				masuk();
				break;
			case 2:
				daftartamu();
				break;
			case 3:
				antrian();
				break;
			case 4:
				tamukeluar();
				break;
			case 5:
				menusouvenir();
				break;
			case 0:
				menu=false;
				exit(0);
				break;
			default:
				cout<<"Pilihan yang Anda masukkan salah"<<endl;
				break;
		}
		cout<<endl;		
	}
	while(menu==true);
	return 0;
}

//create queue 
void makequeue(){
	queue.belakang=0; 
}

//cek queue kosong atau tidak 
int queuenull(){
	if(queue.belakang==0)
		return(True);
	else
		return(False);
}

//cek queue penuh atau tidak 
int queuefull(){
	if(queue.belakang==max)
		return(True);
	else
		return(False); 
}

void enqueue(string nama, int jml){ 
	if(queuefull())
		cout << "queue overflow\n";
	else{
		queue.belakang++;
		queue.t[queue.belakang].nama=nama; 
		queue.t[queue.belakang].jml=jml; 
	}
}

void masuk(){
	string tempnama;
	int tempjml;
	cout<<"Nama yang diundang : ";cin>>tempnama;
	cout<<"Jumlah orang yang datang : ";cin>>tempjml;
	if(tempjml<0 || tempjml>2) {
		cout<<"Maaf tidak boleh lebih dari 2"<<endl;
		cout<<"Jumlah orang yang datang : ";cin>>tempjml;
	}
	if(max>0) {
		enqueue(tempnama, tempjml);
		pop();	
	}
	else{
		cout<<"Sudah penuh, mohon mengantri dahulu"<<endl;
	}
}

void daftartamu(){
	
}
void antrian(){
	
}
void tamukeluar(){
	
}
void menusouvenir(){
	cout<<endl;
	print();
	cout<<"Menu :\n1. Push\n2. Exit\n";
	cout<<"Pilih : ";cin>>pilih;
	switch(pilih) {
			case 1:
				push(9);
				break;
			case 2:
				break;
	}
}
//fungsi untuk menambahkan data pada stack
void push(float dta)
{
        stackbaru.top=dta;
        for(int i=0; i<stackbaru.top; i++){
		stackbaru.data[i]=warna[i];
		}
            
            
}

void print()
{
    for(int i=0; i<=stackbaru.top; i++){
     	if(i==0){
        cout<<endl<<stackbaru.data[i];
    	}
      	else{
          cout<<stackbaru.data[i]<<endl;
    	}
  	}
}

void pop()
{
      if(isempty() == true) //panggil fungsi isempty(), jika kondisi benar pernyataan dijalankan
      {
            cout<<"Souvenir telah habis";
      }
      else
      {
            cout<<"Data yang terambil : " <<stackbaru.data[stackbaru.top]<<endl;
            stackbaru.top--;
      }
}
