#include <iostream>
#include <string.h>
using namespace std;

main(){
	int bnykmhs;	
	cout<<"Banyaknya mahasiswa: "; cin>>bnykmhs;
	cout<<endl;
	
	typedef struct
	{
		int kodemka;
		char nangka,kelas;
	}nilai;
	
	
	typedef struct
	{
		char nomhs[9];
		string namamhs;
		int jmlmka;
		nilai mka[10];
	}datanilai;
	
	datanilai nilaimhs[bnykmhs];
	
	for (int i=0;i<bnykmhs;i++)
	{
		cout<<"\tNo Mhs:\t"; cin>>nilaimhs[i].nomhs;
		cout<<"\tNama:\t"; cin>>nilaimhs[i].namamhs;
		cout<<"\tJumlah MKA: "; cin>>nilaimhs[i].jmlmka;
		for (int j=0;j<nilaimhs[i].jmlmka;j++)
		{
			cout<<"\t\tKode MKA:\t"; cin>>nilaimhs[i].mka[j].kodemka;
			cout<<"\t\tKelas:\t"; cin>>nilaimhs[i].mka[j].kelas;
			cout<<"\t\tNilai UTS:\t"; cin>>nilaimhs[i].mka[j].nangka;
		}
		cout<<endl;
	}
	
	/*if(nangka<=100)
	{
		nhuruf = 'A';
	}
	else if (nhuruf<=75)
	{
		nhuruf = 'B';
	}
	else if (nhuruf<=60)
	{
		nhuruf = 'C';
	}
	else if (nhuruf<=40)
	{
		nhuruf = 'D';
	}
	else
	{
		nhuruf = 'E';
	}
	*/	
	
				if (b<100 && b>=75)
					mhs.data.nilaihuruf[i][j]='A';
				else if (b<75 && b>=60)
					mhs.data.nilaihuruf[i][j]='B';
				else if (b<60 && b>=40)
					mhs.data.nilaihuruf[i][j]='C';
				else if (b<40 && b>=20)
					mhs.data.nilaihuruf[i][j]='D';
				else if (b<20 && b>=0)
					mhs.data.nilaihuruf[i][j]='E';
	for(int i=0;i<bnykmhs;i++)
	{
		cout<<"No Mhs\t: "<<nilaimhs[i].nomhs;
		cout<<"Nama\t: "<<nilaimhs[i].namamhs;
		cout<<"\tKode MKA\tKelas\tNilai UTS\tNilai Angka";
		cout<<endl;
		for(int j=0;j<nilaimhs[i].jmlmka;j++)
		{
		cout<<"\t"<<nilaimhs[i].mka[j].kodemka;
		cout<<"\t"<<nilaimhs[i].mka[j].kelas;
		cout<<"\t"<<nilaimhs[i].mka[j].nangka;
		//cout<<"\t"<<nhuruf<<"\t";
		cout<<endl;
		}
		cout<<endl;
	}
	
		
		
}
