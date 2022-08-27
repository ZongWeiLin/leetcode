#include <stdio.h>
#include <stdlib.h>

typedef struct link_list
{
      int value;
      link_list *next;
};


//�o�D����A�O�z�L�]�m�@�Ӥ���C�������СA�ӧ�X�Z������n�B���`�I//
//����A��X�o�Ӹ`�I���P�ɡA�ѩ�ڭ̭n�i��R���A�ҥH�]�����n���D�R���`�I���e�@�Ӹ`�I��m//
link_list* removeNthFromEnd(link_list* head, int n)
{
    link_list* del_ptr=NULL;
    link_list* del_ptr_pre=NULL;
    link_list* ptr=head;
    int count=0;

    if(ptr==NULL||ptr->next==NULL&&n>=1)return NULL;

    while (ptr!=NULL)
    {   
        if(count==n)del_ptr=head;

        if(count>=n)
        {
            del_ptr_pre=del_ptr;
            del_ptr=del_ptr->next;
        }

        count++;
        ptr=ptr->next;
    }

    if(count==n)del_ptr=head;

    if(del_ptr!=head)
        del_ptr_pre->next=del_ptr->next;
    if(del_ptr==head)
        head=del_ptr->next;
    
    free(del_ptr);
    
    return head;
}

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

int main(void)
{
    link_list *ptr,*first;
    int result;
    first=create(1);
    ptr=first;//�]��l��m��link_list�Ĥ@��
    // series(2,ptr);
    // series(3,ptr->next);
    // series(4,ptr->next->next);
    // series(5,ptr->next->next->next);

    link_list *rem_ptr=removeNthFromEnd(first,1);

    for(ptr=rem_ptr;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d->",ptr->value);
    }
    printf("\n");


    system("pause");
    return 0;
}