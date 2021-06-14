/*
construct a binary search tree using preorder sequence
*/


Node* buildBSTfromPre(int pre[], int &idx, int key, int mn, int mx, int n){
    
    if(idx >= n) return NULL;
    
    Node* root = NULL;
    if(key > mn && key < mx){
        root = new Node(key);
        idx++;
        
        if(idx < n){
            root->left = buildBSTfromPre(pre, idx, pre[idx], mn, key, n);
        }
        if(idx < n){
            root->right = buildBSTfromPre(pre, idx, pre[idx], key, mx, n);
        }
    }
    return root;
    
}
