//顺序栈的基本操作
void InitStack(SqStack &S)
{//构造一个空栈S
	if ( !(S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType))) )
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{//销毁栈S， S不再存在
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
}

void ClearStack(SqStack &S)
{//把S置为空栈
	S.top = S.base;
}

Status StackEmpty(SqStack S)
{//若栈S为空栈， 则返回TRUE；否则返回FALSE
	if ( S.top == S.base )
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)
{//返回S的元素个数，即栈的长度
	return S.top - S.base;
}

Status GetTop(SqStack S, SElemType &e)
{//若栈不空，则用e返回S的栈顶元素， 并返回ok；否则返回ERROR
	if ( S.top > S.base )
	{
		e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}

void Push(SqStack &S, SElemType e)
{//插入元素e为新的栈顶元素
	if ( S.top - S.base >= S.stacksize )
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT)*sizeof(SElemType));
		if ( !S.base )
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e;

}

Status Pop(SqStack &S, SElemType &e)
{//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if ( S.top == S.base )
		return ERROR;
	e = *--S.top;
	return OK;
}

void StackTraverse(SqStack S, void (*visit)(SElemType))
{//从栈底到栈顶依次对栈中每个元素调用函数visit（）
	while ( S.top > S.base )
		visit(*S.base++);
	printf("\n");
}
