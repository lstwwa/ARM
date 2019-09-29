#include "read.h"

#include "double_list.h"


//读取文件夹里面所有的.bmp文件名放在插入到链表中。
int Show_dir(const char *pathname)
{
	char bmp_name_buf[512];
	char jpg_name_buf[512];
	//打开目录argv[1]
	printf("读出文件\n");
	printf("-------------------------\n");
	DIR *dirp = opendir(pathname);

	//循环读取目录下的而所有文件信息，输出每次读取的文件名。
	struct dirent *ret = NULL;
	
	while(ret = readdir(dirp))
	{
		bzero(bmp_name_buf , sizeof(bmp_name_buf));

		if (ret->d_name[0] == '.')
		{
			continue;
		}
		
		
		if(strcmp(ret->d_name+strlen(ret->d_name)-4 , ".bmp") == 0)
		{
			printf("%s\n", ret->d_name);
			if( pathname[strlen(pathname) - 1] == '/')
			{
			sprintf(bmp_name_buf , "%s%s" , pathname , ret->d_name);
			}
			else{
				sprintf(bmp_name_buf , "%s/%s" , pathname , ret->d_name);
			}
			//创建新的节点，把读到的文件路径加名字
			D_Node *new = Create_Node(bmp_name_buf);

			Insert_Node(list , new);
		}
		
		if(strcmp(ret->d_name+strlen(ret->d_name)-5 , ".jpeg") == 0)
		{
			printf("%s\n", ret->d_name);
			if( pathname[strlen(pathname) - 1] == '/')
			{
			sprintf(jpg_name_buf , "%s%s" , pathname , ret->d_name);
			}
			else{
				sprintf(jpg_name_buf , "%s/%s" , pathname , ret->d_name);
			}
			//创建新的节点，把读到的文件路径加名字
			D_Node *new = Create_Node(jpg_name_buf);

			Insert_Node(list , new);
		}
		
		if(strcmp(ret->d_name+strlen(ret->d_name)-4 , ".jpg") == 0)
		{
			printf("%s\n", ret->d_name);
			if( pathname[strlen(pathname) - 1] == '/')
			{
			sprintf(jpg_name_buf , "%s%s" , pathname , ret->d_name);
			}
			else{
				sprintf(jpg_name_buf , "%s/%s" , pathname , ret->d_name);
			}
			//创建新的节点，把读到的文件路径加名字
			D_Node *new = Create_Node(jpg_name_buf);

			Insert_Node(list , new);
		}
		
	}
	printf("-------------------------\n");
	//3,关闭目录
	closedir(dirp);
}