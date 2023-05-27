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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1,head);
        ListNode* prev=dummy;
        ListNode *temp=head;
        ListNode *newhead=head;
        while(true){
            for(int i=0;i<k;i++){
                if(temp==NULL)
                    return dummy->next;
                temp=temp->next;
            }
            temp=head;
            for(int i=0;i<k-1;i++){
                temp=temp->next;
                head->next=temp->next;
                temp->next=newhead;
                newhead=temp;
                temp=head;
            }
            prev->next=newhead;
            prev=head;
            head=head->next;
            temp=head;
            newhead=head;
        }
        return dummy->next;
    }
};