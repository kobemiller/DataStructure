 //不带头结点的单链表的部分基本操作
#define DestroyList ClearList

void InitList(LinkList &L)
{//操作结果：构造一个空的线性表L
	L = NULL;
}

void ClearList(LinkList &L)
{//初始条件：线性表L已存在。操作结果：将L重置为空表
	LinkList p;
	while ( L )
	{
		p = L;
		L = L->next;
		free(p);
	}
}

Status ListEmpty(LinkList L)
{// 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE；否则返回FALSE
	if ( L )
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{//初始条件：线性表L已存在。操作结果：返回L中数据元素的个数
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
{//L为不带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK；否则返回ERROR
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
{// 初始条件：线性表L已存在,compare()是数据元素判定函数(满足为1；否则为0)
// 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
//若这样的数据元素不存在，则返回值为0
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
{// 在不带头结点的单链线性表L中第i个位置之前插入元素e
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
{//在不带头结点的单链线性表L中,删除第i个元素,并由e返回其值
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
{//初始条件：线性表L已存在
// 操作结果：依次对L的每个数据元素调用函数vi()
	LinkList p = L;
	while ( p )
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
}