#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node*next;
}node;
//implementing stacks from sll
//push is nothing but insert in the beginning
node*push(node*start)
{
    node*temp=(node*)malloc(sizeof(node));
    printf("Enter the element you want to push into the stack");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}
//pop is nothing but delete from beginning
node*pop(node*start)
{
    if(start==NULL)
    {
        printf("nothing to delete here.Empty list");
        return start;
    }
    node*t=start;
    start=start->next;
    free(t);
    return start;
}
void display(node*start)
{
    if(start==NULL)
    {
        printf("nothing to delete here.Empty list");
    }
    node*t=start;
    while(t!=NULL)
    {
        printf(" %d",t->info);
        t=t->next;
    }

}
int main()
{
    node*start=NULL;
    char c;
    char dummy;
    do{
        int choice;
        printf("1)Push \n2)Pop \n3)Display \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: start=push(start);break;
            case 2: start=pop(start); break;
            case 3: display(start); break;
            default: printf("invalid\n");break;
        }
        printf("do you want to continue?y/n");
        scanf("%c",&dummy);
        scanf("%c",&c);
    }while(c=='y');
}
