/*
check give tree is BST or not
*/


// using inorder property of BST (inorder sequence of BST is always sorted)

bool checkBST(Node* root, int &pre){
    if(root == NULL){
        pre = 0;
        return 1;
    } 
    
    bool left = checkBST(root->left, pre);
    if(pre > root->data) return 0;
    pre = root->data;
    bool right = checkBST(root->right, pre);
    
    if(left && right) return 1;
    return 0;
}

// mantaining range for current node usig its perent node
bool checkBST(Node* root, Node* mn, Node* mx){
    
    if(root==NULL) return true;
    
    if(mn != NULL && root->data <= mn->data) return false;
    if(mn != NULL && root->data >= mx->data) return false;
    
    bool leftValid = checkBST(root->left, mn, root);
    bool rightValid = checkBST(root->right, root, mx);
    
    return leftValid and rightValid;
    
}
