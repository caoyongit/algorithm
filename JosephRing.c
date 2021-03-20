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
	cyclic->next = head;// 首尾相连
	return head;
}

void findAndKillK(person*head, int k, int m)
{
	person * tail = head;
	//找到链表第一个结点的上一个结点，为删除操作做准备
	//while (tail->next != head) {
	//	tail = tail->next;
	//}
	person * p = head;
	//找到编号为k的人
	while (p->number != k)
	{
		tail = p;
		p = p->next;
	}
	//从编号为k的人开始，只符合p->next==p时，说明链表中除了p结点，所有编号都出列了
	while (p->next != p)
	{
		//找到从p报数1开始，报m的人，并且还要知道数m-1的人的位置tail,方便做删除操作
		for (int i = 1; i < m; i++)
		{
			tail = p;
			p = p->next;
		}
		tail->next = p->next;//从链表上将p结点摘下来
		printf("出列人的编号为：%d\n", p->number);
		free(p);
		p = tail->next;//继续使用指针指向出列编号的下一个编号，继续游戏
	}
	printf("出列人的编号为(胜利者):%d\n", p->number);
	free(p);
}

typedef struct Link {
	char elem;//代表数据域
	struct Link *next;//代表指针域，指向直接后继元素
}link;//link为节点名，每个节点都是一个link结构体

typedef enum bool
{
	False = 0,
	True = 1
}bool;

/*
从给定链表的第一个节点开始遍历，每遍历至一个节点，
都将其和所有的前驱节点进行比对，如果为同一个节点，
则表明当前链表中有环；反之，如果遍历至链表最后一个节点，
仍未找到相同的节点，则证明该链表中无环。
*/
// H为链表的表头
bool haveRing(link * H)
{
	link * Htemp = H;
	// 存储所遍历节点所有前驱节点的存储地址，64位环境下地址占8个字节，所以这里用long long类型
	long long addr[20] = { 0 };
	int length = 0, i = 0;
	//桌个遍历链表中各个节点
	while (Htemp) {
		//依次将Htemp和addr数组中记录的已遍历的地址进行比对
		for (i = 0; i < length; i++) {
			//如果比对成功，则证明有环
			if (Htemp == addr[i]) {
				return True;
			}
		}
		//比对不成功，则记录Htemp节点的存储地址
		addr[length] = Htemp;
		length++;
		Htemp = Htemp->next;
	}
	return False;
}

/*
即在一个链表中，如果 2 个指针（假设为 H1 和 H2）都从表头开始遍历链表，
其中 H1 每次移动 2 个节点的长度（H1 = H1->next->next）,
而 H2 每次移动 1 个节点的长度（H2 = H2->next），如果该链表为有环链表，
则 H1、H2 最终必定会相等；反之，如果该链表中无环，则 H1、H2 永远不会相遇。
*/
bool ifHaveRing(link * H) {
	link * H1 = H->next;
	link * H2 = H;
	while (H1) {
		if (H1 = H2) {
			//链表中有环
			return True;
		}
		else {
			H1 = H1->next;
			if (!H1) {
				//链表中无环
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
	printf("输入圆桌上的人数n:");
	int n;
	scanf("%d", &n);
	person *head = initLink(n);
	printf("从第k人开始报数(k>1&k<%d):", n);
	int k;
	scanf("%d", &k);
	printf("数到m的人出列:");
	int m;
	scanf("%d", &m);
	findAndKillK(head, k, m);
	return 0;
}*/