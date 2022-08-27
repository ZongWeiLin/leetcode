#include <stdio.h>
#include <stdlib.h>

int arr[4]={11,7,2,7};

struct node
{
    long val;
    int index;
    struct node* next;
};

typedef struct node node;

//hash table link list insert//
void insert(node** hash_table,long val,int index,int n)
{
    int t=abs(val)%n;//hash function
    node* temp=hash_table[t];//link_list previos node
    node* add=(node*)malloc(sizeof(node));
    add->val=val;
    add->index=index;
    add->next=temp->next;
    temp->next=add;
}


int search(node** hash_table,long target,int n)
{
    int index=abs(target)%n;
    node* temp=hash_table[index]->next;
    while(temp)
    {
        if(temp->val==target)
        {
            return temp->index;
        }
        temp=temp->next;
    }
    
    return -1;
}

int* twoSum(int* nums, int numsSize, int target)
{
    int i=0,j=0;
    int n=numsSize,index=0;
    int* result=(int*)malloc(sizeof(int)*2);
    node** hash_table=(node**)malloc(sizeof(node*)*n);
    
    //allocate space to hash_table pointer
    for(i=0;i<n;i++)
        hash_table[i]=(node*)calloc(1,sizeof(node));
    
    for(i=0;i<n;i++){
        index=search(hash_table,target-nums[i],n);
        
        if(index==-1)
            insert(hash_table,nums[i],i,n);
        else{
            result[0]=index;
            result[1]=i;
            return result;
        }
    }
        
    return result;
}


int main(void)
{
    int *ret;
    int *size_ret;
    ret=twoSum(arr,4,9);
    printf("[%d,%d]\n",ret[0],ret[1]);
    free(ret);
    system("pause");
    return 0;
}


