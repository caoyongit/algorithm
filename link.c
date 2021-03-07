#include <stdlib.h>
#include <stdio.h>
#define Size 5

typedef struct Link {
	char elem;//����������
	struct Link *next;//����ָ����ָ��ֱ�Ӻ��Ԫ��
}link;//linkΪ�ڵ�����ÿ���ڵ㶼��һ��link�ṹ��

/*
link * initLink() {
	link *p = NULL;//����ͷָ��
	link *temp = (link*)malloc(sizeof(link));//������Ԫ�ڵ�
	temp->elem = 1;
	temp->next = NULL;
	p = temp;//ͷָ��ָ����Ԫ�ڵ�
	//�ӵڶ����ڵ㿪ʼ����
	for (int i = 2; i < 5; i++)
	{
		//����һ���½ڵ㲢��ʼ��
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		//��temp�ڵ����½�����a�ڵ㽨���߼���ϵ
		temp->next = a;
		//ָ��tempÿ�ζ�ָ������������һ���ڵ㣬��ʵ����a�ڵ㣬����дtemp=aҲ��
		temp = temp->next;
	}
	//���ؽ����Ľڵ㣬֮����ͷָ��p���ɣ�ͨ��ͷָ�뼴���ҵ���������
	return p;
}

void display(link *p) {
	link * temp = p;
	while (temp) {
		printf("%d ", temp->elem);
		temp = temp->next;
	}
	printf("\n");
}
*/

link * initLink() {
	link *p = (link*)malloc(sizeof(link));//����һ��ͷ���
	link *temp = p;//����һ��ָ��ָ��ͷ��㣬���ڱ�������
	//��������
	for (int i = 1; i < 5; i++) {
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = a;
	}
	return p;
}

void display(link *p) {
	link * temp = p;
	while (temp->next) {
		temp = temp->next;
		printf("%d ", temp->elem);
	}
	printf("\n");
}

link *insertElem(link *p, int elem, int add) {
	link *temp = p;
	//�����ҵ�Ҫ����λ�õ���һ���ڵ�
	for (int i = 1; i < add; i++) {
		temp = temp->next;
		if (temp == NULL) {
			printf("����λ����Ч\n");
			return p;
		}
	}
	link *c = (link*)malloc(sizeof(link));
	c->elem = elem;
	c->next = temp->next;
	temp->next = c;
	return p;
}

link *delElem(link *p, int add) {
	link * temp = p;
	for (int i = 1; i < add; i++) {
		temp = temp->next;
		if (temp->next == NULL) {
			printf("û�иĽڵ�\n");
			return p;
		}
	}
	link *del = temp->next;//��������һ��ָ��ָ��ɾ���Ľڵ�
	temp->next = temp->next->next;//ɾ��ĳ���ڵ�ķ������Ǹ���ǰһ���ڵ��ָ����
	free(del);//�ֶ��ͷŸýڵ㣬��ֹ�ڴ�й©
	return p;
}

//pΪԭ����elem��ʾ������Ԫ��
int selectElem(link *p, int elem)
{
	//�½�һ��ָ��t����ʼ��Ϊͷָ�� p
	link *t = p;
	int i = 1;
	//����ͷ�ڵ�Ĵ��ڣ����while�е��ж�Ϊt->next
	while (t->next)
	{
		t = t->next;
		if (t->elem == elem)
		{
			return i;
		}
		i++;
	}
	//����ִ�����˴�����ʾ����ʧ��
	return -1;
}

//���º��������У�add��ʾ���Ľڵ��������е�λ�ã�newElemΪ�µ��������ֵ
link *amendElem(link *p, int add, int newElem) {
	link *temp = p;
	temp = temp->next;//�ڱ���֮ǰ��tempָ����Ԫ�ڵ�
	//�����������½ڵ�
	for (int i = 1; i < add; i++) {
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}

int main() {
	//��ʼ������1��2��3��4��
	printf("��ʼ������Ϊ��\n");
	link *p = initLink();
	display(p);

	printf("�ڵ�4��λ�ò���Ԫ��5��\n");
	p = insertElem(p, 5, 4);
	display(p);

	printf("ɾ��Ԫ��3:\n");
	p = delElem(p, 3);
	display(p);

	printf("����Ԫ��2��λ��Ϊ��\n");
	int address = selectElem(p, 2);
	if (address == -1) {
		printf("û�и�Ԫ��");
	} else {
		printf("Ԫ��2��λ��Ϊ��%d\n", address);
	}

	printf("���ĵ�3��λ���ϵ�����Ϊ7:\n");
	p = amendElem(p, 3, 7);
	display(p);

	return 0;
}