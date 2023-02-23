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
    void leafSimilar(TreeNode* root,vector<int> &leaf){
        if(!root)
            return;
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->val);
        }
        leafSimilar(root->left,leaf);
        leafSimilar(root->right,leaf);
    }    
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        leafSimilar(root1,leaf1);
        leafSimilar(root2,leaf2);
        if(leaf1==leaf2)
            return true;
        return false;
    }
};