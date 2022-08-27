#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };


//���D�䬰://
//�ѩ��D�O���@�Ӥw�g�ƧǦn���}�C�A�ҥH�ڭ̥u�ݭn�䤤���I�A�ð�������᩹�U�~��䤤���I//
//�ѩ󳣬O�Z�T�w���ʧ@�A�ҥH�ڭ̥i�H�λ��j���覡�Ӽg//

struct TreeNode* BST_insertion(int *nums,int left,int right)
{
    if(left>right)
    {
        return NULL;
    }
    else
    {
        //���䤤���I//
        int mid=(right+left)/2;
        struct TreeNode *new_node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        new_node->val=nums[mid];//�t�`�I���Ȭ���������
        //���U�䥪�l��k�l��//
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