#include <stdio.h>

int main()
{
    int b[10], p[10], nb, np, i, j, found;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for (i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for (i = 0; i < np; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < np; i++)
    {
        found = 0;

        for (j = 0; j < nb; j++)
        {
            if (b[j] >= p[i])
            {
                printf("P%d allocated to Block %d\n",
                       i + 1, j + 1);
                b[j] -= p[i];
                found = 1;
                break;
            }
        }

        if (!found)
            printf("P%d not allocated\n", i + 1);
    }

    return 0;
}