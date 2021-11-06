#include <iostream> 
#include <malloc.h> 
#define true 1 
#define false 0 
using namespace std;
using std::cout; 
typedef int typeinfo; 
typedef struct typenode *typeptr; 
struct typenode{typeinfo info; 
		 typeptr next;}; 
typeptr awal,akhir; 
void buatlistbaru(); 
void sisipnode(typeinfo IB); 
void hapusnode(typeinfo IH); 
void bacamaju(); 
void bacamundur(); 
int listkosong();
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
{ typeptr NB, bantu; //NB = Nilai Baru
NB=(typenode *) malloc(sizeof(typenode)); 
NB->info=IB; 
NB->next=NULL; 
if (listkosong()) 
{  awal=NB; 
   akhir=NB; } 
else if (IB <= awal->info) // Sisip di depan 
{ NB->next=awal; 
  awal=NB; } 
else 
{ bantu=awal; 
  while (bantu->next!=NULL && IB > bantu->next->info) 
  bantu=bantu->next; 
  NB->next=bantu->next;// Sisip di tengah atau di belakang 
  bantu->next=NB; 
if (IB>akhir->info) 
 akhir=NB; 
} 
} 
void hapusnode(typeinfo IH) 
{ typeptr hapus, bantu; 
  if (listkosong()) 
      cout << "List masih kosong"; 
  else if (awal->info==IH) 
  {   hapus=awal; // Hapus di awal 
      awal=hapus->next; 
      free(hapus); } 
  else 
  {   bantu=awal; 
      while (bantu->next->next!=NULL && IH!=bantu->next->info) 
      bantu=bantu->next; 

  if (IH==bantu->next->info) 
  {  hapus=bantu->next; 
     if (hapus==akhir) // Hapus di akhir 
        { akhir=bantu; 
          akhir->next=NULL; } 
     else 
          bantu->next=hapus->next; // Hapus di tengah 
     free(hapus); 
   } 
  else 
      cout << "Node tidak ditemukan!\n"; } 
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
{ typeptr depan,bantu; 
  depan=awal; 
  awal=akhir; 
  do { bantu=depan; 
while (bantu->next!=akhir) 
bantu=bantu->next; 
akhir->next=bantu; 
akhir=bantu; 
  } while (akhir!=depan);
akhir->next=NULL; 
bantu=awal;
while (bantu!=NULL) 
{ cout << " " << bantu->info; 
  cout << " "; 
  bantu=bantu->next; 
} depan=awal; 
  awal=akhir; 
  do { bantu=depan; 
while (bantu->next!=akhir) 
bantu=bantu->next; 
akhir->next=bantu; 
akhir=bantu; 
  } while (akhir!=depan);
akhir->next=NULL;
  } int main() 
{
 char k;
 int sip,pil,x;
do {

system("cls");
cout<< "Menu : "<<endl;
cout<<"1. Sisip Node"<<endl;
cout<<"2. Hapus Node"<<endl;
cout<<"3. Baca Maju"<<endl;
cout<<"4. Baca Mundur"<<endl;
cout<<"pilih : ";cin>>pil;cin.ignore(); 
			 switch(pil){
			 	case 1:
			 		cout<<"Berapa sisip? : ";cin>>sip;cin.ignore();
					 for(int i = 0; i<sip; i++ ){cin>>x;sisipnode(x);
					 } 
					 break; 
		 		case 2:
		 			cout<<" mana yg mau dihapus ?? : ";
		 			cin>>x;
		 			hapusnode(x);
			 		break;
		 		case 3:
		 			 bacamaju();
		 			 break;
		 	    case 4:
		 	    	bacamundur();
		 	    	break;
			 default :
				cout<<"Pilihan yang Anda masukkan salah"<<endl;
				break;
			 }
	cout<<"\nKembali ke menu?(y/t): ";cin>>k;	
	}while(k=='y' || k=='Y');		 

return 0; 
}


s
