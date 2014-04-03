typedef char SElemType;
#include "c1.h"
#include "c3-1.h"
#include "bo3-1.cpp"

void check()
{
	SqStack s;
	SElemType ch[80], *p, e;

	InitStack(s);
	printf("«Î ‰»Î¥¯¿®∫≈£®£®£©°¢°æ°ø°¢{}£©µƒ±Ì¥Ô Ω\n");
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
					printf("◊Û”“¿®∫≈≤ª≈‰∂‘\n");
					exit(ERROR);
				}
			}
			else
			{
				printf("»±∑¶◊Û¿®∫≈\n");
				exit(ERROR);
			}
		default:
			p++;
	}
	if ( StackEmpty(s) )
		printf("¿®∫≈∆•≈‰\n");
	else
		printf("»±∑¶”“¿®∫≈\n");
}

void main()
{
	check();
}
