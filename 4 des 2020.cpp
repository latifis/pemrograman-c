
//===LATIEF IRFANSYAH===//
//======124190056=======//

#include <iostream>
#include <windows.h>
#include <conio.h>
#define max 50
#define True 1
#define False 0
using namespace std;
int top=0, topbin=0, stack[max], stackbin[max];
void buatstack();
int stackkosong();
int stackbinkosong();
int stackpenuh();
void push(int IB);
void pushbin(int IP);
void pop();
void cetakstack();
void cetakstackbin();

int main()
{
	int pilih, IB;
	
	buatstack();
	
	do
	{
		cout << "Menu : ";
		cout << "\n1. Push";
		cout << "\n2. Lihat";
		cout << "\n3. Pop";
		cout << "\n4. Tumpukan Sampah";
		cout << "\n0. Exit";
		cout << "\nPilih : "; cin >> pilih;
		cout << endl;
		
		switch (pilih)
		{
			case 1 :
				cout << "\nMasukkan angka : "; cin >> IB;
				push(IB);
				break;
			case 2 :
				if (stackkosong())
				{
					cout << "\nStack Kosong !!";
				}
				else
				{
					cetakstack();
				}
				break;
			case 3 :
				if (stackkosong())
				{
					cout << "\nStack Kosong !!";
				}
				else
				{
					pop();
				}
				break;
			case 4 :
				if (stackbinkosong())
				{
					cout << "\nStack Kosong !!";
				}
				else
				{
					cetakstackbin();
				}
				break;
			case 0 :
				exit(0);
				break;
			default:
				cout << "Tidak ada dalam menu !! Exiting program !!";
		}
		getch();
		system("cls");
		
	} while (pilih<5 && pilih>0);
	
}

void buatstack()
{ 
	stack[top]=0; 
	stackbin[top]=0;
}

int stackkosong()
{ 
	if(top==0)
		return(True);
	else
		return(False); 
}

int stackbinkosong()
{ 
	if(topbin==0)
		return(True);
	else
		return(False); 
}

int stackpenuh()
{ 
	if(top==max)
		return(True);
	else
		return(False); 
}

void cetakstack()
{ 
	int i=top;
	cout << "\nBerikut isi stack : \n";
	while (i>=1)
	{ 
		cout << stack[i] << endl;
		i--; 
	}
}

void push(int IB)
{ 
	if (stackpenuh())
		cout << "stack overflow\n";
	else
	{
		top++;
		stack[top]=IB;
		stack[0]=top;
		cout << "\nPush " << IB << " berhasil"; 
	} 
}

void pushbin(int IP)
{
	topbin++;
	stackbin[topbin]=IP;
	stackbin[0]=topbin;
}

void pop()
{ 
	int IP;
	if (stackkosong())
		cout << "stack kosong\n";
	else
	{
		IP=stack[top];
		top--;
		stack[top]=stack[top];
		cout << "Pop " << IP << " berhasil";
		//stack[0]=top; 
		pushbin(IP);
	} 
}

void cetakstackbin()
{ 
	int i=topbin;
	cout << "\nBerikut stack yang dihapus : \n";
	while (i>=1)
	{ 
		cout << stackbin[i] << endl;
		i--; 
	}
}
