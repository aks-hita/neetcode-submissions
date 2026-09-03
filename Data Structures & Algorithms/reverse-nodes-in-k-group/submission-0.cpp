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
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* temp=nullptr;
        while(curr!=tail){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* mid=head;
        int count=0;
        while(count<k && mid!=nullptr){
            count++;
            mid=mid->next;
        }
        if(count<k) return head;
        ListNode* new_head=mid;
        mid=reverse(head,mid);
        head->next=reverseKGroup(new_head,k);
        return mid;
    }
};
