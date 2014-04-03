//行编辑程序
typedef char SElemType;

#include "c1.h"
#include "c3-1.h"
#include "bo3-1.h"

FILE *fp;

void copy(SElemType c)
{//将字符c送至fp所指的文件中
	fputc(c, fp);	
}

void LineEdit()
{
	//利用字符栈s，从终端接受一行并送至调用过程的数据区
	SqStack s;
	char ch;
	InitStack(s);
	printf("请输入一个文本文件，^z结束输入：\n");
	ch = getchar();

	while ( ch != EOF )
	{//当全文没结束（EOF为^z，全文结束符）
		while ( ch != EOF && ch != '\n' )
		{//当全文没有结束且没到行末
			switch ( ch )
			{
				case '#' : if ( !StackEmpty(s) )
								Pop(s, ch);
								break;
				case '@' : ClearStack(s);
								break;
				default  : Push(s, ch);
			}
		
			ch = getchar();
		}

		StackTraverse(s, copy);
		fputc('\n', fp);
		ClearStack(s);
		if ( ch != EOF )
			ch = getchar();
	}

	DestroyStack(s);
}

void main()
{
	fp = fopen("ed.txt", "w");
	if ( fp )
	{
		LineEdit();
		fclose(fp);
	}
	else
		printf("建立文件失败！\n");
}