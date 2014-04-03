/*
 *  bo3-5.cpp 链栈(存储结构由c2-2.h定义)的基本操作(4个)
 *  部分基本操作是由bo2-8.cpp中的函数改名得来
 *  另一部分基本操作是由调用bo2-8.cpp中的函数(取特例)得来
 */
typedef SElemType ElemType;

#include "c2-2.h"
typedef LinkList LinkStack;
#define InitStack InitList
#define DestroyStack DestroyList
#define ClearStack ClearList
#define StackEmpty ListEmpty
#define StackLength ListLength
#include "bo2-8.cpp"

Status GetTop(LinkStack S, SElemType &e)
{// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	return GetElem(S, 1, e);
}

Status Push(LinkStack &S, SElemType e)
{//插入元素e为新的栈顶元素
	return ListInsert(S, 1, e);
}

Status Pop(LinkStack &S, SElemType &e)
{//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	return ListDelete(S, 1, e);
}

void StackTraverse(LinkStack S, void (*visit)(SElemType))
{//从栈底到栈顶依次对栈中每个元素调用函数visit()
	LinkStack temp, p = S;
	InitStack(temp);
	while ( p )
	{
		Push(temp, p->data);
		p = p->next;
	}
	ListTraverse(temp, visit);
}
