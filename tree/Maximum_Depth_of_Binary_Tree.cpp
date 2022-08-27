#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
};


//tree�򥻾ާ@�\��//
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
    //����root����//
    TreeNode *rootptr=*root;

    if(rootptr==NULL)
    {
        //�ѩ�root�O���Ъ����СA�ҥH�o��O�Nderef���᪺�ȡA�]���s�ت�����//
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
    //���쩳�F�A�ѩ�U���S�����I�A�ҥH�S���`��(�^��0)//
    if(root==NULL)return 0;
    hr=maxDepth(root->right);
    hl=maxDepth(root->left);

    //���l��k�l�����A���̤j��+1�^��//
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