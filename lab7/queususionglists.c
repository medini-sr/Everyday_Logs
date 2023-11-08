#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
} node;

node* enqueue(node* start)
{
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter the element you want to enqueue: ");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        node* t = start;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = temp;
    }

    return start;
}

node* dequeue(node* start)
{
    if (start == NULL) {
        printf("The list is empty\n");
        return start;
    }

    if (start->next == NULL) {
        free(start);
        return NULL;
    }

    node* t = start;
    start=start->next;
    free(t);
//while (t->next->next != NULL) {
      //  t = t->next;
  //  }
  //  free(t->next);
  //  t->next = NULL;

    return start;
}

void display(node* start)
{
    if (start == NULL) {
        printf("The list is empty\n");
        return;
    }

    node* t = start;
    while (t != NULL) {
        printf("%d ", t->info);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    node* start = NULL;
    char c;
    char dummy;

    do {
        int choice;
        printf("1) Enqueue\n2) Dequeue\n3) Display\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = enqueue(start);
                break;
            case 2:
                start = dequeue(start);
                break;
            case 3:
                display(start);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &c);
        scanf("%c", &dummy);
    } while (c == 'y');
}
