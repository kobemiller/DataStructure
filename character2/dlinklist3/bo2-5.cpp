void InitList(DuLinkList &L)
{
//产生空的双向循环链表L
	L = (DuLinkList)malloc(sizeof(DuLNode));
	if ( L )
		L->next = L->prior = L;
	else
		exit(OVERFLOW);
}

void DestroyList(DuLinkList &L)
{
//操作结果：销毁双向循环链表L
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
//初始条件：L已存在。操作结果：将L重置为空表
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
//初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE；否则返回FALSE
	if ( L->next == L && L->prior == L )
		return TRUE;
	else
		return FALSE;
}

int ListLength(DuLinkList L)
{
//初始条件：L已存在。操作结果：返回L中数据元素个数
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
//当第i个元素存在时，其值赋给e并返回OK；否则返回ERROR
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
// 初始条件：L已存在，compare()是数据元素判定函数
// 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
// 若这样的数据元素不存在，则返回值为0
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
// 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱；
// 否则操作失败，pre_e无定义
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
// 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继；
// 否则操作失败，next_e无定义
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
// 在双向链表L中返回第i个元素的地址。i为0，返回头结点的地址。若第i个元素不存在，
// 返回NULL
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
// 在带头结点的双链循环线性表L中第i个位置之前插入元素e，i的合法值为1≤i≤表长+1
// 改进算法2.18；否则无法在第表长+1个结点之前插入元素
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
//  删除带头结点的双链循环线性表L的第i个元素，i的合法值为1≤i≤表长	
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
 // 由双链循环线性表L的头结点出发，正序对每个数据元素调用函数visit()
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
 // 由双链循环线性表L的头结点出发，逆序对每个数据元素调用函数visit()
	DuLinkList p = L->prior;
	while ( p != L )
	{
		visit(p->data);
		p = p->prior;
	}
	printf("\n");
}


