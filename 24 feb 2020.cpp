#include <iostream>
#include <math.h>

using namespace std;

int tambah(int awal,int akhir,int beda);
int kurang(int awal,int akhir,int beda);
float pecahan(float bilang, float sebut,float banyak);

int main(){
	int pilih, nilai1, nilai2, beda;
	float banyak;
	cout<<"Menu\n";
	cout<<"1. tambah atau kurang\n";
	cout<<"2. tambah pecahan\n";
	cout<<"pilih: ";cin>>pilih;
	switch (pilih)
	{
		case 1:
			cout<<"nilai 1 :";cin>>nilai1;
			cout<<"nilai 2 :";cin>>nilai2;
			cout<<"beda    :";cin>>beda;
			if (nilai1<nilai2)
			{
				cout<<tambah(nilai1,nilai2,beda);
			}
			if (nilai1>nilai2) {
				
				cout<<(nilai1*2)-kurang(nilai1,nilai2,beda);
			}
			break;
		case 2: cout<<"Masukkan jumlah : ";cin>>banyak;
				cout<<pecahan(2,3,banyak);
			break;
	}
	
	
	
	
}
int tambah(int awal,int akhir,int beda){
	int hasil;
	if(awal<=akhir){
		cout<<awal;
		if(awal==akhir || awal==akhir-1 || awal+beda>akhir){
			cout<<" = ";
		}

		else cout<<" + ";
	}
	if (awal>akhir)
	{
		hasil=0;
	}
	else hasil= awal+tambah((awal+beda),akhir,beda);
	return hasil;
}
int kurang(int awal,int akhir,int beda){
	int hasil;
	if(awal>=akhir){
		cout<<awal;
		if(awal==akhir || awal==akhir+1 || awal+beda<akhir){
			cout<<" = ";
		}

		else cout<<" - ";
	}
	if (awal<akhir)
	{
		hasil=0;
	}
	else{ 
	hasil=awal+kurang((awal-beda),akhir,beda);
	}
	return hasil;

}
float pecahan(float bilang, float sebut, float banyak){ 
    float hasil;
    cout<<bilang<<"/"<<sebut;
	if (banyak==0)
	{
		cout<<" = ";
	}
	else cout<<" + ";
    if (banyak==0)
    hasil=0;
    else
    hasil=pow(2,banyak)/pow(3,banyak)+pecahan(bilang*2,sebut*3,banyak-1);

    return hasil;
}
