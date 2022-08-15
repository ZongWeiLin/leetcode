#include <stdio.h>
#include <stdlib.h>


int singleNumber(int* nums, int numsSize)
{
    int result = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		//透過XOR會把與自己相同部分刪除的特性//
        //所以最後只會剩一下沒有重複的部分//
        result ^= nums[i];
	}
	return result;
    
}

int main(void)
{
    int arr[3]={1,1,498};
    int val=singleNumber(arr,3);
    printf("%d\n",val);
    system("pause");
    return 0;
}