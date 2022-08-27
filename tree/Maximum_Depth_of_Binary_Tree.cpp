#include <stdio.h>
#include <stdlib.h>

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

bool insert_tree(TreeNode **root,int val)
{
    //紀錄root的值//
    TreeNode *rootptr=*root;

    if(rootptr==NULL)
    {
        //由於root是指標的指標，所以這邊是將deref之後的值，設成新建的指標//
        *root=create_tree_node(val);
        return true;
    }
    
    if(val==rootptr->val)
        return false;

    if(val<rootptr->val)
    {
        return insert_tree(&(rootptr->left),val);
    }

    else if(val>rootptr->val)
    {
        return insert_tree(&(rootptr->right),val);
    }

}

int maxDepth(TreeNode* root)
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



int main(void)
{
    TreeNode *root=create_tree_node(2);
    int val;
    val=insert_tree(&root,1);
    val=insert_tree(&root,3);

    int max=maxDepth(root);

    printf("%d\n",root->left->val);
    printf("%d\n",max);


    system("pause");
    return 0;
}