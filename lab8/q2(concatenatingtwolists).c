#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

void display(node *start)
{
    if (start == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", start->info);
        display(start->next);
    }
}

void concatenate(node *a, node *b)
{
    if (a != NULL && b != NULL)
    {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next, b);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
}

int main()
{
    node *prev, *a, *b, *p;
    int n, i;
    printf("Number of elements in a: ");
    scanf("%d", &n);
    a = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(node));
        scanf("%d", &p->info);
        p->next = NULL;
        if (a == NULL)
            a = p;
        else
            prev->next = p;
        prev = p;
    }
    printf("Number of elements in b: ");
    scanf("%d", &n);
    b = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(node));
        scanf("%d", &p->info);
        p->next = NULL;
        if (b == NULL)
            b = p;
        else
            prev->next = p;
        prev = p;
    }
    concatenate(a, b);
    return 0;
}
