#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *rcl;
    struct node *lcl;
    int info;
} node;

node *create_bt(node *root) {
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the information belonging to the pointer: ");
    scanf("%d", &temp->info);
    temp->rcl = temp->lcl = NULL;

    char d[100]; // You need to declare the 'd' variable.
    
    if (root == NULL) { // Use '==' for comparison.
        root = temp;
    } else {
        printf("Enter the path of the binary tree to be created (e.g., LRL or RLL): ");
        scanf("%s", d); // Corrected variable name and format specifier.

        node *c = root;
        node *p = NULL;
        int i; // You need to declare 'i' outside the loop.
        
        for (i = 0; i < strlen(d); i++) {
            if (c == NULL) {
                break;
            }
            p = c;
            if (d[i] == 'L') {
                c = c->lcl;
            } else {
                c = c->rcl;
            }
        }
        
        if (c != NULL || i != strlen(d)) {
            printf("Impossible\n");
            free(temp);
            return root;
        }
        
        if (d[i - 1] == 'L') {
            p->lcl = temp;
        } else {
            p->rcl = temp;
        }
    }
    
    return root;
}

int main() {
    node *root = NULL;
    int choice;
    char ch;
    do {
        printf("1) Create binary tree\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                root = create_bt(root); // Assign the result of the function to 'root'.
                break;
            default:
                printf("Invalid case\n");
                break;
        }
        printf("Do you want to do it again? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    
    // Free the memory when you're done with the tree.
    // You may want to traverse the tree and free each node individually.
    
    return 0;
}
