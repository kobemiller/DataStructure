#include "c1.h"
#include "c2-2.h"
#include "bo2-4.cpp"
#include "func2-3.cpp"

void MergeList(LinkList &La, LinkList Lb)
{
//将Lb合并到La的表尾，由La指示新表
	LinkList p = Lb->next;
	Lb->next = La->next;
	La->next = p->next;
	free(p);
	La = Lb;
}

void main()
{
	int n = 5, i;
	LinkList La, Lb;
	InitList(La);
	for ( i = 1; i < n; i++ )
		ListInsert(La, i, i);
	printf("La = ");
	ListTraverse(La, print);
	
	InitList(Lb);
	for ( i = 1; i < n; i++ )
		ListInsert(Lb, i, i*2);
	printf("Lb = ");
	ListTraverse(Lb, print);
	MergeList(La, Lb);
	printf("La+Lb = ");
	ListTraverse(La, print);
}