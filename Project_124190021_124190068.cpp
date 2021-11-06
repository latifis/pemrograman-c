#include <iostream>
#include <bits/stdc++.h>
#include <malloc.h>
#include <fstream>
#define True 1
#define False 0

using namespace std;

typedef char typeinfo;
typedef struct dataPenumpang *typeptrqueue;
typedef struct dataPenumpang *typeptrstack;

struct simpan
{
    char nama [40], asal[30], tujuan[30], tgl[30], jumlahPenumpang[30];
}simpan1;

struct dataPenumpang
{
    char nama [40], asal[30], tujuan[30], tgl[30], jumlahPenumpang[30];
    
    typeptrqueue nextqueue;
    typeptrstack nextstack;
    
    simpan smpn;
}data, dt;



/*struct typequeuestack
{
    typeptrqueue nextqueue;
    typeptrstack nextstack;
    data info;
    simpan info2;
};*/

typeptrqueue qdepan, qbelakang, qdepan1,qbelakang1;
typeptrstack awalstack, akhirstack;

void buatqueue();
int queuekosong();
void enqueue(char nama2[], char asal2[], char tujuan2[], char tgl2[], char jumlahPenumpang2[]);
void dequeue();
void cetakqueue();
void cetakqueueBerangkat();
void batal();

void buatstack();
int stackkosong();
void push(char nama2[], char asal2[], char tujuan2[], char tgl2[], char jumlahPenumpang2[]);
void pop();
void cetakstack();

int tstack=5, tqueue=3;
FILE *file;
char namaHapus[30];

int main()
{
	int pilih;
    char nama [40], asal[30], tujuan[30], tgl[30], jumlahPenumpang[3], ulang;
    
    do
    {
		if((file = fopen("tiket.txt","r"))==NULL)
		cout<<"file tidak dapat terbaca";
		fread(&data, sizeof(data), 1, file);
		fread(&simpan1, sizeof(simpan1), 1, file);
        cout << endl;
        cout << "=================================\n"
			 << "$\t\t\t\t$\n"
			 << 	"$\tTIKET KERETA API\t$\n"
			 << "$\t\t\t\t$\n"
			 << "=================================\n\n"
			 << "| -------\t\t\t\t+\n"
			 << "| M E N U - - - - - - - - - - - - - - - +\n"
			 << "| -------\t\t\t\t+\n"
			 << "| 1. Beli Tiket\t\t\t\t+\n"
			 << "| 2. Daftar Pembeli Tiket\t\t+\n"
			 << "| 3. Pembatalan Tiket\t\t\t+\n"
			 << "| 4. Pemberangkatan Kereta\t\t+\n"
			 << "| 5. Penandaan Telah Sampai Tujuan\t+\n"
			 << "| 0. Exit\t\t\t\t+\n"
			 << "| - - - - - - - - - - - - - - - - PILIH : ";
        cin >> pilih;
        system("cls");
        cout << endl;

        switch(pilih)
        {
        case 1 :
            {
                if(queuekosong())
                {
                    buatqueue();
                    buatstack();
                }

                while(pilih == 1)
                {
                    
                    cout << "===============================\n"
						 << "$                             $\n"
						 << "$       MENU BELI TIKET       $\n"
						 << "$                             $\n"
						 << "===============================\n\n";
                    cout << "| Nama\t\t\t\t: "; 					cin.ignore();cin.getline(nama,sizeof(nama));
                    cout << "| Asal\t\t\t\t: "; 					cin.getline(asal,sizeof(asal));
                    cout << "| Tujuan\t\t\t: "; 					cin.getline(tujuan,sizeof(tujuan));
                    cout << "| Tanggal Berangkat (dd/mm/yyyy): ";	cin.getline(tgl,sizeof(tgl));
                    cout << "| Jumlah Penumpang\t\t: "; 			cin.getline(jumlahPenumpang,sizeof(jumlahPenumpang));
                    if((file = fopen("tiket.txt","w"))==NULL)
                    cout<<"file tidak dapat diciptakan";
					fread(&data, sizeof(data), 1, file);
					fread(&simpan1, sizeof(simpan1), 1, file);
					cin.ignore();
                    enqueue(nama, asal, tujuan, tgl, jumlahPenumpang);
                    cout << endl; system("pause");
                    system("cls");
                    fflush (stdin);
					fwrite(&data, sizeof(data), 1, file);
					fwrite(&simpan1, sizeof(simpan1), 1, file);
                    main();
                    fclose(file);
                }
            }
            break;
        case 2:
            {
				file = fopen("tiket.txt","r");
				fread(&data, sizeof(data), 1, file);
				fread(&simpan1, sizeof(simpan1), 1, file);
                if(!queuekosong())
                {
                    cetakqueue();
                }
                else
                    cout << "Tidak ada pembeli" << endl;
			}
            break;
        case 3:
            {
                if(!queuekosong())
                {	
					int pilih;
					
					system("cls");
					cetakqueue();
					cout << "\n\nMENU\n";
					cout << "1. Batalkan pembelian tiket di daftar pertama\n";
					cout << "2. Kembali\n";
					cout << "Pilih: ";
					cin >> pilih;
					if (pilih==1)
					{
						dequeue();
						cout << "\nTiket anda berhasil dibatalkan!";
                    }
                    else
					{
						system("cls");
						main();
					}
                }
                else
                    cout << "Tidak ada pembeli!!" << endl;
            }
            break;
        case 4:
            {
                if(!queuekosong())
                    cetakqueueBerangkat();
                else
                    cout << "Belum ada pembeli!" << endl;
            }
            break;
        case 5:
            {
                if(!queuekosong())
                {
                    batal();
                }
                else
                    cout << "Belum ada pembeli!" << endl;
            }
            break;
        case 0:
            exit(0);
            break;
        default :
            cout << "Input salah!" << endl;
            break;
        } cout << "\n\nKembali ke menu? (y/t) "; cin >> ulang;
        system("cls");
    } while(ulang == 'Y'||ulang == 'y');
		if (ulang!='y' || ulang!='Y')
		{
			exit(0);
		}
}

void buatqueue()
{
    qdepan = (dataPenumpang* ) malloc(sizeof(dataPenumpang));
    qdepan = NULL;
    qbelakang = qdepan;
    //Riwayat
    qdepan1 = (dataPenumpang*) malloc(sizeof(dataPenumpang));
    qdepan1 = NULL;
    qbelakang1 = qdepan;
}

int queuekosong()
{
    if(qdepan == NULL)
    {
        return(True);
    }
    else
        return(False);
}

void enqueue(char nama2[], char asal2[], char tujuan2[], char tgl2[], char jumlahPenumpang2[])
{
    typeptrqueue NB;
	NB=(dataPenumpang*) malloc(sizeof(dataPenumpang));
	strcpy(NB->nama, nama2);
	strcpy(NB->asal, asal2);
	strcpy(NB->tujuan, tujuan2);
	strcpy(NB->tgl, tgl2);
	strcpy(NB->jumlahPenumpang, jumlahPenumpang2);
	if (qdepan==NULL){
		qdepan=NB;
	}
	else{
		qbelakang->nextqueue=NB;
	}
	qbelakang=NB;
	qbelakang->nextqueue=NULL;
}

void dequeue()
{
    typeptrqueue hapus;
	if(queuekosong())
	{
		cout << "Queue masih kosong!";
	}
	else
	{
		hapus=qdepan;
		qdepan=hapus->nextqueue;
		{
			typeptrqueue NB;
            NB = (dataPenumpang *) malloc(sizeof(dataPenumpang));
            strcpy(NB->nama,hapus->nama);
            strcpy(NB->asal,hapus->asal);
            strcpy(NB->tujuan,hapus->tujuan);
            strcpy(NB->tgl,hapus->tgl);
            strcpy(NB->jumlahPenumpang,hapus->jumlahPenumpang);
            if (qdepan1 == NULL)
                qdepan1 = NB;
            else
                qbelakang1->nextqueue = NB;

            qbelakang1 = NB;
            qbelakang1->nextqueue = NULL;
		}
		//Riwayat
        free(hapus);
	}
}

void cetakqueue()
{	
	typeptrqueue bantu;
	bantu=qdepan; int i = 0;
		cout << "================================\n"
			 << "$                              $\n"
			 << "$        DAFTAR PEMBELI        $\n"
			 << "$                              $\n"
			 << "================================\n\n";
		cout.precision(6); cout << showpoint;
		cout.width(5); cout << "No |" << " ";
		cout.width(20); cout << "Nama" << " ";
		cout.width(15); cout << "Asal" << " ";
		cout.width(15); cout << "Tujuan" << " ";
		cout.width(20); cout << "Tanggal Berangkat" << " ";
		cout.width(20); cout << "Jumlah Penumpang" << " ";
		cout << "\n----------------------------------------------------------------------------------------------------";
  	do 
    {
		i++;
        cout << endl;
        cout.precision(6); cout << showpoint;
		cout.width(5); cout << i << " |" << " ";
		cout.width(20); cout << bantu->nama << " ";
		cout.width(15); cout << bantu->asal << " ";
		cout.width(15); cout << bantu->tujuan << " ";
		cout.width(20); cout << bantu->tgl << " ";
		cout.width(20); cout << bantu->jumlahPenumpang << " ";
		bantu=bantu->nextqueue;
	}while(bantu!=NULL);
}

void cetakqueueBerangkat()
{
	int pilih;
	
	if (queuekosong()){
		cout << " Data kosong!";
	}
	else{
		cetakqueue();
	}
	cout << "\n\nMENU\n";
	cout << "1. Berangkatkan penumpang pertama\n";
	cout << "2. Kembali\n";
	cout << "Pilih : "; cin >> pilih;
	switch(pilih){
		case 1 : {
			if (queuekosong()){
				cout << "Gagal , queue masih kosong!";
			}
			else{
				if(tstack>0){
					push(qdepan->nama, qdepan->asal, qdepan->tujuan, qdepan->tgl, qdepan->jumlahPenumpang);
					dequeue(); tstack--; tqueue++;
					cout << "\nPenumpang dari " << qbelakang1->asal << " atas nama " << qbelakang1->nama << " telah berangkat ke " << qbelakang1->tujuan << endl;
				}else{
					cout << "\n Mohon maaf penumpang yang berada di kereta sedang penuh\n";
				}
			}
			break;
		}
		case 2 : {
			system("cls");
			main();
			break;
		}
		default :
			cout << "Menu yang anda masukkan salah!\n";
	}
}

void batal()
{
	int pilih;
	
    system("cls");
	cout << "Data Perjalanan :\n\n";
	if (stackkosong()){
		cout << " Mohon Maaf, data masih kosong!";
	}
	else{
		cetakstack();
	}
	cout << "\nOpsi\n";
	cout << "1. Tandai perjalanan daftar pertama sudah selesai\n";
	cout << "2. Kembali\n";
	cout << "PILIH : "; cin >> pilih;
	switch(pilih){
		case 1 : {
			if (stackkosong()){
				cout << "\nGagal, data masih kosong!";
			}
			else{
				pop(); tstack++;
				cout << "\nSelamat sampai tujuan!\n Sisa slot : " << tstack << "\n";
			}
			break;
		}
		case 2 : {
			system("cls");
			main();
			break;
		}
		default :
	        system("pause");
			cetakqueueBerangkat();
	}
	
	system("pause");
}

void buatstack()
{
	typeptrstack NS;
	NS=NULL;
	awalstack=NS;
	akhirstack=NS;
}

int stackkosong()
{
	if(awalstack==NULL)
		return(True);
	else
		return(False);
}

void push(char nama2[], char asal2[], char tujuan2[], char tgl2[], char jumlahPenumpang2[])
{
	typeptrstack NS;
	NS=(dataPenumpang*) malloc(sizeof(dataPenumpang));
	strcpy(NS->nama, nama2);
    strcpy(NS->asal, asal2);
    strcpy(NS->tujuan, tujuan2);
    strcpy(NS->tgl, tgl2);
    strcpy(NS->jumlahPenumpang, jumlahPenumpang2);
	if (awalstack==NULL)
		awalstack=NS;
	else
		akhirstack->nextstack=NS;
	akhirstack=NS;
	akhirstack->nextstack=NULL;
}

void pop()
{
	typeptrstack hapus, bantu;
	if (stackkosong()){
		cout << "Stack kosong!\n";
	}
	else{
		bantu=awalstack;
		hapus=akhirstack;
		if (hapus==awalstack)
			awalstack=NULL;
		else{
			while(bantu->nextstack->nextstack!=NULL)
			bantu=bantu->nextstack;
			akhirstack=bantu;
			akhirstack->nextstack=NULL;
		}
		free(hapus);
	}
}

void cetakstack(){
	typeptrstack bantu;
	bantu=awalstack; int i=1;
	while(bantu!=NULL){
		cout << "Daftar Ke-" << i << "\n";
		cout << "Nama\t\t\t: " << bantu->nama << endl;
		cout << "Asal\t\t\t: " << bantu->asal << endl;
		cout << "Tujuan\t\t\t: " << bantu->tujuan << endl;
		cout << "Tanggal Berangk\t\t: " << bantu->tgl << endl;
		cout << "Jumlah Penumpang\t: " << bantu->jumlahPenumpang << endl;
		
		bantu=bantu->nextstack; i++;
	}
}
