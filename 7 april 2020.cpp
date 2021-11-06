//Latief Irfansyah
//124190056
//System Informasi B

#include <iostream>
#include <stdlib.h>

using namespace std;

void quick_sort(int angka[], int kiri, int kanan)
{
    int i = kiri, j = kanan;int temp;
    int pivot = angka[(kiri+kanan)/2];
	
	while (i<j)
	{
		while (angka[i] < pivot)
			i++;
		while (angka[j] > pivot)
			j--;
		
		if (i<=j)
		{
			temp = angka[i];
			angka[i] = angka[j];
			angka[j] = temp;
			i++;j--;
         };
     }; 
      
     if (kiri < j)
		quick_sort(angka, kiri, j);
     if (i < kanan)
		quick_sort(angka, i, kanan);
}

int main()
{
	
	int pilih, jbil, angka[100], temp, index, tengah;
	char akhir;
	
	do
	{
		cout << " = = = = Menu Pengurutan = = = = ";
		cout << "\n 1. Bubble Sort";
		cout << "\n 2. Quick Sort";
		cout << "\n 3. Selection Sort";
		cout << "\n 4. Insertion Sort";
		cout << "\n 5. Merge Sort";
		cout << "\n 6. Shell Sort";
		cout << "\n Pilih Menu : "; cin >> pilih;
		system("cls");
		
		switch (pilih)
		{
			case 1 :
				do
				{
					cout << " Metode Bubble Sort" << endl << endl;
					cout << " Masukkan jumlah bilangan (minimal 9): "; cin >> jbil;
					cout << endl;
					system("cls");
				} while (jbil<9);
				
				cout << "Metode Bubble Sort" << endl << endl;
				cout << "Input Angka : " << endl;
				
				for (int i = 0; i < jbil; i++)
				{
					cout << "\tAngka ke-" << i+1 << " : "; cin >> angka[i];
				}
				
				cout << "\nProses : " << endl;
				
				for(int i = 0; i < jbil-1; i++)
				{
					for(int j = 0; j < jbil-1; j++)
					{
						if(angka[j]>angka[j+1])
						{
							temp = angka[j];
							angka[j] = angka[j+1];
							angka[j+1] = temp;
							
							cout << "\t";
							
							for (int i = 0; i < jbil; i++)
							{
								cout << angka[i]<<" ";
							}
							cout<<endl;
						}
					}
				}
				break;
				
			case 2 :
				do
				{
					cout << " Metode Quick Sort" << endl << endl;
					cout << " Masukkan jumlah bilangan (minimal 9): "; cin >> jbil;
					cout << endl;
					system("cls");
				} while (jbil<9);
				
				cout << "Metode Quick Sort" << endl << endl;
				cout << "Input Angka : " << endl;
				
				for (int i = 0; i < jbil; i++)
				{
					cout << "\tAngka ke-" << i+1 << " : "; cin >> angka[i];
				}
				
				quick_sort(angka,0,jbil-1);
				break;
				
			case 3 :
				do
				{
					cout << " Metode Selection Sort" << endl << endl;
					cout << " Masukkan jumlah bilangan (minimal 9): "; cin >> jbil;
					cout << endl;
					system("cls");
				} while (jbil<9);
				
				cout << "Metode Selection Sort" << endl << endl;
				cout << "Input Angka : " << endl;
				
				for (int i = 0; i < jbil; i++)
				{
					cout << "\tAngka ke-" << i+1 << " : "; cin >> angka[i];
				}
				
				cout << "\nProses : " << endl;
				
				for(index = 0; index < jbil; index++)
				{
					for(int j = index+1; j < jbil; j++)
					{
						if(angka[index]>angka[j])
						{
							temp = angka[index];
							angka[index] = angka[j];
							angka[j] = temp;
							
							cout << "\t";
							
							for (int i = 0; i < jbil; i++)
							{
								cout << angka[i]<<" ";
							}
							cout<<endl;
						}
					}
				}		
				break;
				
			case 4 :
				do
				{
					cout << " Metode Insertion Sort" << endl << endl;
					cout << " Masukkan jumlah bilangan (minimal 9): "; cin >> jbil;
					cout << endl;
					system("cls");
				} while (jbil<9);
				
				cout << "Metode Insertion Sort" << endl << endl;
				cout << "Input Angka: " << endl;
				
				for (int i = 0; i < jbil; i++)
				{
					cout << "\tAngka ke-" << i+1 << " : "; cin >> angka[i];
				}
				
				cout << "\nProses : " << endl;
				
				for(int i = 0; i < jbil; i++)
				{
					
						temp = angka[i];
						int a = i-1;
						
						while (temp < angka[a] && a >= 0)
						{
							angka[a+1] = angka[a];
							a = a-1;
							angka[a+1] = temp;
						};
							
						cout << "\t";
							
						for (int i = 0; i < jbil; i++)
						{
							cout << angka[i]<<" ";
						}
						cout<<endl;
						
					
				}
				break;
			
			case 5 : 	
				do
				{
					cout << " Metode Merge Sort" << endl << endl;
					cout << " Masukkan jumlah bilangan (minimal 9): "; cin >> jbil;
					cout << endl;
					system("cls");
				} while (jbil<9);
				
				cout << "Metode Merge Sort" << endl << endl;
				cout << "Input Angka : " << endl;
				
				for (int i = 0; i < jbil; i++)
				{
					cout << "\tAngka ke-" << i+1 << " : "; cin >> angka[i];
				}
				
				cout << "\nProses : " << endl;
				
				for (int i = jbil/2; i > 0; i/=2)
				{
					for (int j = i; j < jbil; j++)
					{
						for (int k = j-i; k >= 0; k-=i)
						{
							if (angka[k+i] >= angka[k])
								{
									break;
								}
								else
								{
									tengah = angka[k];
									angka[k] = angka[k+i];
									angka[k+i] = tengah;
								}
							
						}
						
						cout << "\t";
						
						for (int l = 0; l < jbil; l++)
						{
							cout<<angka[l]<<" ";
						}
						cout<<endl;
					}
					cout<<endl;
				}		
				break;
			
			case 6 :
				do
				{
					cout << " Metode Shell Sort" << endl << endl;
					cout << " Masukkan jumlah bilangan (minimal 9): "; cin >> jbil;
					cout << endl;
					system("cls");
				} while (jbil<9);
				
				cout << "Metode Shell Sort" << endl << endl;
				cout << "Input Angka : " << endl;
				
				for (int i = 0; i < jbil; i++)
				{
					cout << "\tAngka ke-" << i+1 << " : "; cin >> angka[i];
				}
				
				cout << "\nProses : " << endl;
				
				for (int i = jbil/2; i > 0; i=i/2)
				{
					for (int j = i; j < jbil; j++)
					{
						for (int k = j-i; k >= 0; k=k-1)
						{
							if (angka[k+i] >= angka[k])
								{
									break;
								}
								else
								{
									temp = angka[k];
									angka[k] = angka[k+i];
									angka[k+i] = temp;
								}
						}
						
						cout << "\t";
						
						for (int l = 0; l < jbil; l++)
						{
							cout<<angka[l]<<" ";
						}
						cout<<endl;
					}
				}
							
				break;
				
			default:
				cout << "Tidak ada dalam menu";
		}
		
		cout << "\nHasil : " << endl << "\t";
		
		for (int i = 0; i < jbil; i++)
		{
			cout << angka[i] << " ";
		}
		
		cout << "\n\nKembali ke menu ? (y/n) : "; cin >> akhir;
		
		system("cls");
	} while (akhir=='y' || akhir=='Y');
		
}
