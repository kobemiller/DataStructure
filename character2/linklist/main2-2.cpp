#include "c1.h"
#include "c2-2.h"
#include "bo2-2.cpp"
#include "func2-3.cpp"

void main()
{
	LinkList L;
	ElemType e, e0;
	Status i;
	int j, k;

	InitList(L);
	for ( j = 1; j <= 5; j++ )
		i = ListInsert(L, 1, j);
	printf("��L�ı�ͷ���β���1~5��L= ");

	i = ListEmpty(L);
	printf("L�Ƿ�գ�i = %d(1:�� 0����)\n", i);

	ClearList(L);
	printf("���L��L= ");

	i = ListEmpty(L);
	printf("L�Ƿ�գ�i = %d(1:�� 0����)\n", i);

	for ( j = 1; j <= 10; j++ )
		ListInsert(L, j, j);
	printf("��L�ı�β���β���1~10��L= ");
	ListTraverse(L, print);

	GetElem(L, 5, e);
	printf("��5��Ԫ�ص�ֵΪ%d\n", e);

	for ( j = 0; j <=1; j++ )
	{
		k = LocateElem(L, j, equal);
		if ( k )
			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}

	for ( j = 1; j <= 2; j++ )
	{
		GetElem(L, j, e0);
		i = PriorElem(L, e0, e);
		if ( i == INFEASIBLE )
			printf("Ԫ��%d��ǰ��\n", e0);
		else 
			printf("Ԫ��%d��ǰ��Ϊ%d\n", e0, e);
	}

	for ( j = ListLength(L) - 1; j <= ListLength(L); j++ )
	{
		GetElem(L, j, e0);
		i = NextElem(L, e0, e);

		if ( i == INFEASIBLE )
			printf("Ԫ��%d�޺��\n", e0);
		else 
			printf("Ԫ��%d�ĺ��Ϊ%d\n", e0, e);
	}

	k = ListLength(L);
	for ( j = k+1; j >= k; j-- )
	{
		i = ListDelete(L, j, e);
		if ( i == ERROR )
			printf("ɾ����%d��Ԫ��ʧ��\n", j);
		else 
			printf("ɾ����%d��Ԫ�سɹ�����ֵΪ%d\n", j, e);
	}

	printf("�������L��Ԫ�أ�");
	ListTraverse(L, print);
	DestroyList(L);
	printf("����L��L= %u\n", L);
}