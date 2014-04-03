int equal(ElemType c1, ElemType c2)
{
//判断是否相等函数
	if ( c1 == c2 )
		return TRUE;
	else
		return FALSE;
}

int comp(ElemType a, ElemType b)
{
//根据a <、>、= b，分别返回-1、1、0
	if ( a == b )
		return 0;
	else
		return (a - b) / abs(a - b);
}

void print(ElemType c)
{
	printf("%d ", c);
}

void print1(ElemType &c)
{
	printf("%d ", c);
}

void print2(ElemType c)
{
	printf("%c ", c);
}
