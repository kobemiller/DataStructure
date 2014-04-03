#include "c1.h"
#define N 6
typedef char ElemType[N];
#include "c2-3.h"

void main()
{
	SLinkList s = { {" ", 1}, {"zhao", 2}, {"qian", 3}, {"sun", 4}, {"li", 5}, {"zhou", 6},
	{"wu", 7}, {"zheng", 8}, {"wang", 0} };
	int i;
	i = s[0].cur;

	while ( i )
	{
		printf("%s  ", s[i].data);
		i = s[i].cur;
	}

	printf("\n");
	s[4].cur = 9;
	s[9].cur = 5;
	strcpy(s[9].data, "shi");
	s[6].cur = 8;
	i = s[0].cur;

	while ( i )
	{
		printf("%s  ", s[i].data);
		i = s[i].cur;
	}
	printf("\n");

}