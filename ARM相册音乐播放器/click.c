#include "lstwwa.h"
#include "double_list.h"
#include "show_pic.h"
#include "ts.h"
#include "read.h"
#include "judge.h"
#include "click.h"



void click(void)
{
	int ts_fd = Ts_Init();			//初始化触摸屏
	Lcd_Init();						//初始化显示屏
	D_Node* p = list->next;
	while(1)
		{
			//获取一个点的坐标值
			Get_Ts(ts_fd);

			//点击相应的区域显示上一张
			if(ts_x > 0 && ts_x < 200 && ts_y > 0 && ts_y < 1024 )
			{
				printf("上一张---------");
				p = p->prev;
				if (p == list)
				{
				//	printf("xxx\n");
					p = p->prev;
				}
				Show_Pic_Mid(p->pic_path);
				
			}
			
			//点击相应的区域显示下一张
			if(ts_x > 824 && ts_x < 1024 && ts_y > 0 && ts_y < 1024)
			{
				printf("下一张---------");
				p = p->next;
				if (p == list)
				{
				//printf("yyyy\n");
					p = p->next;
				}
				Show_Pic_Mid(p->pic_path);

			}
		
			if(ts_x > 200 && ts_x < 824 && ts_y > 400 && ts_y < 600)
			{
				Show_Pic_Mid("exit.bmp");
				printf("\n--------------------\n");
				printf("------退出相册------\n");
				printf("--------------------\n");
				exit(0);
			}
		}
		
		Lcd_Uninit();		//释放lcd资源
		Ts_Uninit(ts_fd);	//释放触摸屏资源
}