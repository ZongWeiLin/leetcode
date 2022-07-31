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

//method1:找中間點把後半段Linked list反轉與前半段比較//
// bool isPalindrome(link_list* head)
// {
    
//     if(head==NULL||head->next==NULL)
//         return true;
    
//     //設置快慢指標找中間點//
//     link_list* slow=head;
//     link_list* fast=head;
//     link_list* mid;
    
//     while(fast!=NULL&&fast->next!=NULL)
//     {
//         mid=slow;//最後跳出時slow剛好會在中間的地方
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     mid->next=NULL;//依中間點將前後做分割
    
//     //反轉List//
//     link_list* previous=NULL;
    
//     fast=slow;
    
//     while(slow!=NULL)
//     {
//         fast=slow->next;//存下一個節點
//         slow->next=previous;//把當前節點指向前一個節點
//         previous=slow;//往後推進，使前一個節點為當前節點
//         slow=fast;//使當前節點為下一個節點
//     }
    
//     fast=head;
    
//     while(fast!=NULL)
//     {
//         if(fast->value!=previous->value)
//             return false;
//         else
//         {
//             fast=fast->next;
//             previous=previous->next;
//         }
//     }
    
//     return true;
// }
//method 2
bool isPalindrome(link_list* head)
{
    
    // if(head==NULL||head->next==NULL)
    //     return true;
    
    link_list* ptr=head;
    int n=0,i=0,j;

    //算linked list有幾個點//
    while (ptr!=NULL)
    {
        n++;
        ptr=ptr->next;
    }

    int arr[n];
    ptr=head;

    //把linked list資料存到陣列//
    while (ptr!=NULL)
    {
        arr[i++]=ptr->value;
        ptr=ptr->next;
    }
    
    //陣列開始頭尾進行比較//
    i=0;j=n-1;
    while(i<j)
    {
        if (arr[i]!=arr[j])
            return false;
        i++;j--;
    }
    
   return true; 
}

int main(void)
{   link_list *ptr,*first;
    int result;
    first=create(1);
    ptr=first;//設初始位置為link_list第一個
    series(2,ptr);
    series(1,ptr->next);
    // series(2,ptr->next);
    // series(2,ptr->next->next);
    // series(1,ptr->next->next->next);

    result=isPalindrome(first);

    printf("%d\n",result);
    printf("\n");
    free(first);
    system("pause");
    return 0;
}