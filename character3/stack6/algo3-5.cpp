#include "c1.h"
#include "func3-1.h"

int curstep = 1;	//当前足迹，初值（在入口处）为1
struct SElemType
{
	int ord;		//通道块在路径上的"序号"
	PosType seat;	//通道块在迷宫中的“坐标位置”
	int di;			//从此通道块走向下一通道块的“方向”（0~3表示东~北）
};

#include "c3-1.h"
#include "bo3-1.h"

Status Pass(PosType b)
{
	//当迷宫m的b点的序号为1(可通过路径)，返回OK；否则，返回ERROR
	if ( m[b.x][b.y] == 1 )
		return OK;
	else
		return ERROR;
}

void FootPrint(PosType a)
{
	//使迷宫m的a点的值变为足迹(curstep)
	m[a.x][a.y] = curstep;
}

void NextPos(PosType &c, int di)
{
	//根据当前位置及移动方向，求得下一位置
	PosType direc[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	c.x += direc[di].x;
	c.y += direc[di].y;
}

void MarkPrint(PosType b)
{
	//使迷宫m的b点的序号变为-1(不能通过的路径)
	m[b.x][b.y] = -1;
}

Status MazePath(PosType start, PosType end)
{
	//若迷宫m中存在从入口start到出口end的通道，则求得一条
	// 存放在栈中(从栈底到栈顶)，并返回TRUE；否则返回FALSE
	SqStack S;
	PosType curpos;
	SElemType e;
	InitStack(S);
	curpos = start;
	do 
	{
		if ( Pass(curpos) )
		{
			// 当前位置可以通过，即是未曾走到过的通道块
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
			// 当前位置不能通过
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
		printf("此迷宫从入口到出口的一条路径如下：\n");
		Print();
	}
	else
		printf("此迷宫没有从入口到出口的路径\n");
}