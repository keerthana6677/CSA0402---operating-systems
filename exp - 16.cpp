#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee e;
    int n, i, pos;

    fp = fopen("employee.dat", "wb+");
    if (fp == NULL)
    {
        printf("File error\n");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter ID, name and salary: ");
        scanf("%d %29s %f", &e.id, e.name, &e.salary);
        fwrite(&e, sizeof(e), 1, fp);
    }

    printf("Enter employee position to search (1-%d): ", n);
    scanf("%d", &pos);

    if (pos >= 1 && pos <= n)
    {
        fseek(fp, (long)(pos - 1) * sizeof(e), SEEK_SET);
        if (fread(&e, sizeof(e), 1, fp) == 1)
            printf("ID: %d\nName: %s\nSalary: %.2f\n",
                   e.id, e.name, e.salary);
    }
    else
        printf("Invalid position\n");

    fclose(fp);
    return 0;
}