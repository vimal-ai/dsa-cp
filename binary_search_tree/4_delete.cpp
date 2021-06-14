Node* inorderSucc(Node* root){
    
    while(root && root->left != NULL){
        root = root->left;
    }return root;
}

Node* deleteBST(Node* root, int val){
    
    if(root==NULL) return NULL;
    
    if(val == root->data){
        if(root->left == NULL){
            Node* node = root->right;
            delete(root);
            return node;
        }
        if(root->right == NULL){
            Node* node = root->left;
            delete(root);
            return node;
        }
        Node* succ = inorderSucc(root->right);
        root->data = succ->data;
        root->right = deleteBST(root->right, succ->data);
    }
    
    if(val < root->data){
        root->left = deleteBST(root->left, val);
    }
    root->right = deleteBST(root->right, val);
    return root;
}
