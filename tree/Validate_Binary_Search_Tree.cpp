#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

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


// bool insert_tree(TreeNode **root,int val)
// {
//     //����root����//
//     TreeNode *rootptr=*root;

//     if(rootptr==NULL)
//     {
//         //�ѩ�root�O���Ъ����СA�ҥH�o��O�Nderef���᪺�ȡA�]���s�ت�����//
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
    //����root����//

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


//�o�D����O�z�L�]�m����d�򪺤j�p�ȡA�ӽT�{�U�Ӥ���O�_���ŦXBST���n�D//
bool ValidBST(TreeNode* root,long long min,long long max)
{
    //�p�G�@�����ŦX�n�D�ABST�N�|���쩳//
    if(root==NULL)
    return true;

    //�p�Groot���ȡA�W�L�]�m���W�U��//
    //�h�N���ŦX�n�D//
    if(root->val<=min||root->val>=max)
    return false;

    //�z�L�Nroot���ȡA�]�����l��W���A�γ]���k�l�𪺤U���A����A���U���j//
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