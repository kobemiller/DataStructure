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
	printf("�������������");
	ListTraverse(L, print);
	printf("�������������");
	ListTraverseBack(L, print);
	n = 2;
	ListDelete(L, n, e);
	printf("ɾ����%d����㣬ֵΪ%d, ������Ϊ��", n, e);
	ListTraverse(L, print);
	printf("����Ԫ�صĸ���Ϊ%d\n", ListLength(L));
	printf("�����Ƿ�Ϊ�գ�%d(1:�� 0:��)\n", ListEmpty(L));
	ClearList(L);
	printf("��պ������Ƿ�գ�%d(1:�� 0:��)\n", ListEmpty(L));

	for ( i = 1; i <= 5; i++ )
		ListInsert(L, i, i);
	ListTraverse(L, print);
	n = 3;
	j = GetElem(L, n, e);
	if ( j )
		printf("�����ĵ�%d��Ԫ��ֵΪ%d\n", n, e);
	else
		printf("�����ڵ�%d��Ԫ��\n", n);

	n = 4;
	i = LocateElem(L, n, equal);
	if ( i )
		printf("����%d��Ԫ���ǵ�%d��\n", n, i);
	else 
		printf("û�е���%d��Ԫ��\n", n);

	j = PriorElem(L, n, e);
	if ( j )
		printf("%d��ǰ����%d\n", n, e);
	else
		printf("������%d��ǰ��\n", n);

	j = NextElem(L, n, e);
	if ( j )
		printf("%d�ĺ����%d\n", n, e);
	else
		printf("������%d�ĺ��\n", n);
	
	DestroyList(L);
}