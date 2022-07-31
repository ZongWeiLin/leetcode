#include <stdio.h>
#include <stdlib.h>

typedef struct link_list
{   int value;
    link_list *next;
};

link_list* create (int value){
    link_list *ptr;
    if(value!=NULL){
        ptr=(link_list*)malloc(sizeof(link_list));//���n�Ŷ�
        ptr->value=value;
        ptr->next=NULL;//��next����null
        return ptr;
    }
}

void series (int value,link_list *last){
    link_list *ptr=create(value);//��_�Ӥ��e���ؤ@��link list
    last->next=ptr;//��e�@�Ӫ�pointer����n�ꪺlink list
}

void insertion(int value,link_list *head)
{
    link_list *ptr=head;
    link_list *new_node=create(value);
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }

    ptr->next=new_node;
}

link_list* middleNode(link_list* head)
{
    if(head==NULL||head->next==NULL)
        return head;
    
    //�ΧֺC���Шӧ䤤���I//
    link_list *mid=head;
    link_list *fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        mid=mid->next;
        fast=fast->next->next;
    }
    
    return mid;
    
}


int main(void)
{
    link_list *first,*ptr,*mid;
    first=create(1);
    ptr=first;
    insertion(2,ptr);
    insertion(3,ptr);

    for(ptr=first;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d->",ptr->value);
    }

    mid=middleNode(first);

    printf("\n");
    
    for(ptr=mid;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d->",ptr->value);
    }

    printf("\n");

    system("pause");
    return 0;
}