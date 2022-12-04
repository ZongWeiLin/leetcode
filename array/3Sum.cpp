#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertion_sort(int *arr,int len)
{
    for(int i=1;i<len;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j-1]>arr[j])
                swap(&arr[j],&arr[j-1]);
            else
                break;
        }
    }
}


void max_heap(int *arr,int mid,int len)
{
    int left=mid*2+1;
    int right=mid*2+2;
    int largest=mid;

    if(left<len&&arr[mid]<arr[left])
        largest=left;
        
    if(right<len&&arr[largest]<arr[right])
        largest=right;

    if(largest!=mid)
    {
        swap(&arr[largest],&arr[mid]);
        max_heap(arr,largest,len);
    }
}

void build_heap(int *arr,int mid,int len)
{
    for (int i=mid-1;i>=0; i--)
    {
        max_heap(arr,i,len);
    }
}

void heap_sort(int *arr,int len)
{
    int mid=len/2;
    int i;
    build_heap(arr,mid,len);

    for(i=len-1;i>=0;i--)
    {
        //��̫᪺element�洫//
        swap(&arr[0],&arr[i]);
        //��̫�@�Ӥ����_�}�A����reheap//
        max_heap(arr,0,i);
    }

}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    
    //���N�}�C�ƧǦn//
    //�o���heap sort�O�]��quick sort�|�ɭPheapoverflow//
    heap_sort(nums,numsSize);

    int total=64;//�G���}�C�檺��l�ȡA�o�䵹64�O�]���p�G�@��realloc�|�ɭP�ɶ��W�L
    *returnSize=0;
    int counter=0;

    *returnColumnSizes=(int*)malloc(sizeof(int)*total);//�����C�@�檺column size
    int **ret_arr=(int**)malloc(sizeof(int*)*total);
    
    int i,j,k;
    int target;
    int sum;

    for(i=0;i<numsSize-2;i++)
    {
        j=i+1,k=numsSize-1;
        target=-nums[i];//��̥��䪺�Ʀr�A���W�t���N�O�ڭ̭n�䪺��
        
        //�p�G�̥��䪺�j��0�A���[�]���|�O0�A�ҥH�i�H����//
        //�M��̥���T�Ӥ����ۥ[�j��0�]�O�i�H������
        if(nums[i]>0||(nums[i]+nums[i+1]+nums[i+2])>0)
                break;
        
        if(i>0&&nums[i]==nums[i-1])//�p�G�����мƦr��e�@�Ӥ@�ˡA���ΦA���@�M�A�]���e���w�g���L�F
            continue;
        
        while(j<k)
        {
            sum=nums[j]+nums[k];//�p�⤤���B�k������Ƥl�`�M
            if(sum==target)
            {                
                //�p�G�P�ؼмƦr�ۦP���ܡA�N�n3��int�j�p��array 
                (*returnColumnSizes)[counter]=3;

                //�⥪���k���ƭȶi�����
                ret_arr[counter]=(int*)malloc(sizeof(int)*3);
                ret_arr[counter][0]=nums[i];
                ret_arr[counter][1]=nums[j++];
                ret_arr[counter][2]=nums[k--];
                
                (*returnSize)++;//�^�Ǫ�row size�]�n+
                counter++;
                
                while(j<k&&nums[j-1]==nums[j])j++;//���������ƪ�����(�����k)
                while(j<k&&nums[k]==nums[k+1])k--;//�]�O���������ƪ�����(�k����)
            
                //�p�Grow���j�p�j�󤧫e�w�]�h�X�j
                 if(counter>=total)
                {
                    total*=2;
                    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*total);
                    ret_arr=(int**)realloc(ret_arr,sizeof(int*)*(total));
                }
            }
            else if(sum<target)
                j++;
            else
                k--;
            
        }
    }

    return ret_arr;
}

void print_arr(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("[%d] ",arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[5]={1,3,4,2,3};
    print_arr(arr,5);



    system("pause");
    return 0;
}