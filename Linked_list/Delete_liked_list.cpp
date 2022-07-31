#include <stdio.h>
#include <stdlib.h>
typedef struct link_list
{   int value;
    link_list *next;
};

link_list* create (int value){
    link_list *ptr;
    if(value!=NULL){
        ptr=(link_list*)malloc(sizeof(link_list));//先要空間
        ptr->value=value;
        ptr->next=NULL;//把next指到null
        return ptr;
    }
}

void series (int value,link_list *last){
    link_list *ptr=create(value);//串起來之前先建一個link list
    last->next=ptr;//把前一個的pointer指到要串的link list
}

void deleteNode(link_list* node) 
{   
    
    //先用temp把下一個節點指標存起來//
    //把下一個節點的值，替換成現在節點的值//
    //並將下一個現在的節點指向下下個節點//
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
    ptr=first;//設初始位置為link_list第一個
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