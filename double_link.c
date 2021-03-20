#include <stdlib.h>
#include <stdio.h>

typedef struct line{
	struct line * prior; //指向直接前趋
	int data;
	struct line * next; //指向直接后继
} line;

line * initLine(line * head) {
	//创建一个首元节点，链表的头指针为head
	head = (line*)malloc(sizeof(line));
	//对节点进行初始化
	head->prior = NULL;
	head->next = NULL;
	head->data = 1;
	//声明一个指向首元节点的指针，方便后期向链表中添加新创建的节点
	line * list = head;
	for (int i = 2; i <= 5; i++)
	{
		line * body = (line*)malloc(sizeof(line));
		body->prior = NULL;
		body->next = NULL;
		body->data = i;

		//新节点与链表最后一个节点建立关系
		list->next = body;
		body->prior = list;
		//list永远指向链表中最后一个节点
		list = list->next;
	}
	//返回新创建的链表
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
		//找到要插入位置的前一个结点
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
	printf("链表中无该数据元素");
	return head;
}

//head为原双链表，elem表示被查找元素
int selectElemLine(line * head, int elem) {
	//新建一个指针t，初始化为头指针 head
	line * t = head;
	int i = 1;
	while (t) {
		if (t->data == elem) {
			return i;
		}
		i++;
		t = t->next;
	}
	//程序执行至此处，表示查找失败
	return -1;
}

//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
line *amendElemLine(line * p, int add, int newElem) {
	line * temp = p;
	//遍历到被删除结点
	for (int i = 1; i<add; i++) {
		temp = temp->next;
	}
	temp->data = newElem;
	return p;
}

/*
int main() {
	//创建一个头指针
	//line * head = NULL;
	//调用链表创建函数
	//head = initLine(head);
	//输出创建好的链表
	//displayLine(head);
	//显示双链表的优点
	//printf("链表中第 4 个节点的直接前驱是：%d\n", head->next->next->next->prior->data);

	line * head = NULL;
	//创建双链表
	head = initLine(head);
	displayLine(head);
	//在表中第 3 的位置插入元素 7
	head = insertLine(head, 7, 3);
	displayLine(head);
	//表中删除元素 2
	head = delLine(head, 2);
	displayLine(head);
	printf("元素 3 的位置是：%d\n", selectElemLine(head, 3));
	//表中第 3 个节点中的数据改为存储 6
	head = amendElemLine(head, 3, 6);
	displayLine(head);
	return 0;

	return 0;
}*/