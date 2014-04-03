#include "c1.h"
#include "c1-1.h"
#include "bo1-1.cpp"



void main()
{
	Triplet T;
	ElemType m;
	Status i;
	i = InitTriplet(T, 5, 7, 9);
	printf("���ó�ʼ��������i = %d(1:�ɹ�) T������ֵΪ", i);
	cout << T[0] << ' ' << T[1] << ' ' << T[2] << endl;
	//Ϊ����ElemType�����ͱ仯��Ӱ�죬��coutȡ��printf������
	i = Get(T, 2, m);
	if ( i == OK )
		cout << "T�ĵ�2��ֵΪ" << m << endl;
	i = Put(T, 2, 6);
	if ( i == OK )
		cout << "��T�ĵ�2��ֵ��Ϊ6��T������ֵΪ" << T[0] << ' ' << T[1] << ' ' << T[2] << endl;
	i = IsAscending(T);	//���ຯ��ʵ����ElemType�������޹أ���ElemType�����ͱ仯ʱ��ʵ�β���ı�
	printf("���ò�������ĺ����� i = %d(0:�� 1:��)\n", i);
	i = IsDescending(T);
	printf("���ò��Խ���ĺ����� i = %d(0:�� 1:��)\n", i);
	if ( (i = Max(T,m)) == OK )
		cout << "T�е����ֵΪ" << m << endl;
	if ( (i = Min(T,m)) == OK)
		cout << "T�е����ֵΪ" << m << endl;
	DestroyTriplet(T);
	cout << "����T��T= " << T << "(NULL)" << endl;
}
