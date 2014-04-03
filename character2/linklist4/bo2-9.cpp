Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回他的前驱
//			返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE
	LinkList q, p = L;

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
	LinkList p = L;
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