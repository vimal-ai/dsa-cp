
// flatten a binary tree into singly linked list inplace in preorder sequence such that all left children are NULL 
void flatten(Node* root){
    if(root==NULL) return;
    
    Node* node = root;
    
    flatten(root->left);
    flatten(root->right);
    
    Node* right = root->right;
    root->right = root->left;
    root->left = NULL;
    
    while(root->right!=NULL){
        root=root->right;
    }
    root->right = right;

}
