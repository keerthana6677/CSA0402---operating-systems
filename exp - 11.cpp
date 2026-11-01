#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    int i;
    for (i = 1; i <= 5; i++)
        printf("Thread %d\n", i);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, display, NULL);
    pthread_create(&t2, NULL, display, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread completed\n");
    return 0;
}