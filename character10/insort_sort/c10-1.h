//待排记录的数据类型
#define MAX_SIZE 20
typedef int KeyType;
struct RedType
{
	KeyType key;
	InfoType otherinfo;
};

struct SqList
{
	RedType r[MAX_SIZE + 1];
	int length;
};