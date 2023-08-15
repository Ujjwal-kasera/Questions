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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* temp=dummy;
        ListNode* prev=dummy;
        ListNode* help;
        while(temp->next){
            if(temp->next->val<x && temp->next==prev->next){
                temp=temp->next;
                prev=prev->next;
            }
            else if(temp->next->val<x){
                help=temp->next;
                temp->next=help->next;
                help->next=prev->next;
                prev->next=help;
                prev=prev->next;
            }
            else
                temp=temp->next;
        }
        return dummy->next;
    }
};