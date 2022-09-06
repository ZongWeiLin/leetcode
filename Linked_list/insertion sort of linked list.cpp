#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{   
    ListNode *next;
    int val;
};

ListNode* create_node(int val)
{
    ListNode *ptr=(ListNode*)malloc(sizeof(ListNode));
    ptr->val=val;
    ptr->next=NULL;
    return ptr;
}

void insert_List(int val,ListNode* head)
{
    ListNode* ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
     
    ptr->next=create_node(val);
}


ListNode* insertionSortList(ListNode* head)
{
    ListNode  *ptr,*ptr2;
     ListNode  *pre_1,*pre_2;
    
    ptr=head->next;
    ptr2=head;
    pre_1=head;pre_2=NULL;
    while(ptr)
    {
        while(ptr2->val<ptr->val)
        {
            pre_2=ptr2;
            ptr2=ptr2->next;
        }
        
        //插入的點在頭
        if(pre_2==NULL)
        {
            pre_1->next=ptr->next;
            ptr->next=ptr2;
            head=ptr;
            ptr=pre_1;
        }
        //不用插入
        else if(ptr2==ptr)
        {
            
        }
        //插入的點在中間
        else
        {
            pre_1->next=ptr->next;
            ptr->next=ptr2;
            pre_2->next=ptr;
            ptr=pre_1;
        }
        pre_2=NULL;
        ptr2=head;
        pre_1=ptr;
        ptr=ptr->next;
    }
    
    return head;
}


int main(void)
{
    ListNode *root=create_node(-1);
    insert_List(5,root);
    insert_List(3,root);
    insert_List(4,root);
    insert_List(0,root);

    ListNode *ptr;
    for(ptr=root;ptr!=NULL;ptr=ptr->next)
        printf("%d->",ptr->val);
    printf("\n");

    ListNode *head=insertionSortList(root);
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
        printf("%d->",ptr->val);

    printf("\n");
    system("pause");
    return 0;
}