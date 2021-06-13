void sumReplacement(Node* root){
    if(root==NULL) return;
    
    sumReplacement(root->left);
    sumReplacement(root->right);
    if(root->left) root->data += root->left->data;
    if(root->right) root->data += root->right->data;
}
