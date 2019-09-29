#ifndef _READ_H
#define _READ_H value

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <dirent.h>		//目录操作的头文件

int Show_dir(const char *pathname);

int Search_all(const char *pathname);

#endif