#define	N	8	//�����ת���Ľ���N
typedef	int	SElemType;
#include "c1.h"
#include "c3-1.h"
#include "bo3-1.cpp"

void conversion()
{
	SqStack s;
	unsigned n;
	SElemType e;

	InitStack(s);
	printf("��ʮ��������nת��Ϊ%d��������������: n( >= 0)=", N);
	scanf("%u", &n);

	while ( n )
	{
		Push(s, n%N);
		n = n / N;
	}

	while ( !StackEmpty(s) )
	{
		Pop(s, e);
		printf("%d", e);
	}

	printf("\n");
}

void main()
{
	conversion();
}