/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int Count(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    TreeNode* create(ListNode* &head,int count){
        if(count<=0 || head==NULL){
            return NULL;
        }
        TreeNode* leftTree = create(head,count/2);
        TreeNode* root=new TreeNode(head->val);
        root->left=leftTree;
        head=head->next;
        root->right=create(head,count-1-count/2);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = create(head,Count(head));
        return root;
    }
};