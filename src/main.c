#include"Bmp.h"
#include"DoubleList.h"
#include"Album.h"
#include"Tounch.h"
#include<pthread.h>
Head* album = NULL;
int main()
{
    
    lcd_info lcd;
    Init_Lcd("/dev/fb0",&lcd);
    album = create_linkedlist();
    char buf[256]={0};
    getcwd(buf,256);
    search_photos(buf);
    print_list(album);
    Node* photo = album->first;
    Draw_bmp(&lcd,photo->photo);
    while (1)
    {
        /* pthread_t th1;
        if(pthread_create(&th1,NULL,Switch_Song,NULL))
        {
            perror("Creating  pthread failed!");
            exit(1);
        }
        void *direct= NULL;
        pthread_join(th1,&direct); */
        switch (Switch_Song())
        {
            case UP:
            printf("UP\n");
                photo = photo->next;   
                Draw_bmp(&lcd,photo->photo);
                break;
            case DOWN:
            printf("DOWN\n");   
                photo = photo->prev;
                Draw_bmp(&lcd,photo->photo);
                break;
            case LEFT:
            printf("LEFT\n");
                photo = photo->next;
                Draw_bmp(&lcd,photo->photo);
                break;
            case RIGHT:
            printf("RIGHT\n");
                photo = photo->prev;  
                Draw_bmp(&lcd,photo->photo);          
                break;
            default:
                break;
        }
    }
    Cle_Lcd(&lcd);
    return 0;
}
