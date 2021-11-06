#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

struct mhs {
int no;
string nama;
int kas;
}data[50];

struct outcome{
	int no;
	string tujuan;
	int jumlah;
}pengeluaran[50];

struct uang{
	int masuk;
	int keluar;
}catatan[13];

int login=0;

void inputdata(); //buat masukin data awal, no dan siswa ke dalam struct;
void urutin(int banyak); //sorting
void inputdatafile(int batas); //masukin data di array ke dalam file
void tambahdata();//menu buat tambah2 data
void load (int *banyak);
void lihatdata();
void hitungtotal(int *total, int batas);
void editdata();
void catatanmasuk();
void loadfilemasuk(int bln);
void hitungmasuk(int bln, int *hasil);
void inputfilecatatanmasuk();
void loadfilekeluar(int *batas);
void inputfilecatatankeluar(int *batas);
void loadfilekeluarbulanan();
void hitungpengeluaran (int bln, int *batas);
void pengeluaranbulanan(int bln, int *hasil);
void inputfilecatatankeluarbulanan();
void lihat();
void reset();
//main untuk menu utama
main (){
	
	if (login==0)
	{
		char sandi[3][4]={('y','y','n','y'),('y','n','y','y')};
	//array multi dimensi
	bool cek=false;
	//ini adalah sandi buat masuk program
	cout <<"Jawab pertanyaan dibawah ini dulu ya!"<<endl;
	cout <<"1. Apakah kamu manusia ? (y/n) : "; cin>>sandi[2][0];
	cout <<"2. Apakah kamu ganteng/cantik? (y/n) : "; cin>>sandi[2][1];
	cout <<"3. Apakah kamu bisa berhitung? (y/n) : "; cin>>sandi[2][2];
	cout <<"3. Apakah kamu yang terpilih menjadi bendahara? (y/n) : "; cin>>sandi[2][3];
	
	for (int i=0; i<2; i++){
		for(int j=0; j<4; j++){
			if (sandi[i][j]==sandi[2][j]){
				cek=true;
			}
			else{
				break;
			}
		}
	}

	login++;

	if (cek==true){
		system("cls");
		cout<<"Selamat datang bendahara kelas"<<endl;
	}
	else{
		cout <<"Maap jawaban kamu salah :), Kamu bukan bendahara yang terpilih"<<endl;
		exit(0);
	}
	}
	
	
	//variabel
	int pilih;
	int banyak=0;
	
	//program
	cout <<"Program BEKAL (Bendahara Kelas) C++" <<endl;
	cout <<"1. Isi data siswa"<<endl;
	cout <<"2. Tambah data kas"<<endl;
	cout <<"3. Lihat data kas"<<endl;
	cout <<"4. Edit data kas"<<endl;
	cout <<"5. Catat pemasukan dan pengeluaran"<<endl;
	cout <<"6. Lihat pemasukan dan pegeluaran"<<endl;
	cout <<"7. Reset data"<<endl;
	cout <<"8. Exit"<<endl;
	cout <<"pilih : "; cin >>pilih;
	switch (pilih){
		case 1:
			system("cls");
			inputdata(); //input data ke array dulu
			break;
		case 2:
			system("cls");
			tambahdata();
			break;
		case 3 :
			system("cls");
			lihatdata();
			break;
		case 4 :
			load(&banyak);
			if(banyak!=0){
				editdata();
			}
			else {
  				system("cls");
  				cout << "Anda harus mengisi data siswa terlebih dahulu"<<endl<<endl;
  				main();
  			}
			break;
		case 5 :
			load(&banyak);
			if(banyak!=0){
				system("cls");
				catatanmasuk();
			}
			else {
  				system("cls");
  				cout << "Anda harus mengisi data siswa terlebih dahulu"<<endl<<endl;
  				main();
  			}
			break;
		case 6 :
			load(&banyak);
			if(banyak!=0){
				system("cls");
				lihat();
			}
			else {
  				system("cls");
  				cout << "Anda harus mengisi data siswa terlebih dahulu"<<endl<<endl;
  				main();
  			}
			break;
		case 7 :
			reset();
			break;
		default : exit(0);
	}
	
}
void inputdata(){
	//variabel
	int banyak; //untuk batas
	char menu;
	bool sorted=false; // untuk cek urut atau ga

	//konfirmasi 
	cout << endl <<endl;
	cout <<"*Menu ini hanya dijalankan ketika pertama kali membuka program*"<<endl; //konfirmasi ini buat pertama kali jalanin doang
	cout <<"lanjutkan?(y/n) : "; cin >> menu;
	system("cls");
	if (menu=='y'){
	
		//program untuk memasukan data siswa
		cout<<"Masukan jumlah siswa : "; cin >> banyak;
		for (int i=0; i<banyak; i++){
			//isi data nomor absen dan nama
			cout <<i+1<<". No absen : "; cin>>data[i].no; 
			cout << "   Nama : "; cin.ignore(); getline(cin, data[i].nama);
	
			// sekalian buat data kas tiap siswa = 0
			data[i].kas=0;			
			}

		//cek apakah data nomor absen yang di input sudah urut	
		for (int i=0; i<banyak; i++){
			if (data[i].no!=i+1){ //kalo belum diurutin dulu
				sorted=true;
				break;
			}
		}
		//panggil void buat nguruti kalo belum urut
		if (sorted){
			urutin(banyak);
		}
		else{ //langsung inputdata ke-file kalo sudah urut
			inputdatafile(banyak); //input data ke file
			system("cls");
		}
			
	}
		
	else { //kalo konfirmasi no dia kembali ke menu utama
		system("cls");
		main();
	}
}
void urutin (int banyak){
	mhs temp;
	//selection sort urutin di array nya
	for (int i=0; i<banyak; i++){
		for (int j=i+1; j<banyak; j++){
			if (data[i].no>data[j].no){
				temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
	inputdatafile(banyak); //input data yang sudah urut ke file
}
void inputdatafile(int batas){
	
		 //untuk nulis ke txt
		ofstream input;
		
		//masukin array data siswa ke file1.txt
		input.open("file1.txt"); //knp ga pake ios::app, karena kita mau input data di awal
		for (int i=0; i<batas; i++){
			//masukin data siswa ke file1
			input << data[i].no << endl << data[i].nama<<endl;	
		}
		input.close();	
		
		//jadi file nama sama file uangkas disini dipisah skarena awalnya sering eror pas digabung

		//masukin array data kas ke file2.txt
		input.open("file2.txt");
		for (int i=0; i<batas; i++){
			input << data[i].no << endl << data[i].kas <<endl;
		}
		input.close();
		
		system("cls");
		cout << "data berhasil disimpan"<<endl;
		main();
		//selesai data disimpan dia kembali ke menu utama
}
void tambahdata(){
	//variabel
	int pilih, byr, tambah, no=0;
	int banyak=0;

	//jadi inget sebelum data nya kita tambah, kita load dulu data yang udah kita save di file
	load(&banyak);
	
	if (banyak!=0){ //dia ngecek kalo program load tadi berhasil di load , artinya nanti nilai banyak berubah baru dia bisa jalanin program ini
	
	//menu untuk tambah data
	cout <<"1. tambah data kas siswa dengan nomor absen "<<endl;
	cout <<"2. tambah data kas semua siswa"<<endl;
	cout <<"3. tambah data siswa"<<endl;
	cout <<"4. Kembali ke menu utama"<<endl;
	cout << "pilih : "; cin >> pilih;
	
	//pili
	switch (pilih){
		case 1 :
		//tampilin data nomor dan namanya
		cout <<"No || Nama                    ||"<<endl;
		cout<<"================================="<<endl; 
		for (int i=0; i<banyak; i++){
			cout << " "<< data[i].no << "    " << data[i].nama << endl;;
		}
		
		cout <<"pilih nomor absen siswa : "; cin >>pilih;
		
			//ini materi searching biasa
			for (int k=0; k<banyak; k++){
			if (pilih==data[k].no){
				cout << data[k].no << ". "<<data[k].nama<<endl;
				cout << "uang kas yang sudah dibayar : " << data[k].kas <<endl;
				cout << "bayar kas (x1000): "; cin >> byr;
				byr*=1000;
				data[k].kas+=byr;
				inputdatafile(banyak);
					system("cls");
					cout <<"data berhasil ditambahkan "<<endl<<endl;
					main();
				}
			}
			

		break;
		case 2 :

		for (int j=0; j<banyak; j++){
			cout << data[j].no << ". " << data[j].nama <<endl;
			cout << "uang kas yang sudah dibayar : " << data[j].kas <<endl;
			cout << "bayar kas (x1000) : "; cin >> byr;
			byr*=1000;
			data[j].kas+=byr;
		}
		inputdatafile(banyak);

		
		system("cls");
		cout <<"data berhasil ditambahkan "<<endl<<endl;
		main();
		break;
		case 3:
			cout << "Masukan banyak data siswa tambahan : "; cin >> tambah;
			for (int i=banyak; i<banyak+tambah; i++){
				cout <<no+1<<". No absen : "; cin>>data[i].no; 
				cout << "   Nama : "; cin.ignore(); getline(cin, data[i].nama);
				//buat data kas tiap siswa tambahannya = 0
				data[i].kas=0;
				no++;	
			}
			no=0; // kalo nanti nambah data lagi biar nomornya ngulang
			banyak+=tambah;
			//disini kita makai inpput karna kita masukin semua data barunya berurutan jadi datanya tinggal di input
			inputdatafile(banyak);
			
		break;
		case 4:
			system("cls");
			main();
		break;
		default : system("cls");
	}
  }	
  else {
  	//kalo nilai banyak belum ada dia bakal kembali kemenu utama
  	system("cls");
  	cout << "Anda harus mengisi data siswa terlebih dahulu"<<endl<<endl;
  	main();
  }
}
void load (int *banyak){
	int b;
		//load file ke dalam array buatditambah
		ifstream baca;
				baca.open("file1.txt");
				for(int i=0; true; i++){
					baca>>data[i].no;
					baca.ignore();
					getline(baca,data[i].nama);//getline karna namanya 
					if(baca.eof()){
						*banyak=i; //dia ngubah pointer banyak dengan nilai i buat batas array nanti
						break;
						}
					}
				baca.close();
				
			//jangan lupa karna file data kas itu beda jadi load juga data kasnya	
			baca.open("file2.txt");
			for (int j=0; j<=*banyak; j++){
				baca >> b; //biar array data no nya ga kedobel, jadi di load kesini aja variabel bantuan istilahnya
				baca >> data[j].kas;
			}
			baca.close();		
}
void lihatdata(){
//variabel
int batas=0, total=0;
load(&batas);
	if (batas!=0){
		
	//buat nampilin
	hitungtotal(&total, batas);
	cout <<"|| No. || Nama                   || bayar kas        ||"<<endl;
	for (int i=0; i<batas; i++){
		cout <<"|| "<<setiosflags(ios::left)<<setw(4)<<data[i].no<<"|| ";
		cout <<setiosflags(ios::left)<<setw(23)<<data[i].nama << "|| ";
		cout <<setiosflags(ios::left)<<setw(17)<<data[i].kas<<"||"<<endl;
	}
	cout << endl << endl << "total pemasukan kas : " << total;
	
			cout <<endl<<endl<<"tekan enter untuk kembali ke menu utama"<<endl;
			getch();
			system("cls");
			main();

}
  else {
  	//kalo nilai banyak belum ada dia bakal kembali kemenu utama
  	system("cls");
  	cout << "Anda harus mengisi data siswa terlebih dahulu"<<endl<<endl;
  	main();
  }
}
void editdata(){
	int pilih, byr, tambah, no=0;
	int banyak=0;

	//sama kaya sebelumnya kita load dulu data yang udah kita save di file
	load(&banyak);
	if (banyak!=0){
		
	//tampilin data yang udah diload tadi
	cout <<"|| No. || Nama                   || bayar kas        ||"<<endl;
	for (int i=0; i<banyak; i++){
		cout <<"|| "<<setiosflags(ios::left)<<setw(4)<<data[i].no<<"|| ";
		cout <<setiosflags(ios::left)<<setw(23)<<data[i].nama << "|| ";
		cout <<setiosflags(ios::left)<<setw(17)<<data[i].kas<<"||"<<endl;
	}
			cout <<"pilih data nomor siswa yang ingin di edit : "; cin >>pilih;
		
			//ini materi searching biasa
			for (int k=0; k<banyak; k++){
			if (pilih==data[k].no){
				cout <<"data sebelumnya : "<<endl;
				cout << data[k].no << ". "<<data[k].nama<<endl;
				cout << "uang kas yang sudah dibayar : " << data[k].kas <<endl<<endl;
				cout <<"Masukan data baru :"<<endl;
				cout << "No absen : "; cin >> data[k].no;
				cout << "Nama : "; cin.ignore(); getline(cin,data[k].nama);
				cout << "Uang kas : "; cin >> data[k].kas;
				inputdatafile(banyak);
					system("cls");
					cout <<"data berhasil diperbarui "<<endl<<endl;
					main();
				}
			}
	}
	else {
  	//kalo nilai banyak belum ada dia bakal kembali kemenu utama
  	system("cls");
  	cout << "Anda harus mengisi data siswa terlebih dahulu"<<endl<<endl;
  	main();
  }

}
//rekrusif
void hitungtotal(int *total, int batas){
	int nilaiakhir;
	if (batas>=0){
		*total+=data[batas].kas;
		batas-=1;
		hitungtotal(total, batas);
	}
}
void catatanmasuk(){
	int pilih, bln, hasil=0;
	int no=0;
	char opsi;
	
			for (int i=0; i<=12; i++){
			catatan[i].masuk=0;
			catatan[i].keluar=0;
			}
			
	cout<<"1. catat pemasukan bulanan"<<endl;
	cout<<"2. catat pengeluaran bulanan"<<endl;
	cout<<"3. kembali ke menu utama"<<endl;
	cout << "pilih : "; cin >> pilih;
	switch (pilih){
	case 1:
		cout <<"Ini adalah bulan ke-(1-12) ? : "; cin >> bln;
		hitungmasuk(bln-1, &hasil);

		if (hasil!=-1){
		cout << "!data telah terekam"<<endl;
		cout << "data pemasukan baru bulan ke-"<<bln<<" sebesar " << hasil;
		}
		
		cout <<endl<<endl<<"tekan enter untuk kembali ke menu utama"<<endl;
		getch();
		system("cls");
		main();
		break;


	case 2 :
			cout << "data pengeluaran kas bulan ke-(1-12) : "; cin>>bln;
			cout <<endl;
			loadfilekeluar(&no);
		do {//masukin data ke array dulu
			pengeluaran[no].no=no+1;
			cin.ignore();
			cout<<no+1<<". Keperluan : ";  getline(cin,pengeluaran[no].tujuan);
			cout<<"   Biaya (x1000): "; cin >> pengeluaran[no].jumlah;
			pengeluaran[no].jumlah*=1000;
			cout<<endl;
			cout <<"masukan lagi ? (y/n) : "; cin >> opsi;
			cout<<endl;
			no++;
		}while (opsi=='y');
		inputfilecatatankeluar(&no); //masukin datanya ke file
		loadfilekeluarbulanan(); //buat nyatat dan ngitung total pengeluaran bulanan
		hitungpengeluaran(bln-1, &no);
		hasil=no+1;
		pengeluaranbulanan(bln-1, &hasil);	
		inputfilecatatankeluarbulanan();

		cout<< "data pengeluaran baru ditambahkan sebesar : "<<hasil<<endl;
		cout<< "pengeluaran total bulan ke-"<<bln<<" : "<<catatan[bln-1].keluar<<endl;
		cout<< "total pengeluaran saat ini    : "<<catatan[12].keluar;
		cout <<endl<<endl<<"tekan enter untuk kembali ke menu utama"<<endl;
		getch();
		system("cls");
		main();
		
		break;
	case 3:
		system("cls");
		main();
		break;	
	}
}
void loadfilemasuk(){
	int b;
	int u;
	catatan[12].masuk=0;
	ifstream baca;
	baca.open("file3.txt");
	for (int i=0; i<12; i++){
		baca>>b;
		baca>>catatan[i].masuk;
		catatan[12].masuk+=catatan[i].masuk; //ngitung total uang masuk bulan bulan sebelumnya
		}
	
	baca.close();
}
void hitungmasuk(int bln, int *hasil){
	int batas=0;
	int uangbaru=0;
	load(&batas);
	loadfilemasuk();
	if (catatan[bln+1].masuk==0 || bln==11 ){
	
	for (int i=0; i<batas; i++){
		uangbaru+=data[i].kas;
	}

	uangbaru-=catatan[12].masuk;
	cout<<"pemasukan bulan-bulan sebelumnya : "<<catatan[12].masuk-catatan[bln].masuk<<endl;
	catatan[bln].masuk+=uangbaru;
	cout<<"pemasukan total bulan ke-"<<bln+1<<" : "<<catatan[bln].masuk<<endl;

	*hasil=uangbaru;
	catatan[12].masuk+=uangbaru;
	inputfilecatatanmasuk();
   }
   else {
   	*hasil=-1;
   	cout<<"akses dilarang karena anda sudah merekan data di bulan selanjutnya";
   }
}
void inputfilecatatanmasuk(){
	ofstream input;
			input.open("file3.txt");
			for (int i=0; i<=12; i++){
				input << i+1 << endl;
				input << catatan[i].masuk<<endl;
			}
			input.close();
}
void loadfilekeluar(int *batas){
	
	ifstream baca;
	baca.open("file4.txt"); 
	if (baca.fail()){//cek file nya dah ada belum, kalo belum dia langsung selese
		
		cout<<endl;
	}
	else { //kalo ada dia ngeload dulu datanya

		for (int i=0; true; i++){

		baca>>pengeluaran[i].no;
		baca.ignore();
		getline(baca,pengeluaran[i].tujuan);
		baca>>pengeluaran[i].jumlah;
			if (baca.eof()){

				*batas+=i;
				break;
			}
		}

	}
	baca.close();
}
void inputfilecatatankeluar(int *batas){
	int banyak;
	ofstream input;

	input.open("file4.txt");
	for (int i=0; i<*batas; i++){
		input<<i+1<<endl;
		input<<pengeluaran[i].tujuan<<endl;
		input<<pengeluaran[i].jumlah<<endl;
		banyak=i+1;
	}
	*batas=banyak;
	input.close();
	
}
void loadfilekeluarbulanan(){
	int b;
	ifstream baca;
	baca.open("file5.txt");
	for (int i=0; i<=12; i++){
			baca>>b; //baca urutan bulannya
			baca>>catatan[i].keluar; //baca pengeluaran
	}
	baca.close();
}
void hitungpengeluaran (int bln, int *batas){

	for (int i=0; i<*batas; i++){
		pengeluaran[*batas+1].jumlah+=pengeluaran[i].jumlah;
	}
}
void pengeluaranbulanan(int bln, int *hasil){
	int h;
	h=*hasil;
	catatan[bln].keluar=catatan[bln].keluar+(pengeluaran[h].jumlah-catatan[12].keluar);
	cout << pengeluaran[h].jumlah <<endl;
	cout<<catatan[12].keluar<<endl;
	 //pengeluaran baru dikurang pengeluaran sebelumnya
	
	cout<<"pengeluaran sebelumnya : "<<catatan[12].keluar<<endl;
	*hasil=pengeluaran[h].jumlah-catatan[12].keluar;
	catatan[12].keluar=pengeluaran[h].jumlah;

	inputfilecatatankeluarbulanan();
	
}
void inputfilecatatankeluarbulanan(){
	ofstream input;
			input.open("file5.txt");
			for (int i=0; i<=12; i++){
				input << i+1 << endl;
				input << catatan[i].keluar<<endl;
			}
			input.close();
}
void lihat(){
	int batas=0, total=0;
	int pilih;
	string bulan[12]={"Januari","Februari","Maret","April","Mei","Juni",
	"Juli","Agustus","September","Oktober","November","Desember"};
	
	system("cls");
	cout <<"1. Lihat semua data pemasukan dan pengeluaran"<< endl;
	cout <<"2. Lihat data pemasukan dan pengeluaran perbulan"<<endl;
	cout <<"3. kembali ke menu utama"<<endl;
	cout <<"pilih : "; cin>>pilih;
	switch(pilih){
		case 1:
			
			load(&batas);
			hitungtotal(&total, batas);
			cout << "               Pemasukan kas kelas "<<endl;
			cout <<"======================================================="<<endl;
			cout <<"|| No. || Nama                   || bayar kas        ||"<<endl;
			for (int i=0; i<batas; i++){
				cout <<"|| "<<setiosflags(ios::left)<<setw(4)<<data[i].no<<"|| ";
				cout <<setiosflags(ios::left)<<setw(23)<<data[i].nama << "|| ";
				cout <<setiosflags(ios::left)<<setw(17)<<data[i].kas<<"||"<<endl;
				}
				cout <<"============================================================="<<endl;
				cout << "total pemasukan kas : " << total << endl;
				batas=0;
				loadfilekeluar(&batas);
				total=0;
				cout<<endl;
			cout << "               Pengeluaran kas kelas "<<endl;
			cout <<"============================================================="<<endl;
			cout <<"|| No. || Keperluan                   || Kas Keluar        ||"<<endl;
			for (int i=0; i<batas; i++){
				cout<<"|| "<<setiosflags(ios::left)<<setw(4)<<pengeluaran[i].no<<"|| ";
				cout<<setiosflags(ios::left)<<setw(28)<<pengeluaran[i].tujuan<< "|| ";
				cout<<setiosflags(ios::left)<<setw(18)<<pengeluaran[i].jumlah<<"||"<<endl;
				total+=pengeluaran[i].jumlah;
			}
			cout <<"============================================================="<<endl;
			cout << "total pengeluaran kas : " << total << endl;
			cout<<endl<<"tekan enter untuk kembali ke menu sebelumnya"<<endl;
			getch();
			system("cls");
			lihat();
			break;
		case 2:
			loadfilekeluarbulanan();
			loadfilemasuk();
			loadfilekeluarbulanan();
			cout <<""<<endl;
			cout <<"======================================================================================"<<endl;
			cout <<"|| No. || Bulan             || Pemasukan         || Pengeluaran       || Subtotal   ||"<<endl;
			for (int i=0; i<12; i++){
				cout<<"|| "<<setiosflags(ios::left)<<setw(4)<<i+1<<"|| ";
				cout<<setiosflags(ios::left)<<setw(18)<<bulan[i]<<"|| ";
				cout<<setiosflags(ios::left)<<setw(18)<<catatan[i].masuk<<"|| ";
				cout<<setiosflags(ios::left)<<setw(18)<<catatan[i].keluar<<"|| ";
				cout<<setiosflags(ios::left)<<setw(11)<<catatan[i].masuk-catatan[i].keluar<<"|| "<<endl;
			}
			cout <<"======================================================================================"<<endl;
			cout <<"|| TOTAL  :"<<setiosflags(ios::right)<<setw(29)<<catatan[12].masuk;
			cout << setiosflags(ios::right)<<setw(23)<<catatan[12].keluar;
			cout << setiosflags(ios::right)<<setw(18)<<catatan[12].masuk-catatan[12].keluar<<"   ||"<<endl;
			cout <<"======================================================================================"<<endl;

			cout<<endl<<endl<<"tekan enter untuk kembali ke menu sebelumnya"<<endl;
			getch();
			system("cls");
			lihat();
			break;
		case 3:
			system("cls");
			main;
			break;
	}
}
void reset (){
	char opsi;
	cout <<endl<<endl<<"Anda yakin ingin mereset semua data ? (y/n) : "; cin>>opsi;
	if (opsi=='y'){
	ofstream input;
		input.open("file1.txt");
	input.close();
		input.open("file2.txt");
	input.close();
		input.open("file3.txt");
	input.close();
		input.open("file4.txt");
	input.close();
		input.open("file5.txt");
	input.close();
	system("cls");
	cout<<"data berhasil direset"<<endl;
	main();
	}
	else{
		system("cls");
		main();
	}
}
