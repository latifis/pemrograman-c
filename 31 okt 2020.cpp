/*Program List Dengan Array*/
#include <iostream>
#include <windows.h>
#include <conio.h>
#define max 12
#define true 1
#define false 0
using namespace std;

typedef struct {
	int info; 
	int next; 
	}typenode;
typenode elemen[max];
typenode temp;

int list,akhirlist,kosong,akhirkosong;
int listkosong();
void buatlist();
void sisipnode(int IB);
void hapusnode();
void cetaklist();

int main()
{ 
	int pilih;
	char keluar;
	
	do
	{
		cout << "Menu : ";
		cout << "\n 1. Buat List Dinamis";
		cout << "\n 2. Cetak List";
		cout << "\n 3. Sisip Node";
		cout << "\n 4. Hapus Node";
		cout << "\n 5. Keluar";
		cout << "\n Pilih : "; cin >> pilih;
		cout << endl;
		
		switch (pilih)
		{
			case 1:
				
				buatlist();
				break;
				
			case 2:
				cetaklist();
				break;
				
			case 3:
				cout << "\nInfo yang akan disisipkan : "; cin >> temp.info;
				sisipnode(temp.info);
				cout << "\nHasil setelah disisipkan : \n";
				cetaklist();
				break;
				
			case 4:
				hapusnode();
				break;
				
			case 5:
				cout << "Terima Kasih Telah Menggunakan Jasa Kami";
				exit(0);
				break;
			
			default : 
				cout << "\n\nMenu tidak tersedia";
			
		}
		cout << "\n\nKembali ke menu ? (y/n)"; cin >> keluar;
		system("cls");
		
	} while (keluar == 'Y' || keluar == 'y');
	
}

void buatlist()
{
	cout << "Masukkan Data : ";
	cout << "\n  List		: "; cin >> list;
	cout << "  List Akhir	: "; cin >> akhirlist;
	cout << "  Kosong	: "; cin >> kosong;
	cout << "  Kosong Akhir	: "; cin >> akhirkosong;
	
	cout << "\n\nMasukkan info dan next : " << endl;
	cout << "\n====  List  =====";
	cout << "\n Elemen [" << list << "]	: "; cin >> elemen[list].info;
	cout << " Next [" << list << "]	: "; cin >> elemen[list].next;
	
	cout << "\n====  List Akhir  =====";
	cout << "\n Elemen [" << akhirlist << "]	: "; cin >> elemen[akhirlist].info;
	cout << " Next [" << akhirlist << "]	: "; cin >> elemen[akhirlist].next;
	
	cout << "\n====  Kosong  =====";
	cout << "\n Elemen [" << kosong << "]	: "; cin >> elemen[kosong].info;
	cout << " Next [" << kosong << "]	: "; cin >> elemen[kosong].next;
	
	cout << "\n====  Kosong Akhir  =====";
	cout << "\n Elemen [" << akhirkosong << "]	: "; cin >> elemen[akhirkosong].info;
	cout << " Next [" << akhirkosong << "]	: "; cin >> elemen[akhirkosong].next;
	
	cout << "\n\n====  Lain Lain  =====" << endl;
	for (int i = 1; i < akhirlist; i++)
	{
		if (elemen[i].info == 0 && elemen[i].next == 0 && i!=akhirkosong) 
		{
			cout << "\n Elemen [" << i << "]	: "; cin >> elemen[i].info;
			cout << " Next [" << i << "]	: "; cin >> elemen[i].next;
		}
		
	}
}

int listkosong()
{ 
	if (list==0)
		return(true);
	else
		return(false);
}

void sisipnode(int IB)
{ 
	int listbaru,k,m,n,x;
	
	//-------------------------- sisip di awal
	if(IB<elemen[list].info)
	{
		listbaru=kosong;
		kosong=elemen[kosong].next;
		elemen[listbaru].info=IB;
		elemen[listbaru].next=list;
		list=listbaru;
	}
	
	//-------------------------sisip di akhir
	else if(IB>elemen[akhirlist].info)
	{	
		listbaru=kosong;
		kosong=elemen[kosong].next;
		elemen[listbaru].info=IB;
		elemen[listbaru].next=0;
		elemen[akhirlist].next=listbaru;
		akhirlist=listbaru;
	}
	
	//--------------------------sisip di tengah
	else
	{
		n=list;
		x=elemen[n].info;
		while(IB>x)
		{
			m=n;
			n=elemen[n].next;
			x=elemen[n].info;
		}
		k=elemen[kosong].next;
		elemen[m].next=kosong;
		elemen[kosong].info=IB;
		elemen[kosong].next=n;
		kosong=k;
	}
}

void cetaklist()
{ 
	int n,m;
	n=list;
	m=kosong;
	cout << "\nisi list : \n";
	do
	{
		cout << elemen[n].info << " ";
		n=elemen[n].next;
	}while (elemen[n].next!=0);
	cout << elemen[akhirlist].info << " " <<endl ;
	cout << "\nIndex tempat-tempat kosong: \n";
	do
	{
		cout << m << " ";
		m=elemen[m].next;
	}while(elemen[m].next!=0);
	cout << akhirkosong << " " << endl;
}

void hapusnode()
{
	int listbaru, IH, k, pilih;
	
	cout << "\nPilih posisi hapus node : "; 
	cout << "\n 1. Hapus depan";
	cout << "\n 2. Hapus akhir";
	cout << "\n 3. Hapus tengah";
	cout << "\n Pilih : "; cin >> pilih;
	
	switch (pilih)
	{
		case 1:
			//------------------------ hapus di awal
				
				cout << "\nMasukkan yang akan di hapus : "; cin >> IH;
				if(IH==elemen[list].info)
				{
					listbaru=elemen[list].next;
					k=kosong;
					kosong=list;
					list=listbaru;
					elemen[kosong].next=k;
					
					
					cout << "\n\nHasil Penghapusan : ";
					cetaklist();
				}
				else
				{
					cout << "\n\nInfo Tidak Dapat Dihapus dengan Metode Hapus Node Awal\n";
				}
			break;
			
		case 2:
			//-------------------------- hapus di akhir
				cout << "\nMasukkan yang akan di hapus : "; cin >> IH;
				if(IH==elemen[akhirlist].info)
				{
					k = list;
					do{
						k = elemen[k].next; 
					}while(elemen[k].next!=akhirlist);
					elemen[akhirlist].next=kosong;
					kosong=akhirlist;
					akhirlist=k;
					elemen[k].next = 0;
						
					cout << "\n\nHasil Penghapusan : \n";
					cetaklist();
				}
				else
				{
					cout << "\n\nInfo Tidak Dapat Dihapus dengan Metode Hapus Node Akhir\n";
				}
			break;
			
		case 3:
			//-------------------------- hapus di tengah
				cout << "\nMasukkan yang akan di hapus : "; cin >> IH;
				if(IH!=elemen[list].info&&IH!=elemen[akhirlist].info)
				{
					int a,b;
					int c=list; 
					int d=elemen[c].info;
					int e;
						
					while (IH>d){
						e=c;
						c=elemen[c].next;
						d=elemen[c].info;
					}
						
					a = elemen[c].next;
					b = elemen[e].next;
					elemen[e].next = a;
					elemen[b].next = kosong;
					elemen[b].info = 0;
					kosong = b;
						
					cout << "\nHasil Penghapusan : \n";
					cetaklist();
				}
				else
				{
					cout << "Info Tidak Dapat Dihapus dengan Metode Hapus Node Tengah\n";
				}
			break;
		
		default : 
			cout << "\n\nMenu tidak tersedia, tekan enter untuk kembali ke menu hapus";
			hapusnode();
	}
}
