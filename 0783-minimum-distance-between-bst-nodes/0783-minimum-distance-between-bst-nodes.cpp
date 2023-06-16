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
    vector<int> vec;
    void solve(TreeNode* root){
        if(!root)
            return;
        solve(root->left);
        vec.push_back(root->val);
        solve(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        solve(root);
        int mini=INT_MAX;
        int len=vec.size();
        sort(vec.begin(),vec.end());
        for(int i=0;i<(len-1);i++){
            mini=min(mini,vec[i+1]-vec[i]);
        }
        return mini;
    }
};