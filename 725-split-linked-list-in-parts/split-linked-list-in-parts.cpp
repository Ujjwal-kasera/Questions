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
    int lenght(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=lenght(head);
        vector <ListNode*> res(k);
        int count=len%k;
        int split;
        int i=0;
        ListNode *temp;
        while(head){
            split=(len/k)+((count--)>0?1:0)-1;
            temp=head;
            while(temp && split--){
                temp=temp->next;
            }
            res[i++]=head;
            head=temp->next;
            temp->next=NULL;
        }
        return res;
    }
};