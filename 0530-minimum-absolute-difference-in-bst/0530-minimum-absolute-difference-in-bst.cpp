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
    priority_queue<int> pq;
    void solve(TreeNode* root){
        if(!root)
            return;
        pq.push(root->val);
        solve(root->left);
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        int ans=1e9;
        int a=pq.top(),b;
        pq.pop();
        while(pq.size()>0){
            b=pq.top();
            pq.pop();
            ans=min(ans,a-b);
            a=b;
        }
        return ans;
    }
};