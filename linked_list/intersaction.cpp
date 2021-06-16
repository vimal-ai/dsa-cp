/*
T = O(N+M) 
S = O(N+M)
*/
Node* intersectPoint(Node* head1, Node* head2)
{
    stack<Node*>s1;
    stack<Node*>s2;
    
    while(head1!=NULL){
        s1.push(head1);
        head1=head1->next;
    }
    while(head2!=NULL){
        s2.push(head2);
        head2=head2->next;
    }
    Node* p=NULL;
    while(!s1.empty() && !s2.empty()){
        
        if(s1.top() == s2.top()){
            p=s1.top();
            s1.pop();
            s2.pop();
        }
        else{
            return p;
        }
        
    }return NULL;
}

/*
T = O(N+M)
S = O(1)
*/

int intersectPoint(Node* head1, Node* head2)
{
    Node* d1=head1;
    Node* d2=head2;
    
    while(d1!=NULL && d2!=NULL){
        d1=d1->next;
        d2=d2->next;
        if(d1==d2) return d1->data;
        if(d1==NULL) d1 = head2;
        if(d2==NULL) d2 = head1;
    }
    
}
