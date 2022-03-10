#include"AT070TN92_LCD.h"
void Init_Lcd( const char*pathname,lcd_info *lcd)
{
    lcd->fd = open(pathname,O_RDWR);
    if (lcd->fd == -1)
    {
        perror("Open failed!");
        exit(1);
    }
    lcd->adr = mmap(NULL,LCD_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,lcd->fd,0);
    if (lcd->adr == MAP_FAILED)
    {
        perror("Map failed!");
        exit(1);
    }
    return;
}
void Clr_Lcd(lcd_info*lcd)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            lcd->adr[i*800+j] = 0xffffffff;
        }
    }
    return;
}
void Cle_Lcd(lcd_info *lcd)
{
    if(munmap(lcd->adr,LCD_SIZE))
    {
        perror("Mumap failed!");
        exit(1);
    }
    if(close(lcd->fd))
    {
        perror("Close failed!");
        exit(1);
    }
    return;
}
void Draw_point(lcd_info*lcd,int x,int y,unsigned int color)
{
    if (x>=480||x<0||y>=800||y<0)
    {
        printf("Point is out of the broad!\n");
        return;
    }
    lcd->adr[y+x*800] = color;
    return;
}