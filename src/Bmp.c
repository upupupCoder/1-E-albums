#include"bmp.h"
/********
 * 函数：Draw_bmp
 * 功能：显示图片
 * 参数：
 *      @lcd:lcd结构体
 *      @pathname:文件目录名
 * 返回值：
 *      无
 * ******/

void Draw_bmp(lcd_info*lcd,const  char*pathname)
{
    int fd_bmp =  open(pathname,O_RDONLY);
    if (fd_bmp == -1 )
    {
        perror("Open BMP failed!");
        exit(1);
    }
    unsigned int wid,hei,color,size_bmp,cor_offset;
    unsigned short int cor_dep;
    {
        int size_file ;
        /*第2个字节读取文件大小*/
        lseek(fd_bmp,0x02,SEEK_SET);
        read(fd_bmp,&size_file,4);
        printf("size_file:%d\n",size_file);
        /*第10个字节读取颜色数据偏移量*/
        lseek(fd_bmp,0x0a,SEEK_SET);
        read(fd_bmp,&cor_offset,4);
        size_bmp = size_file - cor_offset;
    }
    /*第18个字节读取宽度和高度*/
    lseek(fd_bmp,0x12,SEEK_SET);
    read(fd_bmp,&wid,4);
    read(fd_bmp,&hei,4);
    /*第28个字节读取色深*/
    lseek(fd_bmp,0x1c,SEEK_SET);
    read(fd_bmp,&cor_dep,2);
    printf("cor_offset:%d\n",cor_offset);
    printf("The width of BMP:%d\n",wid);
    printf("The height of BMP:%d\n",hei);
    printf("The depth of BMP:%d\n",cor_dep);
    unsigned char bmp_color[size_bmp];
    /*第54个字节开始读取颜色数据*/
    lseek(fd_bmp,0x36,SEEK_SET);
    if(read(fd_bmp,&bmp_color,size_bmp) != size_bmp)
    {
        perror("Read failed!");
        exit(1);
    }
    unsigned char r,g,b,a;
    unsigned int k = 0;
    if(cor_dep == 32) 
    {
        for(int x = HEIGHT-1;x >= 0; x--)
        {
            for (int y = 0; y < WIDTH; y++)
            {
                b = bmp_color[k++];
                g = bmp_color[k++];
                r = bmp_color[k++];
                a = bmp_color[k++];
                color = a<<24 | r<<16 | g<<8 | b;
                Draw_point(lcd,x,y,color);
            }
            
        }
    }
    else
    {
        for(int x = HEIGHT -1;x >= 0; x--)
        {
            for (int y = 0; y < WIDTH; y++)
            {
                b = bmp_color[k++];
                g = bmp_color[k++];
                r = bmp_color[k++];
                color = r<<16 | g<<8 | b;
                Draw_point(lcd,x,y,color);
            }   
        }
    }   
}