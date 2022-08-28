#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };

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



int maxDepth(struct TreeNode* root)
{
    int hr,hl;
    //走到底了，由於下面沒有結點，所以沒有深度(回傳0)//
    if(root==NULL)return 0;
    hr=maxDepth(root->right);
    hl=maxDepth(root->left);

    //左子樹右子樹比較，取最大值+1回傳//
    if(hr>hl)return hr+1;
    else return hl+1;
}

void inorder_traversal(struct TreeNode* root,int **arr,int row,int *col,int depth)
{
    if(root==NULL)
        return ;
    //row表示樹的層數，如果Traversal深度與row就把值進行寫入//
    if(row==depth)
    {
        arr[row][*col]=root->val;
        *col+=1;
    }
    //深度是由上往下遞增//
    inorder_traversal(root->left,arr,row,col,depth+1);
    inorder_traversal(root->right,arr,row,col,depth+1);
}

int** levelOrder(struct TreeNode* root)
{
    //先確認樹的高度//
    int level=maxDepth(root);
    //由樹的高度決定，2維陣列有幾條row//
    int **arr=(int**)malloc(sizeof(int*)*level);
    int col;
    for(int i=0;i<level;i++)
    {
        //每條row都跟記憶體索取空間//
        arr[i]=(int*)malloc(sizeof(int)*500);
        //由於是以row做為階層區分//
        //所以col每到新的row時要歸0//
        col=0;
        //Traversal時，遇到深度與當前row相同的node就進行寫入//
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