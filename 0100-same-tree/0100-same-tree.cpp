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
    
    /* koi bi tree same tbhi hoga jb uska left subtree, right subtree
        aur node ki value same ho.. agr aisa nhi h to wo same tree nhi h
    */
    
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if(p==NULL && q==NULL)
    //         return true;
    //     else if(p==NULL || q==NULL)
    //         return false;
    //     if(p->val!=q->val)
    //         return false;
    //     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    // }
    
    // same logic with optimised code
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        else if(p==NULL || q==NULL)
            return false;
        if(p->val!=q->val)
            return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};