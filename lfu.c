#include <stdio.h>
void print(int frameno, int frame[])
{
    int j;
    for (j = 0; j < frameno; j++)
        printf("%d\t", frame[j]);
    printf("\n");
}
void main()
{
    int i, j, k, n, page[50], frameno, frame[10], move = 0, flag, count = 0, count1[10] = {0}, pos = 0;
    printf("Enter the number of pages\n");
    scanf("%d", &n);
    printf("Enter the page reference numbers\n");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);
    printf("Enter the number of frames\n");
    scanf("%d", &frameno);
    for (i = 0; i < frameno; i++)
        frame[i] = -1;
    printf("Page reference string\tFrames\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t\t", page[i]);
        flag = 0;
        for (j = 0; j < frameno; j++)
        {
            if (page[i] == frame[j])
            {
                flag = 1;
                count1[j]++;
                printf("No replacement\n");
                break;
            }
        }
        if (flag == 0 && count < frameno)
        {
            frame[move] = page[i];
            count1[move] = 1;
            move = (move + 1) % frameno;
            count++;
            print(frameno, frame);
        }
        else if (flag == 0)
        {
            for (j = 0; j < frameno - 1; j++)
            {
                for (int k = 0; k < frameno - j - 1; k++)
                {
                    if (count1[j] > count1[j + 1])
                    {
                        int temp = count1[j];
                        count1[j] = count1[j + 1];
                        count1[j + 1] = temp;

                        temp = page[j];
                        page[j] = page[j + 1];
                        page[j + 1] = temp;
                    }
                    pos = j;
                }
            }

            frame[pos] = page[i];
            count1[pos] += 1;
            count++;
            print(frameno, frame);
        }
    }
    printf("Number of page faults is %d\n", count);
}