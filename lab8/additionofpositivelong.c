#include<stdio.h>
#include<stdlib.h>

typedef struct dnode{
    int info;
    struct dnode *next, *prev;
}dnode;

dnode * ins_end(dnode *start, int ele)
{
    dnode *temp=(dnode*)malloc(sizeof(dnode));
    //printf("Enter ele: ");
    //scanf("%d", &temp->info);
    temp->info=ele;
    temp->prev=temp->next=NULL;
    if(start==NULL) 
        return temp;
    dnode *t=start;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp;
    temp->prev=t;
    return start;
}

dnode * traverse(dnode *start)
{
    if(start==NULL){
        return NULL;
    }
    dnode *t=start;
    while(t!=NULL){
        printf("%d ", t->info);
        t=t->next;
    }
    return start;
}

dnode * addition(dnode *s3, dnode *s2, dnode *s1)
{
    dnode *t1, *t2, *t3;
    t1=s1; t2=s2; t3=s3;
    int ele, carry=0;
    while(t1!=NULL && t2!=NULL)
    {
        ele=(t1->info + t2->info+carry)%10;
        s3=ins_end(s3, ele);
        carry=((t1->info + t2->info)/10);
        t1=t1->next; t2=t2->next;
    }
    if(t1==NULL && t2==NULL && carry!=0){
        s3=ins_end(s3, carry);
        return s3;
    }
    if(t1==NULL)
    {   
        while(t2!=NULL){
            ele=(t2->info+carry)%10;
            s3=ins_end(s3, ele);
            carry=(t2->info+carry)/10;
            t2=t2->next;
        }
        if(carry!=0)
        s3=ins_end(s3, carry);
        return s3;
    }
    if(t2==NULL)
    {   
        while(t1!=NULL){
            ele=(t1->info+carry)%10;
            s3=ins_end(s3, ele);
            carry=(t1->info+carry)/10;
            t1=t1->next;
        }
        if(carry!=0)
        s3=ins_end(s3, carry);
        return s3;
    }
    return s3;

}

int main()
{
    long x,y;
    printf("Addition of two long positive numbers: ");
    printf("\nenter first no.: ");
    scanf("%ld", &x);
    printf("enter seconf no: ");
    scanf("%ld", &y);
    //printf("%ld %ld",x,y);

    dnode *s1=NULL;
    long a=x, rem;
    while(a>0){
        rem=a%10;
        s1=ins_end(s1, rem);
        a=a/10;
    }
    dnode *s2=NULL;
    a=y;
    while(a>0){
        rem=a%10;
        s2=ins_end(s2, rem);
        a=a/10;
    }

    //addition

    dnode *s3=NULL;
    s3=addition(s3,s2,s1);
    printf("%ld + %ld = ",x,y);

    dnode *t=s3;
    while(t->next!=NULL){
        t=t->next;
    }

    while(t!=NULL){
        //printf("here ");
        printf("%d", t->info);
        t=t->prev;
    }

    return 0;
}