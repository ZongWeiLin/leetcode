#include <stdio.h>
#include <stdlib.h>

//mehtod1//
//看要移幾步就多開幾格空間//
// void rotate(int* nums, int numsSize, int k)
// {
    
//     //不能往左移動//
//     if(k<=0)    
//     return;

//     //如果array size為1，代表不用移動//
//     if(numsSize==1)
//     return;
    
//     //如果k為array size倍數，代表不用移動//
//     if(k%numsSize==0)
//     return;

//     k=k%numsSize;

//     int arr[k];
//     int last=numsSize-1;
    
//    //先把要右移部分存的暫存的array//
//     for(int i=k-1;i>=0;i--)
//     {
//         arr[i]=nums[last];
//         last--;
//     }

//     //把原本的array各個值往後移k步//
//     for (int i=numsSize-k-1; i>=0; i--)
//     {
//         nums[i+k]=nums[i];
//     }
    
//     //把剛剛右移的部分，加到原本array的前面//
//     for (int i=0; i<k;i++)
//     {
//         nums[i]=arr[i];
//     }
    
// }

//method2//
//直接開一個跟輸入陣列一樣長的陣列//
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
//只用一個暫存來存陣列最後一個元素//
//把原本這列往右平移//
//把陣列第一個，替換成剛剛暫存的元素//
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