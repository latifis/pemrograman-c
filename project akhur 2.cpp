#include <iostream>
#include <string>
using namespace std;

string nama[100];
string pass[100];
string user,kode,nam, i;

int n=0,p=0,men1;
char men0;
bool valid=false,log=false;

void login();
void buatakun();


int main(){
do{
	cout <<
			" ++ ======  MENU UTAMA  ======= ++\n"
			" ||				||\n"
			" ||	 1. Buat Akun	        ||\n"
			" ||      2. Login	        ||\n"
			" ||	 3. Buat Pesanan        ||\n"
			" ||				||\n"
			" ++ =========================== ++\n\n\n"
			
			" Pilihan: "; cin >> men1;
			cin.ignore();

switch(men1){
	case 1:
		buatakun();
		break;
	case 2:
		login();
		break;
	case 3 :
		cout << "hurong cc";
		break;
	default:
		cout << " Input Tidak Ada Dalam Menu\n";
	}
	cout << "\nKembali ke Menu Utama?(y/n)"; cin>>men0;
	cout << "\n\n\n\n";
}while(men0=='y'||men0=='Y');
	return 0;
}



void buatakun(){
		
		cout << "\n\n\n ====  Menu Buat Akun  ====\n\n";
		cout << " Masukan Username: "; getline(cin,nam);
		
		cout << " Masukan Password: "; getline(cin,pass[p]); 
		cout << endl << "Akun Telah Berhasil Dibuat\n\n";
}


void login(){
	valid=false;
		
		cout << "\n\n\n ====  Menu Login  ====\n\n";
		cout << "\n Masukan Username: "; getline(cin,user);
		cout << " Masukan Password: "; getline(cin,kode);
		
		for(int i=0; i<100; i++){
			if(nama[i]==user && pass[i]==kode){
			valid=true;
			break;
			}
		}
		if(valid==false)
		cout<< "\n Belum Punya Akun ?? Silahkan mendaftar di Menu Buat Akun\n";
		else{
		cout << "\n Login Berhasil\n\n";
		log=true;
	}
		
}
