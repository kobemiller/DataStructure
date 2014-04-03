#define DestroyList ClearList

void InitList(SLinkList L)
{
//����һ���յ�����L����ͷΪL�����һ����ԪL[MAX_SIZE-1]�����൥Ԫ����
//һ���������� ��ͷΪL�ĵ�һ����ԪL[0]�� ��0����ʾ��ָ��
	int i;
	L[MAX_SIZE-1].cur = 0;

	for ( i = 0; i < MAX_SIZE - 2;	i++ )
		L[i].cur = i + 1;
	L[MAX_SIZE-2].cur = 0;
}

void ClearList( SLinkList L)
{
//��ʼ���������Ա�L�Ѵ���
//�����������L����Ϊ�ձ�
	int i, j, k;
	i = L[MAX_SIZE-1].cur;
	L[MAX_SIZE-1].cur = 0;
	k = L[0].cur;
	L[0].cur = i;
	
	while ( i )
	{
		j = i;
		i = L[i].cur;
	}
	L[j].cur = k;
}

Status ListEmpty(SLinkList L)
{
//��L�ǿձ�����TRUE�����򷵻�FALSE
	if ( L[MAX_SIZE-1].cur == 0 )
		return TRUE;
	else
		return FALSE;
}

int ListLength(SLinkLink L)
{
//����L������Ԫ�صĸ���
	int j = 0, i = L[MAX_SIZE-1].cur;

	while ( i )
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

Status GetElem(SLinkList L, int i, ElemType &e)
{
//��e����L�е�i��Ԫ�ص�ֵ
	int l, k = MAX_SIZE-1;

	if ( i < 1 || i > ListLength(L) )
		return ERROR;
	for ( l = 1; l <= i; l++ )
		k = L[k].cur;
	e = L[k].data;
	return OK;
}

int LocateElem(SLinkList L, ElemType e)
{
//�ھ�̬�������в��ҵ�1��ֵΪe��Ԫ��
//���ҵ����򷵻�����L�е�λ�򣻷��򷵻�0
	int i = L[MAX_SIZE-1].cur;

	while ( i && L[i].data != e )
		i = L[i].cur;
	return i;
}

Status PriorElem(SLinkList L, ElemType cur_e, ElemType &pre_e)
{
//��ʼ���������Ա�L�Ѵ���
//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��
//			����OK���������ʧ�ܣ�pre_e�޶��壬����INFEASIBLE
	int j, i = L[MAX_SIZE-1].cur;

	do 
	{
		j = i;
		i = L[i].cur;
	}while ( i && cur_e != L[i].data );

	if ( i )
	{
		pre_e = L[j].data;
		return OK;
	}
	return ERROR;
}

Status NextElem(SLinkList L, ElemType cur_e, ElemType &next_e)
{
//��ʼ���������Ա�L�Ѵ���
//�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
//			����OK���������ʧ�ܣ�next_e�޶��壬����INFEASIBLE
		int j, i = LocateElem(L, cur_e);

		if ( i )
		{
			j = L[i].cur;
			if ( j )
			{
				next_e = L[j].data;
				return OK;
			}
		}
		return ERROR;
}

Status ListInsert(SLinkList L, int i, ElemType e)
{
//��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e
	int l, j, k = MAX_SIZE-1;
	if ( i < 1 || i > ListLength(L) + 1 )
		return ERROR;
	j = Malloc(L);
	if ( j )
	{
		L[j].data = e;
		for (l = 1; l < i; l++ )
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

Status ListDelete(SLinkList L, int i, ElemType &e)
{
//ɾ����L�е�i������Ԫ��e����������ֵ
	int j, k = MAX_SIZE-1;
	if ( i < 1 || i >ListLength(L) )
		return ERROR;
	for ( j = 1; j < i; j++ )
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	e = L[j].data;
	Free(L, j);
	return OK;
}

void ListTraverse(SLinkList L, void (*vi)(ElemType))
{
//��ʼ���������Ա�L�Ѵ���
//������������ζ�L��ÿ������Ԫ�ص��ú���vi()
	int i = L[MAX_SIZE-1].cur;
	while ( i )
	{
		vi(L[i].data);
		i = L[i].cur;
	}
	printf("\n");
}