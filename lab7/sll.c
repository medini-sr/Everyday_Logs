#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node* insertAtBeginning(struct Node *start) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter info: ");
    scanf("%d", &newNode->info);
    newNode->next = start;
    start = newNode;
    return start;
}

struct Node* insertAtEnd(struct Node *start) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter info: ");
    scanf("%d", &newNode->info);
    newNode->next = NULL;
    if (start == NULL) {
        start = newNode;
        return start;
    } else {
        struct Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return start;
    }
}

struct Node* insertAtPosition(struct Node* start) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    int position;
    printf("Enter position: ");
    scanf("%d", &position);
    if (start == NULL) {
        printf("List is empty.");
        return NULL;
    }
    if (position == 0) {
        printf("Invalid position.");
        return start;
    }
    if (position == 1) {
        struct Node *element = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element: ");
        scanf("%d", &element->info);
        element->next = start;
        start = element;
        return start;
    }

    newNode = start;
    int t = 1;

    while (newNode->next != NULL && t < position - 1) {
        newNode = newNode->next;
        t++;
    }

    if (newNode->next == NULL && t != position) {
        printf("Position not available.");
        return start;
    } else {
        struct Node *element = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element: ");
        scanf("%d", &element->info);
        element->next = newNode->next;
        newNode->next = element;
        return start;
    }
    return start;
}

void traverse(struct Node *start) {
    struct Node *temp = start;
    if (start != NULL) {
        do {
            printf("%d ", temp->info);
            temp = temp->next;
        } while (temp->next != NULL);
        printf("%d ", temp->info);
    }
    printf("Underflow");
}

struct Node* insertAfter(struct Node *start) {
    struct Node *current = start;
    int element;
    printf("Enter element: ");
    scanf("%d", &element);
    if (start == NULL) {
        printf("List is empty.");
        return NULL;
    }
    while (current != NULL && current->info != element) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found.");
        return start;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter element to insert: ");
    scanf("%d", &newNode->info);
    newNode->next = NULL;
    newNode->next = current->next;
    current->next = newNode;
    return start;
}

struct Node* insertBefore(struct Node *start) {
    struct Node *current = start;
    int element;
    printf("Enter element: ");
    scanf("%d", &element);
    if (start == NULL) {
        printf("List is empty.");
        return start;
    }
    if (current->info == element) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element to insert: ");
        scanf("%d", &newNode->info);
        newNode->next = NULL;
        newNode->next = current;
        start = newNode;
        return start;
    }
    while (current->next != NULL && current->next->info != element) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Element not found.");
        return start;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter element to insert: ");
    scanf("%d", &newNode->info);
    newNode->next = NULL;
    newNode->next = current->next;
    current->next = newNode;
    return start;
}

struct Node* deleteElement(struct Node *start) {
    struct Node *current, *previous;
    current = start;
    previous = NULL;
    int element;
    printf("Enter element: ");
    scanf("%d", &element);
    if (start == NULL) {
        printf("List is empty.");
        return NULL;
    }
    while (current != NULL && current->info != element) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found.");
        return start;
    }
    if (previous == NULL) {
        start = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return start;
}

struct Node* reverseList(struct Node *start) {
    struct Node *p, *q, *r;
    q = r = NULL;
    p = start;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

struct Node* sortList(struct Node *start) {
    struct Node *current = start;
    int i = 0;
    while (current != NULL) {
        i++;
        current = current->next;
    }
    while (i >= 0) {
        struct Node *p, *q, *r;
        r = NULL;
        q = NULL;
        p = start;
        while (p->next != NULL) {
            r = q;
            q = p;
            p = p->next;
            if (q->info > p->info && r == NULL) {
                q->next = p->next;
                p->next = q;
                q = p;
                p = p->next;
                start = q;
            } else if (q->info > p->info && r != NULL) {
                r->next = p;
                q->next = p->next;
                p->next = q;
                q = p;
                p = p->next;
            }
        }
        i--;
    }
    return start;
}

struct Node* deleteAlternate(struct Node *start) {
    struct Node *temp = start;
    struct Node *t;
    while (temp != NULL && temp->next != NULL) {
        t = temp->next;
        temp->next = t->next;
        free(t);
        temp = temp->next;
    }
    return start;
}

struct Node* insertInSortedOrder(struct Node *start) {
    struct Node *t;
    t = start;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter info: ");
    scanf("%d", &newNode->info);
    if (start == NULL) {
        return newNode;
    }
    if (t->info > newNode->info) {
        newNode->next = t;
        return newNode;
    }
    while (t->next != NULL && t->next->info < newNode->info) {
        t = t->next;
    }
    if (t->next == NULL) {
        t->next = newNode;
        return start;
    }
    newNode->next = t->next;
    t->next = newNode;
    return start;
}

struct Node* recursive(struct Node *start, struct Node *newNode) {
    if (start == NULL)
        return newNode;
    else
        start->next = recursive(start->next, newNode);
    return start;
}

void recTraverse(struct Node* start) {
    if (start == NULL)
        return;

    printf("%d ", start->info);

    recTraverse(start->next);
}

int main() {
    struct Node *start = NULL;

    int option;
    printf("1. Insert at the beginning 2. Insert at the end 3. Insert at position");
    printf("  4. Traverse 5. Insert after 6. Insert before 7. Delete 8. Reverse 9. Sort");
    printf(" 10. Delete alternate element 11. Insert into sorted order 12. Recursive create 13. Recursive traverse 14. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        if (option == 14)
            break;
        switch (option) {
            case 1:
                start = insertAtBeginning(start);
                break;
            case 2:
                start = insertAtEnd(start);
                break;
            case 3:
                start = insertAtPosition(start);
                break;
            case 4:
                traverse(start);
                break;
            case 5:
                start = insertAfter(start);
                break;
            case 6:
                start = insertBefore(start);
                break;
            case 7:
                start = deleteElement(start);
                break;
            case 8:
                start = reverseList(start);
                break;
            case 9:
                start = sortList(start);
                break;
            case 10:
                start = deleteAlternate(start);
                break;
            case 12: {
                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                printf("Enter info: ");
                scanf("%d", &newNode->info);
                newNode->next = NULL;
                start = recursive(start, newNode);
                break;
            }
            case 11:
                start = insertInSortedOrder(start);
                break;
            case 13:
                recTraverse(start);
                break;
            default:
                break;
        }
    }

    return 0;
}
