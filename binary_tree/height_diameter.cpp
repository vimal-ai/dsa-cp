int height(Node* root){
    if(root==NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1+max(lh,rh);
}

int diameter(Node* root){
    if(root==NULL) return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    int cur = lh+rh+1;
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(cur, max(ld,rd));
}

int optimizeDiameter(Node* root, int &h){
    if(root==NULL){
        h=0;
        return 0;  
    } 
    
    int lh,rh;
    int ld = optimizeDiameter(root->left, lh);
    int rd = optimizeDiameter(root->right, rh);
    h=max(lh, rh)+1;
    int cur = lh+rh+1;
    
    return max(cur, max(ld,rd));
}
