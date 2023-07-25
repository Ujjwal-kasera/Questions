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
    // Approach 2
    int count=0;
    void countNode(TreeNode* root,int maxi){
        if(!root)
            return;
        if(root->val>=maxi){
            count++;
            maxi=root->val;
        }
        countNode(root->left,maxi);
        countNode(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        countNode(root,INT_MIN);
        return count;
    }

    // Approach 1
    // int goodNodes(TreeNode* root,int maxi=INT_MIN) {
    //     int ans=0;
    //     if(!root)
    //         return ans;
    //     if(root->val>=maxi){
    //         ans++;
    //         maxi=max(maxi,root->val);
    //     }
    //     int left=goodNodes(root->left,maxi);
    //     int right=goodNodes(root->right,maxi);
    //     ans+=(left+right);
    //     return ans;
    // }
};