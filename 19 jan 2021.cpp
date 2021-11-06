/* Implementasi queue menggunakan list */
#include <iostream>
#include <malloc.h>
#define True 1
#define False 0
using std::cout;
typedef char typeinfo;
typedef struct typequeue *typeptr;
struct typequeue{typeinfo info;
typeptr next;
};
typeptr qdepan, qbelakang;
void buatqueue();
int queuekosong();
void enqueue(typeinfo *IB);
void dequeue();
void cetakqueue();
int main()
{ buatqueue();
cout << "Kondisi Awal queue setelah di enqueue : \n";
enqueue("A");
enqueue("B");
enqueue("C");
enqueue("D");
cetakqueue();
cout << "\n\nKondisi queue setelah di dequeue : \n";
dequeue();
cetakqueue();
cout << "\n\nKondisi Akhir queue setelah di enqueue : \n";
enqueue("E");
enqueue("F");
cetakqueue();
}
void buatqueue()
{ qdepan=(typequeue *) malloc(sizeof(typequeue));
qdepan=NULL;
qbelakang=qdepan;
}
int queuekosong()
{ if(qdepan==NULL)
return(True);
else
return(False);
}
void enqueue(typeinfo *IB)
{ typeptr NB;
NB=(typequeue *) malloc(sizeof(typequeue));
NB->info=*IB;
if (qdepan==NULL)
qdepan=NB;
else
qbelakang->next=NB;
qbelakang=NB;
qbelakang->next=NULL;
