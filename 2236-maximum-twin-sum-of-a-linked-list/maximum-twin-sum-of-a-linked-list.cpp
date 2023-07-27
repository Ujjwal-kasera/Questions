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
class Solution {
public:
    int maxi=0;
    void solve(ListNode* &head,ListNode* tail){
        if(!tail)
            return;
        solve(head,tail->next);
        maxi=max(maxi,head->val+tail->val);
        head=head->next;
    }
    int pairSum(ListNode* head) {
        solve(head,head);
        return maxi;
    }
};