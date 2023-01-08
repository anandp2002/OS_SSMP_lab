#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n, rq[20], i, j, initial, thmt = 0, temp, size, move, index; // thmt=totalheadmovement
    printf("Enter the no of requests\n");
    scanf("%d", &n);
    printf("Enter the request sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &rq[i]);
    printf("Enter the initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction(0 or 1)\n1 for high and 0 for low\n");
    scanf("%d", &move);
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (rq[j] > rq[j + 1])
            {
                temp = rq[j];
                rq[j] = rq[j + 1];
                rq[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (initial < rq[i])
        {
            index = i;
            break;
        }
    }
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            thmt += abs(rq[i] - initial);
            initial = rq[i];
        }
        thmt += abs(size - rq[i - 1] - 1);
        thmt+=size-1;
        initial = 0;
        for (i = 0; i <index ; i++)
        {
            thmt += abs(rq[i] - initial);
            initial = rq[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            thmt += abs(rq[i] - initial);
            initial = rq[i];
        }
        thmt += abs(rq[i + 1] - 0);
        thmt+=size-1;
        initial =size-1;
        for (i = n-1; i >= index; i--)
        {
            thmt += abs(rq[i] - initial);
            initial = rq[i];
        }
    }
    printf("\nTotal head movement = %d\n", thmt);
}