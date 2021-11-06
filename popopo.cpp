#include <iostream> 
using namespace std;  
int main() 
{
	int i; 
	int nim[6] = {123030001, 123030002, 123030003, 123030004, 123030005, 123030006};
	int uts [6] = {80, 45, 75, 65, 100, 30};
	int uas [6] = {85, 60, 70, 55, 95, 50};
	float total=0, jmluts=0, jmluas=0, jmltotal=0;
	float rtuts, rtuas, rttotal;
	
	cout<<"+=========================================================================+"<<endl;
	cout<<"|\t\t\t\tLAPORAN NILAI MAHASISWA\t\t\t\t|"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	
	 cout<<"|\t NIM \t\t| "<<"\t Nilai UTS \t| "<<"\t Nilai UAS \t| "<<"\t Total \t\t|"<<endl;
	 cout<<"--------------------------------------------------------------------------"<<endl;
	 
	for (i=0; i<6; i++)
	{
		total=(0.5*uts[i])+(0.5*uas[i]);
		cout<<"|    "<<nim[i]<<"\t\t|\t "<<uts[i]<<"\t\t|\t  "<<uas[i]<<"\t\t|\t  "<<total<<"\t\t|\t  "<<"\n";
		jmluts=jmluts+uts[i];
		jmluas=jmluas+uas[i];
		jmltotal=jmltotal+total;
		
		cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	}
	rtuts=jmluts/i;
	rtuas=jmluas/i;
	rttotal=jmltotal/i;
	
	cout<<"| Rata-Rata"<<"\t\t|\t "<<rtuts<<"\t|\t  "<<rtuas<<"\t|\t  "<<rttotal<<"\t\t| "<<endl;
	
	cout<<"+===============================================================================================+"<<endl<<endl;
	
}
