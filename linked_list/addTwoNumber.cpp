    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l1;
        int res = 0;
        while(l2!=NULL && temp!=NULL){
            temp->val = temp->val + l2->val + res;
            res = temp->val/10;
            temp->val = temp->val%10;
            
            if(temp->next==NULL){
                if(l2->next!=NULL) temp->next = l2->next;
                else if(res){
                    temp->next = new ListNode(res);
                    return l1;
                } 
                temp=temp->next;
                l2=l2->next;
                break;
            }
            temp=temp->next;
            l2=l2->next;
        }
        
        while(temp!=NULL){
            temp->val = temp->val + res;
            res = temp->val/10;
            temp->val = temp->val%10;
            if(temp->next==NULL){
                if(res) temp->next = new ListNode(res);
                break;
            }
            temp=temp->next;
        }
         
        return l1;
    }
