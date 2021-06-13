int search(int arr[], int start, int end, int key){
    for(int i=start;i<=end;i++){
        if(key == arr[i]) return i;
    }
}

Node* buildFromPre(int pre[], int in[], int start, int end){
    if(start>end) return NULL;
    
    static int idx = 0;
    
    int curr = pre[idx];
    idx++;
    Node* node = new Node(curr);
    
    if(start==end) return node;
    
    int pos = search(in, start, end, curr);
    node->left = buildFromPre(pre, in, start, pos-1);
    node->right = buildFromPre(pre, in, pos+1, end);
    
    return node;
}

Node* buildFromPost(int post[], int in[], int start, int end){
    if(start>end) return NULL;
    
    static int id = end;
    int curr = post[id];
    id--;
    
    Node* node = new Node(curr);
    
    if(start==end) return node;
    int pos = search(in, start, end, curr);
    node->right = buildFromPost(post, in, pos+1, end);
    node->left = buildFromPost(post, in, start, pos-1);
    
    return node;
    
}

int countNodes(Node* root){
    if(root==NULL) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

int treeSum(Node* root){
    if(root==NULL) return 0;
    return root->data+treeSum(root->left)+treeSum(root->right);
}
