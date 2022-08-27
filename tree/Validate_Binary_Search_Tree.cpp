#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
};


//tree基本操作功能//
TreeNode* create_tree_node(int val)
{
    TreeNode *new_node=(TreeNode*)malloc(sizeof(TreeNode));
    new_node->val=val;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}


// bool insert_tree(TreeNode **root,int val)
// {
//     //紀錄root的值//
//     TreeNode *rootptr=*root;

//     if(rootptr==NULL)
//     {
//         //由於root是指標的指標，所以這邊是將deref之後的值，設成新建的指標//
//         *root=create_tree_node(val);
//         return true;
//     }
    
//     if(val==rootptr->val)
//         return false;

//     if(val<rootptr->val)
//     {
//         return insert_tree(&(rootptr->left),val);
//     }

//     else if(val>rootptr->val)
//     {
//         return insert_tree(&(rootptr->right),val);
//     }

// }

TreeNode* insert_tree(TreeNode *root,int val)
{
    //紀錄root的值//

    if(root==NULL)
    {
        return create_tree_node(val);
    }
    

    if(val<root->val)
    {
        root->left=insert_tree(root->left,val);
    }

    else if(val>root->val)
    {
        root->right=insert_tree(root->right,val);
    }

    return root;
}


//這題思路是透過設置比較範圍的大小值，來確認各個分支是否有符合BST的要求//
bool ValidBST(TreeNode* root,long long min,long long max)
{
    //如果一直都符合要求，BST就會走到底//
    if(root==NULL)
    return true;

    //如果root的值，超過設置的上下限//
    //則代表不符合要求//
    if(root->val<=min||root->val>=max)
    return false;

    //透過將root的值，設為左子樹上限，及設為右子樹的下限，之後再往下遞迴//
    return ValidBST(root->left,min,(long long) root->val)&&ValidBST(root->right,(long long) root->val,max);
}

bool isValidBST(TreeNode* root)
{
    return ValidBST(root,-2147483649,2147483648);
}


int main(void)
{
    TreeNode *root=create_tree_node(2);
    root=insert_tree(root,1);
    root=insert_tree(root,3);
    int val=isValidBST(root);


    printf("%d\n",root->left->val);

    printf("%d\n",val);

    system("pause");
    return 0;
}