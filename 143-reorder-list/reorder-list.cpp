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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* tmp=head;
        while(tmp){
            vec.push_back(tmp);
            tmp=tmp->next;
        }
        int left=0,right=vec.size()-1;
        while(left<right){
            vec[left]->next=vec[right];
            ++left;
            if(left==right)
                break;
            vec[right]->next=vec[left];
            --right;
        }
        vec[left]->next=NULL;
    }
};