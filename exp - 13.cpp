#include <stdio.h>

int main()
{
    int b[10], p[10], i, j, nb, np, choice;
    int alloc[10], used[10], best;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for (i = 0; i < nb; i++)
    {
        scanf("%d", &b[i]);
        used[i] = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for (i = 0; i < np; i++)
        scanf("%d", &p[i]);

    printf("1.First Fit  2.Best Fit  3.Worst Fit\n");
    scanf("%d", &choice);

    for (i = 0; i < np; i++)
    {
        alloc[i] = -1;
        best = -1;

        for (j = 0; j < nb; j++)
        {
            if (!used[j] && b[j] >= p[i])
            {
                if (choice == 1)
                {
                    best = j;
                    break;
                }
                else if (choice == 2 &&
                         (best == -1 || b[j] < b[best]))
                    best = j;
                else if (choice == 3 &&
                         (best == -1 || b[j] > b[best]))
                    best = j;
            }
        }

        if (best != -1)
        {
            alloc[i] = best;
            used[best] = 1;
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < np; i++)
    {
        printf("P%d\t%d\t", i + 1, p[i]);
        if (alloc[i] == -1)
            printf("Not allocated\n");
        else
            printf("%d\n", alloc[i] + 1);
    }

    return 0;
}