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
	datadonor data;
	typeptr next; 
};

typenode abc;
typeptr awal,akhir;
void buatlistbaru();
void sisipnode(datadonor dd);
int listkosong();
void bacamaju();
void hapusnode(typeinfo namah);


int main(){
	char jwb;
	int pilih,jml;
	string hnama;
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
					cout<<"\nNama Pendonor\t: "; cin.ignore(); getline(cin,abc.data.nama); 
					cout<<"Umur\t\t: "; cin>>abc.data.umur;
					cout<<"Golongan Darah\t: "; cin>>abc.data.goldar; cin.ignore(); 
					if (abc.data.umur > 16 && abc.data.umur < 61){
						abc.data.status="Bisa Donor";
					}
					else{
						abc.data.status="Tidak Bisa Donor";
					}
					cout<<"Status\t\t: "<<abc.data.status;
					cout<<endl<<endl;
					if (abc.data.umur > 16 && abc.data.umur < 61){
						sisipnode(abc.data);
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
				cout<<"";
				break;
			case 4:
				system("cls");
				cout<<"Data Pendonor\n\n";
				bacamaju();
				cout<<endl;
				cout<<"Masukkan Nama yang akan dihapus : "; cin>>hnama;
				hapusnode(hnama);
				break;
		}
		
		cout<<"Kembali ke Menu? (y/t)"; cin>>jwb;
	} while (jwb == 'y' || jwb == 'Y');
	
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
	if(awal==NULL)
		return(true);
	else
		return(false); 
};

void bacamaju(){
	int i=1;
	typeptr bantu;
	bantu=awal;
	while (bantu!=NULL){
			cout<<"Data ke-"<<i<<endl;
			cout<<"Nama Pendonor\t: " << bantu->data.nama<<endl;
			cout<<"Umur\t\t: " << bantu->data.umur<<endl;
			cout<<"Golongan Darah\t: "<< bantu->data.goldar<<endl;
			cout<<"Status\t\t: "<<bantu->data.status<<endl<<endl;
			bantu=bantu->next;
			i++;
		}
}

void hapusnode(typeinfo namah){
	typeptr hapus, bantu; 
	if (listkosong()) 
		cout << "List masih kosong"; 
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
