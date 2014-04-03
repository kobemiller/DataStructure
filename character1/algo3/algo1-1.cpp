#include <stdio.h>
#include <sys/timeb.h>

void main()
{
	struct timeb t1, t2;
	long t;
	double x, sum = 1, sum1;
	int i, j, n;
	printf("please input x n: ");
	scanf("%lf %d", &x, &n);
	ftime(&t1);
	for ( i = 1; i <= n; i++)
	{
		sum1 = 1;
		for ( j = 1; j <= i; j++)
			sum1 = sum1 * (-1.0 / x);
		sum += sum1;
	}
	ftime(&t2);
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
	printf("sum = %lf time is %ldms\n", sum, t);
}