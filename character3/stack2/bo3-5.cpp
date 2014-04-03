/*
 *  bo3-5.cpp ��ջ(�洢�ṹ��c2-2.h����)�Ļ�������(4��)
 *  ���ֻ�����������bo2-8.cpp�еĺ�����������
 *  ��һ���ֻ����������ɵ���bo2-8.cpp�еĺ���(ȡ����)����
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
{// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	return GetElem(S, 1, e);
}

Status Push(LinkStack &S, SElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	return ListInsert(S, 1, e);
}

Status Pop(LinkStack &S, SElemType &e)
{//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	return ListDelete(S, 1, e);
}

void StackTraverse(LinkStack S, void (*visit)(SElemType))
{//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()
	LinkStack temp, p = S;
	InitStack(temp);
	while ( p )
	{
		Push(temp, p->data);
		p = p->next;
	}
	ListTraverse(temp, visit);
}
