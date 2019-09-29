#include "main.h"
int main(int argc,char **argv)
{
	judge(argc);					//判断两个文件
	list = Create_List();			//初始化一个链表
	Show_dir(argv[1]);				//显示一个文件名字并且放入链表		
	Show_List(list);				//显示文件名字
	click();
	return 0;		
}

