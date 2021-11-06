#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
  
using namespace std;
  
//Struct pertama
struct data_tanggal
{
    int tanggal;
    int bulan;
    int tahun;
};
  
//Struct dalam struct
struct data_mahasiswa
{
    long int nim;
    char nama[100];
    char fakultas[100];
    data_tanggal tanggal_lahir;
};
  
data_mahasiswa mahasiswa , data_tanggal, tanggal_lahir;
  
int main()
{   
    //Input
    cout<<" NIM           : "; cin>>mahasiswa.nim;
    cout<<" Nama          : "; fflush(stdin); gets(mahasiswa.nama);
    cout<<" Fakultas      : "; fflush(stdin); gets(mahasiswa.fakultas);
    cout<<" Tanggal Lahir : "; cin>>mahasiswa.tanggal_lahir.tanggal;
    cout<<" Bulan Lahir   : "; cin>>mahasiswa.tanggal_lahir.bulan;
    cout<<" Tahun Lahir   : "; cin>>mahasiswa.tanggal_lahir.tahun;
    cout<<"\n\n";
 
    //Output
    cout<<" NIM           = "<<mahasiswa.nim<<endl;
    cout<<" Nama          = "<<mahasiswa.nama<<endl;
    cout<<" Fakultas      = "<<mahasiswa.fakultas<<endl;
    cout<<" Tanggal Lahir = "<<mahasiswa.tanggal_lahir.tanggal<<endl;
    cout<<" Bulan Lahir   = "<<mahasiswa.tanggal_lahir.bulan<<endl;
    cout<<" Tahun Lahir   = "<<mahasiswa.tanggal_lahir.tahun<<endl;
    cout<<"\n\n";
    getch();
}
