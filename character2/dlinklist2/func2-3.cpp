int equal(ElemType c1, ElemType c2)
{
//�ж��Ƿ���Ⱥ���
	if ( c1 == c2 )
		return TRUE;
	else
		return FALSE;
}

int comp(ElemType a, ElemType b)
{
//����a <��>��= b���ֱ𷵻�-1��1��0
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
