#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };


//解題思為://
//由於本題是給一個已經排序好的陣列，所以我們只需要找中間點，並做拆分之後往下繼續找中間點//
//由於都是蠻固定的動作，所以我們可以用遞迴的方式來寫//

struct TreeNode* BST_insertion(int *nums,int left,int right)
{
    if(left>right)
    {
        return NULL;
    }
    else
    {
        //先找中間點//
        int mid=(right+left)/2;
        struct TreeNode *new_node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        new_node->val=nums[mid];//另節點的值為中間的值
        //往下找左子樹右子樹//
        new_node->right=BST_insertion(nums,mid+1,right);
        new_node->left=BST_insertion(nums,left,mid-1);
        return new_node;
    }
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return BST_insertion(nums,0,numsSize-1);
}

int main(void)
{
    int arr[5]={-10,-3,0,5,9};

    struct TreeNode* root=sortedArrayToBST(arr,5);

    printf("%d\n",root->right->val);

    system("pause");
    return 0;
}