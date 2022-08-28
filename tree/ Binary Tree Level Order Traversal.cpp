#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };

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



int maxDepth(struct TreeNode* root)
{
    int hr,hl;
    //���쩳�F�A�ѩ�U���S�����I�A�ҥH�S���`��(�^��0)//
    if(root==NULL)return 0;
    hr=maxDepth(root->right);
    hl=maxDepth(root->left);

    //���l��k�l�����A���̤j��+1�^��//
    if(hr>hl)return hr+1;
    else return hl+1;
}

void inorder_traversal(struct TreeNode* root,int **arr,int row,int *col,int depth)
{
    if(root==NULL)
        return ;
    //row��ܾ𪺼h�ơA�p�GTraversal�`�׻Prow�N��ȶi��g�J//
    if(row==depth)
    {
        arr[row][*col]=root->val;
        *col+=1;
    }
    //�`�׬O�ѤW���U���W//
    inorder_traversal(root->left,arr,row,col,depth+1);
    inorder_traversal(root->right,arr,row,col,depth+1);
}

int** levelOrder(struct TreeNode* root)
{
    //���T�{�𪺰���//
    int level=maxDepth(root);
    //�Ѿ𪺰��רM�w�A2���}�C���X��row//
    int **arr=(int**)malloc(sizeof(int*)*level);
    int col;
    for(int i=0;i<level;i++)
    {
        //�C��row����O��������Ŷ�//
        arr[i]=(int*)malloc(sizeof(int)*500);
        //�ѩ�O�Hrow�������h�Ϥ�//
        //�ҥHcol�C��s��row�ɭn�k0//
        col=0;
        //Traversal�ɡA�J��`�׻P��erow�ۦP��node�N�i��g�J//
        inorder_traversal(root,arr,i,&col,0);
    }

    return arr;
}


int main(void)
{
    int arr[7]={3,9,20,3,15,20,7};
    struct TreeNode *root=sortedArrayToBST(arr,7);

    int **arr2=levelOrder(root);

    printf("%d\n",arr2[1][1]);

    system("pause");
    return 0;
}