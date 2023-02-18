/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
// Approach 1
/*
    TreeNode* tmp;
    void invert(TreeNode* root){
        if(!root)
            return;
        invert(root->left);
        invert(root->right);
        tmp=root->right;
        root->right=root->left;
        root->left=tmp;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
*/
public:
   TreeNode* invertTree(TreeNode* root){
        if(!root)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
   }  
};