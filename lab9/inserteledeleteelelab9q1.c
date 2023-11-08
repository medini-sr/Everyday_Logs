#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
    int info;
    struct dnode *next, *prev;
} dnode;

dnode *insertAtEnd(dnode *start) {
    dnode *temp = (dnode *)malloc(sizeof(dnode));
    printf("Enter element: ");
    scanf("%d", &temp->info);
    temp->next = temp->prev = NULL;
    if (start == NULL) {
        temp->next = temp->prev = temp;
        return temp;
    }
    dnode *t = start;
    while (t->next != start) {
        t = t->next;
    }
    t->next = temp;
    temp->prev = t;
    temp->next = start;
    start->prev = temp;
    return start;
}

dnode *deleteElement(dnode *start) {
    int ele;
    printf("Enter element to delete: ");
    scanf("%d", &ele);
    if (start == NULL) return NULL;
    dnode *t = start;
    if (t->info == ele) {
        if (t->next == t) {
            free(t);
            return NULL;
        }
        t->next->prev = t->prev;
        t->prev->next = t->next;
        start = t->next;
        free(t);
        return start;
    }
    while (t->next != start && t->info != ele) {
        t = t->next;
    }
    if (t->next == start && t->info != ele) {
        printf("Element not found.\n");
        return start;
    }
    if (t->info == ele) {
        t->prev->next = t->next;
        t->next->prev = t->prev;
        free(t);
        return start;
    }
}

dnode *traverse(dnode *start) {
    dnode *t = start;
    if (start == NULL) return NULL;
    printf("List: ");
    do {
        printf("%d ", t->info);
        t = t->next;
    } while (t != start);
    printf("\n");
    return start;
}

int main() {
    dnode *start = NULL;
    int choice;
    printf("1. Insert 2. Delete 3. Traverse 4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 4) {
            break;
        }
        switch (choice) {
            case 1:
                start = insertAtEnd(start);
                break;
            case 2:
                start = deleteElement(start);
                break;
            case 3:
                start = traverse(start);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
