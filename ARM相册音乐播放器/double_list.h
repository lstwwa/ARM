#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct double_list_node
{
	int data;
	char pic_path[512];

	struct double_list_node *prev;
	struct double_list_node *next;
}D_Node;

D_Node *list;

//1,创建链表
D_Node *Create_List();

//2,创建链表节点
D_Node *Create_Node(char *pic_path);

//3,节点加入链表
bool Insert_Node(D_Node * list, D_Node * newnode);

//4,删除特征链表节点
bool Remove_Node(D_Node * list, int data);

//5,遍历显示链表
bool Show_List(D_Node * list);

//6,查找节点
bool Search_Node(D_Node * list, int data);

//7,删除链表
void Delete_List(D_Node * list);

#endif



