void InitList(LinkList &L)
{
//操作结果：构造一个空的线性表L
	L = (LinkList)malloc(sizeof(LNode));
	if ( !L )
		exit(OVERFLOW);
	L->next = NULL;
}

void DestroyList(LinkList &L)
{
//初始条件：线性表L已存在
//操作结果：销毁线性表L
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
//初始条件：线性表L已存在
//操作结果：将L重置为空表
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
//初始条件：线性表L已存在
//操作结果：若L为空表，则返回TURE；否则返回FALSE
	if ( L->next )
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{
//初始条件：线性表L已存在
//操作结果：返回L中数据元素的个数
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
//L为带头结点的单链表的头指针
//当第i个元素存在时，其值赋给e并返回OK；否则返回ERROR
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
//初始条件：线性表L已存在，compare（）是数据元素判定函数（满足为1，否则为0）
//操作结果：返回L中第1个与e满足关系compare（）的数据元素的位序
//			若这样的数据元素不存在，则返回值为0
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
//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回他的前驱
//			返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE
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
//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回他的后继，
//			返回OK；否则操作失败，next_e无定义，返回INFEASIBLE
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
//在带头结点的单链表L中第i个位置之前插入元素e
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
//在带头结点的单链表L中，删除第i个元素，并有e返回其值
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
//初始条件:线性表L已存在
//操作结果：依次对L的每一个数据元素调用函数vi()
	LinkList p = L->next;
	while ( p )
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}