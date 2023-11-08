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

dnode * union_of_dll(dnode *s3, dnode *s2, dnode *s1)
{
    dnode *t1=s1, *t2=s2, *t3=s3;
    while(t1!=NULL){
        s3=ins_end(s3, t1->info);
        t1=t1->next;
    }
    while(t2!=NULL){
        t1=s1;
        while(t1!=NULL){
            if(t1->info==t2->info)
                break;
            t1=t1->next;
        }
        if(t1==NULL){
            s3=ins_end(s3, t2->info);
        }
        t2=t2->next;
    }
    return s3;
    
}

dnode * intersection_of_dll(dnode *s4, dnode *s2, dnode *s1)
{
    dnode *t1=s1, *t2=s2, *t4=s4;

    while(t1!=NULL){
        t2=s2;
        while(t2!=NULL){
            if(t2->info==t1->info)
                break;
            t2=t2->next;
        }
        if(t2!=NULL){
            s4=ins_end(s4, t1->info);
        }
        t1=t1->next;
    }
   

    return s4;
    
}

int main()
{
    dnode *s1=NULL, *s2=NULL;
    char ch; int ele;
    printf("Create dll1: \n");
    do{
        printf("Enter ele: ");
        scanf("%d", &ele);
        s1=ins_end(s1,ele);
        printf("add another? ");
        scanf("%s", &ch);
    }while(ch=='y');

    printf("Create dll2: \n");
    do{
        printf("Enter ele: ");
        scanf("%d", &ele);
        s2=ins_end(s2,ele);
        printf("add another? ");
        scanf("%s", &ch);
    }while(ch=='y');

    printf("\ndll1: ");
    s1=traverse(s1);
    printf("\ndll2: ");
    s2=traverse(s2);
    
    //union

    dnode *s3=NULL;
    s3=union_of_dll(s3, s2,s1);
    printf("\nUnion: ");
    s3=traverse(s3);

    //intersection

    dnode *s4=NULL;
    s4=intersection_of_dll(s4, s2,s1);
    printf("\nIntersection: ");
    s4=traverse(s4);


    return 0;
    
}