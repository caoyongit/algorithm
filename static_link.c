#include <stdio.h>
#define maxSize 6

typedef struct {
	int data;//������
	int cur;//�α�
}component;

//������������
void reserveArr(component *array)
{
	for (int i = 0; i < maxSize; i++)
	{
		array[i].cur = i + 1;//��ÿ������������ӵ�һ��
		array[i].data = -1;
	}
	array[maxSize].cur = 0;//�������һ�������α�ֵΪ0
}

//��ȡ����ռ�
int mallocArr(component * array)
{
	//����������ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0�����������һ���ڵ�ʱ���ýڵ���α�ֵΪ0��
	int i = array[0].cur;
	if (array[0].cur) {
		array[0].cur = array[i].cur;
	}
	return i;
}

int initArr(component *array)
{
	reserveArr(array);
	int body = mallocArr(array);
	//����һ��������������ָ��ʹ��ָ�����������һ����㣬��Ϊ����Ϊ�գ����Ժ�ͷ����غ�
	int tempBody = body;
	for (int i = 1; i<4; i++) {
		int j = mallocArr(array);//�ӱ����������ó����еķ���
		array[tempBody].cur = j;//������Ŀ��з�����������������һ��������
		array[j].data = i;//��������ķ������������ʼ��
		tempBody = j;//��ָ���������һ������ָ�����
	}
	array[tempBody].cur = 0;//�µ��������һ������ָ������Ϊ0
	return body;
}

void displayArr(component * array, int body) {
	int tempBody = body;//tempBody׼��������ʹ��
	while (array[tempBody].cur) {
		printf("%d,%d ", array[tempBody].data, array[tempBody].cur);
		tempBody = array[tempBody].cur;
	}
	printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}

int main()
{
	component array[maxSize];
	int body = initArr(array);
	printf("��̬����Ϊ��\n");
	displayArr(array, body);
	return 0;
}