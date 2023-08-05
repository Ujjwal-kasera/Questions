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
    vector<TreeNode*> generateTrees(int n,int s=1) {
        if(s>n)
            return {NULL};
        vector<TreeNode*> res;
        for(int i=s;i<=n;i++){
            vector<TreeNode*> left=generateTrees(i-1,s);
            vector<TreeNode*> right=generateTrees(n,i+1);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(i,l,r);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    // vector<TreeNode*> solve(int s,int e){
    //     if(s>e)
    //         return {NULL};
    //     vector<TreeNode*> res;
    //     for(int i=s;i<=e;i++){
    //         vector<TreeNode*> left=solve(s,i-1);
    //         vector<TreeNode*> right=solve(i+1,e);
    //         for(auto l:left){
    //             for(auto r:right){
    //                 TreeNode* root=new TreeNode(i,l,r);
    //                 res.push_back(root);
    //             }
    //         }
    //     }
    //     return res;
    // }
    // vector<TreeNode*> generateTrees(int n) {
    //     return solve(1,n);
    // }
};