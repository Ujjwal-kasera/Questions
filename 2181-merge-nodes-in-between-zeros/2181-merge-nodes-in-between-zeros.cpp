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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *slow,*fast;
        slow=head;
        fast=head->next;
        while(fast){
            if(fast->next==NULL)
                slow->next=NULL;
            else if(fast->val==0){
                slow->next=fast;
                slow=fast;
            }else{
                slow->val+=fast->val;
            }
            fast=fast->next;
        }
        return head;
    }
};