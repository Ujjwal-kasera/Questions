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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* pred,*temp;
        while(root){
            if(!root->left){
                k--;
                if(k==0)
                    return root->val;
                root=root->right;
            }
            else{
                pred=root->left;
                while(pred->right)
                    pred=pred->right;
                pred->right=root;
                temp=root;
                root=root->left;
                temp->left=NULL;
            }
        }
        return -1;
    }
};