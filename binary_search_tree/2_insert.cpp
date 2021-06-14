Node* insertBST(Node* root, int val){
    
    if(root==NULL) return new Node(val);
    
    if(val > root->data){
        root->right = insertBST(root->right, val);
    }
    else{
        root->left = insertBST(root->left, val);
    }
    return root;
}
