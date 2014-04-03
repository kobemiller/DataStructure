#include "c1.h"
typedef int SElemType;
#include "bo3-5.cpp"

void print(SElemType c)
{
	printf("%d ", c);
}

void main()
{
	int j;
	LinkStack s;
	SElemType e;
	
	InitStack(s);
	for ( j = 1; j <= 5; j++ )
		Push(s, 2*j);
	printf("栈中的元素从栈底到栈顶依次为");
	StackTraverse(s, print);

	Pop(s, e);
	printf("弹出的栈顶元素为%d\n", e);
	printf("栈空否：%d(1：空 0：否)\n", StackEmpty(s));

	GetTop(s, e);
	printf("当前栈顶元素为%d, 栈的长度为%d\n", e, StackLength(s));

	ClearStack(s);
	printf("清空栈后，栈空否：%d(1：空 0：否)\n", StackEmpty(s));

	DestroyStack(s);
}