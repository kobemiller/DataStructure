#include "c1.h"
#include "c2-2.h"
#include "bo2-2.cpp"
#include "func2-3.cpp"

void CreateList(LinkList &L, int n)
{
//逆位序（插在表头）输入n个元素的值，建立带表头结构的单链线性表L
	int i;
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	printf("请输入%d个数据\n", n);
	for ( i = n; i > 0; --i )
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}

void CreateList2(LinkList &L, int n)
{
//正位序（插在表尾）输入n个元素的值，建立带表头结构的单链线性表L
	int i;
	LinkList p, q;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	q = L;
	printf("请输入%d个数据\n", n);
	for ( i = 1; i <= n; i++ )
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		q->next = p;
		q = q->next;
	}
	p->next = NULL;
}

void MergeList(LinkList La, LinkList &Lb, LinkList &Lc)
{
//已知单链线性表La和Lb的元素按值非递减排列
//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列
	LinkList pa = La->next, pb = Lb->next, pc;
	Lc = pc = La;
	
	while ( pa && pb )
		if ( pa->data <= pb->data )
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	pc->next = pa ? pa : pb;
	free(Lb);
	Lb = NULL;
}

void main()
{
	int n = 5;
	LinkList La, Lb, Lc;
	printf("按非递减顺序，");
	CreateList2(La, n);
	printf("La= ");
	ListTraverse(La, print);
	printf("按非递增顺序，");
	CreateList(Lb, n);
	printf("Lb= ");
	ListTraverse(Lb, print);
	MergeList(La, Lb, Lc);
	printf("Lc= ");
	ListTraverse(Lc, print);
}