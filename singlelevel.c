#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    int opt, num = 0, flag = 0, len;
    char files[10][100], name[100];
    printf("1. Create File , 2. Search File , 3. Quit \n");
    printf("Input option : ");
    scanf("%d", &opt);
    while (opt != 3)
    {
        flag = 0;
        if (opt == 1)
        {
            printf(" Input file name : ");
            scanf(" %[^\ n]", name);

            for (int i = 0; i < num; i++)
            {
                if (strcmp(files[i], name) == 0)
                {
                    printf(" File ’%s’ already present !!\ n", name);
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                strcpy(files[num], name);
                num++;
                printf(" File ’%s’ CREATED !!\ n", name);
            }
        }
        else if (opt == 2)
        {
            printf(" Input file name :");
            scanf(" %[^\ n]", name);
            for (int i = 0; i < num; i++)
            {
                if (strcmp(files[i], name) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                printf("File ’%s’ present in directory !\n", name);
            }
            else
            {
                printf(" File ’%s’ not present in directory !\n", name);
            }
        }
        else if (opt == 3)
        {
            break;
        }
        printf(" Input option : ");
        scanf("%d", &opt);
    }
}