#include <stdio.h>
#include <stdlib.h>

typedef struct link_list
{
      int value;
      link_list *next;
};


//這題思路，是透過設置一個比較慢走的指標，來找出距離尾端n步的節點//
//之後再找出這個節點的同時，由於我們要進行刪除，所以也必須要知道刪除節點的前一個節點位置//
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

int main(void)
{
    link_list *ptr,*first;
    int result;
    first=create(1);
    ptr=first;//設初始位置為link_list第一個
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