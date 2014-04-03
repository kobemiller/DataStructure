void InitList(DuLinkList &L)
{
//�����յ�˫��ѭ������L
	L = (DuLinkList)malloc(sizeof(DuLNode));
	if ( L )
		L->next = L->prior = L;
	else
		exit(OVERFLOW);
}

void DestroyList(DuLinkList &L)
{
//�������������˫��ѭ������L
	DuLinkList q, p = L->next;
	while ( p != L )
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(L);
	L = NULL;
}

void ClearList(DuLinkList L)
{
//��ʼ������L�Ѵ��ڡ������������L����Ϊ�ձ�
	DuLinkList q, p = L->next;
	while ( p != L )
	{
		q = p->next;
		//free(p);
		p = q;
	}
	L->next = L->prior = L;
}

Status ListEmpty(DuLinkList L)
{
//��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
	if ( L->next == L && L->prior == L )
		return TRUE;
	else
		return FALSE;
}

int ListLength(DuLinkList L)
{
//��ʼ������L�Ѵ��ڡ��������������L������Ԫ�ظ���
	int i = 0;
	DuLinkList p = L->next;
	while ( p != L )
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(DuLinkList L, int i, ElemType &e)
{
//����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	int j = 1;
	DuLinkList p = L->next;
	while ( p != L && j < i )
	{
		p = p->next;
		j++;
	}
	if ( p == L || j > i )
		return ERROR;
	e = p->data;
	return OK;
}

int LocateElem(DuLinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
// ��ʼ������L�Ѵ��ڣ�compare()������Ԫ���ж�����
// �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
// ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
	int i = 0;
	DuLinkList p = L->next;
	while ( p != L )
	{
		i++;
		if ( compare(p->data, e) )
			return i;
		p = p->next;
	}
	return 0;
}

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType &pre_e)
{
// �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
// �������ʧ�ܣ�pre_e�޶���
	DuLinkList p = L->next->next;
	while ( p != L )
	{
		if ( p->data == cur_e )
		{
			pre_e = p->prior->data;
			return TRUE;
		}
		p = p->next;
	}
	return FALSE;
}

Status NextElem(DuLinkList L, ElemType cur_e, ElemType &next_e)
{
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
// �������ʧ�ܣ�next_e�޶���
	DuLinkList p = L->next->next;
	while ( p != L )
	{
		if ( p->prior->data == cur_e )
		{
			next_e = p->data;
			return TRUE;
		}
		p = p->next;
	}
	return FALSE;
}

DuLinkList GetElemP(DuLinkList L, int i)
{
// ��˫������L�з��ص�i��Ԫ�صĵ�ַ��iΪ0������ͷ���ĵ�ַ������i��Ԫ�ز����ڣ�
// ����NULL
	int j;
	DuLinkList p = L;
	if ( i < 0 || i > ListLength(L) )
		return NULL;
	for ( j = 1; j <= i; j++ )
		p = p->next;
	return p;
}

Status ListInsert(DuLinkList L, int i, ElemType e)
{
// �ڴ�ͷ����˫��ѭ�����Ա�L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1��i�ܱ�+1
// �Ľ��㷨2.18�������޷��ڵڱ�+1�����֮ǰ����Ԫ��
	DuLinkList p, s;
	if ( i < 1 || i > ListLength(L) + 1 )
		return ERROR;
	p = GetElemP(L, i-1);
	if ( !p )
		return ERROR;
	s = (DuLinkList)malloc(sizeof(DuLinkList));
	if ( !s )
		return OVERFLOW;
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	return OK;
}

Status ListDelete(DuLinkList L, int i, ElemType &e)
{
//  ɾ����ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ�أ�i�ĺϷ�ֵΪ1��i�ܱ�	
	DuLinkList p;
	if ( i < 1 )
		return ERROR;

	p = GetElemP(L, i);
	if ( !p )
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	
	//free(p);
	return OK;
}

void ListTraverse(DuLinkList L, void (*visit)(ElemType))
{
 // ��˫��ѭ�����Ա�L��ͷ�������������ÿ������Ԫ�ص��ú���visit()
	DuLinkList p = L->next;
	while ( p != L )
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void ListTraverseBack(DuLinkList L, void (*visit)(ElemType))
{
 // ��˫��ѭ�����Ա�L��ͷ�������������ÿ������Ԫ�ص��ú���visit()
	DuLinkList p = L->prior;
	while ( p != L )
	{
		visit(p->data);
		p = p->prior;
	}
	printf("\n");
}


