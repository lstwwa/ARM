#include "double_list.h"


/*
 *返回值：
 *功能：获取路径加文件的数据放在链表上
 *参数：
 */

//1,创建链表
D_Node *Create_List()
{
	D_Node *head = (D_Node *)malloc(sizeof(D_Node));
	if (NULL == head)
	{
		perror("malloc head failed!");
		return NULL;
	}

	head->prev = head;
	head->next = head;

	return head;
}

//2,创建链表节点
D_Node *Create_Node(char *pic_path)
{
	D_Node *node = (D_Node *)malloc(sizeof(D_Node));
	if (NULL == node)
	{
		perror("malloc node failed!");
		return NULL;
	}
	strcpy(node->pic_path, pic_path);
	node->prev = node;
	node->next = node;

	return node;
}

//3,节点加入链表
bool Insert_Node(D_Node * list, D_Node * newnode)
{
	//1,头插法
	newnode->next = list->next;
	list->next = newnode;
	
	newnode->next->prev = newnode;
	newnode->prev = list; 


	/*//2,尾插法
	D_Node *p = list;
	while(p->next != NULL)
	{
		p = p->next;
	}
	newnode->prev = p;
	p->next = newnode;*/

}

//4,删除特征链表节点
bool Remove_Node(D_Node * list, int data)
{
	if (list->next == list)
	{
		printf("list is empty\n");
		return false;
	}

	D_Node* del = list->next;
	while(del != list)
	{
		if (del->data == data)
		{
			
			del->prev->next = del->next;
			del->next->prev = del->prev;
			free(del);
			break;
		}
		del = del->next;
	}


}

//5,遍历显示链表
bool Show_List(D_Node * list)
{
	if (list->next == list)
	{
		printf("list is empty\n");
		return false;
	}

	D_Node* p = list->next;
	while(p != list)
	{
		//printf("%s\t", p->pic_path);
		p = p->next;
	}
	//printf("\n");
}

//6,查找节点
bool Search_Node(D_Node * list, int data)
{
	if (list->next == list)
	{
		printf("list is empty\n");
		return false;
	}

	D_Node* p = list->next;
	while(p != list)
	{
		if (p->data == data)
		{
			printf("data:%d\n", data);
			break;
		}
		p = p->next;
	}
}


//7,删除链表
void Delete_List(D_Node * list)
{
	if (list->next == list)
	{
		free(list);
		return;
	}

	D_Node* p = list->next;
	D_Node* q = p;

	while(p != list)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(list);
}
