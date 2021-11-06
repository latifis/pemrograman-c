#include <iostream>
#include <math.h>
using namespace std;
int tambah(int awal,int batas,int beda);
int kurang(int awal,int batas,int beda, int hasil);
float pecahan(float atas, float bawah,float nilai);
int main(){
	int x, n1, n2, beda, hasil;
	float kali, a=2, b=3;
	cout<<"\t\t\t\t\t\t+---------Menu--------+\n";
	cout<<"\t\t\t\t\t\t|1. tambah atau kurang|\n";
	cout<<"\t\t\t\t\t\t|2. tambah pecahan    |\n";
	cout<<"\t\t\t\t\t\t+---------------------|\n";
	cout<<"\t\t\t\t\t\tpilih: ";cin>>x;
	switch (x)
	{
		case 1:
			cout<<"nilai 1 :";cin>>n1;
			cout<<"nilai 2 :";cin>>n2;
			cout<<"beda    :";cin>>beda;
			if (n1<n2)
			{
				cout<<tambah(n1,n2,beda);
			}
			if (n1>n2) {
				hasil=n1;
				cout<<kurang(n1,n2,beda,hasil);
			}
			break;
		case 2: cout<<"\tMasukkan jumlah : ";cin>>kali;
				cout<<pecahan(a,b,kali);
			break;
	}
	
	
	
	
}
int tambah(int awal,int batas,int beda){
	int hasil;
	if(awal<=batas){
		cout<<awal;
		if(awal==batas ||awal+beda>batas){
			cout<<" = ";
		}

		else cout<<" + ";
	}
	if (awal>batas)
	{
		hasil=0;
	}
	else hasil= awal+tambah((awal+beda),batas,beda);
	return hasil;
}
int kurang(int awal,int batas,int beda, int hasil){
	if(awal>=batas){
		cout<<awal;
		if(awal==batas || awal-beda<batas){
			cout<< " = ";
		}

		else cout<<" - ";
	}
	
	if (hasil!=awal || awal==beda)
	{
		hasil=hasil-awal;
	}
	
	if (awal-beda<batas)
	{
		if (awal-beda==batas)
		{ 
			return hasil-(awal-beda);
		}
		else return hasil;
	}
	else {
		return kurang(awal-beda,batas,beda,hasil);
	}

}
float pecahan(float atas, float bawah, float nilai){ 
    float hasil;
    cout<<atas<<"/"<<bawah;
	if (nilai==1)
	{
		cout<<" = ";
	}
	else cout<<" + ";
    
    if (nilai==1)
    hasil=0.6666666666666667;
    else hasil=pow(2,nilai)/pow(3,nilai)+pecahan(atas*2,bawah*3,nilai-1);

    return hasil;
}
