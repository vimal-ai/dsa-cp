int height(Node* root){
    if(root==NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1+max(lh,rh);
}

bool isBalanced(Node* root){
    if(root==NULL) return true;
    
    if(!isBalanced(root->left)) return false;
    if(!isBalanced(root->right)) return false;
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)<=1) return true;
    return false;
}

bool optimizeBalanced(Node* root, int &h){
    if(root==NULL){
        h=0;
        return true;
    } 
    
    int lh, rh;
    if(!optimizeBalanced(root->left, lh)) return false;
    if(!optimizeBalanced(root->right, rh)) return false;
    
    h=max(lh, rh)+1;
    
    if(abs(lh-rh)<=1) return true;
    return false;
}
