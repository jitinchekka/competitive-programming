#include<iostream>
using namespace std;
struct TreeNode{
int data;
TreeNode* left;
TreeNode* right;
};
Treenode* invertTree(TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    TreeNode* leftree= invertTree(root->right);
    TreeNode* rightree=invertTree(root->left);

    root->left =rightree;
    root->right=leftree;
    
    return root;
}
int main()
{

}