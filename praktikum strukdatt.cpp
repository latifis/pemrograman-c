#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#define True 1
#define False 0
using namespace std;

typedef int typeinfo;
typedef string infostring;
typedef struct node *typeptr;
struct node{ //node queue (buat input)
	typeinfo no_pas, umur;
	infostring nama_pas, jk;
	typeptr prev;
	typeptr next; 
	};
	typeptr awal,akhir;
	
typedef int typeinfo2;
typedef string infostring2;
typedef struct node2 *typeptr2;
struct node2{ //node stack (buat tampil dan hapus)
	typeinfo2 no_pas, umur;
	infostring2 nama_pas, jk;
	typeptr2 prev;
	typeptr2 next; 
	};
	typeptr2 top,bottom;
	
void input(); // meyisipkan data pasien
void buatqueue();
void buatstack();
void enqueue(typeinfo IB,infostring IB2,infostring IB3,typeinfo IB4);
void push(typeinfo2 IB,infostring2 IB2,infostring2 IB3,typeinfo2 IB4);
void dequeue();
void pop();
int queuekosong() //mengecek queue kosong atau tidak
{ if(awal == NULL)
    return(true);
  else
    return(false); }
int stackkosong() //mengecek stack kosong atau tidak
{ if(top == NULL)
    return(true);
  else
    return(false); }

void cetakstack(); //mencetak data pasien

char FileName[20];

int main(){
	//main menu
	int pilih1;
	system("cls");
	cout<<"=============================================\n";
	cout<<"||           RUMAH SAKIT JOGJA             ||\n";
	cout<<"=============================================\n";
	cout<<"1. Masukan data pasien\n";
	cout<<"2. Proses data\n";
	cout<<"3. Tampilkan data pasien\n";
	cout<<"4. Hapus data pasien\n";
	cout<<"5. Save File\n";
	cout<<"6. Load File\n";
	cout<<"0. Exit\n\n";
	cout<<"Pilih : ";
	cin>>pilih1;
	if(pilih1==1){
		input();
	}
	if(pilih1==2){
		dequeue();
	}
	if(pilih1==3){
		cetakstack();
	}
	if(pilih1==4){
		pop();
	}
	if(pilih1==5){ //menyimpan file
		system("cls");
		cout<<"=============================================\n";
		cout<<"||               SAVE FILE                 ||\n";
		cout<<"=============================================\n";
		cout << "\nMasukkan Nama File : ";cin >> FileName;
		ofstream file;
		file.open(FileName);
		if(!file.is_open())
			{
				cout << "\nFile tidak bisa dibuat.."; 
				char pilih;
				cout<<"\n\nKembali ?\n";
				cout<<"Pilih (y/n) : "; 
				cin>>pilih;
				if(pilih=='y'){main();}
				if(pilih=='n'){exit(0);}	
			}
			
			typeptr2 bantu;
			bantu=top;
			string check="go";

			while (bantu!=NULL)
				{
					file<<"end"<<" ";//tanda file data pasien ada
					file<<bantu->no_pas<<" "<<bantu->nama_pas<<" "<<bantu->jk<<" "<<bantu->umur<<" ";
					bantu=bantu->prev;	
				}
							
		file.close();
	}
	if(pilih1==6){//memuat file
		
		system("cls");
		cout<<"=============================================\n";
		cout<<"||               LOAD FILE                 ||\n";
		cout<<"=============================================\n";
		infostring nama_pas,jk;
		typeinfo no_pas,umur;
		cout << "\nMasukkan Nama File : ";cin >> FileName;
		ifstream file;
		file.open(FileName);
		if(!file.is_open())
		{
			cout << "File tidak ada"; 
			char pilih;
			cout<<"\n\nKembali ?\n";
			cout<<"Pilih (y/n) : "; 
			cin>>pilih;
			if(pilih=='y'){main();}
			if(pilih=='n'){exit(0);}	
		}

		stackkosong();//mengecek stack jika kosong
		if(stackkosong()==1){
		buatstack();
		}
		string check; //Untuk mengecek file, apakah sudah masuk data pasiennya
		while(!file.eof()){
			file>>check;
			cout<<check;

			if(check=="end"){
			file>>no_pas;
			file>>nama_pas; 
			file>>jk;
			file>>umur;  
			
			push(no_pas,nama_pas,jk,umur);}
		}
			//menghapus data pasien yang ganda
			typeptr2 ambil;
			if(top!=bottom){
			ambil=top;
			top=top->prev;
			free(ambil);
			top->next=NULL;
		    }
		file.close();
	}
	if(pilih1== 0){exit(0);}
	main();
}

void input(){// menginput data pasien 

	typeinfo no_pas,umur;
	infostring nama_pas,jk;
	char pilih='y';
	if(queuekosong()==1){
		buatqueue();
		}
	while(pilih=='y'){	
	system("cls");
	
	cout<<"Masukkan nomor pasien : ";
	cin>>no_pas;
	
	cout<<"Masukkan nama pasien : ";cin.ignore();
	getline(cin,nama_pas);
	
	cout<<"Masukkan jenis kelamin : ";cin.ignore();
	getline(cin,jk);
	
	cout<<"Masukkan umur pasien : ";
	cin>>umur;
	
	
	enqueue(no_pas,nama_pas,jk,umur);
	
	cout<<"\n\nInput lagi?\n";
	cout<<"Pilih (y/n) : "; 
	cin>>pilih;
	}
	main();
}
void buatqueue()
{	  awal = NULL; 
	  akhir = NULL; 
}
 void buatstack()
{ 	  bottom = NULL; 
	  top = NULL;
}
void enqueue(typeinfo IB,infostring IB2,infostring IB3,typeinfo IB4) //penyisipan queue dengan sisip belakang
{
	typeptr NB;
	NB=new node;
	NB->no_pas=IB;
	NB->nama_pas=IB2;
	NB->jk=IB3;
	NB->umur=IB4;
	NB->prev=NULL;
	NB->next=NULL;
	if (awal==NULL)
	{	awal=NB;
		akhir=NB;
	}
	else
	{ akhir->next=NB;
	  NB->prev=akhir;
	}
	akhir=NB;
}
void push(typeinfo2 IB,infostring2 IB2,infostring2 IB3,typeinfo2 IB4){ //penyisipan stack yang berasal dari queue
	typeptr2 NB;
	NB=new node2;
	NB->no_pas=IB;
	NB->nama_pas=IB2;
	NB->jk=IB3;
	NB->umur=IB4;
	NB->prev=NULL;
	NB->next=NULL;
	if (top==NULL)
	{	top=NB;
		bottom=NB;
	}
	else
	{ top->next=NB;
		NB->prev=top;
	}
	top=NB;	
}
void dequeue(){ //data pertama yang masuk queue akan di ubah ke stack, kemudian data queue tersebut di hapus
	typeptr ambil;
	if(awal==akhir){//mengubah data queue menjadi stack
		ambil=awal;
		awal=NULL;
		akhir=NULL;
		push(ambil->no_pas,ambil->nama_pas,ambil->jk,ambil->umur);
	}
	else{
	ambil=awal;
	awal=awal->next;
	push(ambil->no_pas,ambil->nama_pas,ambil->jk,ambil->umur);
	awal->prev=NULL;
	}
	main();
}
void pop(){ //menghapus data pasien yang terakhir masuk 
	typeptr2 ambil;
	if(top==bottom){
		ambil=top;
		top=NULL;
		akhir=NULL;
		free(ambil);
	}	
	else{
	ambil=top;
	top=top->prev;
	free(ambil);
	top->next=NULL;
	}
	main();
}

void cetakstack(){ //mencetak data pasien rumah sakit
	system("cls");

	typeptr2 bantu;
	bantu=top;
	cout<<"                ================================================="<< endl;
	cout<<"                ||                 Data Pasien                 ||"<< endl;
	cout<<"                ||              Rumah Sakit Jogja              ||"<< endl;
	cout<<"                ================================================="<< endl;
	cout<< setw(15)<< "===================================================================================="<< endl;
	cout<< setw(15)<< "no pasien"<< setw(20)<< "Nama pasien"<< setw(20)<< "Jenis kelamin"<< setw(20)<< "Umur\n";
	while (bantu!=NULL)
		{	
			cout<< setw(15)<< "===================================================================================="<< endl;
			cout<<setw(15)<<bantu->no_pas;
			cout<<setw(20)<<bantu->nama_pas;
			cout<<setw(19)<<bantu->jk;
			cout<<setw(19)<<bantu->umur;
			cout<<endl;
			bantu=bantu->prev;	
		}
	cout<< setw(15)<< "===================================================================================="<< endl;
	char pilih;
	cout<<"\n\nKembali ?\n";
	cout<<"Pilih (y/n) : "; 
	cin>>pilih;
	if(pilih=='y'){main();}
	if(pilih=='n'){exit(0);}
}
