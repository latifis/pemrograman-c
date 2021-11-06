#include <iostream>
#include <malloc.h>
#include <windows.h>
#define true 1
#define false 0
using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode{
	typeinfo info;
	typeptr next;
	};
typeptr awal,akhir;

void buatlistbaru();
void sisipnode(typeinfo IB);
void hapusnode(typeinfo IH);
void bacamaju();
void bacamundur();
void bacadari(int baca);
int listkosong();
int sisip;

int main (){
	
	main ();
	buatlistbaru();
	
	int baca, pilih, nilai, hapus;
	char menu;
	
	do
	{
		cout << "Menu : ";
		cout << "\n  1. Sisip node";
		cout << "\n  2. Hapus node";
		cout << "\n  3. Baca Maju";
		cout << "\n  4. Baca Mundur";
		cout << "\n  5. Baca Dari";
		cout << "\n  Pilih : "; cin >> pilih;
		
		switch (pilih)
		{
			case 1 :
				cout << "Berapa kali sisip? "; cin >> sisip;
				for (int i = 0; i < sisip; i++)
				{
					cout << "Nilai ke " << i+1 << " : "; cin >> nilai;
					sisipnode(nilai);
				}
				break;
			case 2 :
				cout << "Hapus node dnegan nilai? "; cin >> hapus;
				hapusnode(hapus);
				break;
			case 3 :
				cout << "baca note maju : "; 
				bacamaju();
				break;
			case 4 :
				cout << "baca note mundur : "; 
				bacamundur();
				break;	
			case 5 :
				cout << "baca note dari : "; cin >> baca; 
				bacadari(baca);
				break;
		}
		
		cout << "\nKembali ke Menu ? (y/n)"; cin >> menu;
		
		system("cls");
		
	} while (menu == 'Y' || menu == 'y');
	
	
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

void sisipnode(typeinfo IB)
{ 
	typeptr NB, bantu;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->info=IB;
	NB->next=NULL;
	if (listkosong()== true)
	{ 
		awal=NB;
		akhir=NB; 
	}
	else if (IB <= awal->info) // Sisip di depan
	{ 
		NB->next=awal;
		awal=NB; 
	}
	else
	{ 
		bantu=awal;
		while (bantu->next!=NULL && IB > bantu->next->info)
			bantu=bantu->next;
		NB->next=bantu->next; // Sisip di tengah atau di belakang
		bantu->next=NB;
		if (IB>akhir->info)
			akhir=NB;
	}
}
void hapusnode(typeinfo IH)
{ 
	typeptr hapus, bantu;
	if (listkosong())
		cout << "List masih kosong";
	else if (awal->info==IH)
	{ 
		hapus=awal; // Hapus di awal
		awal=hapus->next;
		free(hapus); 
	}
	else
	{ 
		bantu=awal;
		while (bantu->next->next!=NULL && IH!=bantu->next->info)
		bantu=bantu->next;
		if (IH==bantu->next->info)
		{ 
			hapus=bantu->next;
				if (hapus==akhir) // Hapus di akhir
				{ 
					akhir=bantu;
					akhir->next=NULL; 
				}
				else
					bantu->next=hapus->next; // Hapus di tengah
				free(hapus);
		}
		else
			cout << "Node tidak ditemukan!\n"; 
	}
}

void bacamaju()
{
	typeptr bantu;
	bantu=awal;
	while (bantu!=NULL)
	{
		cout << " " << bantu->info;
		cout << " ";
		bantu=bantu->next;
	}
}
void bacamundur()
{ 
	typeptr depan,bantu;
	depan=awal;
	awal=akhir;
	do { 
		bantu=depan;
		while (bantu->next!=akhir)
			bantu=bantu->next;
		akhir->next=bantu;
		akhir=bantu;
	}while (akhir!=depan);
	akhir->next=NULL;
	bantu=awal;
	while (bantu!=NULL)
	{ 
		cout << " " << bantu->info;
		cout << " ";
		bantu=bantu->next;
	}
}

void bacadari(int baca){
	typeptr bantu, batas;
	akhir->next=awal;
	bantu=awal;
	while (bantu->info!=baca)
	{
		bantu=bantu->next;
	}
	batas=bantu;
	do
	{
		cout << bantu->info << " ";
		bantu = bantu->next;
	} while (bantu->info!=batas->info);
	cout << endl;
	
}

/*
 #include <iostream>
#include <malloc.h>
#define true 1
#define false 0
using namespace std;;

typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode{
	typeinfo info;
	typeptr next;
	};
typeptr awal,akhir;

void buatlistbaru();
void sisipnode(typeinfo IB);
void hapusnode(typeinfo IH);
void bacamaju();
void bacamundur();
int listkosong();

int main()
{
	int nilai, sisip;
	cout << "List Mula-mula :\n";
	buatlistbaru();
	sisipnode(50);
	cout << "Berapa kali sisip? "; cin >> sisip;
			for (int i = 0; i < sisip; i++)
			{
				cout << "Nilai ke " << i+1 << " : "; cin >> nilai;
				sisipnode(nilai);
			}
	bacamaju();
	cout << "\n\nHapus node 50\n";
	cout << "\nKodisi List setelah di hapus, dibaca dari belakang :\n\n";
	hapusnode(50);
	bacamundur();
	return 0;
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

void sisipnode(typeinfo IB)
{ 
	typeptr NB, bantu;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->info=IB;
	NB->next=NULL;
	if (listkosong() == true)
	{ 
		awal=NB;
		akhir=NB; 
	}
	else if (IB <= awal->info) // Sisip di depan
	{ 
		NB->next=awal;
		awal=NB; 
	}
	else
	{ 
		bantu=awal;
		while (bantu->next!=NULL && IB > bantu->next->info)
			bantu=bantu->next;
		NB->next=bantu->next; // Sisip di tengah atau di belakang
		bantu->next=NB;
		if (IB>akhir->info)
			akhir=NB;
	}
}
void hapusnode(typeinfo IH)
{ 
	typeptr hapus, bantu;
	if (listkosong())
		cout << "List masih kosong";
	else if (awal->info==IH)
	{ 
		hapus=awal; // Hapus di awal
		awal=hapus->next;
		free(hapus); 
	}
	else
	{ 
		bantu=awal;
		while (bantu->next->next!=NULL && IH!=bantu->next->info)
		bantu=bantu->next;
		if (IH==bantu->next->info)
		{ 
			hapus=bantu->next;
				if (hapus==akhir) // Hapus di akhir
				{ 
					akhir=bantu;
					akhir->next=NULL; 
				}
				else
					bantu->next=hapus->next; // Hapus di tengah
				free(hapus);
		}
		else
			cout << "Node tidak ditemukan!\n"; 
	}
}

void bacamaju()
{
	typeptr bantu;
	bantu=awal;
	while (bantu!=NULL)
	{
		cout << " " << bantu->info;
		cout << " ";
		bantu=bantu->next;
	}
}
void bacamundur()
{ 
	typeptr depan,bantu;
	depan=awal;
	awal=akhir;
	do { 
		bantu=depan;
		while (bantu->next!=akhir)
			bantu=bantu->next;
		akhir->next=bantu;
		akhir=bantu;
	}while (akhir!=depan);
	akhir->next=NULL;
	bantu=awal;
	while (bantu!=NULL)
	{ 
		cout << " " << bantu->info;
		cout << " ";
		bantu=bantu->next;
	}
}
*/







/* Linked List Berkepala dan Berekor 
#include <iostream>
#include <malloc.h>
using std::cout;
#define true 1
#define false 0
typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode{
	typeinfo info;
	typeptr next;
	};
typeptr kepala,ekor;

void buatlist();
void sisipnode(typeinfo IB);
void hapusnode(typeinfo IH);

void bacamaju();
void bacamundur();
void bacaback();
int listkosong();
int main()
{
	buatlist();
	sisipnode(50);
	sisipnode(20);
	sisipnode(5);
	sisipnode(100);
	sisipnode(70);
	sisipnode(25);
	sisipnode(40);
	bacamaju();
	cout << "\n\nHapus node 20\n";
	cout << "\nList setelah dihapus, dibaca dari belakang :\n\n";
	hapusnode(20);
	bacamundur();
}

void buatlist()
{
	kepala=(typenode *)malloc(sizeof(typenode));
	ekor=(typenode *)malloc(sizeof(typenode));
	kepala->info=-9999;
	kepala->next=ekor;
	ekor->info=9999;
	ekor->next=NULL;
}

int listkosong()
{	
	if(kepala->next==ekor)
	return(true);
	else
	return(false); 
}

void sisipnode(typeinfo IB)
{
	typeptr NB, bantu;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->info=IB;
	bantu=kepala;
	while (IB > bantu->next->info)
		bantu=bantu->next;
	NB->next=bantu->next;
	bantu->next=NB;
}
void hapusnode(typeinfo IH)
{ 
	typeptr hapus, bantu;
	if (listkosong())
		cout << "List masih kosong";
	else
	{ 
		bantu=kepala;
		while (bantu->next!=ekor && IH!=bantu->next->info)
		bantu=bantu->next;
		if (IH==bantu->next->info)
		{ 
			hapus=bantu->next;
			bantu->next=hapus->next;
			free(hapus); 
		}
		else
		cout << "Node tidak ditemukan!\n";
	}
}

void bacamaju()
{
	typeptr bantu;
	bantu=kepala->next;
	while (bantu!=ekor)
	{
		cout << " " << bantu->info;
		bantu=bantu->next;
	}
}

void bacamundur()
{
	typeptr depan,bantu;
	depan=kepala;
	kepala=ekor;
	do { 
		bantu=depan;
		while (bantu->next!=ekor)
			bantu=bantu->next;
		ekor->next=bantu;
		ekor=bantu;
	} while (ekor!=depan);
	
	ekor->next=NULL;
	bantu=kepala->next;
	
	while (bantu!=ekor)
	{ 
		cout << " " << bantu->info;
		bantu=bantu->next; 
	}
}
*/
