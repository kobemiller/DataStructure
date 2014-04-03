struct PosType
{
	int x;
	int y;
};

#define MAXLENGTH 25	//设迷宫的最大行列为25
typedef int MazeType[MAXLENGTH][MAXLENGTH];

MazeType m;
int x, y;
PosType begin, end;

void Print()
{
	//输出迷宫的解
	int i, j;

	for ( i = 0; i < x; i++ )
	{
		for ( j = 0; j < y; j++ )
			printf("%3d", m[i][j]);
		printf("\n");
	}
}

void Init(int k)
{
	int i, j, x1, y1;
	printf("请输入迷宫的行数，列数（包括外墙）：");
	scanf("%d, %d", &x, &y);

	for ( i = 0; i < x; i++ )
	{
		m[0][i] = 0;
		m[x-1][i] = 0;
	}

	for ( i = 0; i < y-1; i++ )
	{
		m[i][0] = 0;
		m[i][y-1] = 0;
	}

	for ( i = 1; i < x-1; i++ )
		for ( j = 1; j < y-1; j++ )
			m[i][j] = k;
	printf("请输入迷宫内墙单元数：");
	scanf("%d", &j);
	printf("请依次输入迷宫内墙每个单元的行数，列数：\n");
	for ( i = 1; i <= j; i++ )
	{
		scanf("%d, %d", &x1, &y1);
		m[x1][y1] = 0;
	}

	printf("迷宫结构如下：\n");
	Print();

	printf("请输入入口的行数,列数：");
	scanf("%d, %d",&begin.x ,&begin.y);
	printf("请输入出口的行数,列数：");
	scanf("%d, %d",&end.x ,&end.y);
}
