#include "ts.h"


/*
 *返回值：
 *功能：获取触摸屏一个值的坐标
 *参数：
 */

 //初始化触摸屏
int Ts_Init()
{
	//1.打开触摸屏文件
	int ts_fd = open("/dev/input/event0", O_RDWR);
	if(-1 == ts_fd)
	{
		perror("open event0 failed");
		exit(0);
	}
	return ts_fd;
}

//释放触摸屏资源
int Ts_Uninit(int ts_fd)
{
	//3.关闭文件
	//free(buf);
	close(ts_fd);
}


//获取一个坐标值
void Get_Ts(int ts_fd)
{

	int flag = 0;
	while(1)
	{
		struct input_event buf;// = malloc(buf , sizeof(buf));//申请一块内存空间
		bzero(&buf ,sizeof(buf));//清空数据

		read(ts_fd , &buf , sizeof(buf));//读取数据

//		printf("type:%d, code:%d, value:%d\n", buf.type , buf.code , buf.value);

		if(buf.type == EV_ABS && buf.code == ABS_X && flag == 0)
		{
			ts_x = buf.value;
			flag = 1; 
		}
		if(buf.type == EV_ABS && buf.code == ABS_Y && flag == 1)
		{
			ts_y = buf.value;
			flag = 2;
		}
		if(flag == 2)
		{
			printf("x: %d , y: %d\n", ts_x , ts_y);
			flag = 0;
			break;
		}

/*		switch(buf.type)
		{
			case EV_SYN:
				printf("\n");
			break;

			case EV_ABS:

				switch(buf.code)
				{
					case ABS_X:
						printf(" x : %u\n", buf.value);
						break;

					case ABS_Y:
						printf(" y : %u\n", buf.value);
						break;

					case ABS_PRESSURE:
						printf(" pressure : %u\n", buf.value);
				}
		}
*/
	}
}


/*
 *返回值：动作指令 0 点击 1 向左滑 2 向右滑 3 向上滑 4 向下滑
 *功能：获取触摸屏一个动作指令
 *参数：触摸屏文件描述符
 */

int Get_Ts_Motion(int ts_fd)
{
	struct input_event buf;
	ts_x = 0 ; ts_y = 0;
	int start_x , start_y;  //手指按下的坐标值
	int ret_x , ret_y;      //手指松开的坐标值

	while(1)
	{
		bzero(&buf ,sizeof(buf));//清空数据

		read(ts_fd , &buf , sizeof(buf));//读取数据

		if(buf.type == EV_ABS && buf.code == ABS_X ) 
			ret_x = buf.value ;  //一直读取的X坐标
		else if(buf.type == EV_ABS && buf.code == ABS_Y ) 
			ret_y = buf.value ;  //一直读取的Y坐标
		
		if(buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 1) // 按下
		{
			start_x = ret_x;//开始的X坐标
			start_y = ret_y;//开始的Y坐标
//			printf("x1:%d y1:%d\n", start_x , start_y);
		}

		if(buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0) //松开手指
		{
//			printf("x2:%d y2:%d\n", ret_x , ret_y);
			break;
		}
	}

	//	if(ret.x==start.x && ret.y==start.y)  // 单击没有那么准确
	if( ret_x<start_x+20 && ret_x >start_x-20 && ret_y<start_y+20 && ret_y >start_y-20 )  //0 单击
		return 0;
	else if( (ret_x - start_x)*(ret_x - start_x) > (ret_y - start_y)*(ret_y - start_y) && ret_x < start_x )  //1 向左滑 
		return 1;
	else if( (ret_x - start_x)*(ret_x - start_x) > (ret_y - start_y)*(ret_y - start_y) && ret_x > start_x )  //2 向右滑
		return 2;
	else if( (ret_x - start_x)*(ret_x - start_x) < (ret_y - start_y)*(ret_y - start_y) && ret_y < start_y )  //3 向上滑
		return 3;
	else if( (ret_x - start_x)*(ret_x - start_x) < (ret_y - start_y)*(ret_y - start_y) && ret_y > start_y )  //4 向下滑
		return 4;

}
