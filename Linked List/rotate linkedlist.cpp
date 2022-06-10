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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* curr=head;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        //cout<<len;
        k=k%len;
        if(k==0) return head;
        curr=head;
        int itr=len-k;
        while(itr>1){
            itr--;
            curr=curr->next;
        }
        ListNode* next=curr->next;
        curr->next=NULL;
        curr=next;
        //if(curr==NULL)
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = head;
        return next;
    }
};