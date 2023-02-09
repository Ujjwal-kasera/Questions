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
private:
    int index;
    map<int,int> mp;
    TreeNode* solve(vector<int>& postorder,int start,int end){
        if(index<0 || start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[index--]);
        int position=mp[root->val];
        root->right=solve(postorder,position+1,end);
        root->left=solve(postorder,start,position-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=postorder.size();
        index=len-1;
        for(int i=0;i<len;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=solve(postorder,0,len-1);
        return root;
    }
};