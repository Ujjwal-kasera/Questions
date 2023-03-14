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
    int target;
    vector<vector<int>> res;
    void path(TreeNode* root, int num,vector<int> temp){
        temp.push_back(root->val);
        if(!root->left && !root->right && num==target){
            res.push_back(temp);
            return;
        }
        else if(!root->left && !root->right && num!=target)
            return;
        if(root->left)
            path(root->left,num+root->left->val,temp);
        if(root->right)
            path(root->right,num+root->right->val,temp);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        vector<int> temp;
        if(root)
            path(root,root->val,temp);
        return res;
    }
};