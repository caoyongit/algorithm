#include <stdlib.h>
#include <stdio.h>
#define Size 5

typedef struct Link {
	char elem;//代表数据域
	struct Link *next;//代表指针域，指向直接后继元素
}link;//link为节点名，每个节点都是一个link结构体

/*
link * initLink() {
	link *p = NULL;//创建头指针
	link *temp = (link*)malloc(sizeof(link));//创建首元节点
	temp->elem = 1;
	temp->next = NULL;
	p = temp;//头指针指向首元节点
	//从第二个节点开始创建
	for (int i = 2; i < 5; i++)
	{
		//创建一个新节点并初始化
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		//将temp节点与新建立的a节点建立逻辑关系
		temp->next = a;
		//指针temp每次都指向新链表的最后一个节点，其实就是a节点，这里写temp=a也对
		temp = temp->next;
	}
	//返回建立的节点，之返回头指针p即可，通过头指针即可找到整个链表
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
	link *p = (link*)malloc(sizeof(link));//创建一个头结点
	link *temp = p;//声明一个指针指向头结点，用于遍历链表
	//生成链表
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
	//首先找到要插入位置的上一个节点
	for (int i = 1; i < add; i++) {
		temp = temp->next;
		if (temp == NULL) {
			printf("插入位置无效\n");
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
			printf("没有改节点\n");
			return p;
		}
	}
	link *del = temp->next;//单独设置一个指针指向被删除的节点
	temp->next = temp->next->next;//删除某个节点的方法就是更改前一个节点的指针域
	free(del);//手动释放该节点，防止内存泄漏
	return p;
}

//p为原链表，elem表示被查找元素
int selectElem(link *p, int elem)
{
	//新建一个指针t，初始化为头指针 p
	link *t = p;
	int i = 1;
	//由于头节点的存在，因此while中的判断为t->next
	while (t->next)
	{
		t = t->next;
		if (t->elem == elem)
		{
			return i;
		}
		i++;
	}
	//程序执行至此处，表示查找失败
	return -1;
}

//更新函数，其中，add表示更改节点在链表中的位置，newElem为新的数据域的值
link *amendElem(link *p, int add, int newElem) {
	link *temp = p;
	temp = temp->next;//在遍历之前，temp指向首元节点
	//遍历到待更新节点
	for (int i = 1; i < add; i++) {
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}

int main() {
	//初始化链表（1，2，3，4）
	printf("初始化链表为：\n");
	link *p = initLink();
	display(p);

	printf("在第4的位置插入元素5：\n");
	p = insertElem(p, 5, 4);
	display(p);

	printf("删除元素3:\n");
	p = delElem(p, 3);
	display(p);

	printf("查找元素2的位置为：\n");
	int address = selectElem(p, 2);
	if (address == -1) {
		printf("没有该元素");
	} else {
		printf("元素2的位置为：%d\n", address);
	}

	printf("更改第3的位置上的数据为7:\n");
	p = amendElem(p, 3, 7);
	display(p);

	return 0;
}