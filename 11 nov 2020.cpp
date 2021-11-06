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


int main(){
	
	//============================================== buat list
	
	typeptr list;
	list=NULL;
	awal=list;
	akhir=list;
	
	
	//============================================== main
	
	int pilih, sisip, nilai, hapus;
	char menu;
	
	cout << "Berapa kali sisip? "; cin >> sisip;
	for (int i = 0; i < sisip; i++)
	{
		cout << "Nilai ke " << i+1 << " : "; cin >> nilai;
		
		typeinfo IB = nilai;
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
	
	}
