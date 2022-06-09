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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)  return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* head=new ListNode( 0);
        ListNode* curr=head;
        ListNode* prev;
        while(list1!=NULL && list2!=NULL){
            if(list1->val > list2->val){
                curr->val=list2->val;
                curr->next=new ListNode(0);
                prev=curr;
                curr=curr->next;
                list2=list2->next;
            }else{
                curr->val=list1->val;
                curr->next=new ListNode(0);
                prev=curr;
                curr=curr->next;
                list1=list1->next;
            }
        }
        while(list1!=NULL){
            curr->val=list1->val;
            curr->next=new ListNode(0);
            prev=curr;
            curr=curr->next;
            list1=list1->next;
        }
        while(list2!=NULL){
            curr->val=list2->val;
            curr->next=new ListNode(0);
            prev=curr;
            curr=curr->next;
            list2=list2->next;
        }
        prev->next=NULL;
        return head;
    }
};



//for Coding ninjas, code is given below:

#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)
{
    // Write your code here.
        if(list1==NULL && list2==NULL)  return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        Node<int>* head=new Node<int>( 0);
        Node<int>* curr=head;
        Node<int>* prev;
        while(list1!=NULL && list2!=NULL){
            if(list1->data > list2->data){
                curr->data = list2->data;
                curr->next=new Node<int>( 0);
                prev=curr;
                curr=curr->next;
                list2=list2->next;
            }else{
                curr->data=list1->data;
                curr->next=new Node<int>(0);
                prev=curr;
                curr=curr->next;
                list1=list1->next;
            }
        }
        while(list1!=NULL){
            curr->data = list1->data;
            curr->next=new Node<int>(0);
            prev=curr;
            curr=curr->next;
            list1=list1->next;
        }
        while(list2!=NULL){
            curr->data=list2->data;
            curr->next=new Node<int>(0);
            prev=curr;
            curr=curr->next;
            list2=list2->next;
        }
        prev->next=NULL;
        return head;
}