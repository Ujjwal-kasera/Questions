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
    map<TreeNode*,int> Rob;
    map<TreeNode*,int> donotRob;
    int traverse(TreeNode* root,bool flag){
        if(!root)
            return 0;
        int ans1=0,ans2=0;
        if(flag){
            if(Rob.count(root))
                return Rob[root];
            ans1+=root->val;
            ans1+=traverse(root->left,0);
            ans1+=traverse(root->right,0);
            ans2+=traverse(root->left,1);
            ans2+=traverse(root->right,1);
            return Rob[root]=max(ans1,ans2);
        }
        else{
            if(donotRob.count(root))
                return donotRob[root];
            ans1+=traverse(root->left,1);
            ans1+=traverse(root->right,1);
            return donotRob[root]=ans1;
        }
    }
    int rob(TreeNode* root) {
        return traverse(root,1);
        
    }
};