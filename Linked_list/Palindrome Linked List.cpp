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

//method1:�䤤���I���b�qLinked list����P�e�b�q���//
// bool isPalindrome(link_list* head)
// {
    
//     if(head==NULL||head->next==NULL)
//         return true;
    
//     //�]�m�ֺC���Ч䤤���I//
//     link_list* slow=head;
//     link_list* fast=head;
//     link_list* mid;
    
//     while(fast!=NULL&&fast->next!=NULL)
//     {
//         mid=slow;//�̫���X��slow��n�|�b�������a��
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     mid->next=NULL;//�̤����I�N�e�ᰵ����
    
//     //����List//
//     link_list* previous=NULL;
    
//     fast=slow;
    
//     while(slow!=NULL)
//     {
//         fast=slow->next;//�s�U�@�Ӹ`�I
//         slow->next=previous;//���e�`�I���V�e�@�Ӹ`�I
//         previous=slow;//������i�A�ϫe�@�Ӹ`�I����e�`�I
//         slow=fast;//�Ϸ�e�`�I���U�@�Ӹ`�I
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

    //��linked list���X���I//
    while (ptr!=NULL)
    {
        n++;
        ptr=ptr->next;
    }

    int arr[n];
    ptr=head;

    //��linked list��Ʀs��}�C//
    while (ptr!=NULL)
    {
        arr[i++]=ptr->value;
        ptr=ptr->next;
    }
    
    //�}�C�}�l�Y���i����//
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
    ptr=first;//�]��l��m��link_list�Ĥ@��
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