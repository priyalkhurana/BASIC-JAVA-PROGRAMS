#include<stdio.h>
#include<conio.h>
#include<dirent.h>
void main()
{
    DIR *d;
    struct dirent *dir;
    d=opendir(".");
    if(d)
    {
        while((dir=readdir(d))!=NULL)
        {
            printf("%s\n",dir->d_name);
        }
    }
    closedir(d);
}