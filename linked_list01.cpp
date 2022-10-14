#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }


};
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;


}
void deletion(node* head,int val){
    node* temp=head;
    while (temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    

}
void dishplay(node* head){
    node* temp=head;
    while (temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;

    }
    cout<<temp->data<<endl;
    
}
node* reverse(node* head){
    node* privious=NULL;
    node* x=head;
    node* current=head;
    node* nextptr;
    while (current!=NULL)
    {
        nextptr=current->next;
        current->next=privious;
        privious=current;
        current=nextptr;


    }

    dishplay(x);
    head=privious;
    dishplay(head);
    dishplay(privious);
    dishplay(head);
    return privious;
    
}
node* reversek(node* head, int k)
{
    // base case
    if (!head)
        return NULL;
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
  
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
  
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reversek(next, k);
  
    /* prev is new head of the input list */
    return prev;
}
  
node* reverseKnode(node* head,int k){
    node* prevptr=NULL;
    node* currentptr=head;
    node* nexptr;
    int count=0;
    while ((currentptr!=NULL)&&(count<k))
    {
        nexptr=currentptr->next;
        currentptr->next=prevptr;
        prevptr=currentptr;
        currentptr=nexptr;
        count++;

    }
    if(nexptr!=NULL){
        
       head->next= reverseKnode(nexptr,k);
    }

    return prevptr;
}
int main(){
    node* head; 
    head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    dishplay(head);
    int k=2;
    // dishplay(reversek(head,k));
    dishplay(reverseKnode(head,k));
    dishplay(head);


 
}
