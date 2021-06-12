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
void insertAtHead(Node* &head, int val){
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

void insert(Node* head, int val){
    Node* node = new Node(val);
    while(head->next != NULL){
        head = head->next;
    }head->next = node;
}

void insertAt(Node* head, int val, int pos){
    Node* node = new Node(val);
    pos--;
    while(pos-- && head->next!=NULL){
        head = head->next;
    }
    node->next = head->next;
    head->next = node;
    
}

// deletion in linked list
void deleteAtEnd(Node* head){
    
    while(head->next->next!=NULL){
        head=head->next;
    }
    delete(head->next);
    head->next=NULL;
}

void deleteVal(Node* &head, int val){
    if(head==NULL) return;
    
    Node* temp = head;
    if(head->data == val){
        head = head->next;
        delete(temp);
        return;
    }
    
    while(temp->next!=NULL && temp->next->data!=val){
        temp = temp->next;
    }
    if(temp->next!=NULL && temp->next->data == val){
        Node* toBeDeleted = temp->next;
        temp->next = toBeDeleted->next;
        delete(toBeDeleted);
    }
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
	
	Node* head = NULL;
    insertAtHead(head, 1);
	insert(head, 2);
	insert(head, 3);
    insert(head, 4);
	travel(head);
	
    deleteAtEnd(head);
	travel(head);
	
	deleteVal(head, 3);
	travel(head);
	
	insertAt(head, 5, 4);
	travel(head);
	
	return 0;
}
