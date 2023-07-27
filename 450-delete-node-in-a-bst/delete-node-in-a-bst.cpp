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
    TreeNode* nodeDelete(TreeNode* root){
        TreeNode* tmp;

        // Left child is only present
        if(root->left && !root->right){
            tmp=root->left;
            delete(root);
            return tmp;
        }

        // Right child is only present
        else if(!root->left && root->right){
            tmp=root->right;
            delete(root);
            return tmp;
        }

        // Both child are present
        else if(root->left && root->right){
            tmp=root->right;
            cout<<tmp->val<<endl;
            while(tmp->left){
                tmp=tmp->left;
            }
            cout<<tmp->val<<endl;
            root->val=tmp->val;
            root->right=deleteNode(root->right,tmp->val);
            return root;
        }

        // Leaf node
        delete(root);
        return NULL;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(!root)
            return NULL;

        // delete function
        if(root->val==key)
            return nodeDelete(root); //delete function

        // to check if key is in left subtree 
        else if(key<root->val)
            root->left=deleteNode(root->left,key);
        
        // to check if key is in left subtree
        else
            root->right=deleteNode(root->right,key);

        return root;
    }
};