#include "iostream"
#include "string"
using namespace std;

string nama[100];
string pass[100];
string user,kode,nam;
string pilih,menu;
string sepatu[50]={"JORDAN AJ 33 SE PF Grey","JORDAN AJ 2 RETRO Black","JORDAN AJ 7 RETRO PE Ray Allen","JORDAN AJ 9 RETRO Blue","JORDAN DNA LX Dark","JORDAN AJ 8 RETRO","JORDAN WMNS AJ 1 MID Military Olive"};

int n=0,p=0,men1,beli,beli1;
int harga[50]={2900000,2700000,2800000,2800000,1800000,2500000,2000000};
int size[8]={40,41,42,43,44,45,46};
int ukuruan;

char men0;
bool valid=false,log=false;

void listsepatu ();
void listsize ();
void login();
void buatakun();


int main(){
			
			for(int i=7; i<=50; i++){
			sepatu[i]="empty";
			harga[i]=0;
			}

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
		cout << "Berikut List Sepatu yang Tersedia	: \n";
		listsepatu();
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
		
		cout << " Masukan Password: "; getline(cin,pass[p]); n++;p++;
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

void listsepatu(){
		for(int i=0; i<=50; i++){
			if(sepatu[i]== "empty" ) break;
			cout << i+1 <<". "<< sepatu[i]; 
			cout <<"\n   Harga		: Rp "<< harga[i] << endl;
			listsize();
			cout << endl;
		}
		cout << "Pilih sepatu	: "; cin >> beli;
		cout << "Pilih size	: "; cin >> beli1;
}
void listsize(){
	cout << "   Size tersedia	: ";	
	for(int i=0; i<7; i++){
		cout << size[i];
		if(i<6)
			cout << ",";
		else
			cout << endl;
	}
}

