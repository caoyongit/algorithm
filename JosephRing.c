#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int number;
	struct node * next;
}person;

person * initLink(int n)
{
	person * head=(person*)malloc(sizeof(person));
	head->number = 1;
	head->next = NULL;
	person*cyclic = head;
	for (int i = 2; i <= n; i++)
	{
		person * body = (person*)malloc(sizeof(person));
		body->number = i;
		body->next = NULL;
		cyclic->next = body;
		cyclic = cyclic->next;
	}
	cyclic->next = head;// ��β����
	return head;
}

void findAndKillK(person*head, int k, int m)
{
	person * tail = head;
	//�ҵ������һ��������һ����㣬Ϊɾ��������׼��
	//while (tail->next != head) {
	//	tail = tail->next;
	//}
	person * p = head;
	//�ҵ����Ϊk����
	while (p->number != k)
	{
		tail = p;
		p = p->next;
	}
	//�ӱ��Ϊk���˿�ʼ��ֻ����p->next==pʱ��˵�������г���p��㣬���б�Ŷ�������
	while (p->next != p)
	{
		//�ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1���˵�λ��tail,������ɾ������
		for (int i = 1; i < m; i++)
		{
			tail = p;
			p = p->next;
		}
		tail->next = p->next;//�������Ͻ�p���ժ����
		printf("�����˵ı��Ϊ��%d\n", p->number);
		free(p);
		p = tail->next;//����ʹ��ָ��ָ����б�ŵ���һ����ţ�������Ϸ
	}
	printf("�����˵ı��Ϊ(ʤ����):%d\n", p->number);
	free(p);
}

typedef struct Link {
	char elem;//����������
	struct Link *next;//����ָ����ָ��ֱ�Ӻ��Ԫ��
}link;//linkΪ�ڵ�����ÿ���ڵ㶼��һ��link�ṹ��

typedef enum bool
{
	False = 0,
	True = 1
}bool;

/*
�Ӹ�������ĵ�һ���ڵ㿪ʼ������ÿ������һ���ڵ㣬
����������е�ǰ���ڵ���бȶԣ����Ϊͬһ���ڵ㣬
�������ǰ�������л�����֮������������������һ���ڵ㣬
��δ�ҵ���ͬ�Ľڵ㣬��֤�����������޻���
*/
// HΪ����ı�ͷ
bool haveRing(link * H)
{
	link * Htemp = H;
	// �洢�������ڵ�����ǰ���ڵ�Ĵ洢��ַ��64λ�����µ�ַռ8���ֽڣ�����������long long����
	long long addr[20] = { 0 };
	int length = 0, i = 0;
	//�������������и����ڵ�
	while (Htemp) {
		//���ν�Htemp��addr�����м�¼���ѱ����ĵ�ַ���бȶ�
		for (i = 0; i < length; i++) {
			//����ȶԳɹ�����֤���л�
			if (Htemp == addr[i]) {
				return True;
			}
		}
		//�ȶԲ��ɹ������¼Htemp�ڵ�Ĵ洢��ַ
		addr[length] = Htemp;
		length++;
		Htemp = Htemp->next;
	}
	return False;
}

/*
����һ�������У���� 2 ��ָ�루����Ϊ H1 �� H2�����ӱ�ͷ��ʼ��������
���� H1 ÿ���ƶ� 2 ���ڵ�ĳ��ȣ�H1 = H1->next->next��,
�� H2 ÿ���ƶ� 1 ���ڵ�ĳ��ȣ�H2 = H2->next�������������Ϊ�л�����
�� H1��H2 ���ձض�����ȣ���֮��������������޻����� H1��H2 ��Զ����������
*/
bool ifHaveRing(link * H) {
	link * H1 = H->next;
	link * H2 = H;
	while (H1) {
		if (H1 = H2) {
			//�������л�
			return True;
		}
		else {
			H1 = H1->next;
			if (!H1) {
				//�������޻�
				return False;
			}
			else {
				H1 = H1->next;
				H2 = H2->next;
			}
		}
	}
	return False;
}

/*
int main()
{
	printf("����Բ���ϵ�����n:");
	int n;
	scanf("%d", &n);
	person *head = initLink(n);
	printf("�ӵ�k�˿�ʼ����(k>1&k<%d):", n);
	int k;
	scanf("%d", &k);
	printf("����m���˳���:");
	int m;
	scanf("%d", &m);
	findAndKillK(head, k, m);
	return 0;
}*/