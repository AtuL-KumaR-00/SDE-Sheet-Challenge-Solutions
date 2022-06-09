/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        while(curr1!=curr2){
            if(curr1==NULL)     curr1=headB;
            else curr1=curr1->next;
            if(curr2==NULL)     curr2=headA;
            else curr2=curr2->next;
        }
        return curr1;
    }
};




//Approach 2:

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=1,lenB=1;
        ListNode* temp1=headA;
        while(temp1->next){
            temp1 = temp1->next;
            lenA++;
        }
        ListNode* temp2=headB;
        while(temp2->next){
            temp2 = temp2->next;
            lenB++;
        }
        //cout<<lenA<<"  "<<lenB;
        if(temp2->val != temp1->val)    return NULL;
        
        if(lenB>lenA){
            int diff=lenB-lenA;
            while(diff){
                headB = headB->next;
                diff--;
            }
        }
        else if(lenA>lenB){
            int diff=lenA-lenB;
            while(diff){
                headA = headA->next;
                diff--;
            }
        }
        //cout<<headA->val<<" "<<headB->val;
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
        
    }
};