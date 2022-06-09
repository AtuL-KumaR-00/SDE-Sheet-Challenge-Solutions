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

//Bruteforce: to store all the values in a vector.

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head->next==NULL) return true;
        while(fast->next!=NULL && fast->next->next!=NULL  ){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast==head)  return head->val==head->next->val;
        slow->next = reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(slow->val!=head->val)    return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};