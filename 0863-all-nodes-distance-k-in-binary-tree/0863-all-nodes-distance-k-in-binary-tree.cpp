/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void buildParent(TreeNode* root){
        if(!root)
            return;
        if(root->left)
            parent[root->left]=root;
        if(root->right)
            parent[root->right]=root;
        buildParent(root->left);
        buildParent(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root);
        set<int> visited;
        vector<int> res;
        queue<TreeNode*> q;
        q.push(target);
        int cnt=0,n;
        TreeNode* node;
        while(!q.empty()){
            n=q.size();
            if(cnt>k){
                break;
            }
            while(n--){
                node=q.front();
                q.pop();
                if(node->left && !visited.count(node->left->val)){
                    q.push(node->left);
                    visited.insert(node->left->val);
                }
                if(node->right && !visited.count(node->right->val)){
                    q.push(node->right);
                    visited.insert(node->right->val);
                }
                if(parent[node] && !visited.count(parent[node]->val)){
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                }
                visited.insert(node->val);
                if(cnt==k){
                    res.push_back(node->val);
                }
            }
            ++cnt;
        }
        return res;
    }
};