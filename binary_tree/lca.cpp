bool path(Node* root, int key, vector<Node*> &v){
    if(root==NULL) return 0;
    
    v.push_back(root);
    
    if(root->data==key) return 1;
    
    bool l=path(root->left, key, v);
    bool r=path(root->right, key, v);
    
    if(!l && !r){
        v.pop_back();
        return 0;
    } 
    return 1;
}

Node* lca(Node* root, int a, int b){
    vector<Node*>lpath;
    vector<Node*>rpath;
    
    if(!path(root,a,lpath) || !path(root, b,rpath)) return NULL;
    Node* node;
    for(int i=0;i<lpath.size() && rpath.size();i++){
        if(lpath[i]!=rpath[i]) break;
        node = lpath[i];
    }
    return node;
}

Node* lca2(Node* root, int a, int b){
    if(root==NULL) return NULL;
    
    if(root->data == a || root->data == b) return root;
    
    Node* leftLCA = lca2(root->left, a, b);
    Node* rightLCA = lca(root->right, a, b);
    
    if(leftLCA && rightLCA) return root;
    if(leftLCA) return leftLCA;
    if(rightLCA) return rightLCA;
    return NULL;
}

int minDist(Node* root, int a, int b){
    vector<Node*>lpath;
    vector<Node*>rpath;
    
    if(!path(root,a,lpath) || !path(root, b,rpath)) return -1;
    int dist;
    int i=0;
    for(i=0;i<lpath.size() && rpath.size();i++){
        if(lpath[i]!=rpath[i]) break;
    }
    dist = lpath.size()+rpath.size()-(2*i);
    return dist;
}
