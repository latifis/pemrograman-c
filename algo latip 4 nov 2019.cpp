#include <iostream>
using namespace std;

int main (){
	
		int i;
		int uts[6]={80, 45, 75, 65, 100, 30};
		int uas[6]={85, 60, 70, 55, 95, 50};
		int total[6];
		float jum_uts, jum_uas, jum_total=0, rata_uts, rata_uas, rata_total;
		
		cout << " ===================================================================== " << endl;
		cout << " ||      NIM      ||   Nilai UTS  ||   Nilai UAS  ||   Total Nilai  ||" << endl;
		cout << " ===================================================================== " << endl;
		
		for (i=0; i<6; i++)
		{
			total[i]= (0.5*uts[i]) + (0.5*uas[i]);
			
			if (i==4)
				cout << " ||   12303000" << i << "   ||     " << uts[i] << "      ||      " << uas[i] << "      ||       " << total[i] << "       || " << endl;
			else
				cout << " ||   12303000" << i << "   ||     " << uts[i] << "       ||      " << uas[i] << "      ||       " << total[i] << "       || " << endl;
			
			jum_uts = jum_uts + uts[i];
			jum_uas = jum_uas + uas[i];
			jum_total = jum_total + total[i];
		}
			
		cout << " ===================================================================== " << endl;
		
		rata_uts = jum_uts/6;
		rata_uas = jum_uas/6;
		rata_total = jum_total/6;
		
		cout << " ||   Rata-rata   ||     " << rata_uts << "       || " << rata_uas <<   "|| "  << rata_total << " ||" << endl;	
	
	 
	
	
	
	
	
	
	
	
	
}
