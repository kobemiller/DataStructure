int Malloc(SLinkList space)
{
//����������ǿգ��򷵻ط���Ľڵ��±꣨��������ĵ�һ��ͷ��㣩�����򷵻�0
	int i = space[0].cur;

	if ( i )
		space[0].cur = space[i].cur;
	return i;
}

void Free(SLinkList space, int k)
{
//���±�Ϊk�Ŀ��н����յ�����������Ϊ���������һ����㣩
	space[k].cur = space[0].cur;
	space[0].cur = k;
}