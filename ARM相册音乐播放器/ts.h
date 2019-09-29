#ifndef _TS_H
#define _TS_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

#include <linux/input.h>  //输入子系统头文件



int ts_x, ts_y;

//初始化触摸屏
int Ts_Init();
//释放触摸屏资源
int Ts_Uninit(int ts_fd);
//获取一个坐标值
void Get_Ts(int ts_fd);

//获取触摸屏一个动作指令
int Get_Ts_Motion(int ts_fd);


#endif