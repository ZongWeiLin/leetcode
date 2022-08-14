#include <stdio.h>
#include <stdlib.h>

//mehtod1//
//�ݭn���X�B�N�h�}�X��Ŷ�//
// void rotate(int* nums, int numsSize, int k)
// {
    
//     //���੹������//
//     if(k<=0)    
//     return;

//     //�p�Garray size��1�A�N���β���//
//     if(numsSize==1)
//     return;
    
//     //�p�Gk��array size���ơA�N���β���//
//     if(k%numsSize==0)
//     return;

//     k=k%numsSize;

//     int arr[k];
//     int last=numsSize-1;
    
//    //����n�k�������s���Ȧs��array//
//     for(int i=k-1;i>=0;i--)
//     {
//         arr[i]=nums[last];
//         last--;
//     }

//     //��쥻��array�U�ӭȩ��Ჾk�B//
//     for (int i=numsSize-k-1; i>=0; i--)
//     {
//         nums[i+k]=nums[i];
//     }
    
//     //����k���������A�[��쥻array���e��//
//     for (int i=0; i<k;i++)
//     {
//         nums[i]=arr[i];
//     }
    
// }

//method2//
//�����}�@�Ӹ��J�}�C�@�˪����}�C//
// void rotate(int* nums, int numsSize, int k)
// {
//     int buf[numsSize];

//     for(int i=0;i<numsSize;i++)
//     {
//         buf[(i+k)%numsSize]=nums[i];
//     }

//     for (int i = 0; i < numsSize; i++)
//     {
//         nums[i]=buf[i];    
//     }
// }

//method3//
//�u�Τ@�ӼȦs�Ӧs�}�C�̫�@�Ӥ���//
//��쥻�o�C���k����//
//��}�C�Ĥ@�ӡA���������Ȧs������//
void rotate(int* nums, int numsSize, int k)
{
    int temp;
    for(int i=0;i<k;i++)
    {   
        temp=nums[numsSize-1];

        for (int j =numsSize-2; j>=0; j--)
        {
            nums[j+1]=nums[j];
        }

        nums[0]=temp;
    }
}

int main(void)
{
    int arr[5]={1,2,3,4,5};

    rotate(arr,5,3);

    for (int i = 0; i < 5; i++)
    {
        printf("%d,",arr[i]);
    }

    printf("\n");

    system("pause");
    return 0;
}