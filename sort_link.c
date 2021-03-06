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

int main() {
	table t = initTable();
	for (int i = 1; i <= Size; i++) {
		t.head[i - 1] = i;
		t.length++;
	}
	printf("˳����д洢��Ԫ�طֱ���\n");
	displayTalbe(t);
	return 0;
}

