void InitList(LinkList &L)
{
//�������������һ���յ����Ա�L
	L = (LinkList)malloc(sizeof(LNode));
	if ( !L )
		exit(OVERFLOW);
	L->next = NULL;
}

void DestroyList(LinkList &L)
{
//��ʼ���������Ա�L�Ѵ���
//����������������Ա�L
	LinkList q;
	while ( L )
	{
		q = L->next;
		free(L);
		L = q;
	}
}

void ClearList(LinkList L)
{
//��ʼ���������Ա�L�Ѵ���
//�����������L����Ϊ�ձ�
	LinkList p, q;
	p = L->next;
	while ( p )
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

Status ListEmpty(LinkList L)
{
//��ʼ���������Ա�L�Ѵ���
//�����������LΪ�ձ��򷵻�TURE�����򷵻�FALSE
	if ( L->next )
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{
//��ʼ���������Ա�L�Ѵ���
//�������������L������Ԫ�صĸ���
	int i = 0;
	LinkList p = L->next;
	while ( p )
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
//LΪ��ͷ���ĵ������ͷָ��
//����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	int j = 1;
	LinkList p = L->next;
	while ( p && j < i )
	{
		p = p->next;
		j++;
	}
	if ( !p || j > i )
		return ERROR;
	e = p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
//��ʼ���������Ա�L�Ѵ��ڣ�compare����������Ԫ���ж�����������Ϊ1������Ϊ0��
//�������������L�е�1����e�����ϵcompare����������Ԫ�ص�λ��
//			������������Ԫ�ز����ڣ��򷵻�ֵΪ0
	int i = 0;
	LinkList p = L->next;
	while ( p )
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
//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��
//			����OK���������ʧ�ܣ�pre_e�޶��壬����INFEASIBLE
	LinkList q, p = L->next;
	while ( p->next )
	{
		q = p->next;
		if ( q->data == cur_e )
		{
			pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
//��ʼ���������Ա�L�Ѵ���
//�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
//			����OK���������ʧ�ܣ�next_e�޶��壬����INFEASIBLE
	LinkList p = L->next;
	while ( p->next )
	{
		if ( p->data == cur_e )
		{
			next_e = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return INFEASIBLE;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
//�ڴ�ͷ���ĵ�����L�е�i��λ��֮ǰ����Ԫ��e
	int j = 0;
	LinkList p = L, s;
	while ( p && j < i-1 )
	{
		p = p->next;
		j++;
	}
	if ( !p || j > i-1 )
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList L, int i, ElemType &e)
{
//�ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�����e������ֵ
	int j = 0;
	LinkList p = L, q;
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
	return OK;
}

void ListTraverse(LinkList L, void (*vi)(ElemType))
{
//��ʼ����:���Ա�L�Ѵ���
//������������ζ�L��ÿһ������Ԫ�ص��ú���vi()
	LinkList p = L->next;
	while ( p )
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}