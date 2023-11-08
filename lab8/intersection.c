int main()
{
    node *start1 = NULL;
    node *start2 = NULL;

    int info;
    char ch;

    do
    {
        printf("Enter info for the first linked list: ");
        scanf("%d", &info);
        if (start1 == NULL)
        {
            start1 = newNode(info);
        }
        else
        {
            node *temp = start1;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode(info);
        }
        printf("Add another node to the first linked list (y/n)? ");
        fflush(stdin);
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    do
    {
        printf("Enter info for the second linked list: ");
        scanf("%d", &info);
        if (start2 == NULL)
        {
            start2 = newNode(info);
        }
        else
        {
            node *temp = start2;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode(info);
        }
        printf("Add another node to the second linked list (y/n)? ");
        fflush(stdin);
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    printf("\nFinding intersection point: ");
    node *intersection = find_intersection(start1, start2);
    if (intersection != NULL)
    {
        printf("%d\n", intersection->info);
    }
    else
    {
        printf("No intersection found.\n");
    }

    return 0;
}
