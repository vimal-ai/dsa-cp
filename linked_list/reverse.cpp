#include <bits/stdc++.h>
using namespace std;

// defination of linked list
class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

// insertion in linked list
void insert(Node* head, int val){
    Node* node = new Node(val);
    while(head->next != NULL){
        head = head->next;
    }head->next = node;
}

// reverse the linked list
void reverseList(Node* &head){
    Node* pre=NULL;
    Node* curr=head;
    Node* next=NULL;
    
    while(curr!=NULL){
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    head = pre;
}

Node* reverseListByGroup(Node* head, int k){
    Node* pre=NULL;
    Node* curr=head;
    Node* next=NULL;
    
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
        count++;
    }
    if(next!=NULL) head->next = reverseListByGroup(next, k);
    return pre;
}

// traversal in linked list
void travel(Node* head){
    if(head==NULL) return;
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }cout<<"NULL"<<endl;
}

int main() {
	Node* head = new Node(1);
	insert(head, 2);
	insert(head, 3);
  insert(head, 4);
	travel(head);
	
	reverseList(head);
	travel(head);
	
	
	return 0;
}
