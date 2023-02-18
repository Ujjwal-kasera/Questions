#include<bits/stdc++.h>
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

// Approach 1
/*
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        vector<int>vec;
        ListNode* head=new ListNode(-10001);
        ListNode* temp=head;
        for(int i=0;i<len;i++){
            while(lists[i]!=NULL){
                vec.push_back(lists[i]->val);
                    lists[i]=lists[i]->next;
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            ListNode* node=new ListNode(vec[i]);
            temp->next=node;
            temp=temp->next;
        }
        return head->next;
    }
};
*/

// Appproach 2

struct compare{
    bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val;
    }
};
class Solution {    
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> mp;
        int k=lists.size();
        if(k==0)
            return NULL;
        for(int i=0;i<k;i++){
            if(lists[i])
                mp.push(lists[i]);
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        ListNode* tmp;
        while(!mp.empty()){
            tmp=mp.top();
            mp.pop();
            if(tmp->next)
                mp.push(tmp->next);
            if(head==NULL){
                head=tmp;
                tail=tmp;
            }else{
                tail->next=tmp;
                tail=tail->next;
            } 
        }
        return head;
    }
};