#include "c1.h"
#include "func3-1.h"

int curstep = 1;	//��ǰ�㼣����ֵ������ڴ���Ϊ1
struct SElemType
{
	int ord;		//ͨ������·���ϵ�"���"
	PosType seat;	//ͨ�������Թ��еġ�����λ�á�
	int di;			//�Ӵ�ͨ����������һͨ����ġ����򡱣�0~3��ʾ��~����
};

#include "c3-1.h"
#include "bo3-1.h"

Status Pass(PosType b)
{
	//���Թ�m��b������Ϊ1(��ͨ��·��)������OK�����򣬷���ERROR
	if ( m[b.x][b.y] == 1 )
		return OK;
	else
		return ERROR;
}

void FootPrint(PosType a)
{
	//ʹ�Թ�m��a���ֵ��Ϊ�㼣(curstep)
	m[a.x][a.y] = curstep;
}

void NextPos(PosType &c, int di)
{
	//���ݵ�ǰλ�ü��ƶ����������һλ��
	PosType direc[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	c.x += direc[di].x;
	c.y += direc[di].y;
}

void MarkPrint(PosType b)
{
	//ʹ�Թ�m��b�����ű�Ϊ-1(����ͨ����·��)
	m[b.x][b.y] = -1;
}

Status MazePath(PosType start, PosType end)
{
	//���Թ�m�д��ڴ����start������end��ͨ���������һ��
	// �����ջ��(��ջ�׵�ջ��)��������TRUE�����򷵻�FALSE
	SqStack S;
	PosType curpos;
	SElemType e;
	InitStack(S);
	curpos = start;
	do 
	{
		if ( Pass(curpos) )
		{
			// ��ǰλ�ÿ���ͨ��������δ���ߵ�����ͨ����
			FootPrint(curpos);
			e.ord = curstep;
			e.seat = curpos;
			e.di = 0;
			Push(S, e);
			curstep++;
			if ( curpos.x == end.x && curpos.y == end.y )
				return TRUE;
			NextPos(curpos, e.di);
		}
		else
		{
			// ��ǰλ�ò���ͨ��
			if ( !StackEmpty(S) )
			{
				Pop(S, e);
				curstep--;
				while ( e.di == 3 && !StackEmpty(S) )
				{
					MarkPrint(e.seat);
					Pop(S, e);
					curstep--;
				}
				if ( e.di < 3 )
				{
					e.di++;
					Push(S, e);
					curstep++;
					curpos = e.seat;
					NextPos(curpos, e.di);
				}
			}
		}
	}while ( !StackEmpty(S) );

	return FALSE;
}

void main()
{
	Init(1);

	if ( MazePath(begin, end) )
	{
		printf("���Թ�����ڵ����ڵ�һ��·�����£�\n");
		Print();
	}
	else
		printf("���Թ�û�д���ڵ����ڵ�·��\n");
}