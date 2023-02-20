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
    pair<bool,int> balance(TreeNode* root){
        if(!root)
            return {true,0};
        auto left=balance(root->left);
        auto right=balance(root->right);
        int height=max(left.second,right.second)+1;
        if(left.first && right.first && abs(left.second-right.second)<=1){
            return {true,height};
        }
        else 
            return {false,height};
    }
public:
    bool isBalanced(TreeNode* root) {
        auto ans=balance(root);
        return ans.first;
    }
};