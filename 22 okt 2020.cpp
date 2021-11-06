#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

void atas();
void bawah();
void h();
void a();
void p();
void y();
void b();
void i();
void r();
void t();
void d();
void slep();
void tulis();
void slep1();


int main (){
	
	string nama;
	
	cout << "\n(*nb : 1. Harus di fullscreen yaaa program ini, jadi kalo belom di fullscreen dulu ,,, 2. kalo ada garis underscore kedip-kedip tekan enter yaa,,,)";
	getch();
	
	cout << "\n\n***=============================================================***" << endl; Sleep(500);
	cout << "***=============================================================***" << endl;Sleep(500);
	cout << "|||								|||" << endl;Sleep(200);
	cout << "|||								|||" << endl;Sleep(200);
	cout << "|||		***	***	*********	***		|||" << endl;Sleep(500);
	cout << "|||		***	***	***   ***	***		|||" << endl;Sleep(500);
	cout << "|||		***	***	***   ***	***		|||" << endl;Sleep(500);
	cout << "|||		***	***	***   ***	***		|||" << endl;Sleep(500);
	cout << "|||		***********	*********	***		|||" << endl;Sleep(500);
	cout << "|||		***********	*********	***		|||" << endl;Sleep(500);
	cout << "|||		***	***	***   ***	***		|||" << endl;Sleep(500);
	cout << "|||		***	***	***   ***	***		|||" << endl;Sleep(500);
	cout << "|||		***	***	***   ***	***		|||" << endl;Sleep(500);
	cout << "|||								|||" << endl;Sleep(200);
	cout << "|||								|||" << endl;Sleep(200);
	cout << "****============================================================***" << endl;Sleep(500);
	cout << "****============================================================***" << endl;Sleep(500);
	cout << ". ";Sleep(500);cout << ". ";Sleep(500);cout << ". ";Sleep(500);cout << ". ";
	getch();
	cout << endl;
	system("cls");
	
	cout << "\n  Bagian 1 ";
	cout << ". ";Sleep(500);cout << ". ";Sleep(500);cout << ". ";Sleep(500);cout << ". ";
	cout << "\n\n\n\n	SELAMAT DATANG DI,"; Sleep(1000);
	cout << " DI INI APA YAA? HAHAHAHA";
	getch();
	cout << "\n\n	MAU TANYA NIH, "; Sleep(1100); cout << "NAMANYA SIAPA YA ? (KHUSUS YG INI KETIKKAN NAMAMU)"; cin >> nama;
	
	system("cls");
	cout << "\n  Bagian 1 ";
	cout << ". . . . ";
	cout << "\n\n\n\n	SELAMAT DATANG DI,";
	cout << " DI INI APA YAA? HAHAHAHA";
	cout << "\n\n	MAU TANYA NIH, NAMANYA SIAPA YA ? ";
	
	cout << "\n\n	" << nama << " ?!?"; Sleep(700); cout << " JELEK BANGET NAMANYA HAHAHAAHA";
	getch();
	cout << "\n\n	HAHAHA ,,"; Sleep(1000); cout << "JANGAN MARAH ,,"; Sleep(1000); cout << " CUMA BERCANDA KOK HEHEHE";getch();
	cout << "\n\n	BTW SEKARANG ULTAH YA??";getch();
	cout << "\n\n	SELAMAT ULANG TAHUN YAAA '" << nama << "' :D";getch();
	cout << "\n\n\n\nADA YANG MENARIK NIH, "; Sleep(1000); cout << "LIHAT DI BAGIAN 2 YAA";getch();
	cout << "\n\n(Tekan enter untuk melanjutkan ke bagian 2) "; Sleep(500);cout << ". "; Sleep(500);cout << ". "; Sleep(500);cout << ". ";
	getch();
	system("cls");

	bawah();	
	atas();
	bawah();
	atas();
	h(); a(); p(); p(); y();
	b(); i(); r(); t(); h(); d(); a(); y();
	bawah();
	tulis();
	
	getch();
}

void atas(){
	int a = 40, b = 0, c = 25;
	
	char A[c][a];
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < a; j++)
		{
			A[i][j]='*';
		}
	}
	
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < a-b; j++)
		{
			cout << A[i][j] << "  ";
			Sleep(5);
		}
		if (b<25)
		{
			b=b+2;
		}
		else
		{
			b=b+1;
		}
		cout << endl;
	} 
}

void bawah(){
	int a = 40, c = 25, d=3;
	
	char A[c][a];
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < a; j++)
		{
			A[i][j]='*';
		}
	}
	
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			cout << A[i][j] << "  ";
			Sleep(5);
		}
		if (d<15)
		{
			d=d+1;
		}
		else
		{
			d=d+2;
		}
		cout << endl;
	}
}

void h(){
	cout << "*  *" << endl; slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	
}

void a(){
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	
}

void p(){
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *" << endl;slep();
	cout << "*  *  *" << endl;slep();
	cout << "*  *  *" << endl;slep();
	cout << "*  *  *" << endl;slep();
	cout << "*  *  *" << endl;slep();
	cout << "*  *  *" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
}

void y(){
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "               *  *  *" << endl;slep();
	cout << "               *  *  *" << endl;slep();
	cout << "               *  *  *" << endl;slep();
	cout << "               *  *  *" << endl;slep();
	cout << "               *  *  *" << endl;slep();
	cout << "               *  *  *" << endl;slep();
	cout << "               *  *" << endl;slep();
	cout << "            *  *" << endl;slep();
	cout << "         *  *" << endl;slep();
	cout << "      *  *" << endl;slep();
	cout << "   *  *" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
}

void b(){
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	
}

void i(){
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *" << endl;slep();
	
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	
}

void r(){
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *" << endl;slep();
	cout << "*  *  *     *  *  *" << endl;slep();
	cout << "*  *  *        *  *  *" << endl;slep();
	cout << "*  *  *           *  *  *" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
}

void t(){
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	
	cout << "*  *  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "         *  *  *" << endl;slep();
	cout << "      *  *" << endl;slep();
	cout << "   *  *" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	
}

void d(){
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *         *  *  *" << endl;slep();
	cout << "*  *  *         *  *  *" << endl;slep();
	cout << "*  *  *          *  *  *" << endl;slep();
	cout << "*  *  *          *  *  *" << endl;slep();
	cout << "*  *  *          *  *  *" << endl;slep();
	cout << "*  *  *           *  *  *" << endl;slep();
	cout << "*  *  *            *  *  *" << endl;slep();
	cout << "*  *  *           *  *  *" << endl;slep();
	cout << "*  *  *          *  *  *" << endl;slep();
	cout << "*  *  *          *  *  *" << endl;slep();
	cout << "*  *  *         *  *  *" << endl;slep();
	cout << "*  *  *         *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *  *" << endl;slep();
	cout << "*  *  *  *  *  *" << endl;slep();
	cout << "*  *" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*" << endl;slep();
	cout << "*  *" << endl;slep();
	
}

void slep(){
	Sleep(10);
}

void slep1(){
	Sleep(100);
}

void tulis(){
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *              *  *              *  *              *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *                 *  *              *  *              *  *              *  *              *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *  *  *  *     *  *  *  *  *  *  *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *  *  *  *     *  *  *  *  *  *  *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *  *  *  *     *  *  *  *  *  *  *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *  *  *  *     *  *  *  *  *  *  *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *  *  *  *     *  *  *  *  *  *  *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *     *  *     *  *     *  *  *  *  *     *  *  *  *  *              *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	
	
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *           *  *  *  *           *  *              *  *                 *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *        *  *  *  *     *  *  *     *  *     *  *                 *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *        *  *  *     *  *  *     *  *     *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *  *     *  *  *     *  *     *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *        *  *  *     *  *  *     *  *     *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *        *  *  *  *     *  *  *     *  *     *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *           *  *  *  *  *     *  *  *              *  *  *  *     *  *  *  *              *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *        *  *  *  *     *  *  *           *  *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *        *  *  *     *  *  *        *  *  *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *  *     *  *  *     *  *  *     *        *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *  *        *  *  *     *  *  *     *        *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *     *        *  *  *  *     *  *  *     *  *     *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *           *  *  *  *           *  *     *  *     *  *  *  *     *  *  *  *     *  *     *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	
	
	
	
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *                    *  *  *                 *  *     *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *        *  *  *     *  *  *     *  *     *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *  *        *  *     *  *  *     *  *     *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *  *  *     *  *     *  *  *     *  *     *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *  *  *     *  *     *  *  *     *  *     *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *  *  *     *  *     *  *  *     *  *     *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *  *  *     *  *                 *  *                 *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *  *  *     *  *     *  *  *     *  *  *  *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *  *  *     *  *     *  *  *     *  *  *  *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *  *        *  *     *  *  *     *  *  *  *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *     *  *  *        *  *  *     *  *  *     *  *  *  *  *  *     *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *                 *  *  *  *     *  *  *     *  *                 *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "   *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "      *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "         *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "            *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "               *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                     *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                        *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                           *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                              *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                                 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                                    *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                                       *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                                          *  *  *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                                             *  *  *  *  *  *  *  *  *" << endl;slep1();
	cout << "                                                *  *  *  *  *  *  *" << endl;slep1();
	cout << "                                                   *  *  *  *  *" << endl;slep1();
	cout << "                                                      *  *  *" << endl;slep1();
	cout << "                                                         *" << endl;slep1();
	cout << "                                                      *" << endl;slep1();
	cout << "                                                   *" << endl;slep1();
	cout << "                                                *" << endl;slep1();
	cout << "                                             *" << endl;slep1();
	cout << "                                          *" << endl;slep1();
	cout << "                                       *" << endl;slep1();
	cout << "                                    *" << endl;slep1();
	cout << "                                 *" << endl;slep1();
	cout << "                              *" << endl;slep1();
	cout << "                           *" << endl;slep1();
	cout << "                        *" << endl;slep1();
	cout << "                     *" << endl;slep1();
	cout << "                  *" << endl;slep1();
	cout << "               *" << endl;slep1();
	cout << "            *" << endl;slep1();
	cout << "         *" << endl;slep1();
	cout << "      *" << endl;slep1();
	cout << "   *" << endl;slep1();
	cout << "*" << endl;slep1();
	cout << "*" << endl;slep1();
	cout << "*" << endl;slep1();
	cout << "*" << endl;slep1();
	cout << "\"AKU MAU NITIP NIH YAAA ... ESTEH HEHA JANLUP YAAA KAKAAA" << endl;Sleep(100); 
	cout << "... TAPI HARUSNYA SIH TAMBAHIN DONG MASA CUMA ESTEH DOANG" << endl;Sleep(100);
	cout << "... MAKASIHHHHHHH :D\"" << endl;Sleep(100);
	cout << "-latif, Temanggung 2020";
	cout << "\n\n\n(TEKAN ENTER UNTUK KELUAR)";
	
}
