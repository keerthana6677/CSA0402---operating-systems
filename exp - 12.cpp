#include <stdio.h>

int main()
{
    int i, j, n = 5;

    for (i = 0; i < n; i++)
        printf("Philosopher %d is thinking\n", i + 1);

    for (i = 0; i < n; i++)
    {
        printf("Philosopher %d picks up chopsticks\n", i + 1);
        printf("Philosopher %d is eating\n", i + 1);
        printf("Philosopher %d puts down chopsticks\n", i + 1);
    }

    return 0;
}