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
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=slow->next;
        slow->next=nullptr;
        ListNode* curr=second; //this is the midpoint
        ListNode* prev=nullptr;
        ListNode* temp=nullptr;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        //the list should be reversed now
        ListNode* ptr1=head;
        ListNode* ptr2=prev;
        while(ptr2){
            ListNode* t1=ptr1->next;
            ListNode* t2=ptr2->next;
            ptr1->next=ptr2;
            ptr2->next=t1;
            ptr1=t1;
            ptr2=t2;
        }
    }
};
