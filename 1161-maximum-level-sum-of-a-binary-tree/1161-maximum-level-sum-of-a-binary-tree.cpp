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
    int maxLevelSum(TreeNode* root) {
        int res=INT_MIN;
        int ans;
        int h=1;
        queue<TreeNode*> q;
        q.push(root);
        int len;
        TreeNode* curr;
        int temp;
        while(!q.empty()){
            len=q.size();
            temp=0;
            while(len--){
                curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                temp+=curr->val;
            }
            if(temp>res){
                res=temp;
                ans=h;
            }
            h++;
        }
        return ans;
    }
};