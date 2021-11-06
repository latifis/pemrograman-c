#include <iostream>
using namespace std;
int main ()
{
	int x, y, no, nama,kategori;
	
	cout<<"|*******************************************************|"<<endl;
	cout<<"|\t\t\tRESTORANKU\t\t\t|"<<endl;
	cout<<"|*******************************************************|"<<endl;
	cout<<"Nomor Pesanan           : ";cin>>no;
	cout<<"Nama Pemesanan          : ";cin>>nama;
	
	cout<<"||==============================================||"<<endl;
	cout<<"|| NO |  KATEGORI |      MENU      |    HARGA   ||"<<endl;
	cout<<"||==============================================||"<<endl;
	cout<<"||    |           | Ayam Goreng    | Rp 16.000  ||"<<endl;
	cout<<"|| 01 |  Makanan  | Ayam Bakar     | Rp 18.000  ||"<<endl;
	cout<<"||    |           | Lele Goreng    | Rp 13.000  ||"<<endl;
	cout<<"||----------------| Lele Bakar     | Rp 14.000  ||"<<endl;
	cout<<"|| 02 |  Minuman  | Es Jeruk       | Rp 3.000   ||"<<endl;
	cout<<"||    |           | Es Teh         | Rp 3.000   ||"<<endl;
	cout<<"||==============================================||"<<endl;
	
	cout<<"Masukan Kategori Menu :"; cin>>kategori;
	cout<<endl;
	
	switch(kategori)
	{
		case 1 :
		{
			cout<<"Masukan Banyak Makanan : "; cin>>x;
			
			int banyak;
			char menu[x][20];
			cin.ignore(); 
			for(int i=1; i<=x; i++)
			{
				cout<<"Masukkan Menu Makanan ke-"<<i<<"\t: ";
				cin.getline(menu[i],sizeof(menu[i]));
				cout<<"Masukkan banyak makanan\t\t: "; cin>>banyak;
				
				if (menu[i]=="Ayam Goreng")
				{
					cout<<"Harga = "<<16000*banyak;
				}
				if (menu[i]=="Ayam Bakar")
				{
					cout<<"Harga = "<<18000*banyak;
				}
				if (menu[i]=="Lele Goreng")
				{
					cout<<"Harga = "<<13000*banyak;
				}
				if (menu[i]=="Lele Bakar")
				{
					cout<<"Harga = 14000";
				}
				else
				{
					cout<<"Maaf, Menu Tidak Tersedia";
				}
				
			}
			/*for(i=1; i<=x; i++)
			{
				//gimana cara menjumlahkan harga
			}
			cout<<"Total harga makanan\t\t: Rp. "<<total1;*/
		}
		case 2 :
		{
			cout<<"Masukan Banyak Minuman : "; cin>>y;
			int banyak2;
			char menu[y][20];
			cin.ignore(); 
			for(int j=1; j<=y; j++)
			{
				cout<<"Masukkan Menu Makanan ke-"<<j<<"\t: "; cin>>menu[j];
				cin.getline(menu[j],sizeof(menu[j]));
				cout<<"Masukkan banyak makanan\t\t: "; cin>>banyak2;
				
				if (menu[j]=="Es Jeruk")
				{
					cout<<"Harga = "<<3000*banyak2;
				}
				if (menu[j]=="Es Teh")
				{
					cout<<"Harga = "<<3000*banyak2;
				}
				else
				{
					cout<<"Maaf, Menu Tidak Tersedia";
				}
				
			}
			/*for(i=1; i<=x; i++)
			{
				//gimana cara menjumlahkan harga
			}
			cout<<"Total harga minuman\t\t: Rp. "<<total1;*/
		}
		
	}
	/*th=total1+total2;
	cout<<"Total harga makanan\t\t: Rp "<<th;
    cout<<"\nMasukkan jumlah pembayaran\t: Rp "; cin>>bayar;
    if(bayar<th)
    {
		cout<<"Silahkan Tambahkan\t: Rp "<<th-bayar<<endl;
		cout<<"Pembayaran Tambahan\t: Rp "; cin<<bayar2;
	}
	if (bayar2>=th)
	{
		cout<<"Kembalian             : Rp "<<bayar2-(th-bayar)<<endl;
	}
	
	}
	else if (bayar>=th)
	{
		cout<<"Kembalian             : Rp "<<bayar-th;
	}	
	*/
	
}
