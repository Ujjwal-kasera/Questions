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
    bool ans=true;
    int balance(TreeNode* root){
        if(!root)
            return 0;
        int left=balance(root->left);
        int right=balance(root->right);
        if(abs(left-right)>1){
            ans=false;
            return 0;
        }
        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h=balance(root);
        return ans;
    }
};