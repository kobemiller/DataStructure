 //����ͷ���ĵ�����Ĳ��ֻ�������
#define DestroyList ClearList

void InitList(LinkList &L)
{//�������������һ���յ����Ա�L
	L = NULL;
}

void ClearList(LinkList &L)
{//��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
	LinkList p;
	while ( L )
	{
		p = L;
		L = L->next;
		free(p);
	}
}

Status ListEmpty(LinkList L)
{// ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
	if ( L )
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{//��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�صĸ���
	int i = 0;
	LinkList p = L;
	while ( p )
	{
		p = p->next;
		i++;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{//LΪ����ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	int j = 1;
	LinkList p = L;

	if ( i < 1 )
		return ERROR;
	while ( j < i && p )
	{
		j++;
		p = p->next;
	}
	if ( j == i )
	{
		e = p->data;
		return OK;
	}
	else
		return ERROR;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{// ��ʼ���������Ա�L�Ѵ���,compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
// �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//������������Ԫ�ز����ڣ��򷵻�ֵΪ0
	int i = 0;
	LinkList p = L;
	while ( p )
	{
		i++;
		if ( compare(p->data, e) )
			return i;
		p = p->next;
	}
	return 0;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{// �ڲ���ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
	int j = 1;
	LinkList p = L, s;
	if ( i < 1 )
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	if ( i == 1 )
	{
		s->next = L;
		L = s;
	}
	else
	{
		while ( p && j < i-1 )
		{
			p = p->next;
			j++;
		}
		if ( !p )
			return ERROR;
		s->next = p->next;
		p->next = s;
	}
	return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{//�ڲ���ͷ���ĵ������Ա�L��,ɾ����i��Ԫ��,����e������ֵ
	int j = 1;
	LinkList p = L, q;
	if ( i == 1 )
	{
		L = p->next;
		e = p->data;
		free(p);
	}
	else
	{
		while ( p->next && j < i-1 )
		{
			p = p->next;
			j++;
		}
		if ( !p->next || j > i-1 )
			return ERROR;
		q = p->next;
		p->next = q->next;
		e = q->data;
		free(q);
	}
	return OK;
}

void ListTraverse(LinkList L, void (*vi)(ElemType))
{//��ʼ���������Ա�L�Ѵ���
// ������������ζ�L��ÿ������Ԫ�ص��ú���vi()
	LinkList p = L;
	while ( p )
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}