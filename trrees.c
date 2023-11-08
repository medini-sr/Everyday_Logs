#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef struct node{
int info;
struct node *rcl;
struct node *lcl;
}node;
char d[100];
node*createtree(node*root)
{
    node*temp=(node*)malloc(sizeof(node));
    printf("enter the temp info");
    scanf("%d",temp->info);
    temp->rcl=temp->lcl=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else{

        printf("enter the path");
        scanf("%s",d);
         getchar();
        node*c=root;
        node*p=NULL;
        int i;
        for(i=0;i<strlen(d);i++)
        {

            if(c==NULL)
            {
                break;
            }
            p=c;
            if(d[i]=='L')
               {
                   c=c->lcl;
               }
            else
            c=c->rcl;
        }
        if(c!=NULL || i!=strlen(d))
        {
            printf("invalid");
            free(temp);
            return root;
        }
        if(d[i-1]=='L')
        {
            p->lcl=temp;
        }
        else
            p->rcl=temp;
        return root;
        }

}

typedef struct stack{
int top;
struct  node*a[max];
}stack;
stack s;
void push(node*root)
{
    s.a[++s.top]=root;
}
node* pop()
{
    if(s.top==-1)
    {
        return NULL;
    }

        return s.a[s.top--];
}

void inorder(node*root)
{
    for(;;)
    {
        for(;root;root=root->lcl)
        {
          push(root);
        }
        root=pop();
        if(!root)
        {
            break;
        }
        printf("%d",root->info);
        root=root->rcl;

    }
}
void preorder(node* root) {
    for (;;) {
        for (; root; root = root->lcl) {
            printf("%d ", root->info);
            push(root);
        }
        root = pop();
        if (!root) {
            break;
        }
        root = root->rcl;
    }
}

void display(node* root, int level) {
    if (root) {
        display(root->rcl, level + 1);
        for (int i = 0; i < level; i++) {
            printf("\t");
        }
        printf("%d\n", root->info);
        display(root->lcl, level + 1);
    }
}

int main()
{
    node*root=NULL;
    char c;
    do{
        int choice;
        printf("your choice of number will accomplish the following tasks \n0)Create a Tree \n1)Inorder Traversal \n2)Pretorder Traversal \n3)Postorder Traversal \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            root=createtree(root);
            break;
            case 1: inorder(root);
            display(root,0);
            break;
            case 2: preorder(root);
            display(root,0);
            break;
            default:
                printf("invalid.Please try again");
                break;
        }
        printf("do you want to continue? y/n");
        scanf(" %c",&c);

    }while(c=='y');
}
