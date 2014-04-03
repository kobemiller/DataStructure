#include "c1.h"
#include "c2-2.h"
#include "bo2-4.cpp"
#include "func2-3.cpp"

void main()
{
	LinkList L;
	ElemType e;
	int j;
	Status i;
	InitList(L);
	i = ListEmpty(L);
	printf("L�Ƿ�� i = %d (1���� 0����)\n", i);
	ListInsert(L, 1, 3);
	ListInsert(L, 2, 5);
	i = GetElem(L, 1, e);
	j = ListLength(L);
	printf("L�е�����Ԫ�ظ���=%d, ��һ������Ԫ�ص�ֵΪ%d.\n", j, e);
	printf("L�е�����Ԫ������Ϊ��");
	ListTraverse(L, print);
	PriorElem(L, 5, e);
	printf("5ǰ���Ԫ�ص�ֵΪ%d.\n", e);
	NextElem(L, 3, e);
	printf("3�����Ԫ�ص�ֵΪ%d.\n", e);
	printf("L�Ƿ�� %d(1:�� 0����)\n", ListEmpty(L));
	j = LocateElem(L, 5, equal);
	if ( j )
		printf("L�ĵ�%d��Ԫ��Ϊ5.\n", j);
	else
		printf("������ֵΪ5��Ԫ��.\n");
	i = ListDelete(L, 2, e);
	printf("ɾ��L�ĵ�2��Ԫ�أ�\n");
	if ( i )
	{
		printf("ɾ����Ԫ��ֵΪ%d, ����L�е�����Ԫ������Ϊ", e);
		ListTraverse(L, print);
	}
	else
		printf("ɾ�����ɹ���\n");
	ClearList(L);
	printf("���L�� L�Ƿ�գ�%d (1:�� 0:��)\n", ListEmpty(L));
	DestroyList(L);
}