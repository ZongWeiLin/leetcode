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

void deleteNode(link_list* node) 
{   
    
    //����temp��U�@�Ӹ`�I���Цs�_��//
    //��U�@�Ӹ`�I���ȡA�������{�b�`�I����//
    //�ñN�U�@�Ӳ{�b���`�I���V�U�U�Ӹ`�I//
    link_list *temp=node->next;
    node->value=node->next->value;
    node->next=node->next->next;
    free(temp);
}

int main(void)
{
    link_list *ptr,*first;
    int result;
    first=create(1);
    ptr=first;//�]��l��m��link_list�Ĥ@��
    series(2,ptr);
    series(3,ptr->next);
    series(4,ptr->next->next);

    for(ptr=first;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d->",ptr->value);
    }
    printf("\n");

    ptr=first->next->next;
    deleteNode(ptr);

    printf("After deletion\n");
    for(ptr=first;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d->",ptr->value);
    }
    printf("\n");

    system("pause");
    return 0;
}