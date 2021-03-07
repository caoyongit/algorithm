#include <stdio.h>
#include <stdlib.h>
#define Size 5

typedef struct Table {
	int * head;//申明了一个名为head的长度不确定的数组，也叫动态数组
	int length;//记录当前顺序表的长度
	int size;//记录顺序表分配的容量
}table;

table initTable() {
	table t;
	t.head = (int*)malloc(Size*sizeof(int));
	if (!t.head)
	{
		printf("初始化失败\n");
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

//插入函数，elem为插入元素，add为插入到顺序表的位置
table addTable(table t, int elem, int add) {
	//判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作为提示并自动退出）
	if (add > t.length + 1 || add < 1)
	{
		printf("插入的位置有问题\n");
		return t;
	}
	//做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
	if (t.length == t.size)
	{
		t.head = (int*)realloc(t.head, (t.length + 1)*sizeof(int));
		if (!t.head)
		{
			printf("存储分配失败\n");
			exit(0);
		}
		t.size += 1;
	}
	//插入操作，需要从插入位置开始的后续元素，卓个后移
	for (int i = t.length - 1; i >= add - 1; i--)
	{
		t.head[i + 1] = t.head[i];
	}
	//后移完成后，直接将所需插入元素，添加到顺序表的相应位置
	t.head[add - 1] = elem;
	//由于添加了元素，所以长度+1
	t.length++;
	return t;
}

table delTable(table t, int add) {
	if (add > t.length + 1 || add < 1)
	{
		printf("插入的位置有问题\n");
		return t;
	}
	for (int i = add; i < t.length; i++)
	{
		t.head[i - 1] = t.head[i];
	}
	t.length--;
	return t;
}

int selectTable(table t, int elem) {
	for (int i = 0; i < t.length; i++)
	{
		if (t.head[i] == elem)
		{
			return i + 1;
		}
	}
	return -1;//查找失败，返回-1
}

//更改元素，elem为要更改的元素，newElem为新的数据元素
table amendTable(table t, int elem, int newElem) {
	int add = selectTable(t, elem);
	t.head[add - 1] = newElem;//返回的是元素在顺序表中的位置，所以-1就是该元素在数组中的下标
	return t;
}

/*
int main() {
	table t = initTable();
	for (int i = 1; i <= Size; i++) {
		t.head[i - 1] = i;
		t.length++;
	}
	printf("原顺序表\n");
	displayTalbe(t);

	printf("删除元素1：\n");
	t = delTable(t, 1);
	displayTalbe(t);

	printf("在第2的位置插入元素5：\n");
	t = addTable(t, 5, 2);
	displayTalbe(t);

	printf("查找元素3的位置：\n");
	int add = selectTable(t, 3);
	printf("%d\n", add);

	printf("将元素3改为6:\n");
	t = amendTable(t, 3, 6);
	displayTalbe(t);

	return 0;
}*/

