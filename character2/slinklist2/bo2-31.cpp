#define DestroyList ClearList

void InitList(SLinkList L)
{
//构造一个空的链表L，表头为L的最后一个单元L[MAX_SIZE-1]，其余单元链成
//一个备用链表， 表头为L的第一个单元L[0]， “0”表示空指针
	int i;
	L[MAX_SIZE-1].cur = 0;

	for ( i = 0; i < MAX_SIZE - 2;	i++ )
		L[i].cur = i + 1;
	L[MAX_SIZE-2].cur = 0;
}

void ClearList( SLinkList L)
{
//初始条件：线性表L已存在
//操作结果：将L重置为空表
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
//若L是空表，返回TRUE；否则返回FALSE
	if ( L[MAX_SIZE-1].cur == 0 )
		return TRUE;
	else
		return FALSE;
}

int ListLength(SLinkLink L)
{
//返回L中数据元素的个数
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
//用e返回L中第i个元素的值
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
//在静态单链表中查找第1个值为e的元素
//若找到，则返回他在L中的位序；否则返回0
	int i = L[MAX_SIZE-1].cur;

	while ( i && L[i].data != e )
		i = L[i].cur;
	return i;
}

Status PriorElem(SLinkList L, ElemType cur_e, ElemType &pre_e)
{
//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回他的前驱
//			返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE
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
//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回他的后继，
//			返回OK；否则操作失败，next_e无定义，返回INFEASIBLE
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
//在L中第i个元素之前插入新的数据元素e
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
//删除在L中第i个数据元素e，并返回其值
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
//初始条件：线性表L已存在
//操作结果：依次对L的每个数据元素调用函数vi()
	int i = L[MAX_SIZE-1].cur;
	while ( i )
	{
		vi(L[i].data);
		i = L[i].cur;
	}
	printf("\n");
}