#include <stdio.h>
#include <stdlib.h>
typedef struct link_list
{   int value;
    link_list *next;
};

link_list* create (int value){
    link_list *ptr;
    
        ptr=(link_list*)malloc(sizeof(link_list));//先要空間
        ptr->value=value;
        ptr->next=NULL;//把next指到null
        return ptr;
}

void series (int value,link_list *last){
    link_list *ptr=create(value);//串起來之前先建一個link list
    last->next=ptr;//把前一個的pointer指到要串的link list
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

void print_list(link_list *head)
{
    link_list *ptr=head;
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d->",ptr->value);
    }
    printf("\n");
}

int getDecimalValue(link_list* head)
{   
    int n=0,sum=0;
    link_list* ptr=head;
    
    //先走過一遍看長度有多長，就代表這個數字二進位有幾位//
    while(ptr!=NULL)
    {
        n++;
        ptr=ptr->next;
    }
    
    ptr=head;
        
    //頭的地方為二進位的最高位，依次往下遞減//
    //用shift來做2的次方運算//
    while(ptr!=NULL)
    {
        sum+=ptr->value<<(n-1);
        n--;
        ptr=ptr->next;
    }
    
    return sum;
}

int main(void)
{
    link_list *head,*ptr;
    int value;
    head=create(1);
    insertion(1,head);
    series(0,head->next);

    value=getDecimalValue(head);

    printf("%d\n",value);

    system("pause");
    return 0;
}