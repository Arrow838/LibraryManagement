
/*
Author: Harshvardhan Gaggar
Language: C 
Time Spent: 1 hr
Version: 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lib 
{
    int n;
    char t[20];
    char a[20];
    int p;
    int f;
};

int compare(const void *x, const void * y)
{
    struct lib a = *(struct lib *) x;
    struct lib b = *(struct lib *) y;
    return a.n - b.n;
}


void add(struct lib rec[], int i)
{
    printf("Enter book info:\n");
    scanf("%d %s %s %d %d", &rec[i].n, rec[i].t, rec[i].a, &rec[i].p, &rec[i].f);
}

void display(struct lib rec[], int i)
{
    for(int j = 0; j < i; j++)
        printf("%d %s %s %d %d\n", rec[j].n, rec[j].t, rec[j].a, rec[j].p, rec[j].f);
}

void author(struct lib rec[], int i)
{
    char c[20];
    int k = 0;
    printf("Enter author name: ");
    scanf("%s", c);
    for(int j = 0; j < i; j++)
    {
        if(strcmp(rec[j].a, c) == 0)
        {
            printf("%d %s %s %d %d\n", rec[j].n, rec[j].t, rec[j].a, rec[j].p, rec[j].f);
            k++;
        }
    }
    if (k == 0)
        printf("No record found!\n");
}

void title(struct lib rec[], int i)
{
    int k = 0;
    char c[20];
    printf("Enter book title: ");
    scanf("%s", c);
    for(int j = 0; j < i; j++)
    {
        if(strcmp(rec[j].t, c) == 0)
        {
            printf("%d %s %s %d %d\n", rec[j].n, rec[j].t, rec[j].a, rec[j].p, rec[j].f);
            k++;
        }
    }   
    if (k == 0)
        printf("No record found!\n");
}

int main(void)
{
    int n, i = 0;
    struct lib rec[100];
    printf("***************************\n");
    printf("Welcome to Harsh's library!\n");
    printf("***************************\n");
    while(1)
    {
        printf("Enter:\n\t1. Add book information\n\t2. Display book information\n\t3. List all books of a given author\n\t4. List the title of a specific book\n\t5. List the count of books in the library\n\t6. List the books in the order of accession number\n\t7. Exit\n");
        printf("\nYour choise: ");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                add(rec, i);
                i++;
                break;
            case 2:
                if (i == 0)
                    printf("No information found!\n");
                display(rec, i);
                break;
            case 3:
                author(rec, i);
                break;
            case 4:
                title(rec, i);
                break;
            case 5:
                printf("Total Number of Books in Library: %d\n", i);
                break;
            case 6:
                qsort(rec, i, sizeof(struct lib), compare);
                display(rec, i);
                break;
            case 7:
                printf("Logging out of Library Management System!\n");
                return 0;
            default:
                printf("Invalid Input!\n");
        }
        printf("\n");
    }
}
