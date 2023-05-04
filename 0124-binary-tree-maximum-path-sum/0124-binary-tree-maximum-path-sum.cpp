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
    int sum=INT_MIN;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int leftSum=max(solve(root->left),0);
        int rightSum=max(solve(root->right),0);
        sum=max(sum,(leftSum+rightSum+root->val));
        return (max(leftSum,rightSum)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return sum;
    }
};