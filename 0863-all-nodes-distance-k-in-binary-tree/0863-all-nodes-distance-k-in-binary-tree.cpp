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
    vector<int> res;
    set<int> visited;
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
    
    void bfs(TreeNode* root,int k){
        queue<TreeNode*> q;
        q.push(root);
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
    }
    
    void dfs(TreeNode* root,int k){
        if(k<0)
            return;
        if(k==0){
            res.push_back(root->val);
            return;
        }
        visited.insert(root->val);
        if(root->left && !visited.count(root->left->val)){
            dfs(root->left,k-1);
            visited.insert(root->left->val);
        }
        if(root->right && !visited.count(root->right->val)){
            dfs(root->right,k-1);
            visited.insert(root->right->val);
        }
        if(parent[root] && !visited.count(parent[root]->val)){
            dfs(parent[root],k-1);
            visited.insert(parent[root]->val);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root);
        // bfs(target,k);
        dfs(target,k);
        return res;
    }
};