#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node*next;
};

struct node* ins_beg(struct node *start)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter ele: ");
    scanf("%d", &temp->info);
    temp->next=start;
    start=temp;
    return start;
}

struct node* ins_end(struct node *start)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    int ele;
    printf("Enter ele: ");
    scanf("%d", &temp->info);
    temp->next=NULL;
    if(start==NULL){
        start=temp;
        return start;
    }
    else
    {
        struct node *t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
        return start;
    }
}

struct node* ins_atpos(struct node* start)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(start==NULL){
        printf("list is empty");
        return NULL;
    }
    if(pos==0){
        printf("invalid position");
        return start;
    }
    if(pos==1){
        struct node*ele=(struct node*)malloc(sizeof(struct node));
        printf("Enter element: ");
        scanf("%d", &ele->info);
        ele->next=start;
        start=ele;
        return start;
    }

    temp=start;
    int t=1;

    while(temp->next!=NULL && t<pos-1)
    {
        temp=temp->next;
        t++;
    }

    if(temp->next==NULL && t!=pos)
    {
        printf("Position not available.");
        return start;
    }
    else{
        struct node*ele=(struct node*)malloc(sizeof(struct node));
        printf("Enter element: ");
        scanf("%d", &ele->info);
        ele->next=temp->next;
        temp->next=ele;
        return start;
    }
    return start;
}

struct node* traverse(struct node *start)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp=start;
    if(start!=NULL){
        do{
            printf("%d ", temp->info);
            temp=temp->next;
        }while(temp->next!=NULL);
        printf("%d ", temp->info);
        return start;
    }
    printf("Underflow");
    return start;

}

struct node* ins_after(struct node *start)
{
    struct node *cur=start;
    int ele;
    printf("Enter element: ");
    scanf("%d", &ele);
    if(start==NULL){
        printf("List is empty.");
        return NULL;
    }
    while(cur!=NULL && cur->info!=ele){
        cur=cur->next;
    }
    if(cur==NULL){
        printf("Element not found.");
        return start;
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to insert: ");
    scanf("%d", &temp->info);
    temp->next=NULL;
    temp->next=cur->next;
    cur->next=temp;
    return start;
}

struct node* ins_before(struct node *start)
{
    struct node *cur=start;
    int ele;
    printf("Enter element: ");
    scanf("%d", &ele);
    if(start==NULL){
        printf("List is empty.");
        return start;
    }
    if(cur->info==ele){
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter element to insert: ");
        scanf("%d", &temp->info);
        temp->next=NULL;
        temp->next=cur;
        start=temp;
        return start;
    }
    while(cur->next!=NULL && cur->next->info!=ele){
        cur=cur->next;
    }
    if(cur->next==NULL){
        printf("Element not found.");
        return start;
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to insert: ");
    scanf("%d", &temp->info);
    temp->next=NULL;
    temp->next=cur->next;
    cur->next=temp;
    return start;
}

struct node* del(struct node *start)
{
    struct node *curr, *prev;
    curr=start; prev=NULL;
    int ele;
    printf("Enter element: ");
    scanf("%d", &ele);
    if(start==NULL){
        printf("List is empty.");
        return NULL;
    }

    while(curr!=NULL && curr->info!=ele){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        printf("Element not found.");
        return start;
    }
    prev->next=curr->next;
    free(curr);
    return start;
}

struct node* reverse(struct node *start)
{
    struct node *p, *q, *r;
    q=r=NULL;
    p=start;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;
}

struct node* sort(struct node *start)
{

    struct node *c=start;
    int i=0;
    while(c!=NULL){
        i++;
        c=c->next;
    }
    while(i>=0){

        struct node *p, *q, *r;
        r=NULL; q=NULL;
        p=start;
        while(p->next!=NULL){

            r=q;
            q=p;
            p=p->next;
            if(q->info > p->info && r==NULL){

                q->next=p->next;
                p->next=q;
                q=p;
                p=p->next;
                start=q;
            }
            else if(q->info>p->info && r!=NULL){
                r->next=p;
                q->next=p->next;
                p->next=q;
                q=p;
                p=p->next;
            }

        }
        i--;

    }
    return start;
}

struct node* del_alt(struct node *start)
{
    struct node *temp=start;
    struct node *t;
    while(temp!=NULL &&  temp->next!=NULL){
        t=temp->next;
        temp->next=t->next;
        free(t);
        temp=temp->next;
    }return start;
}

struct node* ins_sort(struct node *start)
{
    struct node *t;
    t=start;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter ele:");
    scanf("%d", &temp->info);
    if(start==NULL){ return temp;}
    if(t->info > temp->info){
        temp->next=t;
        return temp;
    }
    while(t->next!=NULL && t->next->info < temp->info){
            t=t->next;
    }
    if(t->next==NULL){
        t->next=temp;
        return start;
    }
    temp->next=t->next;
    t->next=temp;
    return start;
}

struct node* recursive(struct node *start, struct node *temp){
    if (start == NULL)
         return temp;
    else
        start->next = recursive(start->next, temp);
    return start;
}

void rec_traverse(struct node* head)
{
    if (head == NULL)
       return;

    printf("%d ", head->info);

    rec_traverse(head->next);
}

int main()
{
    struct node *start=NULL;

    int op;
    printf("1.Insert at the beginning\n 2.Insert at the end \n3.insert at position\n 4.Traverse\n 5.insert after \n 6.insert before \n 7.delete 8.reverse \n 9.sort \n10.delete alternate element 11.ins to sorted 12.recursive create 13.recursive travesre 14.exit");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &op);
        if(op==14)
            break;
        switch(op)
        {
            case 1: start=ins_beg(start);
                    break;
            case 2: start=ins_end(start);
                    break;
            case 3: start=ins_atpos(start);
                    break;
            case 4: start=traverse(start);
                    break;
            case 5: start=ins_after(start);
                    break;
            case 6: start=ins_before(start);
                    break;
            case 7: start=del(start);
                    break;
            case 8: start=reverse(start);
                    break;
            case 9: start=sort(start);
                    break;
            case 10: start=del_alt(start);
                    break;
            case 12:
                    {
                        struct node *temp=(struct node *)malloc(sizeof(struct node));
                        printf("Enter ele:");
                        scanf("%d", &temp->info);
                        temp->next=NULL;
                        start=recursive(start, temp);
                        break;
                    }
            case 11: start=ins_sort(start);
                    break;
            case 13: rec_traverse(start);
            default: break;
        }

    }

    return 0;

}
