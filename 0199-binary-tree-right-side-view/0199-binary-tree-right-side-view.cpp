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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        map<int,int> mp;
        queue <pair<TreeNode*,int>> q;
        pair<TreeNode*,int> curr;
        TreeNode* node;
        int lv;
        if(root)
            q.push({root,0});
        while(!q.empty()){
            curr=q.front();
            q.pop();
            node=curr.first;
            lv=curr.second;
            mp[lv]=node->val;
            if(node->left)
                q.push({node->left,lv+1});
            if(node->right)
                q.push({node->right,lv+1});
        }
        for(auto i:mp)
            res.push_back(i.second);
        return res;
    }
};