/*
 *变量的引用类型和非引用类型的区别
 *形参前带有“&”，说明形参是引用类型的。引用类型是c++语言特有的。引用类型的变量，其值若在函数中发生变化，
 *则变化的值会带回主调函数中
 */
#include <stdio.h>

void fa(int a)
//在函数中改变a，将不会带回主调函数，主调函数中a值保持不变
{
	a++;
	printf("在函数fa中：a = %d\n", a);
}

void fb(int &a)
//在函数中改变a值，其值将带回主调函数
{
	a++;
	printf("在函数fb中：a = %d\n", a);
}

void main()
{
	int n = 1;
	printf("在主程序中，调用函数fa之前: n = %d\n", n);

	fa(n);
	printf("在主程序中，调用函数fa之后，fb之前： n = %d\n", n);

	fb(n);
	printf("在主程序中，调用函数fb之后：n = %d\n", n);
}
