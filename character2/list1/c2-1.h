#define LIST_INIT_SIZE 10	//���Ա��洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT 2	//���Ա��洢�ռ�ķ�������

typedef int ElemType;

typedef struct SqList
{
	ElemType *elem;			//�洢�ռ��ַ
	int length;				//��ǰ����
	int listsize;			//��ǰ����Ĵ洢����
}SqList;
