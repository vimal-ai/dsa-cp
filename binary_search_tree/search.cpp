Node* searchBST(Node* root, int val){
    
    if(root == NULL) return NULL;
    
    if(val == root->data) return root;
    
    if(val < root->data){
        return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
}
