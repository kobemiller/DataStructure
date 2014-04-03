#include "c1.h"
typedef int SElemType;
#include "c3-1.h"
#include "bo3-1.cpp"

void print(SElemType c)
{
	printf("%d ", c);
}

void main()
{
	int j;
	SqStack s;
	SElemType e;
	
	InitStack(s);
	for ( j = 1; j <= 12; j++ )
		Push(s, j);
	printf("Õ»ÖÐÔªËØÒÀ´ÎÎª");
	StackTraverse(s, print);
	
	Pop(s, e);
	printf("µ¯³öµÄÕ»¶¥ÔªËØ e = %d\n", e);
	
	printf("Õ»¿Õ·ñ: %d(1: ¿Õ  0: ·ñ)\n", StackEmpty(s));

	GetTop(s, e);
	printf("Õ»¶¥ÔªËØ e = %d  Õ»µÄ³¤¶ÈÎª%d\n", e, StackLength(s));

	ClearStack(s);
	printf("Çå¿ÕÕ»ºó£¬Õ»¿Õ·ñ£º%d(1: ¿Õ  0: ·ñ)\n", StackEmpty(s));
	
	DestroyStack(s);
	printf("Ïú»ÙÕ»ºó, s.top = %u  s.base = %u  s.stacksize = %d\n", s.top, s.base, s.stacksize);
}