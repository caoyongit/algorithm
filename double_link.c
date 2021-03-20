#include <stdlib.h>
#include <stdio.h>

typedef struct line{
	struct line * prior; //ָ��ֱ��ǰ��
	int data;
	struct line * next; //ָ��ֱ�Ӻ��
} line;

line * initLine(line * head) {
	//����һ����Ԫ�ڵ㣬�����ͷָ��Ϊhead
	head = (line*)malloc(sizeof(line));
	//�Խڵ���г�ʼ��
	head->prior = NULL;
	head->next = NULL;
	head->data = 1;
	//����һ��ָ����Ԫ�ڵ��ָ�룬�������������������´����Ľڵ�
	line * list = head;
	for (int i = 2; i <= 5; i++)
	{
		line * body = (line*)malloc(sizeof(line));
		body->prior = NULL;
		body->next = NULL;
		body->data = i;

		//�½ڵ����������һ���ڵ㽨����ϵ
		list->next = body;
		body->prior = list;
		//list��Զָ�����������һ���ڵ�
		list = list->next;
	}
	//�����´���������
	return head;
}

void displayLine(line * head) {
	line * temp = head;
	while (temp) {
		if (temp->next == NULL) {
			printf("%d\n", temp->data);
		}
		else {
			printf("%d <-> ", temp->data);
		}
		temp = temp->next;
	}
}

line *insertLine(line *head, int data, int add) {
	line * temp = (line*)malloc(sizeof(line));
	temp->data = data;
	temp->next = NULL;
	temp->prior = NULL;
	if(add ==1) {
		temp->next = head;
		head->prior = temp;
		head = temp;
	} 
	else {
		line * body = head;
		//�ҵ�Ҫ����λ�õ�ǰһ�����
		for (int i = 1; i < add - 1; i++) {
			body = body->next;
		}
		if (body->next == NULL) {
			body->next = temp;
			temp->prior = body;
		}
		else {
			body->next->prior = temp;
			temp->next = body->next;
			body->next = temp;
			temp->prior = body;
		}
	}
	return head;
}

line * delLine(line * head, int data) {
	line * temp = head;
	while (temp) {
		if (temp->data == data) {
			temp->prior->next = temp->next;
			temp->next->prior = temp->prior;
			free(temp);
			return head;
		}
		temp = temp->next;
	}
	printf("�������޸�����Ԫ��");
	return head;
}

//headΪԭ˫����elem��ʾ������Ԫ��
int selectElemLine(line * head, int elem) {
	//�½�һ��ָ��t����ʼ��Ϊͷָ�� head
	line * t = head;
	int i = 1;
	while (t) {
		if (t->data == elem) {
			return i;
		}
		i++;
		t = t->next;
	}
	//����ִ�����˴�����ʾ����ʧ��
	return -1;
}

//���º��������У�add ��ʾ���Ľ����˫�����е�λ�ã�newElem Ϊ�����ݵ�ֵ
line *amendElemLine(line * p, int add, int newElem) {
	line * temp = p;
	//��������ɾ�����
	for (int i = 1; i<add; i++) {
		temp = temp->next;
	}
	temp->data = newElem;
	return p;
}

/*
int main() {
	//����һ��ͷָ��
	//line * head = NULL;
	//��������������
	//head = initLine(head);
	//��������õ�����
	//displayLine(head);
	//��ʾ˫������ŵ�
	//printf("�����е� 4 ���ڵ��ֱ��ǰ���ǣ�%d\n", head->next->next->next->prior->data);

	line * head = NULL;
	//����˫����
	head = initLine(head);
	displayLine(head);
	//�ڱ��е� 3 ��λ�ò���Ԫ�� 7
	head = insertLine(head, 7, 3);
	displayLine(head);
	//����ɾ��Ԫ�� 2
	head = delLine(head, 2);
	displayLine(head);
	printf("Ԫ�� 3 ��λ���ǣ�%d\n", selectElemLine(head, 3));
	//���е� 3 ���ڵ��е����ݸ�Ϊ�洢 6
	head = amendElemLine(head, 3, 6);
	displayLine(head);
	return 0;

	return 0;
}*/