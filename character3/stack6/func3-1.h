struct PosType
{
	int x;
	int y;
};

#define MAXLENGTH 25	//���Թ����������Ϊ25
typedef int MazeType[MAXLENGTH][MAXLENGTH];

MazeType m;
int x, y;
PosType begin, end;

void Print()
{
	//����Թ��Ľ�
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
	printf("�������Թ���������������������ǽ����");
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
	printf("�������Թ���ǽ��Ԫ����");
	scanf("%d", &j);
	printf("�����������Թ���ǽÿ����Ԫ��������������\n");
	for ( i = 1; i <= j; i++ )
	{
		scanf("%d, %d", &x1, &y1);
		m[x1][y1] = 0;
	}

	printf("�Թ��ṹ���£�\n");
	Print();

	printf("��������ڵ�����,������");
	scanf("%d, %d",&begin.x ,&begin.y);
	printf("��������ڵ�����,������");
	scanf("%d, %d",&end.x ,&end.y);
}
