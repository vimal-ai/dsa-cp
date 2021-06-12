// floyd's algorithm (hare and tartoise algorithm)

// cycle detection 
bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

// cycle removal
void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    do{
        slow=slow->next;
        fast=fast->next->next;                                                                                                                                                
    }while(slow!=fast);
    
    fast=head;
    while(slow->next != fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = NULL;
}
