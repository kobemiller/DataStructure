/*
 *说明exit（）函数的作用
 */
#include "c1.h"

int a(int i)
{
	if ( i == 1 )
	{
		printf("退出程序的运行\n");
		exit(1);
	}
	return i;
}

void main()
{
	int i;
	printf("please input i: ");
	scanf("%d", &i);
	printf("a(i) = %d\n", a(i));
}
