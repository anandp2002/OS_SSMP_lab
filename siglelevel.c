#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
    char dname[10], fname[10][10];
    int fcnt;
} dir;
void main()
{
    int i;
    char ch,f[30];
    dir.fcnt = 0;
    printf("\nEnter name of directory : ");
    scanf("%s", dir.dname);
    while (1)
    {
        printf("\n1.Create File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit\n\nEnter your choice : ");
        scanf("%s", &ch);
        switch (ch)
        {
        case '1':
            printf("\nEnter the name of the file : ");
            scanf("%s", dir.fname[dir.fcnt]);
            dir.fcnt++;
            break;
        case '2':
            printf("\nEnter the name of the file : ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("\n%s is deleted", f);
                    strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                    break;
                }
            }
            if (i == dir.fcnt)
                printf("\n%s not found", f);
            else
                dir.fcnt--;
            break;
        case '3':
            printf("\nEnter the name of the file : ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("\n%s is found\n", f);
                    break;
                }
            }
            if (i == dir.fcnt)
                printf("\n%s not found", f);
            break;
        case '4':
            if (dir.fcnt == 0)
                printf("\n Directory Empty");
            else
            {
                printf("\nThe Files are\n");
                for (i = 0; i < dir.fcnt; i++)
                    printf("\t%s\n", dir.fname[i]);
            }
            break;
        case '5':
            exit(0);
        default:printf("\nEnter correct choice : ");
        }
    }
}