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
