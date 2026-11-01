#include <stdio.h>
#include <string.h>

int main()
{
    char users[10][20], files[10][10][20];
    int count[10] = {0};
    int nu = 0, i, u, choice, found;
    char user[20], file[20];

    while (1)
    {
        printf("\n1.Create 2.Display 3.Exit\n");
        scanf("%d", &choice);

        if (choice == 3)
            break;

        printf("Enter user name: ");
        scanf("%19s", user);
        u = -1;

        for (i = 0; i < nu; i++)
            if (strcmp(users[i], user) == 0)
                u = i;

        if (u == -1 && choice == 1 && nu < 10)
        {
            u = nu++;
            strcpy(users[u], user);
        }

        if (u == -1)
        {
            printf("User directory not found\n");
            continue;
        }

        if (choice == 1)
        {
            printf("Enter file name: ");
            scanf("%19s", file);
            found = 0;

            for (i = 0; i < count[u]; i++)
                if (strcmp(files[u][i], file) == 0)
                    found = 1;

            if (found)
                printf("File already exists\n");
            else if (count[u] < 10)
            {
                strcpy(files[u][count[u]++], file);
                printf("File created\n");
            }
            else
                printf("Directory full\n");
        }
        else if (choice == 2)
        {
            printf("Files of %s:\n", users[u]);
            for (i = 0; i < count[u]; i++)
                printf("%s\n", files[u][i]);
        }
    }

    return 0;
}