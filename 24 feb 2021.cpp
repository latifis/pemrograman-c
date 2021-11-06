#include <iostream>
using namespace std;

main(){
	int bil[100], jml, bilangan;

	cout<<"Banyak angka: "; cin>>jml;
	
	for(int i=1; i<=jml; i++)
	{
		cout<<"Angka ke-"<<i<<": "; cin>>bil[i];
	}
	
	cout<<endl;
	cout<<"HASIL"<<endl;
	
	for(int i=1; i<=jml; i++)
	{
		bilangan = bil[i];
		
		if(bil[i]%2==1 || bil[i]%3==0)
		{
			cout<<"Angka ke-"<<i<<": ADA"<<endl;
			cout<<"  Bilangan pembagi: ";
			
			for(int i=1; i<bil[i]; i++)
			{
				if(bil[i]%2==1 && bilangan%bil[i]==0)
				{
				cout<<bil[i]<<" ";
				}
			}
			cout<<endl;
		}
		else
		{
			cout<<"Angka ke-"<<i<<": TIDAK ADA"<<endl;
		}
	}
	}

