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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(!head->next) return NULL;
        int len=0;
        ListNode* curr=head;
        while(curr!=NULL)   {
            len++;
            curr=curr->next;
        }
        len=len-n;
        if(len==0) return head->next;
        ListNode* prev=NULL;
        curr=head;
        int i=0;
        while(i!=len){
            i++;
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
    }
};



//Optimal approach:

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(!head->next) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++)    fast=fast->next;
        if(fast==NULL)  return head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next=slow->next->next;
        return head;
    }
};