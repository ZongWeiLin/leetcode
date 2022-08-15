#include <stdio.h>
#include <stdlib.h>


int singleNumber(int* nums, int numsSize)
{
    int result = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		//�z�LXOR�|��P�ۤv�ۦP�����R�����S��//
        //�ҥH�̫�u�|�Ѥ@�U�S�����ƪ�����//
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