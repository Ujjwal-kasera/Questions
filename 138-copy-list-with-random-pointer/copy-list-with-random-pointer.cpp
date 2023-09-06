/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> mp;
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        if(mp.count(head))
            return mp[head];
        Node* temp=new Node(head->val);
        mp[head]=temp;
        temp->next=copyRandomList(head->next);
        temp->random=copyRandomList(head->random);
        return temp;
    }
};