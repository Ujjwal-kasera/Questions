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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int len;
        TreeNode* curr;
        double temp;
        while(!q.empty()){
            len=q.size();
            temp=0;
            for(int i=0;i<len;i++){
                curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                temp+=curr->val;
            }
            res.push_back(temp/len);
        }
        return res;
    }
};