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
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        int ans=1e9;
        int len=vec.size();
        for(int i=0;i<len-1;i++)
            ans=min(ans,vec[i+1]-vec[i]);
        return ans;
    }
};