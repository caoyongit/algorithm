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

//������ת����head Ϊ��ͷ�ڵ������ͷָ��
link * iteration_reverse(link* head) {
	if (head == NULL || head->next == NULL) 
	{
		return head;
	}
	else 
	{
		link *beg = NULL;
		link *mid = head;
		link *end = head->next;
		while (1)
		{
			//�޸� mid ��ָ�ڵ��ָ��
			mid->next = beg;
			//��ʱ�ж� end �Ƿ�Ϊ NULL������������˳�ѭ��
			if (end == NULL)
			{
				break;
			}
			//��������ƶ� 3 ��ָ��
			beg = mid;
			mid = end;
			end = end->next;
		}
		//����޸� head ͷָ���ָ��
		head = mid;
		return head;
	}
}

//�ݹ鷴ת��
link* recursive_reverse(link* head) 
{
	//�ݹ�ĳ���
	if (head == NULL && head->next == NULL) { // ������ֻ��һ����㣬ֱ�ӷ���ͷָ��
		
		return head;
	}
	else
	{
		//һֱ�ݹ飬�ҵ����������һ���ڵ�
		link *new_head = recursive_reverse(head->next);
		//������˳�ʱ��new_head ��ָ�򶼲��䣬һֱָ��ԭ���������һ���ڵ㣻

		//�ݹ�ÿ�˳�һ�㣬������ head ָ���ָ�򶼻ᷢ���ı䣬��ָ����һ���ڵ㡣
		//ÿ�˳�һ�㣬����Ҫ�ı� head->next �ڵ�ָ�����ָ��ͬʱ�� head ��ָ�ڵ��ָ����Ϊ NULL��
		head->next->next = head;
		head->next = NULL;
		//ÿһ��ݹ��������Ҫ���µ�ͷָ�뷵�ظ���һ�㡣�ɴˣ����ɱ�֤�����ݹ�����У��ܹ�һֱ�ҵõ�������ı�ͷ��
		return new_head;
	}
}

//ͷ�巨ʵ������ת
link *head_reverse(link *head)
{
	link *new_head = NULL;
	link * temp = NULL;
	if (head == NULL || head->next == NULL) {
		return head;
	}
	while (head != null)
	{
		temp = head;
		//�� temp �� head ��ժ��
		head = head->next;

		//�� temp ���뵽 new_head ��ͷ��
		temp->next = new_head;
		new_head = temp;
	}
	return new_head;
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