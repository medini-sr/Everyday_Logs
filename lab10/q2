#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *lcl, *rcl;
} node;

node *create(node *root, int ele)
{
    if (root == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->info = ele;
        temp->lcl = temp->rcl = NULL;
        return temp;
    }
    fflush(stdin);
    char path;
    printf("Enter path (l for left, r for right): ");
    scanf(" %c", &path);
    if (path == 'l')
    {
        if (root->lcl == NULL)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->info = ele;
            temp->lcl = temp->rcl = NULL;
            root->lcl = temp;
            return root;
        }
        else
        {
            node *p = create(root->lcl, ele);
        }
    }
    else if (path == 'r')
    {
        if (root->rcl == NULL)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->info = ele;
            temp->lcl = temp->rcl = NULL;
            root->rcl = temp;
            return root;
        }
        else
        {
            node *p = create(root->rcl, ele);
        }
    }
    return root;
}

void display(node *root, int level)
{
    if (root == NULL)
        return;
    display(root->rcl, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->info);
    display(root->lcl, level + 1);
}

int main()
{
    node *root = NULL;
    char ch;
    int ele;
    do
    {
        fflush(stdin);
        printf("Enter element: ");
        scanf("%d", &ele);
        root = create(root, ele);
        fflush(stdin);
        printf("Do you want to add another element? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');
    printf("Root: %d", root->info);
    int level;
    printf("\nEnter the level for displaying the tree: ");
    scanf("%d", &level);
    display(root, level);

    return 0;
}
