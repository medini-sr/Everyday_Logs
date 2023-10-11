#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define max 100
typedef struct{
    int top;
    int stack[max];
    //int minstack[max];
    int min;
    
}minstacK;
minstacK s;
void getmin(int ele) {
    if (s.top == -1 || ele < s.min) {
        s.min = ele;
    }
}
void push(int ele)

{
    scanf("%d",&ele);
    if(s.top==max-1)
    {
        printf("full stakc");
        return;
    }
    
    s.stack[++s.top]=ele;
    getmin(ele);
}
int pop()
{
    if(s.top==-1)
    {
        printf("empty stakc");
        return -1;
    }
    int popped = s.stack[s.top--];
    if (popped == s.min) {
        
        s.min = s.stack[0];
        for (int i = 1; i <= s.top; i++) {
            if (s.stack[i] < s.min) {
                s.min = s.stack[i];
            }
        }
    }
    return popped;
}

void display()
{
    if(s.top==-1)
    {
        printf("empty stakc");
        
    }
    else
    {
        for(int i=s.stack[s.top];i>=0;i--)
        {
            printf("%d ",s.stack[i]);
        }
    }
}
int main() {
    s.top = -1;
    s.min = max; // Initialize min to a large value
    int ele;
    char choice;
    
    do {
        int ch;
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Get Min\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                ele = pop();
                if (ele != -1) {
                    printf("Popped element: %d\n", ele);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                if (s.top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Minimum element: %d\n", s.min);
                }
                break;
            
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character
    } while (choice == 'y' || choice == 'Y');

    return 0;
}