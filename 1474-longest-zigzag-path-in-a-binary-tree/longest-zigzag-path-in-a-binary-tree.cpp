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
    int ans=0;
    int path(TreeNode* root,int count,bool dir){
        if(!root)
            return count-1;
        int ans;
        if(!dir)
            ans=path(root->right,count+1,!dir);
        else
            ans=path(root->left,count+1,!dir);
        return ans;
    }
    void traverse(TreeNode* root){
        if(!root)
            return;
        int temp1=path(root,0,0);
        int temp2=path(root,0,1);
        ans=max({ans,temp1,temp2});
        traverse(root->left);
        traverse(root->right);
    }
    int longestZigZag(TreeNode* root) {
        traverse(root);
        return ans;
    }
};