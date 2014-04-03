//�б༭����
typedef char SElemType;

#include "c1.h"
#include "c3-1.h"
#include "bo3-1.h"

FILE *fp;

void copy(SElemType c)
{//���ַ�c����fp��ָ���ļ���
	fputc(c, fp);	
}

void LineEdit()
{
	//�����ַ�ջs�����ն˽���һ�в��������ù��̵�������
	SqStack s;
	char ch;
	InitStack(s);
	printf("������һ���ı��ļ���^z�������룺\n");
	ch = getchar();

	while ( ch != EOF )
	{//��ȫ��û������EOFΪ^z��ȫ�Ľ�������
		while ( ch != EOF && ch != '\n' )
		{//��ȫ��û�н�����û����ĩ
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
		printf("�����ļ�ʧ�ܣ�\n");
}