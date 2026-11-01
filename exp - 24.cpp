#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    ssize_t n;

    fd = open("sample.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, "Hello UNIX", 10);
    close(fd);

    fd = open("sample.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    n = read(fd, buffer, sizeof(buffer) - 1);

    if (n >= 0)
    {
        buffer[n] = '\0';
        printf("File content: %s\n", buffer);
    }
    else
        perror("read");

    close(fd);
    return 0;
}