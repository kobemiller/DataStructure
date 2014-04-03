typedef char SElemType;
#include "c1.h"
#include "c3-1.h"
#include "bo3-1.cpp"

void check()
{
	SqStack s;
	SElemType ch[80], *p, e;

	InitStack(s);
	printf("����������ţ�������������{}���ı��ʽ\n");
	gets(ch);

	p = ch;
	while ( *p )
		switch ( *p )
	{
		case '(':
		case '[':
		case '{':
			Push(s, *p++);
			break;
		case ')':
		case ']':
		case '}':
			if ( !StackEmpty(s) )
			{
				Pop(s, e);
				if ( !(e == '(' && *p == ')' || e == '[' && *p == ']' || e == '{' && *p == '}') )
				{
					printf("�������Ų����\n");
					exit(ERROR);
				}
			}
			else
			{
				printf("ȱ��������\n");
				exit(ERROR);
			}
		default:
			p++;
	}
	if ( StackEmpty(s) )
		printf("����ƥ��\n");
	else
		printf("ȱ��������\n");
}

void main()
{
	check();
}
