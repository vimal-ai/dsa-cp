/*
merge linked list using extra space (additional linked list)
*/

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    SinglyLinkedListNode* head;

    if(head1->data <= head2->data){
        head = head1;
        head->next = mergeLists(head1->next, head2);
    }else{
        head = head2;
        head->next = mergeLists(head1, head2->next);   
    } 
    return head;
}

/*
merge two linked list with O(1) space (in place)
*/
Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    if(head1->data < head2->data){
        head1->next = sortedMerge(head1->next, head2);
    }else{
        Node* temp = head2->next;
        head2->next = head1;
        head1 = head2;
        head1->next = sortedMerge(head1->next,temp);
    }
    return head1;
} 
