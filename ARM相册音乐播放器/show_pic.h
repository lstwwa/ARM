#ifndef _SHOW_PIC_H
#define _SHOW_PIC_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <linux/fb.h>

//宏定义
#define LENGTH 800
#define HEIGHT 480

int fd;
unsigned int* lcd_map;

//初始化Lcd
void Lcd_Init();
//释放资源
void Lcd_Uninit();
//任意bmp图片居中显示
void Show_Pic_Mid(const char* picname);

void display(const char *picname);

#endif