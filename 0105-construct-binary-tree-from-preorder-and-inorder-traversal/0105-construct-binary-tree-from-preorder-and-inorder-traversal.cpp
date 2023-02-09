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
    int findElement(vector<int> inorder,int size,int element){
        for(auto i=0;i<size;i++)
            if(inorder[i]==element)
                return i;
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int &index,int size){
        if(index>=size || start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index++]);
        int position=findElement(inorder,size,root->val);
        root->left=solve(preorder,inorder,start,position-1,index,size);
        root->right=solve(preorder,inorder,position+1,end,index,size);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=preorder.size();
        int index=0;
        TreeNode* root=solve(preorder,inorder,0,len-1,index,len);
        return root;
    }
};