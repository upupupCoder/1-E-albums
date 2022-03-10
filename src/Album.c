#include"Album.h"
extern Head *album;
void search_photos(const char*pathname)
{
    /*用opendir()来打开目录，返回一个目录流类型的指针*/
    DIR *dir = opendir(pathname);
    if(dir == NULL)
    {
        perror("Open dir failed!");
        exit(1);
    }
    printf("%s\n",pathname);
    char dirpath[DIR_SIZE] = {0};
    char buf[DIR_SIZE] = {0};
    struct dirent *curdir;
    /*用readdir函数来循环读取目录文件，参数是一个目录流类型的指针，返回值用一个struct dirent类型的指针来接收，每循环读取一次，目录流就会指向下一个文件*/
    while ((curdir = readdir(dir))!=NULL)
    {
        printf("haha\n");
        if (!strncmp(curdir->d_name,".",DIR_SIZE) || !strncmp(curdir->d_name,"..",DIR_SIZE))
        {
            continue;
        }
/*         printf("%s\n",getcwd(dirpath,DIR_SIZE)); */
        getcwd(buf,DIR_SIZE);
        snprintf(dirpath,DIR_SIZE*2,"%s/%s",buf,curdir->d_name);
/*         printf("%s\n",dirpath);    */
        if (curdir->d_type == DT_DIR)
        {
            search_photos(dirpath);
        }
        else if(curdir->d_type == DT_REG)
        {
        /*或者用rindex函数，这个函数是用来查找字符串中最后出现的一个指定字符，返回值是这个字符的地址*/
        /*用strrchr函数，这个函数用来查找字符串中第一个出现的指定字符串，返回值是指定字符串的地址*/
            char *suffix = rindex(curdir->d_name,'.');
//            printf("%s\n",curdir->d_name);
            if (suffix !=NULL && !strncmp(suffix,".bmp",4))
            {
                album = insert_node(album,dirpath);
            }
        }
    }
    closedir(dir);
    return ;
}