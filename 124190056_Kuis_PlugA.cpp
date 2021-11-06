#include <iostream>
#include <malloc.h>
#define true 1
#define false 0
using namespace std;

typedef string typeinfo;
typedef struct typenode *typeptr;
struct datadonor{
	typeinfo nama,status;
	int umur;
	char goldar;
};
struct typenode{
	datadonor data, penerima;
	typeptr next; 
};

typenode aku;
typeptr awal,akhir;
void buatlistbaru();
void sisipnode(datadonor dd);
int listkosong();
void bacamaju();
void bacadonor(char d);
void hapusnode(typeinfo namah);

int main(){
	char jwb;
	string hapnama;
	int pilih,jml;
	buatlistbaru();
	
	do{
		system("cls");
		cout<<"Unit Pelayanan Transfusi Darah";
		cout<<"\n\nMENU :";
		cout<<"\n1. Input Data Donor \n2. Lihat Data Pendonor \n3. Cek Kandidat Pendonor \n4. Hapus Data Pendonor \n5. Keluar";
		cout<<"\nPilih : "; cin>>pilih;
		
		switch (pilih){
			case 1:
				system("cls");
				cout<<"Input Data Pendonor\n";
				cout<<"Jumlah Data : "; cin>>jml;
				
				for (int i = 0; i < jml; i++){
					cout<<"Data ke-"<<i+1;
					cout<<"\nNama Pendonor\t: "; cin.ignore(); getline(cin,aku.data.nama); 
					cout<<"Umur\t\t: "; cin>>aku.data.umur;
					cout<<"Golongan Darah\t: "; cin>>aku.data.goldar;
					
					//cek data yg bisa donor
					if (aku.data.umur > 16 && aku.data.umur < 61){
						aku.data.status="Bisa Donor";
					}
					else{
						aku.data.status="Tidak Bisa Donor";
					}
					cout<<"Status\t\t: "<<aku.data.status;
					cout<<endl<<endl;
					
					//Handel biar yg masuk ke data haya yg bisa donor saja
					if (aku.data.umur > 16 && aku.data.umur < 61){
						sisipnode(aku.data);
					}
				}
				break;
			case 2: 
				system("cls");
				cout<<"Data Pendonor :\n";
				bacamaju();
				break;
			case 3:
				system("cls");
				cout<<"\nNama Penerima Donor\t: "; cin.ignore(); getline(cin,aku.penerima.nama); 
				cout<<"Umur\t\t: "; cin>>aku.penerima.umur;
				cout<<"Golongan Darah\t: "; cin>>aku.penerima.goldar;
				cout << endl << endl;
				if (aku.penerima.goldar==aku.data.goldar)
				{
					bacadonor(aku.penerima.goldar);
				}
				else
				{
					cout << "Tidak ada pendonor yang bisa berdonor untuk anda";  //handel bila tidak ada yg sama goldarnya
				}
				break;
			case 4:
				system("cls");
				cout<<"Data Pendonor\n\n";
				bacamaju();
				cout<<endl;
				cout<<"Masukkan Nama yang akan dihapus : "; cin>>hapnama;
				hapusnode(hapnama);
				break;
			case 5:
				exit(0);
			default:
				cout << "Tidak ada dalam menu"; //Handeling apabila tidak ada dalam menu
			
		}
		
		cout<<"Kembali ke Menu? (y/t)"; cin>>jwb;
	} while (jwb == 'y' || jwb == 'Y'); // buat handeling main
	
}

void buatlistbaru(){
	typeptr list;
	list=NULL;
	awal=list;
	akhir=list;
};

void sisipnode(datadonor dd){
	typeptr NB;
	
	NB=(typenode *) malloc(sizeof(typenode));
	NB->data=dd;
	NB->next=NULL;
	if (listkosong()){ 
		awal=NB;
		akhir=NB; 
	}
	else {  // Sisip di depan
		NB->next=awal;
		awal=NB; 
	}
};

int listkosong(){ 
	if(awal==NULL)				// cek list kosong
		return(true);
	else
		return(false); 
};

void bacamaju(){
	typeptr bantu;
	bantu=awal;
	while (bantu!=NULL){
			cout<<"Nama Pendonor\t: " << bantu->data.nama<<endl;
			cout<<"Umur\t\t: " << bantu->data.umur<<endl;
			cout<<"Golongan Darah\t: "<< bantu->data.goldar<<endl;
			cout<<"Status\t\t: "<<bantu->data.status<<endl<<endl;
			bantu=bantu->next;
		}
}

void bacadonor(char d){
	typeptr bantu;
	bantu=awal;
	while (bantu!=NULL && d==bantu->data.goldar){
			cout<<"Nama Pendonor\t: " << bantu->data.nama<<endl;
			cout<<"Umur\t\t: " << bantu->data.umur<<endl;
			cout<<"Golongan Darah\t: "<< bantu->data.goldar<<endl;
			cout<<"Status\t\t: "<<bantu->data.status<<endl<<endl;
			bantu=bantu->next;
		}
}

void hapusnode(typeinfo namah){
	typeptr hapus, bantu; 
	if (listkosong()) 
		cout << "List masih kosong";  //handling apabila list kosong
	else if (awal->data.nama==namah){
		hapus=awal; // Hapus di awal 
		awal=hapus->next; 
		free(hapus); } 
	else{
		bantu=awal; 
		while (bantu->next->next!=NULL && namah!=bantu->next->data.nama) 
		bantu=bantu->next; 
		if (namah==bantu->next->data.nama){
			hapus=bantu->next; 
			if (hapus==akhir){// Hapus di Akhir
				akhir=bantu; 
				akhir->next=NULL;
			}
			else 
			bantu->next=hapus->next; // Hapus di Tengah 
			free(hapus); 
		} 
		else 
		cout << "Node tidak ditemukan!\n";
	} 
}
