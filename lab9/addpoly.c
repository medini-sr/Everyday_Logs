#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff, exp;
    struct node *next;
} node;

node *attach(int c, int e, node *p) {
    node *temp = (node *)malloc(sizeof(node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    if (p == NULL) {
        p = temp;
        return p;
    }
    node *curr = p;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    return p;
}

node *read(node *p) {
    while (1) {
        int c, e;
        printf("Enter another coefficient (or -999 to finish): ");
        scanf("%d", &c);
        if (c == -999) {
            break;
        }
        printf("Enter exponent: ");
        scanf("%d", &e);
        p = attach(c, e, p);
    }
    return p;
}

node *addPoly(node *a, node *b) {
    int c, coeff, exp;
    node *result = NULL;
    while (a != NULL && b != NULL) {
        if (a->exp > b->exp) {
            c = 1;
        } else if (a->exp == b->exp) {
            c = 0;
        } else {
            c = -1;
        }
        switch (c) {
            case 0:
                coeff = a->coeff + b->coeff;
                if (coeff != 0) {
                    result = attach(coeff, a->exp, result);
                }
                a = a->next;
                b = b->next;
                break;
            case 1:
                result = attach(a->coeff, a->exp, result);
                a = a->next;
                break;
            case -1:
                result = attach(b->coeff, b->exp, result);
                b = b->next;
                break;
        }
    }
    while (a != NULL) {
        result = attach(a->coeff, a->exp, result);
        a = a->next;
    }
    while (b != NULL) {
        result = attach(b->coeff, b->exp, result);
        b = b->next;
    }
    return result;
}

void display(node *p) {
    node *t = p;
    while (t->next != NULL) {
        printf("(%d)x^%d + ", t->coeff, t->exp);
        t = t->next;
    }
    printf("(%d)x^%d\n", t->coeff, t->exp);
}

int main() {
    node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    poly1 = read(poly1);
    poly2 = read(poly2);
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    poly3 = addPoly(poly1, poly2);
    printf("Resulting Polynomial: ");
    display(poly3);
    return 0;
}
