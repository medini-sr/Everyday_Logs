
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#define max 100
typedef struct{
    int f,r;
    int a[max];
}que;
que q;

void enq()
{
    int ele;
    printf("enter the element to be enqueued");
    scanf("%d",&ele);
    if(q.r==max-1)
    {
        printf("overflow");
        return;
    }
    q.r++;
    q.a[q.r]=ele;
}
void deq()
{
    if(q.r==q.f)
    {
        printf("underflow");
        return;
    }
    q.a[q.f++];
}
void display()
{
     if(q.r==q.f)
    {
        printf("underflow");
        return;
    }
    for(int i=q.f;i<=q.r;i++)
    {
        printf(" %d",q.a[i]);
    }
}


void fibo() {
    int t1 = 0;
    int t2 = 1;
    int newterm = 0;
    int n;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    if (n >= 1) {
        printf("%d", t1);
    }
    if (n >= 2) {
        printf(" %d", t2);
    }

    for (int i = 3; i <= n; i++) {
        newterm = t1 + t2;
        printf(" %d", newterm);
        t1 = t2;
        t2 = newterm;
    }

    printf("\n");
}

int main()
{
    q.r=-1;
    q.f=-1;
    int choice;
    char ch;
    do{
        printf("1)enqueue \n");
        printf("2)dequeue \n");
        printf("3)display \n");
        printf("4)fibo \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enq();
            break;
            case 2:
            deq();
            break;
            case 3:
            display();
            break;
            case 4:
            fibo();
            break;
            default:
            printf("invalid");
            break;
        }
        printf("do you want to continue? y/n");
        scanf(" %c",&ch);
    }while(ch=='y' || ch == 'Y');
}