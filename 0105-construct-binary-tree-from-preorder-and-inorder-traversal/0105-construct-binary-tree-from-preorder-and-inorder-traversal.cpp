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
    // int findElement(vector<int> inorder,int size,int element){
    //     for(auto i=0;i<size;i++)
    //         if(inorder[i]==element)
    //             return i;
    //     return -1;
    // }
    int index=0;
    map<int,int> mp;
    TreeNode* solve(vector<int>& preorder,int start,int end){
        if(start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index++]);
        int position=mp[root->val];
        root->left=solve(preorder,start,position-1);
        root->right=solve(preorder,position+1,end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=preorder.size();
        for(int i=0;i<len;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=solve(preorder,0,len-1);
        return root;
    }
};