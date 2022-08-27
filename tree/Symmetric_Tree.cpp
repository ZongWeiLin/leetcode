#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };


//�ΨӲ��;�//
TreeNode* BST_insertion(int *nums,int left,int right)
{
    if(left>right)
    {
        return NULL;
    }
    else
    {
        //���䤤���I//
        int mid=(right+left)/2;
        TreeNode *new_node=(TreeNode*)malloc(sizeof(TreeNode));
        new_node->val=nums[mid];//�t�`�I���Ȭ���������
        //���U�䥪�l��k�l��//
        new_node->right=BST_insertion(nums,mid+1,right);
        new_node->left=BST_insertion(nums,left,mid-1);
        return new_node;
    }
}

TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return BST_insertion(nums,0,numsSize-1);
}



//method1//
//�z�Linorder traversal�⨫�Lnode���Ȧs�btemp�o��array//
//�ðO���`�@���X��node//
//����ѩ�Oinorder traversal�����Y�A�ҥH�ڭ̥u�ݭn�Ѥ����I�}�l�i��e����//
//�N�i�H�T�{�O�_�O��پ�//
// int temp[1000];
// int counter=0;//�Ω����node�ƶq


// int inorder_traversal(TreeNode* node)
// {
//     if(node!=NULL)
//     {
//         inorder_traversal(node->left);
//         temp[counter]=node->val;
//         counter++;
//         inorder_traversal(node->right);
//     }

// }



// bool isSymmetric(TreeNode* root)
// {
//     inorder_traversal(root);

//     int mid=counter/2;

//     if(counter%2==0) return false;//�p�Gcounter�O���ƾ����|�����šA�ҥH�|�D���

//     for(int i=0;i<counter/2;i++)
//     {
//         if(temp[mid-i]!=temp[mid+i]) return false;
//     }

//     memset(temp,0,sizeof(int)*1000);

//     return true;
// }

bool isMirror(TreeNode *t1,TreeNode *t2)
{
    if(t1==NULL&&t2==NULL) return true;
    if(t1==NULL||t2==NULL) return false;
    if(t1->val!=t2->val) return false;
    else
    return isMirror(t1->right,t2->left)&&isMirror(t1->left,t2->right);
}

bool isSymmetric(TreeNode* root)
{
    if(root==NULL) return true;
    return isMirror(root->left,root->right);
}

int main(void)
{   
    int arr[1]={1};
    
    TreeNode *root=sortedArrayToBST(arr,1);

    int val=isSymmetric(root);

    printf("%d\n",val);

    system("pause");
    return 0;
}