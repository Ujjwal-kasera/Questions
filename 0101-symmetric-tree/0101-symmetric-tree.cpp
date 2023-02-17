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
    bool mirror(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2)
            return true;
        else if(!root1 || !root2)
            return false;
        if(root1->val==root2->val){
            bool left=mirror(root1->left,root2->right);
            bool right=mirror(root1->right,root2->left);
            return left && right;
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left,root->right);
    }
};