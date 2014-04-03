void InitList(SqList &L)
{
//����һ���յ�˳�����Ա�L
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if ( !L.elem )
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList &L)
{
//��ʼ������˳���L�Ѵ��ڡ��������������˳�����Ա�L
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}

void ClearList(SqList &L)
{
//��ʼ������˳���L�Ѵ��ڡ������������L����Ϊ�ձ�
	L.length = 0;
}

Status ListEmpty(SqList L)
{
//��ʼ������˳���L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
	if ( L.length == 0 )
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L)
{
//��ʼ������˳���L�Ѵ��ڡ��������������L�е�����Ԫ�صĸ���
	return L.length;
}

Status GetElem(SqList L, int i, ElemType &e)
{
//��ʼ������˳���L�Ѵ��ڣ�1 < i < ListLength(L)�������������e����L�е�i������Ԫ�ص�ֵ
	if ( i < 1 || i > L.length )
		return ERROR;
	e = *(L.elem + i - 1);
	return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
//��ʼ������˳���L�Ѵ��ڣ�compare()������Ԫ���ж�����������Ϊ1�� ����Ϊ0��
//�������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//			������������Ԫ�ز����ڣ��򷵻�0
	ElemType *p;
	int i = 1;
	p = L.elem;
	while ( i <= L.length && compare(*p++, e) )
		++i;
	if ( i <= L.length )
		return i;
	else 
		return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
//��ʼ������˳���L�Ѵ���
//�����������cur_e��L��Ԫ�أ��Ҳ��ǵ�һ��������pre_e������ǰ��;
//			�������ʧ�ܣ�pre_e�޶���
	int i = 2;
	ElemType *p = L.elem + 1;
	while ( i <= L.length && *p != cur_e )
	{
		p++;
		i++;
	}
	if ( i > L.length )
		return INFEASIBLE;
	else
	{
		pre_e = *--p;
		return OK;
	}
}

Status NextElem(SqList L, ElemType cur_e, ElemType next_e)
{
//��ʼ������˳���L�Ѵ���
//�����������cur_e��L��Ԫ�أ��Ҳ������һ��������next_e��������̣�
//			�������ʧ�ܣ�next_e�޶���
	int i = 1;
	ElemType *p = L.elem;
	while ( i < L.length && *p != cur_e )
	{
		i++;
		p++;
	}
	if ( i == L.length )
		return INFEASIBLE;
	else
	{
		next_e = *++p;
		return OK;
	}
}

Status ListInsert(SqList &L, int i, ElemType e)
{
//��ʼ������˳���L�Ѵ��ڣ�1 < i < ListLength(L)+1
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
	ElemType *newbase, *q,  *p;
	if ( i < 1 || i > L.length + 1 )
		return ERROR;
	if ( L.length >= L.listsize )
	{
		if ( !(newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType))) )
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LIST_INCREMENT;
	}
	q = L.elem + i - 1;
	for ( p = L.elem + L.length - 1; p >= q; --p )
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e)
{
//��ʼ������˳���L�Ѵ��ڣ�1 < i < ListLength(L)
//���������ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
	ElemType *p, *q;
	if ( i < 1 || i > L.length )
		return ERROR;
	p = L.elem + i - 1;
	e = *p;
	q = L.elem + L.length - 1;
	for ( ++p; p <= q; ++p )
		*(p - 1) = *p;
	L.length --;
	return OK;
}

void ListTraverse(SqList L, void(*vi)(ElemType&))
{
//��ʼ������˳���L�Ѵ���
//������������ζ�L��ÿ������Ԫ�ص��ú���vi()
//			vi()���βμӡ�&����������ͨ������vi()�ı�Ԫ�ص�ֵ
	ElemType *p;
	int i;
	p = L.elem;
	for ( i = 1; i <= L.length; i++ )
		vi(*p++);
	printf("\n");
}