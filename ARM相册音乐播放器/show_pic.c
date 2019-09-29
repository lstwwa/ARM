#include "show_pic.h"
#include "jpeglib.h"

//初始化Lcd
void Lcd_Init()
{
	fd = open("/dev/fb0", O_RDWR);
	if(-1 == fd)
	{
		perror("open lcd failed");
		exit(0);
	}

	lcd_map = (unsigned int* )mmap(NULL, LENGTH*HEIGHT*4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(lcd_map == MAP_FAILED)
	{
		perror("mmap failed");
		exit(1);
	}

}



//释放lcd资源
void Lcd_Uninit()
{
	
	munmap(lcd_map, LENGTH*HEIGHT*4);
	close(fd);
}


void Show_Pic_Mid(const char* picname)
{
	
	
	FILE * pic_fp = fopen(picname , "r");
	if(strcmp(picname+strlen(picname)-4 , ".bmp") == 0)
	{
		
		if(NULL == pic_fp)
		{
			perror("open bmp failed");
			exit(0);
		}
	//	printf("这是一张bmp----------你触摸了：");
		unsigned char head[54];
		int heigh , len , len1 , x0 , y0 , num;
		fread(head, 54, 1,pic_fp);
		len = head[21]<<24 | head[20]<<16 | head[19]<<8 | head[18];
		heigh = head[25]<<24 | head[24]<<16 | head[23]<<8 | head[22];

		x0 = 400 - len/2;
		y0 = 240 - heigh/2;

		if(0 != (num = (len*3)%4))
		{
			len1 = (len*3 + 4 - num);
		}else{
			len1 = len*3;
		}


		unsigned char bmp_buf[heigh*len1];
		unsigned int buf[heigh*len];
		int i,j;

		bzero(buf , sizeof(buf));
		bzero(bmp_buf , sizeof(bmp_buf));
	//	bzero(lcd_map , LENGTH*HEIGHT*4);
		for(i=0; i<LENGTH*HEIGHT; i++)
		{
			lcd_map[i] = 0xffffffff;
		}

		fread(bmp_buf, len1*heigh, 1, pic_fp);

		unsigned char A, R, G, B;

		for(i=0; i<heigh; i++)
		{
			for(j=0; j<len; j++)
			{
				A = 0x00;
				B = bmp_buf[i*len1 + j*3];
				G = bmp_buf[i*len1 + j*3 + 1];
				R = bmp_buf[i*len1 + j*3 + 2];
				// ARGB = A R G B ==> 1234 == 1*1000 + 2*100 + 3*10 + 4*1
				buf[i*len + j] = A<<24 | R<<16 | G<<8 | B;
			}
			if(num != 0)
			{
				A = 0x00;
				B = bmp_buf[i*len1 + j*3];
				G = bmp_buf[i*len1 + j*3 + 1];
				R = bmp_buf[i*len1 + j*3 + 2];
				// ARGB = A R G B ==> 1234 == 1*1000 + 2*100 + 3*10 + 4*1
				buf[i*len + j] = A<<24 | R<<16 | G<<8 | B;
			}

			
		}

		for(i=y0; (i<heigh+y0) && (i<HEIGHT); i++)
		{
			for(j=x0; (j<len+x0) && (j<LENGTH); j++)
			{
				lcd_map[800*i+j] = buf[len*(heigh-1-i+y0)+j-x0];
			}
		}
	}
	
	
	
	if(strcmp(picname+strlen(picname)-5 , ".jpeg") == 0)
	{
		
	//	printf("这是一张jpeg---------你触摸了：");
		if(NULL == pic_fp)
		{
			perror("open jpg failed");
			exit(0);
		}		
		display(picname);
	}
	
	

	if(strcmp(picname+strlen(picname)-4 , ".jpg") == 0)
	{
	//	printf("这是一张jpg----------你触摸了：");
		if(NULL == pic_fp)
		{
			perror("open jpg failed");
			exit(0);
		}		
		display(picname);
	}
	fclose(pic_fp);
}

