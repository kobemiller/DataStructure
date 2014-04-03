#include "c1.h"
#include "c2-1.h"
#include "bo2-1.cpp"
#include "func2-3.cpp"

void Union(SqList &La, SqList &Lb)
{
//将所有在线性表Lb中但不在La中的数据元素插入到La中
	ElemType e;
	//int La_len, Lb_len;
	int i;
	//La_len = ListLength(La);
	//Lb_len = ListLength(Lb);
	for ( i = 1; i <= Lb.length; i++ )
	{
		GetElem(Lb, i, e);
		if ( !LocateElem(La, e, equal) )
			ListInsert(La, ++La.length, e);
	}
}

void main()
{
	SqList La, Lb;
	int j;
	InitList(La);
	for ( j = 1; j <= 5; j++ )
		ListInsert(La, j, j);
	printf("La = ");
	ListTraverse(La, print1);
	InitList(Lb);
	for ( j = 1; j <= 5; j++ )
		ListInsert(Lb, j, 2 * j);
	printf("Lb = ");
	ListTraverse(Lb, print1);
	Union(La, Lb);
	printf("new La= ");
	ListTraverse(La, print1);
}