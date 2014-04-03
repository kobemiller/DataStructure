void InitList(LinkList &L)
{
//�������������һ���յ����Ա�L
	L = ( LinkList)malloc(sizeof(LNode));
	if ( !L )
		exit(OVERFLOW);
	L->next = L;
}

void DestroyList(LinkList &L)
{
//����������������Ա�L
	LinkList q, p = L->next;
	while ( p != L )
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(L);
	L = NULL;
}

void ClearList(LinkList &L)
{
//��ʼ���������Ա�L�Ѵ���
//�����������L����Ϊ�ձ�
	LinkList p, q;
	L = L->next;
	p = L->next;
	
	while ( p != L )
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = L;
}

Status ListEmpty(LinkList L)
{
//��ʼ���������Ա�L�Ѵ���
//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
	if ( L->next == L )
		return TRUE;
	else
		return FALSE;
}

int ListLength(LinkList L)
{
//��ʼ���������Ա�L�Ѵ���
//�������������L������Ԫ�صĸ���
	int i = 0;
	LinkList p = L->next;
	while ( p != L )
	{
		i++;
		p=p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
//����i��Ԫ�ش���ʱ����֧����e������OK�����򷵻�ERROR
	int j = 1;
	LinkList p = L->next->next;
	if ( i < 0 || i > ListLength(L) )
		return ERROR;
	while ( j < i )
	{
		p = p->next;
		j++;
	}
	e = p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
//��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����
//�������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
// ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
	int i = 0;
	LinkList p = L->next->next;
	while ( p != L->next )
	{
		i++;
		if ( compare(p->data, e) )
			return i;
		p = p->next;
	}
	return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
//��ʼ���������Ա�L�Ѵ���
//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
// �������ʧ�ܣ�pre_e�޶���
	LinkList q, p = L->next->next;
	q = p->next;
	while ( q != L->next )
	{
		if ( q->data == cur_e )
		{
			pre_e = p->data;
			return TRUE;
		}
		p = q;
		q = q->next;
	}
	return FALSE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
//��ʼ���������Ա�L�Ѵ���
//�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
// �������ʧ�ܣ�next_e�޶���
	LinkList p = L->next->next;
	while ( p != L )
	{
		if ( p->data == cur_e )
		{
			next_e = p->next->data;
			return TRUE;
		}
		p = p->next;
	}
	return FALSE;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
//��L�ĵ�i��λ��֮ǰ����Ԫ��e
	LinkList p = L->next, s;
	int j = 0;
	if ( i <= 0 || i > ListLength(L) + 1 )
	return ERROR;
	while ( j < i - 1 )
	{
		p = p->next;
		j++;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	if ( p == L )
		L = s;
	return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{
//ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ
	LinkList  p = L->next, q;
	int j = 0;
	if ( i <= 0 || ListLength(L) )
		return ERROR;
	while ( j < i - 1 )
	{
		p = p->next;
		j++;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	if ( L == q )
		L = p;
	free(q);
	return OK;
}

void ListTraverse(LinkList L, void (*vi)(ElemType))
{
//��ʼ������L�Ѵ���
// ������������ζ�L��ÿ������Ԫ�ص��ú���vi()
	LinkList p = L->next->next;
	while ( p != L->next )
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}



























