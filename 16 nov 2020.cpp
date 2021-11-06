#include <stdio.h>
#include <malloc.h>
typedef struct node *typeptr;
struct node{ int info;
		 typeptr next; };
int main()
{ int a = 56;
  typeptr p,q,r;
  p=(node *) malloc(sizeof(node));
  q=(node *) malloc(sizeof(node));
  r=(node *) malloc(sizeof(node));

  p->info=a;  r->next=p;  p=q; q->info=20;
  p->info=2 * r->next->info + 15;
  r->info=q->info; q=r->next; q->next=p;
  p->next=r->next; a=q->next->info + q->info - a;
  printf("p->next->next->info = %d\n",
  p->next->next->info);
  printf("q->next->info = %d\n",q->next->info);
  printf("r->info = %d\n",r->info);
  printf("a = %d",a);
}
