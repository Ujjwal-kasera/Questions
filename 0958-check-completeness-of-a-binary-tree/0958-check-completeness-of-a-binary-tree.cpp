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
    int count=0;
    void countNode(TreeNode* root){
        if(!root)
            return;
        countNode(root->left);
        count++;
        countNode(root->right);
    }
    bool isComplete(TreeNode* root,int index){
        if(!root)
            return true;
        if(index>=count)
            return false;
        bool left=isComplete(root->left,2*index+1);
        bool right=isComplete(root->right,2*index+2);
        return left && right;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        countNode(root);
        return isComplete(root,0);
    }
};