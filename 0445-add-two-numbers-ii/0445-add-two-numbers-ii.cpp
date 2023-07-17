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
    ListNode* reverse(ListNode* head){
        ListNode* newhead=head,*tmp=head;
        while(head && head->next){
            tmp=tmp->next;
            head->next=tmp->next;
            tmp->next=newhead;
            newhead=tmp;
            tmp=head;
        }
        return newhead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int sum,carry;
        ListNode *head=new ListNode(-1);
        ListNode *prev=head;
        while(l1 || l2 || carry){
            sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* tmp=new ListNode(sum%10);
            prev->next=tmp;
            prev=prev->next;
        }
        return reverse(head->next);
    }
};