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
    void path(TreeNode* root,int count,bool dir){
        if(!root)
            return;
        ans=max(ans,count);
        if(dir==0){
            path(root->left,count+1,1);
            path(root->right,1,0);
        }
        else{
            path(root->right,count+1,0);
            path(root->left,1,1);
        }
        return;
    }
    int longestZigZag(TreeNode* root) {
        path(root,0,0);
        path(root,0,1);
        return ans;
    }
    
    // int ans=0;
    // int path(TreeNode* root,int count,bool dir){
    //     if(!root)
    //         return count-1;
    //     int ans;
    //     if(!dir)
    //         ans=path(root->right,count+1,!dir);
    //     else
    //         ans=path(root->left,count+1,!dir);
    //     return ans;
    // }
    // void traverse(TreeNode* root){
    //     if(!root)
    //         return;
    //     int temp1=path(root,0,0);
    //     int temp2=path(root,0,1);
    //     ans=max({ans,temp1,temp2});
    //     traverse(root->left);
    //     traverse(root->right);
    // }
    // int longestZigZag(TreeNode* root) {
    //     traverse(root);
    //     return ans;
    // }
};