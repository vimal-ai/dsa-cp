/*
  Remove the nth node from end of the linked list
*/

/*
T = O(2N)
*/    

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        
        int length = 0;
        ListNode* temp = head;
        do{
            length++;
            temp=temp->next;
        }while(temp!=NULL);
        
        temp = head;
        length -= n;
        if(length==0) return head->next;
        while(--length){
            temp=temp->next;
        }
        
        ListNode* toBeDeleted = temp->next;
        temp->next = toBeDeleted->next;
        delete(toBeDeleted);
        return head;
    }


/*
T = O(N)
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++) fast=fast->next;
        
        if(fast==NULL) return head->next;
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        fast = slow->next;
        slow->next = fast->next;
        delete(fast);
        return head;
    }
