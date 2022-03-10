#include"Tounch.h"
int  Switch_Song()
{
    int fd = open("/dev/input/event0",O_RDONLY);
    if (fd == -1)
    {
        perror("Open Touch Lcd failed!\n");
        exit(1);
    }
    struct input_event ev;
    Point start,end;
    start.x = -1;
    start.y = -1;
    int flag = 0;
    while (1)
    {
        if ( read(fd,&ev,sizeof(ev)) != sizeof(ev))
        {
            perror("Read failed!\n");
            exit(1);
        }
        if (ev.type == EV_ABS && ev.code == ABS_X)
        {
            if (start.x == -1 )
            {
                start.x = ev.value;
            }
            end.x = ev.value;
        }
        if (ev.type == EV_ABS && ev.code == ABS_Y )
        {
            if (start.y == -1 )
            {
                start.y = ev.value;
            }
            end.y = ev.value;
        }
        if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
        {
            printf("start.x=%d,start.y=%d\n",start.x,start.y);
            printf("end.x=%d,end.y=%d\n",end.x,end.y);
            break;
        }
    } 
    int value;
    int dy,dx;
    dy = end.y - start.y;
    dx = end.x - start.x;
    if (dy>dx&&dy>-dx)
    {
        value = DOWN;
    }
    else if (dy<dx&&dy>-dx)
    {
        value = LEFT;
        
    }
    else if (dy>dx&&dy<-dx)
    {
        value = RIGHT;   
    }
    else if (dy<dx&&dy<-dx)
    {
        value = UP;      
    }
    return value;
}