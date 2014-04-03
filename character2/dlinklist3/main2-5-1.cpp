#include "c1.h"
typedef int ElemType;
#include "c2-4.h"
#include "bo2-5.cpp"
#include "func2-3.cpp"

void main()
{
	DuLinkList L;
	int i, n;
	Status j;
	ElemType e;

	InitList(L);
	for ( i = 1; i <= 5; i++ )
		ListInsert(L, i, i);
	printf("正向输出链表：");
	ListTraverse(L, print);
	printf("逆向输出链表：");
	ListTraverseBack(L, print);
	n = 2;
	ListDelete(L, n, e);
	printf("删除第%d个结点，值为%d, 其余结点为：", n, e);
	ListTraverse(L, print);
	printf("链表元素的个数为%d\n", ListLength(L));
	printf("链表是否为空：%d(1:是 0:否)\n", ListEmpty(L));
	ClearList(L);
	printf("清空后，链表是否空：%d(1:是 0:否)\n", ListEmpty(L));

	for ( i = 1; i <= 5; i++ )
		ListInsert(L, i, i);
	ListTraverse(L, print);
	n = 3;
	j = GetElem(L, n, e);
	if ( j )
		printf("链表的第%d个元素值为%d\n", n, e);
	else
		printf("不存在第%d个元素\n", n);

	n = 4;
	i = LocateElem(L, n, equal);
	if ( i )
		printf("等于%d的元素是第%d个\n", n, i);
	else 
		printf("没有等于%d的元素\n", n);

	j = PriorElem(L, n, e);
	if ( j )
		printf("%d的前驱是%d\n", n, e);
	else
		printf("不存在%d的前驱\n", n);

	j = NextElem(L, n, e);
	if ( j )
		printf("%d的后继是%d\n", n, e);
	else
		printf("不存在%d的后继\n", n);
	
	DestroyList(L);
}