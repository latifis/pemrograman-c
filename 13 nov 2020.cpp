#include <iostream>
#include <malloc.h>
#define true 1
#define false 0
using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;
struct data_Node{
	typeinfo goldar;
	typeinfo nama;
	int umur;
	typeinfo status;
	
};
struct typenode{
	data_Node data;
	typeptr next; 
	};
typeptr awal,akhir;
void buatlistbaru();
void sisipnode(data_Node dt);
void hapusnode(typeinfo nimH);
void bacamaju();
void bacamundur();
int listkosong();
int main()
{
	buatlistbaru();
	typenode tmp;
	int pilih;
	char keluar;
	
	do
	{
		cout << "UNIT PELAYANAN TRANFUSI DARAH\n\n\n";
		cout << "Daftar Menu : "<<endl;
		cout << "1. Input Data Pendonor"<<endl;
		cout << "2. Lihat Data Pendonor"<<endl;
		cout << "3. Cek Kandidat Pendonor"<<endl;
		cout << "4. Hapus Data Pendonor"<<endl;
		cout << "5. Keluar"<<endl;
		cout << "Masukkan Pilihan  :  ";
		cin >> pilih;
		
		switch(pilih){
			case 1 :
			
				int n;
				cout <<"Input Data Pendonor = ";
				cin>>n;
				for(int i=0; i<n; i++){
					cout <<"Data ke " << i+1 <<endl;
					cin.ignore();
					cout << "Nama      : "; getline(cin, tmp.data.nama);
					cout <<"Umur      : ";
					cin>> tmp.data.umur;
					cout <<"Goldar : ";
					cin>>tmp.data.goldar;
					
					if (tmp.data.umur >=17 && tmp.data.umur <=60)
					{
						tmp.data.status="Bisa Donor";
					}
					else
					{
						tmp.data.status="Tidak Bisa Donor";
					}
					
					int urut = i;
					cout <<"Status : ";
					sisipnode(urut);
				}
				cin.ignore();
				cin.get();
				break;
				
			case 2 :
				cout <<"Data Mahasiswa "<<endl;
				bacamaju();
				cin.ignore();
				cin.get();
				break;	
				
			case 3 :
				
				break;
				
			case 4 :
				int b;
				cout <<"Hapus data yang memiliki nim = ";
				cin>>b;
				hapusnode(b);
				cin.ignore();
				cin.get();
			case 5 :
				exit(0);
				break;
			default :
				cout << "Tidak Ada dalam Menu"; //apabila tidak ada dalam menu pilihan
				break;
			}
			
			cout << "Keluar program ? (y/n)"; cin >> keluar;
			system("cls");
			
	} while (keluar=='Y' || keluar=='y');
	
}
void buatlistbaru()
{
 typeptr list;
 list=NULL;
 awal=list;
 akhir=list;
}

int listkosong()
{ 
	if(awal==NULL)
		return(true);
	else
		return(false); 
}

void sisipnode(data_Node dt)
{ 
	typeptr NB,bantu;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->data=dt;
	NB->next=NULL;
	if (listkosong())
	{ 
		awal=NB;
		akhir=NB; 
	}
	else if (dt.umur <= awal->data.umur)  // Sisip di depan
	{ 
		NB->next=awal;
		awal=NB; 
	}
	else
	{ 
		bantu=awal;
		while (bantu->next!=NULL && dt.umur > bantu->next->data.umur)
			bantu=bantu->next;
		NB->next=bantu->next; // Sisip di tengah atau di belakang
		bantu->next=NB;
		if (dt.umur>akhir->data.umur)
			akhir=NB;
	}
}


void hapusnode(typeinfo nimH)
{ typeptr hapus, bantu;
	if (listkosong())
		cout << "List masih kosong";
	else if (awal->data.nim==nimH){ 
		hapus=awal; // Hapus di awal
		awal=hapus->next;
		free(hapus); 
		cout <<"Data berhasil terhapus";
	}
	else{ 
		bantu=awal;
		while (bantu->next->next!=NULL && nimH!=bantu->next->data.nim){
			bantu=bantu->next;}
		if (nimH==bantu->next->data.nim){
				hapus=bantu->next;
			if (hapus==akhir){ // Hapus di akhir
				akhir=bantu;
				akhir->next=NULL; 
				cout <<"Data berhasil terhapus";
			}
			else{
				bantu->next=hapus->next; // Hapus di tengah
				free(hapus);
				cout <<"Data berhasil terhapus";
			}
		}
		else if(nimH!=bantu->next->data.nim)
		cout << "Data tidak ditemukan!\n";
	}
}


void bacamaju()
{
 typeptr bantu;
 bantu=awal;
 while (bantu!=NULL)
 {
cout <<"Nama      : " << bantu->data.nama<<endl;
cout <<"Umur     : " << bantu->data.umur<<endl;
cout <<"Goldar : "<< bantu->data.goldar<<endl<<endl;
bantu=bantu->next;
 }
}
