void InitList(LinkList &L)
{
//操作结果：构造一个空的线性表L
	L = ( LinkList)malloc(sizeof(LNode));
	if ( !L )
		exit(OVERFLOW);
	L->next = L;
}

void DestroyList(LinkList &L)
{
//操作结果：销毁线性表L
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
//初始条件：线性表L已存在
//操作结果：将L重置为空表
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
//初始条件：线性表L已存在
//操作结果：若L为空表，则返回TRUE；否则返回FALSE
	if ( L->next == L )
		return TRUE;
	else
		return FALSE;
}

int ListLength(LinkList L)
{
//初始条件：线性表L已存在
//操作结果：返回L中数据元素的个数
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
//当第i个元素存在时，其支付给e并返回OK；否则返回ERROR
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
//初始条件：线性表L已存在，compare()是数据元素判定函数
//操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
// 若这样的数据元素不存在，则返回值为0
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
//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱；
// 否则操作失败，pre_e无定义
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
//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继；
// 否则操作失败，next_e无定义
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
//在L的第i个位置之前插入元素e
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
//删除L的第i个元素，并由e返回其值
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
//初始条件：L已存在
// 操作结果：依次对L的每个数据元素调用函数vi()
	LinkList p = L->next->next;
	while ( p != L->next )
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}



























