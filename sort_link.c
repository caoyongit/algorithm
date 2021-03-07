#include <stdio.h>
#include <stdlib.h>
#define Size 5

typedef struct Table {
	int * head;//������һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�ж�̬����
	int length;//��¼��ǰ˳���ĳ���
	int size;//��¼˳�����������
}table;

table initTable() {
	table t;
	t.head = (int*)malloc(Size*sizeof(int));
	if (!t.head)
	{
		printf("��ʼ��ʧ��\n");
		exit(0);
	}
	t.length = 0;
	t.size = Size;
	return t;
}

void displayTalbe(table t) {
	for (int i = 0; i < t.length; i++) {
		printf("%d ", t.head[i]);
	}
	printf("\n");
}

//���뺯����elemΪ����Ԫ�أ�addΪ���뵽˳����λ��
table addTable(table t, int elem, int add) {
	//�жϲ��뱾���Ƿ�������⣨�������Ԫ��λ�ñ����ű�ĳ���+1���������ȣ���β�������������߲����λ�ñ������ڣ�������Ϊ��ʾ���Զ��˳���
	if (add > t.length + 1 || add < 1)
	{
		printf("�����λ��������\n");
		return t;
	}
	//���������ʱ��������Ҫ��˳����Ƿ��ж���Ĵ洢�ռ��ṩ�������Ԫ�أ����û�У���Ҫ����
	if (t.length == t.size)
	{
		t.head = (int*)realloc(t.head, (t.length + 1)*sizeof(int));
		if (!t.head)
		{
			printf("�洢����ʧ��\n");
			exit(0);
		}
		t.size += 1;
	}
	//�����������Ҫ�Ӳ���λ�ÿ�ʼ�ĺ���Ԫ�أ�׿������
	for (int i = t.length - 1; i >= add - 1; i--)
	{
		t.head[i + 1] = t.head[i];
	}
	//������ɺ�ֱ�ӽ��������Ԫ�أ���ӵ�˳������Ӧλ��
	t.head[add - 1] = elem;
	//���������Ԫ�أ����Գ���+1
	t.length++;
	return t;
}

table delTable(table t, int add) {
	if (add > t.length + 1 || add < 1)
	{
		printf("�����λ��������\n");
		return t;
	}
	for (int i = add; i < t.length; i++)
	{
		t.head[i - 1] = t.head[i];
	}
	t.length--;
	return t;
}

int selectTable(table t, int elem) {
	for (int i = 0; i < t.length; i++)
	{
		if (t.head[i] == elem)
		{
			return i + 1;
		}
	}
	return -1;//����ʧ�ܣ�����-1
}

//����Ԫ�أ�elemΪҪ���ĵ�Ԫ�أ�newElemΪ�µ�����Ԫ��
table amendTable(table t, int elem, int newElem) {
	int add = selectTable(t, elem);
	t.head[add - 1] = newElem;//���ص���Ԫ����˳����е�λ�ã�����-1���Ǹ�Ԫ���������е��±�
	return t;
}

/*
int main() {
	table t = initTable();
	for (int i = 1; i <= Size; i++) {
		t.head[i - 1] = i;
		t.length++;
	}
	printf("ԭ˳���\n");
	displayTalbe(t);

	printf("ɾ��Ԫ��1��\n");
	t = delTable(t, 1);
	displayTalbe(t);

	printf("�ڵ�2��λ�ò���Ԫ��5��\n");
	t = addTable(t, 5, 2);
	displayTalbe(t);

	printf("����Ԫ��3��λ�ã�\n");
	int add = selectTable(t, 3);
	printf("%d\n", add);

	printf("��Ԫ��3��Ϊ6:\n");
	t = amendTable(t, 3, 6);
	displayTalbe(t);

	return 0;
}*/

