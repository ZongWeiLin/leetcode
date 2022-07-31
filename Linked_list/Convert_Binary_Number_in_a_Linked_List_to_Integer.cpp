#include <stdio.h>
#include <stdlib.h>
typedef struct link_list
{   int value;
    link_list *next;
};

link_list* create (int value){
    link_list *ptr;
    
        ptr=(link_list*)malloc(sizeof(link_list));//���n�Ŷ�
        ptr->value=value;
        ptr->next=NULL;//��next����null
        return ptr;
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
    
    //�����L�@�M�ݪ��צ��h���A�N�N��o�ӼƦr�G�i�즳�X��//
    while(ptr!=NULL)
    {
        n++;
        ptr=ptr->next;
    }
    
    ptr=head;
        
    //�Y���a�謰�G�i�쪺�̰���A�̦����U����//
    //��shift�Ӱ�2������B��//
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