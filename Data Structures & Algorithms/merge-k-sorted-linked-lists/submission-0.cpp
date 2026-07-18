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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        ListNode dummy;
        ListNode* ans=&dummy;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
        greater<pair<int, ListNode*>>> pq;
        for(int i=0;i<len;i++){
            if(lists[i]!=nullptr){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        if(pq.empty()){return nullptr;}
        while(!pq.empty()){
            auto p=pq.top();
            ans->next=p.second;
            pq.pop();
            if(p.second->next!=nullptr){
                pq.push({p.second->next->val,p.second->next});
            }
            ans=ans->next;
        }
        return dummy.next;
    }
};
