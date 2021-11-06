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
int listkosong();

int main (){
	
	cout << "aku";
	main ();
	buatlistbaru();
	
	int pilih, sisip, nilai, hapus;
	char menu;
	
	do
	{
		cout << "Menu : ";
		cout << "\n  1. Sisip node";
		cout << "\n  2. Hapus node";
		cout << "\n  3. Baca Maju";
		cout << "\n  4. Baca Mundur";
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
