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
    int index=0;
    TreeNode* bstFromPreorder(vector<int>& preorder,int maxi=INT_MAX) {
        if(index==preorder.size() || preorder[index]>maxi)
            return NULL;
        TreeNode* root=new TreeNode(preorder[index++]);
        root->left=bstFromPreorder(preorder,root->val);
        root->right=bstFromPreorder(preorder,maxi);
        return root; 
    }
    // TreeNode* buildTree(vector<int>&preorder,int maxi){
    //     if(index==preorder.size() || preorder[index]>maxi)
    //         return NULL;
    //     TreeNode* root=new TreeNode(preorder[index++]);
    //     root->left=buildTree(preorder,root->val);
    //     root->right=buildTree(preorder,maxi);
    //     return root;
    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder){
    //     return buildTree(preorder,INT_MAX);
    // }
};