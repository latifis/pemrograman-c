#include <iostream>
using namespace std;

int main (){
	
	string nim[6];
	int  i, uts[6],uas[6], rata_uts, rata_uas, rata_total;
	float total[6];
	
	for (i=0; i<6; i++)
	{	
		cout << "Input NIM Mahasiswa ke-" << i+1 << " : ";
		cin >> nim[i];
		cout << "Input Nilai UTS : ";
		cin >> uts[i];
		cout << "Input Nilai UAS : ";
		cin >> uas[i];
		total[i] = (0.5*uts[i]) + (0.5*uas[i]);
		cout << "Total Nilai : " << total[i] << endl << endl;
		
		rata_uts = rata_uts + uts[i];
		rata_uas = rata_uas + uas[i];
		rata_total = rata_total + total[i];
	}
	
	rata_uts = rata_uts/6;
	rata_uas = rata_uas/6;
	rata_total = rata_total/6;
	
	cout << "Rata - Rata UTS : " << rata_uts << endl;
	cout << "Rata - Rata UAS : " << rata_uas << endl;
	cout << "Rata - Rata Total : " << rata_total << endl;
	
	cout << "  ___________ ___________ ___________ ___________________________" <<endl;
	cout << " |    NIM    | Nilai UTS | Nilai UAS |        Total Nilai        |" << endl;
	cout << " | 123030001 |     80    |     85    |           "<<total[0]<<"             |" << endl;
	cout << " | 123030002 |     45    |     60    |           "<<total[1]<<"             |" << endl;
	cout << " | 123030003 |     75    |     70    |           "<<total[2]<<"             |" << endl;
	cout << " | 123030004 |     65    |     55    |           "<<total[3]<<"              |" << endl;
	cout << " | 123030005 |    100    |     95    |           "<<total[4]<<"             |" << endl;
	cout << " | 123030006 |     30    |     60    |           "<<total[5]<<"              |" << endl;
	cout << " |___________ ___________ ___________ ___________________________" <<endl;
	cout << " | Rata-rata |     "<<rata_uts<<"    |     "<<rata_uas<<"    |           "<<rata_total<<"              |" << endl;
}

