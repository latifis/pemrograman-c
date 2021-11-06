
//PROGRAM LINKED LIST MENGGUNAKAN ARRAY

#include <iostream>

using namespace std;

//Pendeklarasian Struct
typedef struct{
	int info; int next;
	}typenode;
typenode elemen[20];

//Pendeklarasian Global
int list, listakhir, kosong, kosongakhir, pilih, sisip, hapus;
char kembali;

//Pemanggilan Void
int listkosong();
void menu();
void menu1();
void menu2();
void menu3();
void menu4();
void buatlist();
void sisipnode(int IB);
void hapusnodeawal(int IH);
void hapusnodeakhir(int IH);
void hapusnodetengah(int IH);
void cetaklist();

int main(){
	menu();
}

void menu(){
	system("cls");
	cout << "Menu :\n";
	cout << "1. Buat List Dinamis\n";
	cout << "2. Cetak list\n";
	cout << "3. Sisip Node\n";
	cout << "4. Hapus Node\n";
	cout << "5. Keluar\n";
	cout << "Pilih : "; cin >> pilih;
	switch(pilih){
		case 1 :
			menu1();
			break;
		case 2 :
			menu2();
			break;
		case 3 :
			menu3();
			break;
		case 4 :
			menu4();
			break;
		case 5 :
			cout << "\n\nTerima Kasih";
			break;
		default :{
			cout << "\n\nSalah Memilih Menu\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
			if(kembali=='Y'||kembali=='y'){
				menu();
			}
		}
	}
}

void menu1(){
	cout << "\nList\t\t: "; cin >> list; //Menentukan Index Awal suatu List berisi
	cout << "List Terakhir\t: "; cin >> listakhir;//Menentukan Index Akhir suatu List berisi
	cout << "Kosong\t\t: "; cin >> kosong;  //Menentukan Index Awal suatu List kosong
	cout << "Kosong Terakhir\t: "; cin >> kosongakhir;//Menentukan Index Akhir suatu List kosong
	buatlist();
}

void menu2(){
	cout << "\n";
	cetaklist();//Melakukan pemanggilan ke Void cetaklist()
	cout << "\n\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
	if(kembali=='Y'||kembali=='y'){
		menu();
	}
}

void menu3(){
	cout << "\nInfo Yang Akan Disisipkan : "; cin >> sisip;
	sisipnode(sisip);//Melakukan pemanggilan ke Void sisipnode() dengan mengirimkan nilai bervariabel sisip
	cout << "\nHasil Setelah Disisipkan : \n";
	cetaklist();//Melakukan pemanggilan ke Void cetaklist()
	cout << "\n\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
	if(kembali=='Y'||kembali=='y'){
		menu();
	}
}

void menu4(){
	cout << "\nPilih Posisi Hapus Node : \n";
	cout << "1. Hapus Depan\n";
	cout << "2. Hapus Akhir\n";
	cout << "3. Hapus Tengah\n";
	cout << "Pilih :"; cin >> pilih;
	switch(pilih){
		case 1 :{
			cout << "\nIndex List yang akan Dihapus : " << list;
			hapusnodeawal(elemen[list].info); //Melakukan pemanggilan ke Void hapusnodeawal() dengan mengirimkan nilai berupa index list berisi pertama
			break;
		}
		case 2 :{
			cout << "\nIndex List yang akan Dihapus : " << listakhir;
			hapusnodeakhir(elemen[listakhir].info);//Melakukan pemanggilan ke Void hapusnodeakhir() dengan mengirimkan nilai berupa index list berisi terakhir
			break;
		}
		case 3 :{
			cout << "\nMasukkan Info yang akan Dihapus : "; cin >> hapus;
			hapusnodetengah(hapus);//Melakukan pemanggilan ke Void hapusnodetengah() dengan mengirimkan nilai berupa nilai dari variabel hapus yang telah diinputkan
			break;
		}
		default : {
			cout << "\n\nSalah Memilih Menu\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
			if(kembali=='Y'||kembali=='y'){
				menu();
			}
		}
	}cout << "\n\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
	if(kembali=='Y'||kembali=='y'){
		menu();
	}
}

void buatlist(){//digunakan untuk pembuatan list baru
	cout <<"\nMasukkan Info dan Next :\n";
	for(int i=1; i<=listakhir; i++){
		cout << "Elemen\t[" << i << "]\t: "; cin >> elemen[i].info;
		cout << "Next\t[" << i << "]\t: "; cin >> elemen[i].next;
	}
	cout << "\nIngin Kembali Ke Menu? (Y/N) ";cin >> kembali;
	if(kembali=='Y'||kembali=='y'){
		menu();
	}
}

int listkosong(){//digunakan untuk pengecekan apakah list kosong atau berisi
	if (list==0)
		return(true);
	else
		return(false);
}

void cetaklist(){//digunakan untuk melakukan cetak list
	int n,m;
	n=list;
	m=kosong;
	cout << "Isi list : \n";
	do{
		cout << elemen[n].info << " ";
		n=elemen[n].next;
	}while (elemen[n].next!=0);
	cout << " "<< elemen[listakhir].info <<endl ;
	cout << "\nIndex tempat-tempat kosong: \n";
	do{
		cout << m << " ";
		m=elemen[m].next;
	}while(elemen[m].next!=0);
	cout << " " << kosongakhir;
}

void sisipnode(int IB){//digunakan untuk menyisipkan nilai yang telah ditentukan pada void menu3();
	int listbaru,k,m,n,x;
	//sisipnode diawal
	if(IB<elemen[list].info){
		listbaru=kosong;
		kosong=elemen[kosong].next;
		elemen[listbaru].info=IB;
		elemen[listbaru].next=list;
		list=listbaru;
	}
	else{
	//sisipnode diakhir
		if(IB>elemen[listakhir].info){
			listbaru=kosong;
			kosong=elemen[kosong].next;
			elemen[listbaru].info=IB;
			elemen[listbaru].next=0;
			elemen[listakhir].next=listbaru;
			listakhir=listbaru;
		}
		else{//sisipnode di tengah
			x=elemen[n].info;
			while(IB>x){
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
}

void hapusnodeawal(int IH){//hapusnode di awal
	int listbaru,k;
	if(IH==elemen[list].info){
		listbaru=elemen[list].next;
		k=kosong;
		kosong=list;
		list=listbaru;
		elemen[kosong].next=k;
		
		
		cout << "\n\nHasil Penghapusan : \n";
		cetaklist();
	}
	else{
		cout << "\n\nInfo Tidak Dapat Dihapus dengan Metode Hapus Node Awal\n";
	}
}

void hapusnodeakhir(int IH){//hapusnode di akhir
	int listbaru,k;
	if(IH==elemen[listakhir].info){
		k = list;
		do{
			k = elemen[k].next; 
		}while(elemen[k].next!=listakhir);
		elemen[listakhir].next=kosong;
		kosong=listakhir;
		listakhir=k;
		elemen[k].next = 0;
			
		cout << "\n\nHasil Penghapusan : \n";
		cetaklist();
	}
	else{
		cout << "\n\nInfo Tidak Dapat Dihapus dengan Metode Hapus Node Akhir\n";
	}
}

void hapusnodetengah(int IH){//hapusnode di tengah
	int listbaru;
	if(IH!=elemen[list].info&&IH!=elemen[listakhir].info){
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
	else{
		cout << "Info Tidak Dapat Dihapus dengan Metode Hapus Node Tengah\n";
	}
}

