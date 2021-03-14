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

//�������в������ݣ�body��ʾ�����ͷ����������е�λ�ã�add��ʾ����Ԫ�ص�λ�ã�a��ʾҪ���������
void insertArr(component * array, int body, int add, char a)
{
	//tempBody�������ṹ������ʹ��
	int tempBody = body;
	//�ҵ�Ҫ����λ�õ���һ������������е�λ��
	for (int i = 1; i < add; i++)
	{
		tempBody = array[tempBody].cur;
	}
	int insert = mallocArr(array);//����ռ䣬׼������
	array[insert].data = a;
	array[insert].cur = array[tempBody].cur;//�²�������α������ֱ��ǰ�������α�
	array[tempBody].cur = insert;//ֱ��ǰ�������α�����²��������������е��±�
}

//����������տռ�ĺ���������arrayΪ�洢���ݵ����飬k��ʾδʹ�ýڵ�����������±�
void freeArr(component * array, int k)
{
	array[k].cur = array[0].cur;
	array[0].cur = k;
}

//ɾ����㺯����a ��ʾ��ɾ��������������ŵ�����
void deletArr(component * array, int body, char a) {
	int tempBody = body;
	//�ҵ���ɾ������λ��
	while (array[tempBody].data != a) {
		tempBody = array[tempBody].cur;
		//��tempBodyΪ0ʱ����ʾ�������������˵��������û�д洢�����ݵĽ��
		if (tempBody == 0) {
			printf("������û�д�����");
			return;
		}
	}
	//���е��ˣ�֤���иý��
	int del = tempBody;
	tempBody = body;
	//�ҵ��ý�����һ����㣬��ɾ������
	while (array[tempBody].cur != del) {
		tempBody = array[tempBody].cur;
	}
	//����ɾ�������α�ֱ�Ӹ���ɾ��������һ�����
	array[tempBody].cur = array[del].cur;
	//���ձ�ժ���ڵ�Ŀռ�
	freeArr(array, del);
}

//����body��Ϊͷ���������в���������Ϊelem�Ľ���������е�λ��
int selectElem(component * array, int body, char elem) {
	int tempBody = body;
	//���α�ֵΪ0ʱ����ʾ�������
	while (array[tempBody].cur != 0) {
		if (array[tempBody].data == elem) {
			return tempBody;
		}
		tempBody = array[tempBody].cur;
	}
	return -1;//����-1����ʾ��������û���ҵ���Ԫ��
}

//����body��Ϊͷ���������н�������ΪoldElem�Ľ�㣬�������ΪnewElem
void amendElem(component * array, int body, char oldElem, char newElem) {
	int add = selectElem(array, body, oldElem);
	if (add == -1) {
		printf("�޸���Ԫ��");
		return;
	}
	array[add].data = newElem;
}

/*int main()
{
	component array[maxSize];
	int body = initArr(array);
	printf("��̬����Ϊ��\n");
	displayArr(array, body);

	printf("�ڵ�3��λ���ϲ����㡮e��:\n");
	insertArr(array, body, 3, 'e');
	displayArr(array, body);

	printf("ɾ��������Ϊ��a���Ľ��:\n");
	deletArr(array, body, 'a');
	displayArr(array, body);

	printf("����������Ϊ��e���Ľ���λ��:\n");
	int selectAdd = selectElem(array, body, 'e');
	printf("%d\n", selectAdd);
	printf("�����������Ϊ��e����Ϊ��h��:\n");
	amendElem(array, body, 'e', 'h');
	displayArr(array, body);

	return 0;
}*/