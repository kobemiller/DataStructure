int Malloc(SLinkList space)
{
//若备用链表非空，则返回分配的节点下标（备用链表的第一个头结点）；否则返回0
	int i = space[0].cur;

	if ( i )
		space[0].cur = space[i].cur;
	return i;
}

void Free(SLinkList space, int k)
{
//将下标为k的空闲结点回收到备用链表（成为备用链表第一个结点）
	space[k].cur = space[0].cur;
	space[0].cur = k;
}