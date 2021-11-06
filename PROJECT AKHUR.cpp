#include <iostream>
using namespace std;

int main (){

	//deklarasi
	
	int pilih, pilih1, pilih2, berapa, jmltkt;
	string pas, pas1, usn, usn1,pilihan;
	
	
	
	//deskripsi
	
	cout << "Menu Utama";
	cout << "\n1. daftar";
	cout << "\n2. login";
	cout << "\nmasukkan pilian : "; cin >> pilih;
	
	switch(pilih)
	{	
		case 1 :
			cout << "\n\nmenu daftar" << endl;
			cout << "\nusername : "; cin >> usn;
			cout << "\npassword : "; cin >> pas;
		case 2 :
			cout << "menu login" << endl;
			cout << "\nusername : "; cin >> usn1;
			cout << "\npassword : "; cin >> pas1;
			
			if (usn==usn1 && pas==pas1)
			{	cout << "login berhasil";
				
				cout << "Pesan berapa tiket? ";  cin >> berapa;
				string nama[berapa], email[berapa];
				int jmltkt[berapa], hp[berapa], ktp[berapa];
					for (int i=1;i<=berapa;i++)
					{	cout << "Masukan data ke " << i << "	: \n";
						cout << "Nama	: "; cin >> nama[i];
						cout << "Email	: "; cin >> email[i];
						cout << "No HP	: "; cin >> hp[i];
						cout << "No KTP	: "; cin >> ktp[i];
					}
				
					do
				{
					do
					{
						cout << "\ndaftar tujuan";
						cout << "\n1. Jogja-Jakarta";
						cout << "\n2. Jogja-Medan";
						cout << "\n3. Jogja-Bali";
						cout << "\n4. Jogja-Surabaya";
						cout << "\n5. Jogja-Palembang";
						cout << "\n6. Jogja-Makassar";
					
						cout << "\npilih : "; cin >> pilih1; cout << endl;
						
						cout << "\ndaftar pesawat";
						cout << "\n1. Garuda Indonesia";
						cout << "\n2. Liion Air";
						cout << "\n3. Citilink";
						cout << "\n4. Batik Air";
						
						cout << "\npilih : "; cin >> pilih2; cout << endl;
						
						
							
					}while (pilih=='ya');
					
					
					
					cout << "Kembali kemenu? (ya/tidak)"; cin >> pilihan;
				}while (pilihan=="ya");
				
				
				
				
			}
			else 
				cout << "login gagal";
				
	}			
	
	

	
	
}
