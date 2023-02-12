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
public:
    
    /*
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left!=NULL && root->val<root->left->val)
            return false;
        if(root->right!=NULL && root->val>root->right->val)
            return false;
        bool left=isValidBST(root->left);
        bool right=isValidBST(root->right);
        if(left && right)
            return true;
        else 
            return false;
    }
    */
    
    bool isBST(TreeNode* root,long mini,long maxi){
        if(root==NULL)
            return true;
        if(root->val<=mini || root->val>=maxi){
            return false;
        }
        return (isBST(root->left,mini,root->val) && isBST(root->right,root->val,maxi));
    }
    bool isValidBST(TreeNode* root) {
        long mini=-2147483649;
        long maxi=2147483648;
        return isBST(root,mini,maxi);
    }
};