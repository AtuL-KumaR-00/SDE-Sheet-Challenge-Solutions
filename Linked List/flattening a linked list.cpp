// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

    int t;
    cin>>t;
    while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
    struct Node * head=NULL;
    struct Node * pre=NULL;
    struct Node * tempB=NULL;
    struct Node * preB=NULL;
        cin>>n;
        int work[n];
        for(int i=0;i<n;i++)
            cin>>work[i];
        for(int i=0;i<n;i++){
            m=work[i];
            --m;
            int data;
            scanf("%d",&data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;
            
            if(flag){
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else{
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for(int j=0;j<m;j++){
                
                int temp_data;
                scanf("%d",&temp_data);
                tempB = new Node(temp_data);

                if(flag1){
                    temp->bottom=tempB;
                    preB=tempB;
                    flag1=0;
                }
                else{
                    preB->bottom=tempB;
                    preB=tempB;
                }
            }
        }
           Node *fun = head;
           Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

    }
    return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* mergeTwoLists(Node* list1,Node* list2) {
        if(list1==NULL && list2==NULL)  return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        Node* head=new Node( 0);
        Node* curr=head;
        Node* prev;
        while(list1!=NULL && list2!=NULL){
            if(list1->data > list2->data){
                curr->data=list2->data;
                curr->bottom = new Node(0);
                prev=curr;
                curr=curr->bottom;
                list2=list2->bottom;
            }else{
                curr->data=list1->data;
                curr->bottom=new Node(0);
                prev=curr;
                curr=curr->bottom;
                list1=list1->bottom;
            }
        }
        while(list1!=NULL){
            curr->data=list1->data;
            curr->bottom=new Node(0);
            prev=curr;
            curr=curr->bottom;
            list1=list1->bottom;
        }
        while(list2!=NULL){
            curr->data=list2->data;
            curr->bottom=new Node(0);
            prev=curr;
            curr=curr->bottom;
            list2=list2->bottom;
        }
        prev->bottom=NULL;
        return head;
    }
    
    
    
Node *flatten(Node *root)
{
   // Your code here
   //Node* head;
   if(root->next==NULL) return root;
   root ->next= flatten ( root->next);
   root = mergeTwoLists( root , root->next );
   
   return root;
}




// APPROACH 2 BETTER

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/

Node* merge(Node* a , Node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    Node* result;
    if(a->data < b->data){
        result = a;
        result->child = merge(a->child , b);
    }
    else{
        result = b;
        result->child = merge(a,b->child);
    }
    result->next = NULL;
    return result;
}
Node* flattenLinkedList(Node* head) 
{
    if(head == NULL || head->next == NULL)
        return head;
    return merge(head , flattenLinkedList(head->next));
}
